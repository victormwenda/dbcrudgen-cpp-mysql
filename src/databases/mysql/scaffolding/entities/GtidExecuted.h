#ifndef INFORMATION_SCHEMA_CPP_GTID_EXECUTED_H
#define INFORMATION_SCHEMA_CPP_GTID_EXECUTED_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class GtidExecuted {

            private:
                std::string sourceUuid;
                long intervalStart;
                long intervalEnd;

            public:

                static constexpr const char *TABLE_NAME = "gtid_executed";

                struct COLUMNS {
                    struct SOURCE_UUID {
                        static constexpr const char *NAME = "source_uuid";
                        static const int INDEX = 1;
                    };
                    struct INTERVAL_START {
                        static constexpr const char *NAME = "interval_start";
                        static const int INDEX = 2;
                    };
                    struct INTERVAL_END {
                        static constexpr const char *NAME = "interval_end";
                        static const int INDEX = 3;
                    };
                };

                GtidExecuted(std::string &sourceUuid, long intervalStart, long intervalEnd)
                        : sourceUuid{sourceUuid}, intervalStart{intervalStart}, intervalEnd{intervalEnd} {}

                // Get the value of sourceUuid
                const std::string &getSourceUuid() const {
                    return sourceUuid;
                }

                // Get the value of intervalStart
                long getIntervalStart() const {
                    return intervalStart;
                }

                // Get the value of intervalEnd
                long getIntervalEnd() const {
                    return intervalEnd;
                }


                /**
                * Returns the table name 'gtid_executed';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_GTID_EXECUTED_H