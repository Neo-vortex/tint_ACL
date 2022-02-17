#include <sstream>
#include <iostream>
#include <map>
#include "PanicHelper.h"
#include "../ErrorPrinter/ErrorPrinter.h"

std::map<int, std::string> PanicHelper::errormap = {{0, "Could not create needed directories"},
                                                    {1 , "Not enough args "} ,
                                                    { 2, "user exists"},
                                                    {3,"username is missing"},
                                                    {4,"no such user"},
                                                    {5,"bad password"},
                                                    {6,"missing domain"},
                                                    {7,"invalid argument"},
                                                    {8,"missing object"},
                                                    {9,"missing type"},
                                                    {10,"missing operation"},
                                                    {11,"access denied"}  };

ErrorPrinter  global_error_printer;
 void  PanicHelper::panic_withcode( int code, bool critical , const std::string& message ) {
    std::stringstream ss;
    ss  << errormap.find(code)->second ;
    if (!message.empty()){
     //ss<< " : " << message;  output should be standard
    }
    ErrorPrinter::printerror(ss.str());
    if (critical) exit(code);
}

void PanicHelper::success() {
     std::cout << "Success" << std::endl;
}
