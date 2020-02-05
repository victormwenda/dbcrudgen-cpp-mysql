/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/13/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_MSSQLDATABASECONNECTION_H
#define DBCRUDGEN_CPP_MSSQLDATABASECONNECTION_H

#include <iostream>
#include <sstream>
#include <memory.h>

/**
* MSSQLDatabaseConnection
* */
class MSSQLDatabaseConnectionParams {

private:
    std::string host;
    std::string port;
    std::string serverName;
    std::string username;
    std::string password;
public:
    /**
     * Connect to a Microsoft SQL Server database
     * @param serverName (host:port)
     * @param username
     * @param password
     */
    MSSQLDatabaseConnectionParams(std::string serverName, std::string username,
                            std::string password) :
            serverName(serverName), username(username), password(password) {
    }


    /**
     * Connect to a Microsoft SQL Server database
     * @param host
     * @param port
     * @param username
     * @param password
     */
    MSSQLDatabaseConnectionParams(std::string host, std::string port, std::string username,
                            std::string password)
            : host(host), port(port), username(username), password(password) {
        serverName = createServerName(host, port);
    }

    std::string
    createServerName(std::string host, std::string port) {
        std::stringstream buffer;
        buffer << host << ":" << port;
        return buffer.str();
    }

    std::string getHost() {
        return host;
    }

    std::string getPort() {
        return port;
    }

    std::string getServerName() {
        return serverName;
    }

    std::string getUsername() {
        return username;
    }

    std::string getPassword() {
        return password;
    }
};


#endif //DBCRUDGEN_CPP_MSSQLDATABASECONNECTION_H
