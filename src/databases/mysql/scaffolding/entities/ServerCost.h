#ifndef INFORMATION_SCHEMA_CPP_SERVER_COST_H
#define INFORMATION_SCHEMA_CPP_SERVER_COST_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class ServerCost {

            private:
                std::string costName;
                long double costValue;
                std::string lastUpdate;
                std::string comment;

            public:

                static constexpr const char *TABLE_NAME = "server_cost";

                struct COLUMNS {
                    struct COST_NAME {
                        static constexpr const char *NAME = "cost_name";
                        static const int INDEX = 1;
                    };
                    struct COST_VALUE {
                        static constexpr const char *NAME = "cost_value";
                        static const int INDEX = 2;
                    };
                    struct LAST_UPDATE {
                        static constexpr const char *NAME = "last_update";
                        static const int INDEX = 3;
                    };
                    struct COMMENT {
                        static constexpr const char *NAME = "comment";
                        static const int INDEX = 4;
                    };
                };

                ServerCost(std::string &costName, long double costValue, std::string &lastUpdate, std::string &comment)
                        : costName{costName}, costValue{costValue}, lastUpdate{lastUpdate}, comment{comment} {}

                // Get the value of costName
                const std::string &getCostName() const {
                    return costName;
                }

                // Get the value of costValue
                long double getCostValue() const {
                    return costValue;
                }

                // Get the value of lastUpdate
                const std::string &getLastUpdate() const {
                    return lastUpdate;
                }

                // Get the value of comment
                const std::string &getComment() const {
                    return comment;
                }


                /**
                * Returns the table name 'server_cost';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_SERVER_COST_H