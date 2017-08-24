/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/13/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_MYSQLDATABASECONNECTION_H
#define DBCRUDGEN_CPP_MYSQLDATABASECONNECTION_H

#include <iostream>

class MYSQLDatabaseConnectionParams {

private:
    std::string host;
    std::string username;
    std::string password;
    std::string schemas;
public:
    MYSQLDatabaseConnectionParams(const std::string &host, const std::string &username,
                                  const std::string &password, const std::string &schemas) : host(
            host), username(username), password(password), schemas(schemas) {}

    const std::string &getHost() const {
        return host;
    }

    const std::string &getUsername() const {
        return username;
    }

    const std::string &getPassword() const {
        return password;
    }

    const std::string &getSchemas() const { return schemas; }
};


#endif //DBCRUDGEN_CPP_MYSQLDATABASECONNECTION_H
