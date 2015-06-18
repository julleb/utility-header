#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../utility-header.hpp"

#include <string>
#include <vector>

TEST_CASE( "Splitting strings with spaces", "[strings/tokenize]" ) {
    std::string test_string1 = "Hello World!";
    std::string test_string2 = "";
    std::string test_string3 = "1";
    std::vector<std::string> should_be1 = {"Hello", "World!"};
    std::vector<std::string> should_be2 = {""};
    std::vector<std::string> should_be3 = {"1"};
    REQUIRE( utils::split_on_spaces(test_string1) == should_be1 );
    REQUIRE( utils::split_on_spaces(test_string2) == should_be2 );
    REQUIRE( utils::split_on_spaces(test_string3) == should_be3 );

}

TEST_CASE( "Changing strings to lowercase", "[strings/to_lower]" ) {
    std::string test_string1 = "Hello World!";
    std::string test_string2 = "";
    std::string test_string3 = "11A11a11";
    utils::to_lower(test_string1);
    utils::to_lower(test_string2);
    utils::to_lower(test_string3);
    REQUIRE( test_string1 == "hello world!" );
    REQUIRE( test_string2 == "" );
    REQUIRE( test_string3 == "11a11a11" );
}

TEST_CASE( "Changing strings to uppercase", "[strings/to_upper]" ) {
    std::string test_string1 = "Hello World!";
    std::string test_string2 = "";
    std::string test_string3 = "11A11a11";
    utils::to_upper(test_string1);
    utils::to_upper(test_string2);
    utils::to_upper(test_string3);
    REQUIRE( test_string1 == "HELLO WORLD!" );
    REQUIRE( test_string2 == "" );
    REQUIRE( test_string3 == "11A11A11" );
}

