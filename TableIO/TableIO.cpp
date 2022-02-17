#include <filesystem>
#include "TableIO.h"
#include "../PanicHelper/PanicHelper.h"
#include "iostream"
#include <string>
#include <cstring>
#include "../FileUtilities/FileUtilities.h"
#include "../StringUtlities/StringUtilities.h"

bool TableIO::user_exists(const std::string &username) {
    auto user_path= FileUtilities::build_user_file_path(username);
    return FileUtilities::file_exists(user_path);
}

bool TableIO::add_user(const std::string &username, const std::string &password) {
    if (username.empty()) {
        PanicHelper::panic_withcode(3, true);
        return false;
    }
    if (user_exists(username)) {
        PanicHelper::panic_withcode(2, true, username);
        return false;
    }
    auto user_path= FileUtilities::build_user_file_path(username);
    FileUtilities::append_to_file(user_path, password);
    PanicHelper::success();
    return true;
}

bool TableIO::authenticate_user(const std::string &username, const std::string &password) {
    if (username.empty()) {
        PanicHelper::panic_withcode(3, true);
        return false;
    }
    if (!user_exists(username)) {
        PanicHelper::panic_withcode(4, true, username);
        return false;
    }
    auto user_path= FileUtilities::build_user_file_path(username);
    auto line =  strtok(FileUtilities::read_first_line_of_file(user_path), "\n");
    if (  line == nullptr || (std::strcmp(line, password.c_str()) == 0) ) {
        PanicHelper::success();
        return true;
    }
    PanicHelper::panic_withcode(5, true);
    return true;
}

bool TableIO::set_domain(const std::string &username, const std::string &domain) {
    if (username.empty()) {
        PanicHelper::panic_withcode(3, true);
        return false;
    }
    if (!user_exists(username)) {
        PanicHelper::panic_withcode(4, true, username);
        return false;
    }
    if (domain.empty()) {
        PanicHelper::panic_withcode(6, true);
        return false;
    }
    auto domain_path= FileUtilities::build_domain_file_path(domain);
    if(!domain_exists(domain)){
        FileUtilities::append_to_file(domain_path , username );
        auto user_path= FileUtilities::build_user_file_path(username);
        auto domain_already_in_user =  FileUtilities::check_if_line_exists_special(user_path, username);
        if (! domain_already_in_user){
            FileUtilities::append_to_file(user_path, domain);
        }
        PanicHelper::success();
        return true;
    }
    auto user_path= FileUtilities::build_user_file_path(username);
    auto user_already_in_domain =  FileUtilities::check_if_line_exists(domain_path, username);
    auto domain_already_in_user =  FileUtilities::check_if_line_exists_special(user_path, domain);
    if (! domain_already_in_user){
        FileUtilities::append_to_file(user_path, domain);
    }
    if (!user_already_in_domain){
        FileUtilities::append_to_file(domain_path, username);
    }
    PanicHelper::success();
    return true;
}

bool TableIO::domain_exists(const std::string &domain) {
    std::stringstream path_string_builder;
    path_string_builder << "./Domains/" << domain;
    return FileUtilities::file_exists(path_string_builder.str());
}


bool TableIO::domain_info(const std::string &domain_name) {
    if (domain_name.empty()) {
        PanicHelper::panic_withcode(6, true);
        return false;
    }
    if (!domain_exists(domain_name)){
        return true;
    }
    auto domain_path = FileUtilities::build_domain_file_path(domain_name);
    auto domain_users = FileUtilities::read_all_text(domain_path);
    auto domain_users_cleaned = StringUtilities::remove_pattern_from_string(domain_users, '\n');
    if (!domain_users_cleaned.empty()){
        std::cout << domain_users;
    }
    return true;
}

