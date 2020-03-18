//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_PROCESSLIST_H
#define DBCRUDGEN_CPP_PROCESSLIST_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class ProcessList {

        private:
            long id;
            std::string user;
            std::string host;
            std::string db;
            std::string command;
            int time;
            std::string state;
            std::string info;

        public:

            static constexpr const char *TABLE_NAME = "PROCESSLIST";

            struct COLUMNS {
                struct ID {
                    static constexpr const char *NAME = "ID";
                    static const int INDEX = 1;
                };
                struct USER {
                    static constexpr const char *NAME = "USER";
                    static const int INDEX = 2;
                };
                struct HOST {
                    static constexpr const char *NAME = "HOST";
                    static const int INDEX = 3;
                };
                struct DB {
                    static constexpr const char *NAME = "DB";
                    static const int INDEX = 4;
                };
                struct COMMAND {
                    static constexpr const char *NAME = "COMMAND";
                    static const int INDEX = 5;
                };
                struct TIME {
                    static constexpr const char *NAME = "TIME";
                    static const int INDEX = 6;
                };
                struct STATE {
                    static constexpr const char *NAME = "STATE";
                    static const int INDEX = 7;
                };
                struct INFO {
                    static constexpr const char *NAME = "INFO";
                    static const int INDEX = 8;
                };
            };

            ProcessList(long id, std::string &user, std::string &host, std::string &db, std::string &command, int time,
                        std::string &state, std::string &info) : id{id}, user{user}, host{host}, db{db},
                                                                 command{command}, time{time}, state{state},
                                                                 info{info} {}

            // Get the value of id
            long getId() const {
                return id;
            }

            // Get the value of user
            const std::string &getUser() const {
                return user;
            }

            // Get the value of host
            const std::string &getHost() const {
                return host;
            }

            // Get the value of db
            const std::string &getDb() const {
                return db;
            }

            // Get the value of command
            const std::string &getCommand() const {
                return command;
            }

            // Get the value of time
            int getTime() const {
                return time;
            }

            // Get the value of state
            const std::string &getState() const {
                return state;
            }

            // Get the value of info
            const std::string &getInfo() const {
                return info;
            }

            /**
            * Returns the table name 'PROCESSLIST';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_PROCESSLIST_H
