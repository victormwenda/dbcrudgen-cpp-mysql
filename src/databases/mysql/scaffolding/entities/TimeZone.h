#ifndef INFORMATION_SCHEMA_CPP_TIME_ZONE_H
#define INFORMATION_SCHEMA_CPP_TIME_ZONE_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class TimeZone {

        private:
            int timeZoneId;
            std::string useLeapSeconds;

        public:

            static constexpr const char *TABLE_NAME = "time_zone";

            struct COLUMNS {
                struct TIME_ZONE_ID {
                    static constexpr const char *NAME = "Time_zone_id";
                    static const int INDEX = 1;
                };
                struct USE_LEAP_SECONDS {
                    static constexpr const char *NAME = "Use_leap_seconds";
                    static const int INDEX = 2;
                };
            };

            TimeZone(int timeZoneId, std::string &useLeapSeconds)
                    : timeZoneId{timeZoneId}, useLeapSeconds{useLeapSeconds} {}

            // Get the value of timeZoneId
            int getTimeZoneId() const {
                return timeZoneId;
            }

            // Get the value of useLeapSeconds
            const std::string &getUseLeapSeconds() const {
                return useLeapSeconds;
            }


            /**
            * Returns the table name 'time_zone';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_TIME_ZONE_H