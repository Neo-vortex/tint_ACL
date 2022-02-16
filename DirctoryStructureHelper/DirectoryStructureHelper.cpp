#include "DirectoryStructureHelper.h"
#include <filesystem>

bool DirectoryStructureHelper::InsureCreated() {
    int needed_dir_count = 4;
    bool final_result = true;
    bool result_per_operation[needed_dir_count] ;
    result_per_operation[0]=
            std::filesystem::is_directory("./Domains") || std::filesystem::create_directories("./Domains");
    result_per_operation[1]=
            std::filesystem::is_directory("./Users") || std::filesystem::create_directories("./Users");
    result_per_operation[2]=
            std::filesystem::is_directory("./Objects") || std::filesystem::create_directories("./Objects");
    result_per_operation[3]=
            std::filesystem::is_directory("./Types") || std::filesystem::create_directories("./Types");
    for (int i = 0; i < needed_dir_count; ++i) {
        final_result &=  result_per_operation[i];
    }
    return final_result;
}
