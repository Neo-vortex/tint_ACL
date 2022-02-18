#include <filesystem>
#include "FileUtilities.h"
#include "iostream"
#include <fstream>
#include <cstring>

bool FileUtilities::create_empty_file(const std::string& filepath) {
    append_to_file(filepath,"");
    return  true;
}

bool FileUtilities::append_to_file(const std::string& filepath, const std::string& target) {
    std::ofstream outfile;
    outfile.open(filepath, std::ios_base::app);
    if (!target.empty()) outfile << target << std::endl;
    outfile.close();
    return true;
}

bool FileUtilities::file_exists(const std::string& filepath) {
    return std::filesystem::exists(filepath);
}


char* FileUtilities::read_first_line_of_file(const std::string &filename) {
    FILE *fp = fopen(filename.c_str(), "r");
    char *line = nullptr;
    size_t len = 0;
    getline(&line, &len, fp);
    strtok(line, "\n");
    fclose(fp);
    return line;
}

std::string FileUtilities::read_all_text(const std::string &filename) {
    std::ifstream user_file(filename);
    std::stringstream buffer;
    buffer << user_file.rdbuf();
    return  buffer.str();
}

std::string FileUtilities::build_user_file_path(const std::string &username) {
    std::stringstream path_string_builder;
    path_string_builder << "./Users/" << username;
    return path_string_builder.str();
}

std::string FileUtilities::build_domain_file_path(const std::string &domain) {
    std::stringstream path_string_builder;
    path_string_builder << "./Domains/" << domain;
    return path_string_builder.str();
}

std::string FileUtilities::build_object_file_path(const std::string &object) {
    std::stringstream path_string_builder;
    path_string_builder << "./Objects/" << object;
    return path_string_builder.str();
}

std::string FileUtilities::build_types_file_path(const std::string &type) {
    std::stringstream path_string_builder;
    path_string_builder << "./Types/" << type;
    return path_string_builder.str();
}

bool FileUtilities::check_if_line_exists(const std::string &filepath, const std::string& target) {
    char const* const fileName = filepath.c_str();
    FILE* file = fopen(fileName, "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        strtok(line, "\n");
        if (std::strcmp(line, target.c_str()) ==0) {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

bool FileUtilities::check_if_line_exists_special(const std::string &filepath, const std::string &target) {
    char const* const fileName = filepath.c_str();
    FILE* file = fopen(fileName, "r");
    char line[256];
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file)) {
        strtok(line, "\n");
        if (std::strcmp(line, target.c_str()) ==0) {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

std::string FileUtilities::build_types_file_permission_path(const std::string &type) {
    std::stringstream path_string_builder;
    path_string_builder << "./Types/" << type << "_permissions";
    return path_string_builder.str();
}
