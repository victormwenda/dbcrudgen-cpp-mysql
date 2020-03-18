#ifndef INFORMATION_SCHEMA_CPP_SLAVE_RELAY_LOG_INFO_H
#define INFORMATION_SCHEMA_CPP_SLAVE_RELAY_LOG_INFO_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class SlaveRelayLogInfo {

        private:
            int numberOfLines;
            std::string relayLogName;
            long relayLogPos;
            std::string masterLogName;
            long masterLogPos;
            int sqlDelay;
            int numberOfWorkers;
            int id;
            std::string channelName;

        public:

            static constexpr const char *TABLE_NAME = "slave_relay_log_info";

            struct COLUMNS {
                struct NUMBER_OF_LINES {
                    static constexpr const char *NAME = "Number_of_lines";
                    static const int INDEX = 1;
                };
                struct RELAY_LOG_NAME {
                    static constexpr const char *NAME = "Relay_log_name";
                    static const int INDEX = 2;
                };
                struct RELAY_LOG_POS {
                    static constexpr const char *NAME = "Relay_log_pos";
                    static const int INDEX = 3;
                };
                struct MASTER_LOG_NAME {
                    static constexpr const char *NAME = "Master_log_name";
                    static const int INDEX = 4;
                };
                struct MASTER_LOG_POS {
                    static constexpr const char *NAME = "Master_log_pos";
                    static const int INDEX = 5;
                };
                struct SQL_DELAY {
                    static constexpr const char *NAME = "Sql_delay";
                    static const int INDEX = 6;
                };
                struct NUMBER_OF_WORKERS {
                    static constexpr const char *NAME = "Number_of_workers";
                    static const int INDEX = 7;
                };
                struct ID {
                    static constexpr const char *NAME = "Id";
                    static const int INDEX = 8;
                };
                struct CHANNEL_NAME {
                    static constexpr const char *NAME = "Channel_name";
                    static const int INDEX = 9;
                };
            };

            SlaveRelayLogInfo(int numberOfLines, std::string &relayLogName, long relayLogPos,
                              std::string &masterLogName, long masterLogPos, int sqlDelay, int numberOfWorkers, int id,
                              std::string &channelName)
                    : numberOfLines{numberOfLines}, relayLogName{relayLogName}, relayLogPos{relayLogPos},
                      masterLogName{masterLogName}, masterLogPos{masterLogPos}, sqlDelay{sqlDelay},
                      numberOfWorkers{numberOfWorkers}, id{id}, channelName{channelName} {}

            // Get the value of numberOfLines
            int getNumberOfLines() const {
                return numberOfLines;
            }

            // Get the value of relayLogName
            const std::string &getRelayLogName() const {
                return relayLogName;
            }

            // Get the value of relayLogPos
            long getRelayLogPos() const {
                return relayLogPos;
            }

            // Get the value of masterLogName
            const std::string &getMasterLogName() const {
                return masterLogName;
            }

            // Get the value of masterLogPos
            long getMasterLogPos() const {
                return masterLogPos;
            }

            // Get the value of sqlDelay
            int getSqlDelay() const {
                return sqlDelay;
            }

            // Get the value of numberOfWorkers
            int getNumberOfWorkers() const {
                return numberOfWorkers;
            }

            // Get the value of id
            int getId() const {
                return id;
            }

            // Get the value of channelName
            const std::string &getChannelName() const {
                return channelName;
            }


            /**
            * Returns the table name 'slave_relay_log_info';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_SLAVE_RELAY_LOG_INFO_H