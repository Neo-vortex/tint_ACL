#include <vector>
#include "iostream"
#ifndef AUTH_STRINGUTILITIES_H
#define AUTH_STRINGUTILITIES_H


class StringUtilities {
public: static  std::string remove_first_line(std::string string);
public: static  std::string remove_pattern_from_string(std::string string, char pattern);

public: static  void split(std::string const &str, char delim,
                              std::vector<std::string> &out);
};


#endif //AUTH_STRINGUTILITIES_H