bool TableIO::set_type(const std::string &object, const std::string &type) {
    if (object.empty()) {
        PanicHelper::panic_withcode(8, true);
        return false;
    }
    if (type.empty()) {
        PanicHelper::panic_withcode(9, true);
        return false;
    }
    auto type_path = FileUtilities::build_types_file_path(type);
    auto type_permission_path = FileUtilities::build_types_file_permission_path(type);
    auto object_path = FileUtilities::build_object_file_path(object);
    FileUtilities::append_to_file(type_path,object);
    FileUtilities::append_to_file(object_path,type);
    FileUtilities::create_empty_file(type_permission_path);
    PanicHelper::success();
    return true;
}

bool TableIO::type_exists(const std::string &type) {
   auto type_path = FileUtilities::build_types_file_path(type);
   return FileUtilities::file_exists(type_path);
}

bool TableIO::object_exists(const std::string &object) {
    auto object_path = FileUtilities::build_object_file_path(object);
    return FileUtilities::file_exists(object_path);
}

bool TableIO::type_info(const std::string &type) {
    if (type.empty()) {
        PanicHelper::panic_withcode(9, true);
        return false;
    }
    auto type_path = FileUtilities::build_types_file_path(type);
    auto type_objects = FileUtilities::read_all_text(type_path);
    auto type_users_cleaned = StringUtilities::remove_pattern_from_string(type_objects, '\n');
    if (!type_users_cleaned.empty()){
        std::cout << type_objects;
    }
    return true;
}

bool TableIO::add_access(const std::string &operation, const std::string &domain_name, const std::string &type) {
    if (operation.empty()) {
        PanicHelper::panic_withcode(10, true);
        return false;
    }
    if (type.empty()) {
        PanicHelper::panic_withcode(9, true);
        return false;
    }
    if (domain_name.empty()) {
        PanicHelper::panic_withcode(6, true);
        return false;
    }
    if (!domain_exists(domain_name)){
        auto domain_path =   FileUtilities::build_domain_file_path(domain_name);
        FileUtilities::create_empty_file(domain_path);
    }
    if (!type_exists(type)){
        std::stringstream operation_string_builder;
        operation_string_builder << operation << ":" << domain_name;
        auto type_permission_path = FileUtilities::build_types_file_permission_path(type);
        FileUtilities::append_to_file(type_permission_path , operation_string_builder.str());
        auto type_path = FileUtilities::build_types_file_path(type);
        FileUtilities::create_empty_file(type_path);
    }
    PanicHelper::success();
    return true;
}

bool TableIO::can_access(const std::string &operation, const std::string &user, const std::string &object) {
    if (operation.empty()) {
        PanicHelper::panic_withcode(10, true);
        return false;
    }
    if (user.empty()) {
        PanicHelper::panic_withcode(3, true);
        return false;
    }
    if (!user_exists(user)) {
        PanicHelper::panic_withcode(4, true);
        return false;
    }
    if (object.empty()) {
        PanicHelper::panic_withcode(8, true);
        return false;
    }
    auto user_path = FileUtilities::build_user_file_path(user);
    auto users_domains = FileUtilities::read_all_text(user_path);
    auto users_domains_cleaned = StringUtilities::remove_first_line(users_domains);
    std::vector<std::string> users_domains_cleaned_list ;
    StringUtilities::split(users_domains_cleaned, '\n' ,users_domains_cleaned_list );

    auto object_path = FileUtilities::build_object_file_path(object);
    auto objects_types = FileUtilities::read_all_text(object_path);
    std::vector<std::string> object_types_list ;
    StringUtilities::split(objects_types, '\n' ,object_types_list );

    for ( const std::string& type_name : object_types_list) {
        for (const std::string& domain_name : users_domains_cleaned_list) {
            std::stringstream permission_string_builder;
            permission_string_builder << operation << ":" << domain_name;
            auto type_path = FileUtilities::build_types_file_permission_path(type_name);
            auto can_access = FileUtilities::check_if_line_exists(type_path,permission_string_builder.str() );
            if (can_access) {
                PanicHelper::success();
                return true;
            }
        }
    }
    PanicHelper::panic_withcode(11, true);
    return  true;
}
