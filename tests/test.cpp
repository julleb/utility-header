#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../utility-header.hpp"

#include <string>
#include <vector>

TEST_CASE( "Splitting strings with spaces", "[strings]" ) {
    std::string test_string1 = "Hello World!";
    std::vector<std::string> should_be1 = {"Hello", "World!"};
    REQUIRE( split_on_spaces(test_string1) == should_be1 );
}
