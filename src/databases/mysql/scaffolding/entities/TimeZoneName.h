#ifndef INFORMATION_SCHEMA_CPP_TIME_ZONE_NAME_H
#define INFORMATION_SCHEMA_CPP_TIME_ZONE_NAME_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class TimeZoneName {

        private:
            std::string name;
            int timeZoneId;

        public:

            static constexpr const char *TABLE_NAME = "time_zone_name";

            struct COLUMNS {
                struct NAME {
                    static constexpr const char *_NAME = "Name";
                    static const int INDEX = 1;
                };
                struct TIME_ZONE_ID {
                    static constexpr const char *NAME = "Time_zone_id";
                    static const int INDEX = 2;
                };
            };

            TimeZoneName(std::string &name, int timeZoneId) : name{name}, timeZoneId{timeZoneId} {}

            // Get the value of name
            const std::string &getName() const {
                return name;
            }

            // Get the value of timeZoneId
            int getTimeZoneId() const {
                return timeZoneId;
            }


            /**
            * Returns the table name 'time_zone_name';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_TIME_ZONE_NAME_H