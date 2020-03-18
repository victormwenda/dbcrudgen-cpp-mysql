#ifndef INFORMATION_SCHEMA_CPP_SLOW_LOG_H
#define INFORMATION_SCHEMA_CPP_SLOW_LOG_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class SlowLog {

        private:
            std::string startTime;
            std::string userHost;
            std::string queryTime;
            std::string lockTime;
            int rowsSent;
            int rowsExamined;
            std::string db;
            int lastInsertId;
            int insertId;
            int serverId;
            std::string sqlText;
            long threadId;

        public:

            static constexpr const char *TABLE_NAME = "slow_log";

            struct COLUMNS {
                struct START_TIME {
                    static constexpr const char *NAME = "start_time";
                    static const int INDEX = 1;
                };
                struct USER_HOST {
                    static constexpr const char *NAME = "user_host";
                    static const int INDEX = 2;
                };
                struct QUERY_TIME {
                    static constexpr const char *NAME = "query_time";
                    static const int INDEX = 3;
                };
                struct LOCK_TIME {
                    static constexpr const char *NAME = "lock_time";
                    static const int INDEX = 4;
                };
                struct ROWS_SENT {
                    static constexpr const char *NAME = "rows_sent";
                    static const int INDEX = 5;
                };
                struct ROWS_EXAMINED {
                    static constexpr const char *NAME = "rows_examined";
                    static const int INDEX = 6;
                };
                struct DB {
                    static constexpr const char *NAME = "db";
                    static const int INDEX = 7;
                };
                struct LAST_INSERT_ID {
                    static constexpr const char *NAME = "last_insert_id";
                    static const int INDEX = 8;
                };
                struct INSERT_ID {
                    static constexpr const char *NAME = "insert_id";
                    static const int INDEX = 9;
                };
                struct SERVER_ID {
                    static constexpr const char *NAME = "server_id";
                    static const int INDEX = 10;
                };
                struct SQL_TEXT {
                    static constexpr const char *NAME = "sql_text";
                    static const int INDEX = 11;
                };
                struct THREAD_ID {
                    static constexpr const char *NAME = "thread_id";
                    static const int INDEX = 12;
                };
            };

            SlowLog(std::string &startTime, std::string &userHost, std::string &queryTime, std::string &lockTime,
                    int rowsSent, int rowsExamined, std::string &db, int lastInsertId, int insertId, int serverId,
                    std::string &sqlText, long threadId)
                    : startTime{startTime}, userHost{userHost},
                      queryTime{queryTime}, lockTime{lockTime}, rowsSent{rowsSent},
                      rowsExamined{rowsExamined}, db{db},
                      lastInsertId{lastInsertId}, insertId{insertId},
                      serverId{serverId}, sqlText{sqlText}, threadId{threadId} {}

            // Get the value of startTime
            const std::string &getStartTime() const {
                return startTime;
            }

            // Get the value of userHost
            const std::string &getUserHost() const {
                return userHost;
            }

            // Get the value of queryTime
            const std::string &getQueryTime() const {
                return queryTime;
            }

            // Get the value of lockTime
            const std::string &getLockTime() const {
                return lockTime;
            }

            // Get the value of rowsSent
            int getRowsSent() const {
                return rowsSent;
            }

            // Get the value of rowsExamined
            int getRowsExamined() const {
                return rowsExamined;
            }

            // Get the value of db
            const std::string &getDb() const {
                return db;
            }

            // Get the value of lastInsertId
            int getLastInsertId() const {
                return lastInsertId;
            }

            // Get the value of insertId
            int getInsertId() const {
                return insertId;
            }

            // Get the value of serverId
            int getServerId() const {
                return serverId;
            }

            // Get the value of sqlText
            const std::string &getSqlText() const {
                return sqlText;
            }

            // Get the value of threadId
            long getThreadId() const {
                return threadId;
            }


            /**
            * Returns the table name 'slow_log';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_SLOW_LOG_H