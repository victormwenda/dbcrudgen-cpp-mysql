//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSTABLESTATS_H
#define DBCRUDGEN_CPP_INNODBSYSTABLESTATS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbSysTableStats {

            private:
                long tableId;
                std::string name;
                std::string statsInitialized;
                long numRows;
                long clustIndexSize;
                long otherIndexSize;
                long modifiedCounter;
                long autoinc;
                int refCount;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_SYS_TABLESTATS";

                struct COLUMNS {
                    struct TABLE_ID {
                        static constexpr const char *NAME = "TABLE_ID";
                        static const int INDEX = 1;
                    };
                    struct NAME {
                        static constexpr const char *_NAME = "NAME";
                        static const int INDEX = 2;
                    };
                    struct STATS_INITIALIZED {
                        static constexpr const char *NAME = "STATS_INITIALIZED";
                        static const int INDEX = 3;
                    };
                    struct NUM_ROWS {
                        static constexpr const char *NAME = "NUM_ROWS";
                        static const int INDEX = 4;
                    };
                    struct CLUST_INDEX_SIZE {
                        static constexpr const char *NAME = "CLUST_INDEX_SIZE";
                        static const int INDEX = 5;
                    };
                    struct OTHER_INDEX_SIZE {
                        static constexpr const char *NAME = "OTHER_INDEX_SIZE";
                        static const int INDEX = 6;
                    };
                    struct MODIFIED_COUNTER {
                        static constexpr const char *NAME = "MODIFIED_COUNTER";
                        static const int INDEX = 7;
                    };
                    struct AUTOINC {
                        static constexpr const char *NAME = "AUTOINC";
                        static const int INDEX = 8;
                    };
                    struct REF_COUNT {
                        static constexpr const char *NAME = "REF_COUNT";
                        static const int INDEX = 9;
                    };
                };

                InnoDbSysTableStats(long tableId, std::string &name, std::string &statsInitialized, long numRows,
                                    long clustIndexSize, long otherIndexSize, long modifiedCounter, long autoinc,
                                    int refCount) : tableId{tableId}, name{name}, statsInitialized{statsInitialized},
                                                    numRows{numRows}, clustIndexSize{clustIndexSize},
                                                    otherIndexSize{otherIndexSize}, modifiedCounter{modifiedCounter},
                                                    autoinc{autoinc}, refCount{refCount} {}

                // Get the value of tableId
                long getTableId() const {
                    return tableId;
                }

                // Get the value of name
                const std::string &getName() const {
                    return name;
                }

                // Get the value of statsInitialized
                const std::string &getStatsInitialized() const {
                    return statsInitialized;
                }

                // Get the value of numRows
                long getNumRows() const {
                    return numRows;
                }

                // Get the value of clustIndexSize
                long getClustIndexSize() const {
                    return clustIndexSize;
                }

                // Get the value of otherIndexSize
                long getOtherIndexSize() const {
                    return otherIndexSize;
                }

                // Get the value of modifiedCounter
                long getModifiedCounter() const {
                    return modifiedCounter;
                }

                // Get the value of autoinc
                long getAutoinc() const {
                    return autoinc;
                }

                // Get the value of refCount
                int getRefCount() const {
                    return refCount;
                }

                /**
                * Returns the table name 'INNODB_SYS_TABLESTATS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBSYSTABLESTATS_H
