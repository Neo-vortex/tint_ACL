CXX = g++
CXXFLAGS = -Wall -Ofast
STD = -std=c++17
final:
	$(CXX) $(CXXFLAGS) $(STD) main.cpp ./DirctoryStructureHelper/DirectoryStructureHelper.cpp ./ErrorPrinter/ErrorPrinter.cpp ./FileUtilities/FileUtilities.cpp ./PanicHelper/PanicHelper.cpp ./StringUtlities/StringUtilities.cpp ./TableIO/TableIO.cpp -o ./auth
	strip ./auth
