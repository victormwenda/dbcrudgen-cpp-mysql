#ifndef INFORMATION_SCHEMA_CPP_SERVERS_H
#define INFORMATION_SCHEMA_CPP_SERVERS_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class Servers {

        private:
            std::string serverName;
            std::string host;
            std::string db;
            std::string username;
            std::string password;
            int port;
            std::string socket;
            std::string wrapper;
            std::string owner;

        public:

            static constexpr const char *TABLE_NAME = "servers";

            struct COLUMNS {
                struct SERVER_NAME {
                    static constexpr const char *NAME = "Server_name";
                    static const int INDEX = 1;
                };
                struct HOST {
                    static constexpr const char *NAME = "Host";
                    static const int INDEX = 2;
                };
                struct DB {
                    static constexpr const char *NAME = "Db";
                    static const int INDEX = 3;
                };
                struct USERNAME {
                    static constexpr const char *NAME = "Username";
                    static const int INDEX = 4;
                };
                struct PASSWORD {
                    static constexpr const char *NAME = "Password";
                    static const int INDEX = 5;
                };
                struct PORT {
                    static constexpr const char *NAME = "Port";
                    static const int INDEX = 6;
                };
                struct SOCKET {
                    static constexpr const char *NAME = "Socket";
                    static const int INDEX = 7;
                };
                struct WRAPPER {
                    static constexpr const char *NAME = "Wrapper";
                    static const int INDEX = 8;
                };
                struct OWNER {
                    static constexpr const char *NAME = "Owner";
                    static const int INDEX = 9;
                };
            };

            Servers(std::string &serverName, std::string &host, std::string &db, std::string &username,
                    std::string &password, int port, std::string &socket, std::string &wrapper, std::string &owner)
                    : serverName{serverName}, host{host}, db{db}, username{username}, password{password}, port{port},
                      socket{socket}, wrapper{wrapper}, owner{owner} {}

            // Get the value of serverName
            const std::string &getServerName() const {
                return serverName;
            }

            // Get the value of host
            const std::string &getHost() const {
                return host;
            }

            // Get the value of db
            const std::string &getDb() const {
                return db;
            }

            // Get the value of username
            const std::string &getUsername() const {
                return username;
            }

            // Get the value of password
            const std::string &getPassword() const {
                return password;
            }

            // Get the value of port
            int getPort() const {
                return port;
            }

            // Get the value of socket
            const std::string &getSocket() const {
                return socket;
            }

            // Get the value of wrapper
            const std::string &getWrapper() const {
                return wrapper;
            }

            // Get the value of owner
            const std::string &getOwner() const {
                return owner;
            }


            /**
            * Returns the table name 'servers';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_SERVERS_H