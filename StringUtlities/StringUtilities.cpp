#include "StringUtilities.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
std::string StringUtilities::remove_first_line(std::string string) {
    string.erase(0, string.find('\n') + 1);
    return  string;
}

std::string StringUtilities::remove_pattern_from_string(std::string string, char pattern) {
    string.erase(remove(string.begin(), string.end(), pattern), string.end()); 
    return string;
}

void StringUtilities::split(const std::string &str, const char delim, std::vector<std::string> &out) {
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}


