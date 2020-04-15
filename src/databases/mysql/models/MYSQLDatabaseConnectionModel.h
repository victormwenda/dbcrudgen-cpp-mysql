//
// Created by victor on 4/15/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLDATABASECONNECTIONMODEL_H
#define DBCRUDGEN_CPP_MYSQLDATABASECONNECTIONMODEL_H


#include <string>
#include <vector>
#include <map>
#include "../scaffolding/entities/Tables.h"
#include "../scaffolding/entities/Columns.h"

namespace dbcrudgen {
    namespace db {
        namespace mysql {

            class MYSQLDatabaseConnectionModel {

            private:
                std::string host;
                int port;
                std::string user;
                std::string password;
                std::string database;

            public:

                /**
                 * MYSQL Database Connection Model
                 * @param host
                 * @param port
                 * @param user
                 * @param password
                 * @param database
                 */
                MYSQLDatabaseConnectionModel(std::string &host, int port, std::string &user,
                                             std::string &password, std::string &database)
                        : host(host), port(port), user(user), password(password), database(database) {}

                const std::string &getHost() const {
                    return host;
                }

                void setHost(const std::string &host) {
                    MYSQLDatabaseConnectionModel::host = host;
                }

                int getPort() const {
                    return port;
                }

                void setPort(int port) {
                    MYSQLDatabaseConnectionModel::port = port;
                }

                const std::string &getUser() const {
                    return user;
                }

                void setUser(const std::string &user) {
                    MYSQLDatabaseConnectionModel::user = user;
                }

                const std::string &getPassword() const {
                    return password;
                }

                void setPassword(const std::string &password) {
                    MYSQLDatabaseConnectionModel::password = password;
                }

                const std::string &getDatabase() const {
                    return database;
                }

                void setDatabase(const std::string &database) {
                    MYSQLDatabaseConnectionModel::database = database;
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MYSQLDATABASECONNECTIONMODEL_H
