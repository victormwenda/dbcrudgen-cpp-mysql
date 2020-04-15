//
// Created by victor on 4/15/20.
//

#ifndef DBCRUDGEN_CPP_CONNECTION_H
#define DBCRUDGEN_CPP_CONNECTION_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace generic {

            class Connection {

            private:
                std::string host;
                int port;
                std::string user;
                std::string password;
                std::string database;

            public:

                /**
                 * Database Connection
                 * @param host
                 * @param port
                 * @param user
                 * @param password
                 * @param database
                 */
                Connection(std::string &host, int port, std::string &user, std::string &password, std::string &database)
                        : host(host), port(port), user(user), password(password), database(database) {}

                const std::string &getHost() const {
                    return host;
                }

                void setHost(const std::string &host) {
                    Connection::host = host;
                }

                int getPort() const {
                    return port;
                }

                void setPort(int port) {
                    Connection::port = port;
                }

                const std::string &getUser() const {
                    return user;
                }

                void setUser(const std::string &user) {
                    Connection::user = user;
                }

                const std::string &getPassword() const {
                    return password;
                }

                void setPassword(const std::string &password) {
                    Connection::password = password;
                }

                const std::string &getDatabase() const {
                    return database;
                }

                void setDatabase(const std::string &database) {
                    Connection::database = database;
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_CONNECTION_H
