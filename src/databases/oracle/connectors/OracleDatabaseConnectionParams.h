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
#include "../../../orm/utils/StringUtils.h"

namespace dbcrudgen {
    namespace db {
        namespace oracle {
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
                std::string connDesc;
                std::string databaseName;

                /**
                 * Get oracle connection string
                 * @param connDesc
                 * @return
                 */
                std::string getConnectStringTemplate(const std::string &connDescriptor = "sname") const {
                    if (connDescriptor == "sid") {
                        return getConnectStringSIDTemplate();
                    }
                    return getConnectStringSNameTemplate();
                }

                /**
                 * Get oracle connection string while using a service id
                 * @return
                 */
                static std::string getConnectStringSIDTemplate() {
                    return "//${HOST}:${PORT}:${SERVICE_ID}";
                }

                /**
                 * Get oracle connection string while using a service name
                 * @return
                 */
                static std::string getConnectStringSNameTemplate() {
                    return "//${HOST}:${PORT}/${SERVICE_NAME}";
                }

            public:
                OracleDatabaseConnectionParams(std::string &host, int &port, std::string &username,
                                               std::string &password, std::string &connDesc, std::string &databaseName)
                        : host(host), port(port), username(username), password(password), databaseName(databaseName),
                          connDesc(connDesc) {}

                explicit OracleDatabaseConnectionParams(std::string &connectString) : connectString(connectString) {}

                const std::string &getConnectString(const std::string &connDesc = "sname") {
                    std::string _connectionString = getConnectStringTemplate(connDesc);
                    StringUtils::replace(_connectionString, "${HOST}", host);
                    StringUtils::replace(_connectionString, "${PORT}", std::to_string(port));
                    StringUtils::replace(_connectionString, "${SERVICE_NAME}", databaseName);
                    connectString = std::move_if_noexcept(_connectionString);
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

                const std::string &getDatabaseName() const {
                    return databaseName;
                }

                const std::string &getConnDesc() const {
                    return connDesc;
                }
            };

        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLEDATABASECONNECTION_H
