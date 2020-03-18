#ifndef INFORMATION_SCHEMA_CPP_EVENT_H
#define INFORMATION_SCHEMA_CPP_EVENT_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class Event {

        private:
            std::string db;
            std::string name;
            std::string body;
            std::string definer;
            std::string executeAt;
            int intervalValue;
            std::string intervalField;
            std::string created;
            std::string modified;
            std::string lastExecuted;
            std::string starts;
            std::string ends;
            std::string status;
            std::string onCompletion;
            std::string sqlMode;
            std::string comment;
            int originator;
            std::string timeZone;
            std::string characterSetClient;
            std::string collationConnection;
            std::string dbCollation;
            std::string bodyUtf8;

        public:

            static constexpr const char *TABLE_NAME = "event";

            struct COLUMNS {
                struct DB {
                    static constexpr const char *NAME = "db";
                    static const int INDEX = 1;
                };
                struct NAME {
                    static constexpr const char *_NAME = "name";
                    static const int INDEX = 2;
                };
                struct BODY {
                    static constexpr const char *NAME = "body";
                    static const int INDEX = 3;
                };
                struct DEFINER {
                    static constexpr const char *NAME = "definer";
                    static const int INDEX = 4;
                };
                struct EXECUTE_AT {
                    static constexpr const char *NAME = "execute_at";
                    static const int INDEX = 5;
                };
                struct INTERVAL_VALUE {
                    static constexpr const char *NAME = "interval_value";
                    static const int INDEX = 6;
                };
                struct INTERVAL_FIELD {
                    static constexpr const char *NAME = "interval_field";
                    static const int INDEX = 7;
                };
                struct CREATED {
                    static constexpr const char *NAME = "created";
                    static const int INDEX = 8;
                };
                struct MODIFIED {
                    static constexpr const char *NAME = "modified";
                    static const int INDEX = 9;
                };
                struct LAST_EXECUTED {
                    static constexpr const char *NAME = "last_executed";
                    static const int INDEX = 10;
                };
                struct STARTS {
                    static constexpr const char *NAME = "starts";
                    static const int INDEX = 11;
                };
                struct ENDS {
                    static constexpr const char *NAME = "ends";
                    static const int INDEX = 12;
                };
                struct STATUS {
                    static constexpr const char *NAME = "status";
                    static const int INDEX = 13;
                };
                struct ON_COMPLETION {
                    static constexpr const char *NAME = "on_completion";
                    static const int INDEX = 14;
                };
                struct SQL_MODE {
                    static constexpr const char *NAME = "sql_mode";
                    static const int INDEX = 15;
                };
                struct COMMENT {
                    static constexpr const char *NAME = "comment";
                    static const int INDEX = 16;
                };
                struct ORIGINATOR {
                    static constexpr const char *NAME = "originator";
                    static const int INDEX = 17;
                };
                struct TIME_ZONE {
                    static constexpr const char *NAME = "time_zone";
                    static const int INDEX = 18;
                };
                struct CHARACTER_SET_CLIENT {
                    static constexpr const char *NAME = "character_set_client";
                    static const int INDEX = 19;
                };
                struct COLLATION_CONNECTION {
                    static constexpr const char *NAME = "collation_connection";
                    static const int INDEX = 20;
                };
                struct DB_COLLATION {
                    static constexpr const char *NAME = "db_collation";
                    static const int INDEX = 21;
                };
                struct BODY_UTF8 {
                    static constexpr const char *NAME = "body_utf8";
                    static const int INDEX = 22;
                };
            };

            Event(std::string &db, std::string &name, std::string &body, std::string &definer, std::string &executeAt,
                  int intervalValue, std::string &intervalField, std::string &created, std::string &modified,
                  std::string &lastExecuted, std::string &starts, std::string &ends, std::string &status,
                  std::string &onCompletion, std::string &sqlMode, std::string &comment, int originator,
                  std::string &timeZone, std::string &characterSetClient, std::string &collationConnection,
                  std::string &dbCollation, std::string &bodyUtf8)
                    : db{db}, name{name}, body{body}, definer{definer}, executeAt{executeAt},
                      intervalValue{intervalValue}, intervalField{intervalField}, created{created}, modified{modified},
                      lastExecuted{lastExecuted}, starts{starts}, ends{ends}, status{status},
                      onCompletion{onCompletion}, sqlMode{sqlMode}, comment{comment}, originator{originator},
                      timeZone{timeZone}, characterSetClient{characterSetClient},
                      collationConnection{collationConnection}, dbCollation{dbCollation}, bodyUtf8{bodyUtf8} {}

            // Get the value of db
            const std::string &getDb() const {
                return db;
            }

            // Get the value of name
            const std::string &getName() const {
                return name;
            }

            // Get the value of body
            const std::string &getBody() const {
                return body;
            }

            // Get the value of definer
            const std::string &getDefiner() const {
                return definer;
            }

            // Get the value of executeAt
            const std::string &getExecuteAt() const {
                return executeAt;
            }

            // Get the value of intervalValue
            int getIntervalValue() const {
                return intervalValue;
            }

            // Get the value of intervalField
            const std::string &getIntervalField() const {
                return intervalField;
            }

            // Get the value of created
            const std::string &getCreated() const {
                return created;
            }

            // Get the value of modified
            const std::string &getModified() const {
                return modified;
            }

            // Get the value of lastExecuted
            const std::string &getLastExecuted() const {
                return lastExecuted;
            }

            // Get the value of starts
            const std::string &getStarts() const {
                return starts;
            }

            // Get the value of ends
            const std::string &getEnds() const {
                return ends;
            }

            // Get the value of status
            const std::string &getStatus() const {
                return status;
            }

            // Get the value of onCompletion
            const std::string &getOnCompletion() const {
                return onCompletion;
            }

            // Get the value of sqlMode
            const std::string &getSqlMode() const {
                return sqlMode;
            }

            // Get the value of comment
            const std::string &getComment() const {
                return comment;
            }

            // Get the value of originator
            int getOriginator() const {
                return originator;
            }

            // Get the value of timeZone
            const std::string &getTimeZone() const {
                return timeZone;
            }

            // Get the value of characterSetClient
            const std::string &getCharacterSetClient() const {
                return characterSetClient;
            }

            // Get the value of collationConnection
            const std::string &getCollationConnection() const {
                return collationConnection;
            }

            // Get the value of dbCollation
            const std::string &getDbCollation() const {
                return dbCollation;
            }

            // Get the value of bodyUtf8
            const std::string &getBodyUtf8() const {
                return bodyUtf8;
            }


            /**
            * Returns the table name 'event';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_EVENT_H