#ifndef SOFTLOQ_UNICODE_HPP
#define SOFTLOQ_UNICODE_HPP

/**
 * @author Brandon Foster
 * @file unicode.hpp
 * @version 1.0.0
 * @brief Basic Unicode Conversion Functions.
 */

#include "softloq-unicode/error.hpp"

namespace Softloq::Unicode
{

    /**
     * @brief Converts the first UTF-8 character sequence in a string to their corresponding codepoint.
     *
     * @param utf8 The string that will be used in the conversion. Only the first UTF-8 sequence found will be converted.
     * @param codepoint Holds the UTF-8 codepoint.
     * @param byte_count Holds the number of bytes read. Value will be 0 on failure.
     * @param err Holds the error message on failure.
     *            Use a reference to a local error instance.
     *            A value of nullptr will skip this process.
     *            Default value: nullptr.
     * @return bool - true on successful conversion else false.
     */

    SOFTLOQ_UNICODE_API const bool ConvertUTF8ToCodepoint(const std::string_view &utf8, char32_t &codepoint, size_t &byte_count, Error *err = nullptr);
    /**
     * @brief Converts the UTF-8 codepoint to their corresponding UTF-8 character sequence. Appends the sequence to end of a string.
     *
     * @param codepoint The UTF-8 codepoint that will be used in the conversion.
     * @param utf8 The string that the converted codepoint will be append to.
     * @param err Holds the error message on failure.
     *            Use a reference to a local error instance.
     *            A value of nullptr will skip this process.
     *            Default value: nullptr.
     * @return bool - true on successful conversion else false.
     */
    SOFTLOQ_UNICODE_API const bool ConvertCodepointToUTF8(const char32_t codepoint, std::string &utf8, Error *err = nullptr);
}

#endif