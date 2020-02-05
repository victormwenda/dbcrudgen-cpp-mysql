/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/13/17.
* C/C++ Laptop
*/

#ifndef DBCRUDGEN_CPP_DATABASECONNECTION_H
#define DBCRUDGEN_CPP_DATABASECONNECTION_H

#include <iostream>

class DatabaseConnection {
    std::string host;
    std::string username;
    std::string password;
public:
    DatabaseConnection(const std::string &host, const std::string &username, const std::string &password)
            : host(host), username(username), password(password) {}

    /**
     * Returns the database host
     * This can be the server the database is hosted,
     * the file path to the database or the database connection string
     * @return
     */
    const std::string &getHost() const {
        return host;
    }

    void setHost(const std::string &host) {
        DatabaseConnection::host = host;
    }

    const std::string &getUsername() const {
        return username;
    }

    void setUsername(const std::string &username) {
        DatabaseConnection::username = username;
    }

    const std::string &getPassword() const {
        return password;
    }

    void setPassword(const std::string &password) {
        DatabaseConnection::password = password;
    }
};


#endif //DBCRUDGEN_CPP_DATABASECONNECTION_H
