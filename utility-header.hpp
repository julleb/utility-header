#ifndef JULLEB_UTILITY_HEADER_HPP
#define JULLEB_UTILITY_HEADER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdexcept>
namespace utils {

    // Splits a string on spaces and returns a vector:
    // "Hello World !" => ["Hello", "World", "!"]
    std::vector<std::string> split_on_spaces(const std::string& s);

    // Splits a string on delimeter and returns a vector:
    // "the_cat-is_black" => ["the", "cat-is", "black"]
    // if the delimeter is an underscore.
    std::vector<std::string> tokenize(const std::string& s, const std::string& delim);

    // Modifies your string and converts it to lowercase.
    void to_lower(std::string& s);

    // Modifies your string and converts it to uppercase.
    void to_upper(std::string& s);

    //converts a integer to a string
    std::string int_to_string(const int &integer);
    
    //converts a string to int
    int string_to_int(const std::string& s);

    
    std::string read_file(const std::string & filename);
    
    ////////////////////
    // Implementation //
    ////////////////////

    std::string read_file(const std::string & filename) {

        std::string text; //returning the file as a string        
        std::ifstream file(filename);
        std::string line;
        
        if(!file.is_open()) { // could not open the file
           throw "File couldnt be open due to some reasons!";
        }        

        while(std::getline(file, line)) {   
            text +=line;
            text +='\n';
        }
        return text;
    }

    std::vector<std::string> split_on_spaces(const std::string& s) {
        return tokenize(s, std::string(" "));
    }

    std::vector<std::string>
    tokenize(const std::string& s, const std::string& delim) {
        // put substrings in this result vector as soon as you find a delimeter
        std::vector<std::string> tokens;

        // we'll start from s[0] and look for a delimeter
        size_t pos = 0;
        size_t delim_location = s.find_first_of(delim, pos);

        // no delimiters found, cant tokenize
        if(delim_location == std::string::npos) {
            tokens.push_back(s);
        } else {
            while(pos != std::string::npos) {
                // push back word without delimiter
                tokens.push_back(s.substr(pos, delim_location - pos));
                if(delim_location == std::string::npos) {
                    // end of string
                    pos = delim_location;
                } else {
                    // next char, skip the delimiter
                    pos = delim_location + 1;
                }
                delim_location = s.find_first_of(delim, pos);
            }
        }
        return tokens;
    }

    void to_lower(std::string& s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    }

    void to_upper(std::string& s) {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    
    
    std::string int_to_string(const int &integer) {
        char the_string[32];
        sprintf(the_string, "%d", integer);
        return the_string;
    }

    int string_to_int(const std::string& s) {
        int integer = atoi(&s[0]);
        return integer;
        
    }
    std::string keyboard_input() {
        std::string input;        
        getline(std::cin, input);
        return input; 
    }



}
#endif
