#include <catch2/catch_test_macros.hpp>
#include <softloq-unicode/macros.hpp>

TEST_CASE("Unicode Macros", "[macros]")
{
    SECTION("SOFTLOQ_UNICODE_LIMIT macro")
    {
        REQUIRE(SOFTLOQ_UNICODE_LIMIT == 0x10FFFF);
    }
}