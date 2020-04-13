#ifndef INFORMATION_SCHEMA_CPP_TIME_ZONE_TRANSITION_H
#define INFORMATION_SCHEMA_CPP_TIME_ZONE_TRANSITION_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class TimeZoneTransition {

            private:
                int timeZoneId;
                long transitionTime;
                int transitionTypeId;

            public:

                static constexpr const char *TABLE_NAME = "time_zone_transition";

                struct COLUMNS {
                    struct TIME_ZONE_ID {
                        static constexpr const char *NAME = "Time_zone_id";
                        static const int INDEX = 1;
                    };
                    struct TRANSITION_TIME {
                        static constexpr const char *NAME = "Transition_time";
                        static const int INDEX = 2;
                    };
                    struct TRANSITION_TYPE_ID {
                        static constexpr const char *NAME = "Transition_type_id";
                        static const int INDEX = 3;
                    };
                };

                TimeZoneTransition(int timeZoneId, long transitionTime, int transitionTypeId)
                        : timeZoneId{timeZoneId}, transitionTime{transitionTime}, transitionTypeId{transitionTypeId} {}

                // Get the value of timeZoneId
                int getTimeZoneId() const {
                    return timeZoneId;
                }

                // Get the value of transitionTime
                long getTransitionTime() const {
                    return transitionTime;
                }

                // Get the value of transitionTypeId
                int getTransitionTypeId() const {
                    return transitionTypeId;
                }


                /**
                * Returns the table name 'time_zone_transition';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_TIME_ZONE_TRANSITION_H