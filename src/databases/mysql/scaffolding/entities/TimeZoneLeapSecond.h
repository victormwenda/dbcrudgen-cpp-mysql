#ifndef INFORMATION_SCHEMA_CPP_TIME_ZONE_LEAP_SECOND_H
#define INFORMATION_SCHEMA_CPP_TIME_ZONE_LEAP_SECOND_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class TimeZoneLeapSecond {

            private:
                long transitionTime;
                int correction;

            public:

                static constexpr const char *TABLE_NAME = "time_zone_leap_second";

                struct COLUMNS {
                    struct TRANSITION_TIME {
                        static constexpr const char *NAME = "Transition_time";
                        static const int INDEX = 1;
                    };
                    struct CORRECTION {
                        static constexpr const char *NAME = "Correction";
                        static const int INDEX = 2;
                    };
                };

                TimeZoneLeapSecond(long transitionTime, int correction)
                        : transitionTime{transitionTime}, correction{correction} {}

                // Get the value of transitionTime
                long getTransitionTime() const {
                    return transitionTime;
                }

                // Get the value of correction
                int getCorrection() const {
                    return correction;
                }


                /**
                * Returns the table name 'time_zone_leap_second';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_TIME_ZONE_LEAP_SECOND_H