//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSINDEXES_H
#define DBCRUDGEN_CPP_INNODBSYSINDEXES_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbSysIndexes {

            private:
                long indexId;
                std::string name;
                long tableId;
                int type;
                int nFields;
                int pageNo;
                int space;
                int mergeThreshold;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_SYS_INDEXES";

                struct COLUMNS {
                    struct INDEX_ID {
                        static constexpr const char *NAME = "INDEX_ID";
                        static const int INDEX = 1;
                    };
                    struct NAME {
                        static constexpr const char *_NAME = "NAME";
                        static const int INDEX = 2;
                    };
                    struct TABLE_ID {
                        static constexpr const char *NAME = "TABLE_ID";
                        static const int INDEX = 3;
                    };
                    struct TYPE {
                        static constexpr const char *NAME = "TYPE";
                        static const int INDEX = 4;
                    };
                    struct N_FIELDS {
                        static constexpr const char *NAME = "N_FIELDS";
                        static const int INDEX = 5;
                    };
                    struct PAGE_NO {
                        static constexpr const char *NAME = "PAGE_NO";
                        static const int INDEX = 6;
                    };
                    struct SPACE {
                        static constexpr const char *NAME = "SPACE";
                        static const int INDEX = 7;
                    };
                    struct MERGE_THRESHOLD {
                        static constexpr const char *NAME = "MERGE_THRESHOLD";
                        static const int INDEX = 8;
                    };
                };

                InnoDbSysIndexes(long indexId, std::string &name, long tableId, int type, int nFields, int pageNo,
                                 int space, int mergeThreshold) : indexId{indexId}, name{name}, tableId{tableId},
                                                                  type{type}, nFields{nFields}, pageNo{pageNo},
                                                                  space{space}, mergeThreshold{mergeThreshold} {}

                // Get the value of indexId
                long getIndexId() const {
                    return indexId;
                }

                // Get the value of name
                const std::string &getName() const {
                    return name;
                }

                // Get the value of tableId
                long getTableId() const {
                    return tableId;
                }

                // Get the value of type
                int getType() const {
                    return type;
                }

                // Get the value of nFields
                int getNFields() const {
                    return nFields;
                }

                // Get the value of pageNo
                int getPageNo() const {
                    return pageNo;
                }

                // Get the value of space
                int getSpace() const {
                    return space;
                }

                // Get the value of mergeThreshold
                int getMergeThreshold() const {
                    return mergeThreshold;
                }

                /**
                * Returns the table name 'INNODB_SYS_INDEXES';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };

        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBSYSINDEXES_H
