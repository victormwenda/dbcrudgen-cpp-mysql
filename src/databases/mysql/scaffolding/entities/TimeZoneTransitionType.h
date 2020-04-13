#ifndef INFORMATION_SCHEMA_CPP_TIME_ZONE_TRANSITION_TYPE_H
#define INFORMATION_SCHEMA_CPP_TIME_ZONE_TRANSITION_TYPE_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class TimeZoneTransitionType {

            private:
                int timeZoneId;
                int transitionTypeId;
                int offset;
                int isDst;
                std::string abbreviation;

            public:

                static constexpr const char *TABLE_NAME = "time_zone_transition_type";

                struct COLUMNS {
                    struct TIME_ZONE_ID {
                        static constexpr const char *NAME = "Time_zone_id";
                        static const int INDEX = 1;
                    };
                    struct TRANSITION_TYPE_ID {
                        static constexpr const char *NAME = "Transition_type_id";
                        static const int INDEX = 2;
                    };
                    struct OFFSET {
                        static constexpr const char *NAME = "Offset";
                        static const int INDEX = 3;
                    };
                    struct IS_DST {
                        static constexpr const char *NAME = "Is_DST";
                        static const int INDEX = 4;
                    };
                    struct ABBREVIATION {
                        static constexpr const char *NAME = "Abbreviation";
                        static const int INDEX = 5;
                    };
                };

                TimeZoneTransitionType(int timeZoneId, int transitionTypeId, int offset, int isDst,
                                       std::string &abbreviation)
                        : timeZoneId{timeZoneId},
                          transitionTypeId{transitionTypeId}, offset{offset},
                          isDst{isDst}, abbreviation{abbreviation} {}

                // Get the value of timeZoneId
                int getTimeZoneId() const {
                    return timeZoneId;
                }

                // Get the value of transitionTypeId
                int getTransitionTypeId() const {
                    return transitionTypeId;
                }

                // Get the value of offset
                int getOffset() const {
                    return offset;
                }

                // Get the value of isDst
                int getIsDst() const {
                    return isDst;
                }

                // Get the value of abbreviation
                const std::string &getAbbreviation() const {
                    return abbreviation;
                }


                /**
                * Returns the table name 'time_zone_transition_type';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_TIME_ZONE_TRANSITION_TYPE_H