#include "iostream"
#ifndef AUTH_FILEUTILITIES_H
#define AUTH_FILEUTILITIES_H


class FileUtilities {
public: static  bool  create_empty_file(const std::string& filepath);
public: static  bool append_to_file(const std::string& filepath, const std::string& target);
public: static  bool file_exists(const std::string& filepath);
public: static  char*  read_first_line_of_file(const std::string& filename);
public: static  std::string  read_all_text(const std::string& filename);
public: static  std::string build_user_file_path(const std::string& username);
public: static  std::string build_domain_file_path(const std::string& domain);
public: static  std::string build_object_file_path(const std::string& object);
public: static  std::string build_types_file_path(const std::string&  type);
public: static  std::string build_types_file_permission_path(const std::string&  type);
public: static  bool check_if_line_exists (const std::string&  filepath , const std::string& target);
public: static  bool check_if_line_exists_special (const std::string&  filepath , const std::string& target);
};


#endif //AUTH_FILEUTILITIES_H
