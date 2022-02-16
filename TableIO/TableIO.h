#ifndef AUTH_TABLEIO_H
#define AUTH_TABLEIO_H
#include "string"

class TableIO {

public: static bool user_exists(const std::string& username);
public: static bool domain_exists(const std::string& domain);
public: static bool type_exists(const std::string& type);
public: static bool object_exists(const std::string& object);
public: static bool add_user(const std::string& username , const std::string& password);
public: static  bool authenticate_user(const std::string& username , const std::string& password);
public:static bool set_domain(const std::string& username , const std::string& domain);
public:static bool domain_info(const std::string& domain_name );
public: static  bool set_type (const std::string& object , const std::string& type  );
public: static  bool type_info (const std::string& type );
public: static  bool add_access(const std::string& operation , const std::string& domain_name ,const std::string& type );

public: static  bool  can_access(const std::string& operation ,const std::string& user, const std::string& object );

};


#endif //AUTH_TABLEIO_H
