//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBMETRICS_H
#define DBCRUDGEN_CPP_INNODBMETRICS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbMetrics {

        private:
            std::string name;
            std::string subsystem;
            long count;
            long maxCount;
            long minCount;
            long double avgCount;
            long countReset;
            long maxCountReset;
            long minCountReset;
            long double avgCountReset;
            std::string timeEnabled;
            std::string timeDisabled;
            long timeElapsed;
            std::string timeReset;
            std::string status;
            std::string type;
            std::string comment;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_METRICS";

            struct COLUMNS {
                struct NAME {
                    static constexpr const char *_NAME = "NAME";
                    static const int INDEX = 1;
                };
                struct SUBSYSTEM {
                    static constexpr const char *NAME = "SUBSYSTEM";
                    static const int INDEX = 2;
                };
                struct COUNT {
                    static constexpr const char *NAME = "COUNT";
                    static const int INDEX = 3;
                };
                struct MAX_COUNT {
                    static constexpr const char *NAME = "MAX_COUNT";
                    static const int INDEX = 4;
                };
                struct MIN_COUNT {
                    static constexpr const char *NAME = "MIN_COUNT";
                    static const int INDEX = 5;
                };
                struct AVG_COUNT {
                    static constexpr const char *NAME = "AVG_COUNT";
                    static const int INDEX = 6;
                };
                struct COUNT_RESET {
                    static constexpr const char *NAME = "COUNT_RESET";
                    static const int INDEX = 7;
                };
                struct MAX_COUNT_RESET {
                    static constexpr const char *NAME = "MAX_COUNT_RESET";
                    static const int INDEX = 8;
                };
                struct MIN_COUNT_RESET {
                    static constexpr const char *NAME = "MIN_COUNT_RESET";
                    static const int INDEX = 9;
                };
                struct AVG_COUNT_RESET {
                    static constexpr const char *NAME = "AVG_COUNT_RESET";
                    static const int INDEX = 10;
                };
                struct TIME_ENABLED {
                    static constexpr const char *NAME = "TIME_ENABLED";
                    static const int INDEX = 11;
                };
                struct TIME_DISABLED {
                    static constexpr const char *NAME = "TIME_DISABLED";
                    static const int INDEX = 12;
                };
                struct TIME_ELAPSED {
                    static constexpr const char *NAME = "TIME_ELAPSED";
                    static const int INDEX = 13;
                };
                struct TIME_RESET {
                    static constexpr const char *NAME = "TIME_RESET";
                    static const int INDEX = 14;
                };
                struct STATUS {
                    static constexpr const char *NAME = "STATUS";
                    static const int INDEX = 15;
                };
                struct TYPE {
                    static constexpr const char *NAME = "TYPE";
                    static const int INDEX = 16;
                };
                struct COMMENT {
                    static constexpr const char *NAME = "COMMENT";
                    static const int INDEX = 17;
                };
            };

            InnoDbMetrics(std::string &name, std::string &subsystem, long count, long maxCount, long minCount,
                          long double avgCount, long countReset, long maxCountReset, long minCountReset,
                          long double avgCountReset, std::string &timeEnabled, std::string &timeDisabled,
                          long timeElapsed, std::string &timeReset, std::string &status, std::string &type,
                          std::string &comment) : name{name}, subsystem{subsystem}, count{count}, maxCount{maxCount},
                                                  minCount{minCount}, avgCount{avgCount}, countReset{countReset},
                                                  maxCountReset{maxCountReset}, minCountReset{minCountReset},
                                                  avgCountReset{avgCountReset}, timeEnabled{timeEnabled},
                                                  timeDisabled{timeDisabled}, timeElapsed{timeElapsed},
                                                  timeReset{timeReset}, status{status}, type{type}, comment{comment} {}

            // Get the value of name
            const std::string &getName() const {
                return name;
            }

            // Get the value of subsystem
            const std::string &getSubsystem() const {
                return subsystem;
            }

            // Get the value of count
            long getCount() const {
                return count;
            }

            // Get the value of maxCount
            long getMaxCount() const {
                return maxCount;
            }

            // Get the value of minCount
            long getMinCount() const {
                return minCount;
            }

            // Get the value of avgCount
            long double getAvgCount() const {
                return avgCount;
            }

            // Get the value of countReset
            long getCountReset() const {
                return countReset;
            }

            // Get the value of maxCountReset
            long getMaxCountReset() const {
                return maxCountReset;
            }

            // Get the value of minCountReset
            long getMinCountReset() const {
                return minCountReset;
            }

            // Get the value of avgCountReset
            long double getAvgCountReset() const {
                return avgCountReset;
            }

            // Get the value of timeEnabled
            const std::string &getTimeEnabled() const {
                return timeEnabled;
            }

            // Get the value of timeDisabled
            const std::string &getTimeDisabled() const {
                return timeDisabled;
            }

            // Get the value of timeElapsed
            long getTimeElapsed() const {
                return timeElapsed;
            }

            // Get the value of timeReset
            const std::string &getTimeReset() const {
                return timeReset;
            }

            // Get the value of status
            const std::string &getStatus() const {
                return status;
            }

            // Get the value of type
            const std::string &getType() const {
                return type;
            }

            // Get the value of comment
            const std::string &getComment() const {
                return comment;
            }


            /**
            * Returns the table name 'INNODB_METRICS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBMETRICS_H
