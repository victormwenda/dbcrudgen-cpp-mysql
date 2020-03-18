//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_EVENTS_H
#define DBCRUDGEN_CPP_EVENTS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class Events {

        private:
            std::string eventCatalog;
            std::string eventSchema;
            std::string eventName;
            std::string definer;
            std::string timeZone;
            std::string eventBody;
            std::string eventDefinition;
            std::string eventType;
            std::string executeAt;
            std::string intervalValue;
            std::string intervalField;
            std::string sqlMode;
            std::string starts;
            std::string ends;
            std::string status;
            std::string onCompletion;
            std::string created;
            std::string lastAltered;
            std::string lastExecuted;
            std::string eventComment;
            long originator;
            std::string characterSetClient;
            std::string collationConnection;
            std::string databaseCollation;

        public:

            static constexpr const char *TABLE_NAME = "EVENTS";

            struct COLUMNS {
                struct EVENT_CATALOG {
                    static constexpr const char *NAME = "EVENT_CATALOG";
                    static const int INDEX = 1;
                };
                struct EVENT_SCHEMA {
                    static constexpr const char *NAME = "EVENT_SCHEMA";
                    static const int INDEX = 2;
                };
                struct EVENT_NAME {
                    static constexpr const char *NAME = "EVENT_NAME";
                    static const int INDEX = 3;
                };
                struct DEFINER {
                    static constexpr const char *NAME = "DEFINER";
                    static const int INDEX = 4;
                };
                struct TIME_ZONE {
                    static constexpr const char *NAME = "TIME_ZONE";
                    static const int INDEX = 5;
                };
                struct EVENT_BODY {
                    static constexpr const char *NAME = "EVENT_BODY";
                    static const int INDEX = 6;
                };
                struct EVENT_DEFINITION {
                    static constexpr const char *NAME = "EVENT_DEFINITION";
                    static const int INDEX = 7;
                };
                struct EVENT_TYPE {
                    static constexpr const char *NAME = "EVENT_TYPE";
                    static const int INDEX = 8;
                };
                struct EXECUTE_AT {
                    static constexpr const char *NAME = "EXECUTE_AT";
                    static const int INDEX = 9;
                };
                struct INTERVAL_VALUE {
                    static constexpr const char *NAME = "INTERVAL_VALUE";
                    static const int INDEX = 10;
                };
                struct INTERVAL_FIELD {
                    static constexpr const char *NAME = "INTERVAL_FIELD";
                    static const int INDEX = 11;
                };
                struct SQL_MODE {
                    static constexpr const char *NAME = "SQL_MODE";
                    static const int INDEX = 12;
                };
                struct STARTS {
                    static constexpr const char *NAME = "STARTS";
                    static const int INDEX = 13;
                };
                struct ENDS {
                    static constexpr const char *NAME = "ENDS";
                    static const int INDEX = 14;
                };
                struct STATUS {
                    static constexpr const char *NAME = "STATUS";
                    static const int INDEX = 15;
                };
                struct ON_COMPLETION {
                    static constexpr const char *NAME = "ON_COMPLETION";
                    static const int INDEX = 16;
                };
                struct CREATED {
                    static constexpr const char *NAME = "CREATED";
                    static const int INDEX = 17;
                };
                struct LAST_ALTERED {
                    static constexpr const char *NAME = "LAST_ALTERED";
                    static const int INDEX = 18;
                };
                struct LAST_EXECUTED {
                    static constexpr const char *NAME = "LAST_EXECUTED";
                    static const int INDEX = 19;
                };
                struct EVENT_COMMENT {
                    static constexpr const char *NAME = "EVENT_COMMENT";
                    static const int INDEX = 20;
                };
                struct ORIGINATOR {
                    static constexpr const char *NAME = "ORIGINATOR";
                    static const int INDEX = 21;
                };
                struct CHARACTER_SET_CLIENT {
                    static constexpr const char *NAME = "CHARACTER_SET_CLIENT";
                    static const int INDEX = 22;
                };
                struct COLLATION_CONNECTION {
                    static constexpr const char *NAME = "COLLATION_CONNECTION";
                    static const int INDEX = 23;
                };
                struct DATABASE_COLLATION {
                    static constexpr const char *NAME = "DATABASE_COLLATION";
                    static const int INDEX = 24;
                };
            };

            Events(std::string &eventCatalog, std::string &eventSchema, std::string &eventName, std::string &definer,
                   std::string &timeZone, std::string &eventBody, std::string &eventDefinition, std::string &eventType,
                   std::string &executeAt, std::string &intervalValue, std::string &intervalField, std::string &sqlMode,
                   std::string &starts, std::string &ends, std::string &status, std::string &onCompletion,
                   std::string &created, std::string &lastAltered, std::string &lastExecuted, std::string &eventComment,
                   long originator, std::string &characterSetClient, std::string &collationConnection,
                   std::string &databaseCollation) : eventCatalog{eventCatalog}, eventSchema{eventSchema},
                                                     eventName{eventName}, definer{definer}, timeZone{timeZone},
                                                     eventBody{eventBody}, eventDefinition{eventDefinition},
                                                     eventType{eventType}, executeAt{executeAt},
                                                     intervalValue{intervalValue}, intervalField{intervalField},
                                                     sqlMode{sqlMode}, starts{starts}, ends{ends}, status{status},
                                                     onCompletion{onCompletion}, created{created},
                                                     lastAltered{lastAltered}, lastExecuted{lastExecuted},
                                                     eventComment{eventComment}, originator{originator},
                                                     characterSetClient{characterSetClient},
                                                     collationConnection{collationConnection},
                                                     databaseCollation{databaseCollation} {}

            // Get the value of eventCatalog
            const std::string &getEventCatalog() const {
                return eventCatalog;
            }

            // Get the value of eventSchema
            const std::string &getEventSchema() const {
                return eventSchema;
            }

            // Get the value of eventName
            const std::string &getEventName() const {
                return eventName;
            }

            // Get the value of definer
            const std::string &getDefiner() const {
                return definer;
            }

            // Get the value of timeZone
            const std::string &getTimeZone() const {
                return timeZone;
            }

            // Get the value of eventBody
            const std::string &getEventBody() const {
                return eventBody;
            }

            // Get the value of eventDefinition
            const std::string &getEventDefinition() const {
                return eventDefinition;
            }

            // Get the value of eventType
            const std::string &getEventType() const {
                return eventType;
            }

            // Get the value of executeAt
            const std::string &getExecuteAt() const {
                return executeAt;
            }

            // Get the value of intervalValue
            const std::string &getIntervalValue() const {
                return intervalValue;
            }

            // Get the value of intervalField
            const std::string &getIntervalField() const {
                return intervalField;
            }

            // Get the value of sqlMode
            const std::string &getSqlMode() const {
                return sqlMode;
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

            // Get the value of created
            const std::string &getCreated() const {
                return created;
            }

            // Get the value of lastAltered
            const std::string &getLastAltered() const {
                return lastAltered;
            }

            // Get the value of lastExecuted
            const std::string &getLastExecuted() const {
                return lastExecuted;
            }

            // Get the value of eventComment
            const std::string &getEventComment() const {
                return eventComment;
            }

            // Get the value of originator
            long getOriginator() const {
                return originator;
            }

            // Get the value of characterSetClient
            const std::string &getCharacterSetClient() const {
                return characterSetClient;
            }

            // Get the value of collationConnection
            const std::string &getCollationConnection() const {
                return collationConnection;
            }

            // Get the value of databaseCollation
            const std::string &getDatabaseCollation() const {
                return databaseCollation;
            }


            /**
            * Returns the table name 'EVENTS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_EVENTS_H
