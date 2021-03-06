#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../utility-header.hpp"

#include <string>
#include <vector>

/*
TEST_CASE("Reading files", "[ReadFiles]") {
    utils::read_file("test_textfile1");
}
*/

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

TEST_CASE( "Converts int to string", "[int/to_string]" ) {
    int test_int1 = 5;
    int test_int2 = 100;
    int test_int3 = 9000;
    
    REQUIRE( utils::int_to_string(test_int1) == "5" );
    REQUIRE( utils::int_to_string(test_int2) == "100" );
    REQUIRE( utils::int_to_string(test_int3) == "9000" );
}

TEST_CASE( "Converts string to int", "[string/to_int]" ) {
    std::string s1 = "100";
    std::string s2 = "1";
    std::string s3 = "20";
    REQUIRE( utils::string_to_int(s1) == 100 );
    REQUIRE( utils::string_to_int(s2) == 1  );
    REQUIRE( utils::string_to_int(s3) == 20  );
}

/*
TEST_CASE("Input", "[INPUT]" ) {
    std::string input = utils::keyboard_input();
    std::cout<<input<<std::endl;
    REQUIRE(input == "hej");
}*/


