#include <catch2/catch_test_macros.hpp>
#include <softloq-unicode/unicode.hpp>

using namespace Softloq;

TEST_CASE("Unicode UTF-8 to Codepoint", "[utf8-to-codepoint]")
{
    SECTION("UTF-8 string to a single byte codepoint.")
    {
        std::string utf8 = "A";
        char32_t codepoint;
        size_t byte_count;

        REQUIRE(Unicode::convertUTF8ToCodepoint(utf8, codepoint, &byte_count));
        REQUIRE(byte_count == 1);
        REQUIRE(codepoint == 'A');
    }

    SECTION("UTF-8 string to a two byte codepoint.")
    {
        std::string utf8 = "©"; // Copyright Symbol
        char32_t codepoint;
        size_t byte_count;

        REQUIRE(Unicode::convertUTF8ToCodepoint(utf8, codepoint, &byte_count));
        REQUIRE(byte_count == 2);
        REQUIRE(codepoint == 0xA9);
    }

    SECTION("UTF-8 string to a three byte codepoint.")
    {
        std::string utf8 = "∑"; // Capital Sigma
        char32_t codepoint;
        size_t byte_count;

        REQUIRE(Unicode::convertUTF8ToCodepoint(utf8, codepoint, &byte_count));
        REQUIRE(byte_count == 3);
        REQUIRE(codepoint == 0x2211);
    }

    SECTION("UTF-8 string to a four byte codepoint.")
    {
        std::string utf8 = "😐"; // Neutral Face Emoji
        char32_t codepoint;
        size_t byte_count;

        REQUIRE(Unicode::convertUTF8ToCodepoint(utf8, codepoint, &byte_count));
        REQUIRE(byte_count == 4);
        REQUIRE(codepoint == 0x1F610);
    }
}

TEST_CASE("Unicode Codepoint to UTF-8", "[codepoint-to-utf8]")
{
    SECTION("Appending a single byte codepoint to string.")
    {
        char32_t codepoint = 'A';
        std::string utf8;

        REQUIRE(Unicode::convertCodepointToUTF8(codepoint, utf8));
        REQUIRE(utf8.size() == 1);
        REQUIRE(utf8 == "A");
    }

    SECTION("Appending a two byte codepoint to string.")
    {
        char32_t codepoint = 0xA9; // Copyright Symbol
        std::string utf8;

        REQUIRE(Unicode::convertCodepointToUTF8(codepoint, utf8));
        REQUIRE(utf8.size() == 2);
        REQUIRE(utf8 == "©");
    }

    SECTION("Appending a three byte codepoint to string.")
    {
        char32_t codepoint = 0x2211; // Capital Sigma
        std::string utf8;

        REQUIRE(Unicode::convertCodepointToUTF8(codepoint, utf8));
        REQUIRE(utf8.size() == 3);
        REQUIRE(utf8 == "∑");
    }

    SECTION("Appending a four byte codepoint to string.")
    {
        char32_t codepoint = 0x1F610; // Neutral Face Emoji
        std::string utf8;

        REQUIRE(Unicode::convertCodepointToUTF8(codepoint, utf8));
        REQUIRE(utf8.size() == 4);
        REQUIRE(utf8 == "😐");
    }
}
