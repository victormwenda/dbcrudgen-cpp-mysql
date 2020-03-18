#ifndef INFORMATION_SCHEMA_CPP_GENERAL_LOG_H
#define INFORMATION_SCHEMA_CPP_GENERAL_LOG_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class GeneralLog {

        private:
            std::string eventTime;
            std::string userHost;
            long threadId;
            int serverId;
            std::string commandType;
            std::string argument;

        public:

            static constexpr const char *TABLE_NAME = "general_log";

            struct COLUMNS {
                struct EVENT_TIME {
                    static constexpr const char *NAME = "event_time";
                    static const int INDEX = 1;
                };
                struct USER_HOST {
                    static constexpr const char *NAME = "user_host";
                    static const int INDEX = 2;
                };
                struct THREAD_ID {
                    static constexpr const char *NAME = "thread_id";
                    static const int INDEX = 3;
                };
                struct SERVER_ID {
                    static constexpr const char *NAME = "server_id";
                    static const int INDEX = 4;
                };
                struct COMMAND_TYPE {
                    static constexpr const char *NAME = "command_type";
                    static const int INDEX = 5;
                };
                struct ARGUMENT {
                    static constexpr const char *NAME = "argument";
                    static const int INDEX = 6;
                };
            };

            GeneralLog(std::string &eventTime, std::string &userHost, long threadId, int serverId,
                       std::string &commandType, std::string &argument) : eventTime{eventTime}, userHost{userHost},
                                                                          threadId{threadId}, serverId{serverId},
                                                                          commandType{commandType},
                                                                          argument{argument} {}

            // Get the value of eventTime
            const std::string &getEventTime() const {
                return eventTime;
            }

            // Get the value of userHost
            const std::string &getUserHost() const {
                return userHost;
            }

            // Get the value of threadId
            long getThreadId() const {
                return threadId;
            }

            // Get the value of serverId
            int getServerId() const {
                return serverId;
            }

            // Get the value of commandType
            const std::string &getCommandType() const {
                return commandType;
            }

            // Get the value of argument
            const std::string &getArgument() const {
                return argument;
            }


            /**
            * Returns the table name 'general_log';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_GENERAL_LOG_H