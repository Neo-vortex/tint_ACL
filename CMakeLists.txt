cmake_minimum_required(VERSION 3.21)
project(auth)

set(CMAKE_CXX_STANDARD 23)
#add_compile_options(-Ofast -funroll-loops -flto)
add_executable(auth main.cpp DirctoryStructureHelper/DirectoryStructureHelper.cpp DirctoryStructureHelper/DirectoryStructureHelper.h ErrorPrinter/ErrorPrinter.cpp ErrorPrinter/ErrorPrinter.h PanicHelper/PanicHelper.cpp PanicHelper/PanicHelper.h TableIO/TableIO.cpp TableIO/TableIO.h FileUtilities/FileUtilities.cpp FileUtilities/FileUtilities.h StringUtlities/StringUtilities.cpp StringUtlities/StringUtilities.h)
