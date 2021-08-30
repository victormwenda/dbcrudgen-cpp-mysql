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
#include "../../../orm/templates/mssql/MSSQLStrTemplates.h"
#include "../../../orm/utils/StringUtils.h"

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            /**
            * MSSQLDatabaseConnection
            * */
            class MSSQLDbConnParams {

            private:
                std::string host;
                int port;
                std::string database;
                std::string user;
                std::string password;
            public:


                /**
                 * Connect to a Microsoft SQL Server database
                 * @param host
                 * @param port
                 * @param user
                 * @param password
                 */
                MSSQLDbConnParams(std::string &host, int port, std::string& database, std::string &user,
                                  std::string &password)
                        : host(host), port(port), database(database), user(user), password(password) {
                }

                std::string
                getConnStr() const {
                    std::string connStrTpl = dbcrudgen::orm::mssql::MSSQLStrTemplates::CONN_STR::TEMPLATE;

                    StringUtils::replace(connStrTpl, "${HOST}", getHost());
                    StringUtils::replace(connStrTpl, "${PORT}", std::to_string(port));
                    StringUtils::replace(connStrTpl, "${DATABASE}", getDatabase());
                    StringUtils::replace(connStrTpl, "${USER}", getUser());
                    StringUtils::replace(connStrTpl, "${PASSWORD}", getPassword());

                    return connStrTpl;
                }

                std::string getHost() const {
                    return host;
                }

                int getPort() const {
                    return port;
                }

                std::string getDatabase() const {
                    return database;
                }

                std::string getUser() const {
                    return user;
                }

                std::string getPassword() const {
                    return password;
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLDATABASECONNECTION_H
