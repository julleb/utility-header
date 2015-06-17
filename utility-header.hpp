#ifndef JULLEB_UTILITY_HEADER_HPP
#define JULLEB_UTILITY_HEADER_HPP

#include <string>
#include <vector>

std::vector<std::string> split_on_spaces(const std::string& str);
std::vector<std::string> tokenize(const std::string& str, const std::string& delim);

/* TODO documentation*/
std::vector<std::string> split_on_spaces(const std::string& str)
{
    return tokenize(str, std::string(" "));
}

/* TODO documentation*/
std::vector<std::string> tokenize(const std::string& str, const std::string& delim)
{
    // result vector
    std::vector<std::string> tokens;

    // we'll start from str[0] and look for a delimeter
    size_t pos = 0;
    size_t delim_location = str.find_first_of(delim, pos);

    // no delimiters found, cant tokenize
    if(delim_location == std::string::npos) {
        tokens.push_back(str);
    } else {
        while(pos != std::string::npos) {
            // push back word without delimiter
            tokens.push_back(str.substr(pos, delim_location - pos));
            if(delim_location == std::string::npos) {
                // end of string
                pos = delim_location;
            } else {
                // next char, skip the delimiter
                pos = delim_location + 1;
            }
            delim_location = str.find_first_of(delim, pos);
        }
    }
    return tokens;
}

#endif
