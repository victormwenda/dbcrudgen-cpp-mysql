//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_STATISTICS_H
#define DBCRUDGEN_CPP_STATISTICS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class Statistics {

            private:
                std::string tableCatalog;
                std::string tableSchema;
                std::string tableName;
                long nonUnique;
                std::string indexSchema;
                std::string indexName;
                long seqInIndex;
                std::string columnName;
                std::string collation;
                long cardinality;
                long subPart;
                std::string packed;
                std::string nullable;
                std::string indexType;
                std::string comment;
                std::string indexComment;

            public:

                static constexpr const char *TABLE_NAME = "STATISTICS";

                struct COLUMNS {
                    struct TABLE_CATALOG {
                        static constexpr const char *NAME = "TABLE_CATALOG";
                        static const int INDEX = 1;
                    };
                    struct TABLE_SCHEMA {
                        static constexpr const char *NAME = "TABLE_SCHEMA";
                        static const int INDEX = 2;
                    };
                    struct TABLE_NAME {
                        static constexpr const char *NAME = "TABLE_NAME";
                        static const int INDEX = 3;
                    };
                    struct NON_UNIQUE {
                        static constexpr const char *NAME = "NON_UNIQUE";
                        static const int INDEX = 4;
                    };
                    struct INDEX_SCHEMA {
                        static constexpr const char *NAME = "INDEX_SCHEMA";
                        static const int INDEX = 5;
                    };
                    struct INDEX_NAME {
                        static constexpr const char *NAME = "INDEX_NAME";
                        static const int INDEX = 6;
                    };
                    struct SEQ_IN_INDEX {
                        static constexpr const char *NAME = "SEQ_IN_INDEX";
                        static const int INDEX = 7;
                    };
                    struct COLUMN_NAME {
                        static constexpr const char *NAME = "COLUMN_NAME";
                        static const int INDEX = 8;
                    };
                    struct COLLATION {
                        static constexpr const char *NAME = "COLLATION";
                        static const int INDEX = 9;
                    };
                    struct CARDINALITY {
                        static constexpr const char *NAME = "CARDINALITY";
                        static const int INDEX = 10;
                    };
                    struct SUB_PART {
                        static constexpr const char *NAME = "SUB_PART";
                        static const int INDEX = 11;
                    };
                    struct PACKED {
                        static constexpr const char *NAME = "PACKED";
                        static const int INDEX = 12;
                    };
                    struct NULLABLE {
                        static constexpr const char *NAME = "NULLABLE";
                        static const int INDEX = 13;
                    };
                    struct INDEX_TYPE {
                        static constexpr const char *NAME = "INDEX_TYPE";
                        static const int INDEX = 14;
                    };
                    struct COMMENT {
                        static constexpr const char *NAME = "COMMENT";
                        static const int INDEX = 15;
                    };
                    struct INDEX_COMMENT {
                        static constexpr const char *NAME = "INDEX_COMMENT";
                        static const int INDEX = 16;
                    };
                };

                Statistics(std::string &tableCatalog, std::string &tableSchema, std::string &tableName, long nonUnique,
                           std::string &indexSchema, std::string &indexName, long seqInIndex, std::string &columnName,
                           std::string &collation, long cardinality, long subPart, std::string &packed,
                           std::string &nullable, std::string &indexType, std::string &comment, std::string &indexComment)
                        : tableCatalog{tableCatalog}, tableSchema{tableSchema}, tableName{tableName}, nonUnique{nonUnique},
                          indexSchema{indexSchema}, indexName{indexName}, seqInIndex{seqInIndex}, columnName{columnName},
                          collation{collation}, cardinality{cardinality}, subPart{subPart}, packed{packed},
                          nullable{nullable}, indexType{indexType}, comment{comment}, indexComment{indexComment} {}

                // Get the value of tableCatalog
                const std::string &getTableCatalog() const {
                    return tableCatalog;
                }

                // Get the value of tableSchema
                const std::string &getTableSchema() const {
                    return tableSchema;
                }

                // Get the value of tableName
                const std::string &getTableName() const {
                    return tableName;
                }

                // Get the value of nonUnique
                long getNonUnique() const {
                    return nonUnique;
                }

                // Get the value of indexSchema
                const std::string &getIndexSchema() const {
                    return indexSchema;
                }

                // Get the value of indexName
                const std::string &getIndexName() const {
                    return indexName;
                }

                // Get the value of seqInIndex
                long getSeqInIndex() const {
                    return seqInIndex;
                }

                // Get the value of columnName
                const std::string &getColumnName() const {
                    return columnName;
                }

                // Get the value of collation
                const std::string &getCollation() const {
                    return collation;
                }

                // Get the value of cardinality
                long getCardinality() const {
                    return cardinality;
                }

                // Get the value of subPart
                long getSubPart() const {
                    return subPart;
                }

                // Get the value of packed
                const std::string &getPacked() const {
                    return packed;
                }

                // Get the value of nullable
                const std::string &getNullable() const {
                    return nullable;
                }

                // Get the value of indexType
                const std::string &getIndexType() const {
                    return indexType;
                }

                // Get the value of comment
                const std::string &getComment() const {
                    return comment;
                }

                // Get the value of indexComment
                const std::string &getIndexComment() const {
                    return indexComment;
                }

                /**
                * Returns the table name 'STATISTICS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };

        }
    }

}


#endif //DBCRUDGEN_CPP_STATISTICS_H
