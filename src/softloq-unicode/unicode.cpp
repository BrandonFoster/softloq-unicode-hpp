#include "softloq-unicode/unicode.hpp"

namespace Softloq::Unicode
{
    SOFTLOQ_UNICODE_API const bool convertUTF8ToCodepoint(const std::string_view &utf8, char32_t &codepoint, size_t &byte_count, Error *err)
    {
        if (utf8.empty())
            return false;

        const char8_t c0 = static_cast<char8_t>(utf8[0]);
        if (c0 <= 0x7F)
        {
            // utf-8 one byte char range: 0000 0000 - 0111 1111

            byte_count = 1;
            codepoint = c0;
            return true;
        }
        else if (0xC0 <= c0 && c0 <= 0xDF)
        {
            // utf-8 two byte char range: 1100 0000 - 1101 1111

            const char8_t c1 = static_cast<char8_t>(utf8[1]);
            if (0x80 <= c1 && c1 <= 0xBF)
            {
                byte_count = 2;
                codepoint = static_cast<char32_t>(((c0 - 0xC0) << 6) + (c1 - 0x80));
                return true;
            }
        }
        else if (0xE0 <= c0 && c0 <= 0xEF)
        {
            // utf-8 three byte char range: 1110 0000 - 1110 1111

            const char8_t c1 = static_cast<char8_t>(utf8[1]);
            const char8_t c2 = static_cast<char8_t>(utf8[2]);
            if (0x80 <= c1 && c1 <= 0xBF && 0x80 <= c2 && c2 <= 0xBF)
            {
                byte_count = 3;
                codepoint = static_cast<char32_t>(((c0 - 0xE0) << 12) + ((c1 - 0x80) << 6) + (c2 - 0x80));
                return true;
            }
        }
        else if (0xF0 <= c0 && c0 <= 0xF7)
        {
            // utf-8 four byte char range: 1111 0000 - 1111 0111

            const char8_t c1 = static_cast<char8_t>(utf8[1]);
            const char8_t c2 = static_cast<char8_t>(utf8[2]);
            const char8_t c3 = static_cast<char8_t>(utf8[3]);
            if (0x80 <= c1 && c1 <= 0xBF && 0x80 <= c2 && c2 <= 0xBF && 0x80 <= c3 && c3 <= 0xBF)
            {
                byte_count = 4;
                codepoint = static_cast<char32_t>(((c0 - 0xF0) << 18) + ((c1 - 0x80) << 12) + ((c2 - 0x80) << 6) + (c3 - 0x80));
                return true;
            }
        }

        // not defined in any utf-8 ranges
        if (err)
            err->message = "Undefined UTF8 Sequence.";

        byte_count = 0;
        return false;
    }

    SOFTLOQ_UNICODE_API const bool convertCodepointToUTF8(const char32_t codepoint, std::string &utf8, Error *err)
    {
        if (codepoint <= 0x007F)
        {
            utf8 += static_cast<char>(codepoint);
            return true;
        }
        else if (codepoint <= 0x07FF)
        {
            utf8 += static_cast<char>(0xC0 + (0x1F & (codepoint >> 6)));
            utf8 += static_cast<char>(0x80 + (0x3F & codepoint));
            return true;
        }
        else if (codepoint <= 0xFFFF)
        {
            utf8 += static_cast<char>(0xE0 + (0x0F & (codepoint >> 12)));
            utf8 += static_cast<char>(0x80 + (0x3F & (codepoint >> 6)));
            utf8 += static_cast<char>(0x80 + (0x3F & codepoint));
            return true;
        }
        else if (codepoint <= 0x10FFFF)
        {
            utf8 += static_cast<char>(0xF0 + (0x07 & (codepoint >> 18)));
            utf8 += static_cast<char>(0x80 + (0x3F & (codepoint >> 12)));
            utf8 += static_cast<char>(0x80 + (0x3F & (codepoint >> 6)));
            utf8 += static_cast<char>(0x80 + (0x3F & codepoint));
            return true;
        }

        if (err)
            err->message = "Expected Range 0x0 - 0x10FFFF.";

        return false;
    }
}