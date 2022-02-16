#include "ErrorPrinter.h"
#include "iostream"
void ErrorPrinter::printerror(const std::string& message) {
    std::cout << "Error: " << message;
}
