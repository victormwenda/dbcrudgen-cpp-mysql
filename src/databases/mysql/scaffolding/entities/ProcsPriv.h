#ifndef INFORMATION_SCHEMA_CPP_PROCS_PRIV_H
#define INFORMATION_SCHEMA_CPP_PROCS_PRIV_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class ProcsPriv {

        private:
            std::string host;
            std::string db;
            std::string user;
            std::string routineName;
            std::string routineType;
            std::string grantor;
            std::string procPriv;
            std::string timestamp;

        public:

            static constexpr const char *TABLE_NAME = "procs_priv";

            struct COLUMNS {
                struct HOST {
                    static constexpr const char *NAME = "Host";
                    static const int INDEX = 1;
                };
                struct DB {
                    static constexpr const char *NAME = "Db";
                    static const int INDEX = 2;
                };
                struct USER {
                    static constexpr const char *NAME = "User";
                    static const int INDEX = 3;
                };
                struct ROUTINE_NAME {
                    static constexpr const char *NAME = "Routine_name";
                    static const int INDEX = 4;
                };
                struct ROUTINE_TYPE {
                    static constexpr const char *NAME = "Routine_type";
                    static const int INDEX = 5;
                };
                struct GRANTOR {
                    static constexpr const char *NAME = "Grantor";
                    static const int INDEX = 6;
                };
                struct PROC_PRIV {
                    static constexpr const char *NAME = "Proc_priv";
                    static const int INDEX = 7;
                };
                struct TIMESTAMP {
                    static constexpr const char *NAME = "Timestamp";
                    static const int INDEX = 8;
                };
            };

            ProcsPriv(std::string &host, std::string &db, std::string &user, std::string &routineName,
                      std::string &routineType, std::string &grantor, std::string &procPriv, std::string &timestamp)
                    : host{host}, db{db}, user{user}, routineName{routineName}, routineType{routineType},
                      grantor{grantor}, procPriv{procPriv}, timestamp{timestamp} {}

            // Get the value of host
            const std::string &getHost() const {
                return host;
            }

            // Get the value of db
            const std::string &getDb() const {
                return db;
            }

            // Get the value of user
            const std::string &getUser() const {
                return user;
            }

            // Get the value of routineName
            const std::string &getRoutineName() const {
                return routineName;
            }

            // Get the value of routineType
            const std::string &getRoutineType() const {
                return routineType;
            }

            // Get the value of grantor
            const std::string &getGrantor() const {
                return grantor;
            }

            // Get the value of procPriv
            const std::string &getProcPriv() const {
                return procPriv;
            }

            // Get the value of timestamp
            const std::string &getTimestamp() const {
                return timestamp;
            }


            /**
            * Returns the table name 'procs_priv';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_PROCS_PRIV_H