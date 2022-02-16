#include "map"//
#ifndef AUTH_PANICHELPER_H
#define AUTH_PANICHELPER_H
#include "string"

class PanicHelper {
public:  static  std::map<int, std::string> errormap;
public:  static void panic_withcode( int code, bool critical = false, const std::string& message = "");
public:  static  void success();

};
#endif //AUTH_PANICHELPER_H