/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/13/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_ORACLEDATABASECONNECTION_H
#define DBCRUDGEN_CPP_ORACLEDATABASECONNECTION_H

#include <iostream>

/**
* OracleDatabaseConnection
* */
class OracleDatabaseConnectionParams {

private:

    std::string connectString;

    std::string host;
    int port;
    std::string username;
    std::string password;
    std::string serviceName;

    std::string getConnectStringTemplate() const {
        return "${USERNAME}/${PASSWORD}@[//]${HOST}[:${PORT}][/${SERVICE_NAME}]";
    }

public:
    OracleDatabaseConnectionParams(const std::string &host, const int &port, const std::string &username,
                                   const std::string &password, const std::string &serviceName)
            : host(host), port(port),
              username(username),
              password(password),
              serviceName(serviceName) {}

    explicit OracleDatabaseConnectionParams(std::string &connectString) : connectString(connectString) {}

    const std::string &getConnectString() const {
        return connectString;
    }

    const std::string &getHost() const {
        return host;
    }

    const int &getPort() const {
        return port;
    }

    const std::string &getUsername() const {
        return username;
    }

    const std::string &getPassword() const {
        return password;
    }

    const std::string &getServiceName() const {
        return serviceName;
    }
};


#endif //DBCRUDGEN_CPP_ORACLEDATABASECONNECTION_H
