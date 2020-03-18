//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_PARTITIONS_H
#define DBCRUDGEN_CPP_PARTITIONS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class Partitions {

        private:
            std::string tableCatalog;
            std::string tableSchema;
            std::string tableName;
            std::string partitionName;
            std::string subpartitionName;
            long partitionOrdinalPosition;
            long subpartitionOrdinalPosition;
            std::string partitionMethod;
            std::string subpartitionMethod;
            std::string partitionExpression;
            std::string subpartitionExpression;
            std::string partitionDescription;
            long tableRows;
            long avgRowLength;
            long dataLength;
            long maxDataLength;
            long indexLength;
            long dataFree;
            std::string createTime;
            std::string updateTime;
            std::string checkTime;
            long checksum;
            std::string partitionComment;
            std::string nodegroup;
            std::string tablespaceName;

        public:

            static constexpr const char *TABLE_NAME = "PARTITIONS";

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
                struct PARTITION_NAME {
                    static constexpr const char *NAME = "PARTITION_NAME";
                    static const int INDEX = 4;
                };
                struct SUBPARTITION_NAME {
                    static constexpr const char *NAME = "SUBPARTITION_NAME";
                    static const int INDEX = 5;
                };
                struct PARTITION_ORDINAL_POSITION {
                    static constexpr const char *NAME = "PARTITION_ORDINAL_POSITION";
                    static const int INDEX = 6;
                };
                struct SUBPARTITION_ORDINAL_POSITION {
                    static constexpr const char *NAME = "SUBPARTITION_ORDINAL_POSITION";
                    static const int INDEX = 7;
                };
                struct PARTITION_METHOD {
                    static constexpr const char *NAME = "PARTITION_METHOD";
                    static const int INDEX = 8;
                };
                struct SUBPARTITION_METHOD {
                    static constexpr const char *NAME = "SUBPARTITION_METHOD";
                    static const int INDEX = 9;
                };
                struct PARTITION_EXPRESSION {
                    static constexpr const char *NAME = "PARTITION_EXPRESSION";
                    static const int INDEX = 10;
                };
                struct SUBPARTITION_EXPRESSION {
                    static constexpr const char *NAME = "SUBPARTITION_EXPRESSION";
                    static const int INDEX = 11;
                };
                struct PARTITION_DESCRIPTION {
                    static constexpr const char *NAME = "PARTITION_DESCRIPTION";
                    static const int INDEX = 12;
                };
                struct TABLE_ROWS {
                    static constexpr const char *NAME = "TABLE_ROWS";
                    static const int INDEX = 13;
                };
                struct AVG_ROW_LENGTH {
                    static constexpr const char *NAME = "AVG_ROW_LENGTH";
                    static const int INDEX = 14;
                };
                struct DATA_LENGTH {
                    static constexpr const char *NAME = "DATA_LENGTH";
                    static const int INDEX = 15;
                };
                struct MAX_DATA_LENGTH {
                    static constexpr const char *NAME = "MAX_DATA_LENGTH";
                    static const int INDEX = 16;
                };
                struct INDEX_LENGTH {
                    static constexpr const char *NAME = "INDEX_LENGTH";
                    static const int INDEX = 17;
                };
                struct DATA_FREE {
                    static constexpr const char *NAME = "DATA_FREE";
                    static const int INDEX = 18;
                };
                struct CREATE_TIME {
                    static constexpr const char *NAME = "CREATE_TIME";
                    static const int INDEX = 19;
                };
                struct UPDATE_TIME {
                    static constexpr const char *NAME = "UPDATE_TIME";
                    static const int INDEX = 20;
                };
                struct CHECK_TIME {
                    static constexpr const char *NAME = "CHECK_TIME";
                    static const int INDEX = 21;
                };
                struct CHECKSUM {
                    static constexpr const char *NAME = "CHECKSUM";
                    static const int INDEX = 22;
                };
                struct PARTITION_COMMENT {
                    static constexpr const char *NAME = "PARTITION_COMMENT";
                    static const int INDEX = 23;
                };
                struct NODEGROUP {
                    static constexpr const char *NAME = "NODEGROUP";
                    static const int INDEX = 24;
                };
                struct TABLESPACE_NAME {
                    static constexpr const char *NAME = "TABLESPACE_NAME";
                    static const int INDEX = 25;
                };
            };

            Partitions(std::string &tableCatalog, std::string &tableSchema, std::string &tableName,
                       std::string &partitionName, std::string &subpartitionName, long partitionOrdinalPosition,
                       long subpartitionOrdinalPosition, std::string &partitionMethod, std::string &subpartitionMethod,
                       std::string &partitionExpression, std::string &subpartitionExpression,
                       std::string &partitionDescription, long tableRows, long avgRowLength, long dataLength,
                       long maxDataLength, long indexLength, long dataFree, std::string &createTime,
                       std::string &updateTime, std::string &checkTime, long checksum, std::string &partitionComment,
                       std::string &nodegroup, std::string &tablespaceName)
                    : tableCatalog{tableCatalog}, tableSchema{tableSchema}, tableName{tableName},
                      partitionName{partitionName}, subpartitionName{subpartitionName},
                      partitionOrdinalPosition{partitionOrdinalPosition},
                      subpartitionOrdinalPosition{subpartitionOrdinalPosition}, partitionMethod{partitionMethod},
                      subpartitionMethod{subpartitionMethod}, partitionExpression{partitionExpression},
                      subpartitionExpression{subpartitionExpression}, partitionDescription{partitionDescription},
                      tableRows{tableRows}, avgRowLength{avgRowLength}, dataLength{dataLength},
                      maxDataLength{maxDataLength}, indexLength{indexLength}, dataFree{dataFree},
                      createTime{createTime}, updateTime{updateTime}, checkTime{checkTime}, checksum{checksum},
                      partitionComment{partitionComment}, nodegroup{nodegroup}, tablespaceName{tablespaceName} {}

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

            // Get the value of partitionName
            const std::string &getPartitionName() const {
                return partitionName;
            }

            // Get the value of subpartitionName
            const std::string &getSubpartitionName() const {
                return subpartitionName;
            }

            // Get the value of partitionOrdinalPosition
            long getPartitionOrdinalPosition() const {
                return partitionOrdinalPosition;
            }

            // Get the value of subpartitionOrdinalPosition
            long getSubpartitionOrdinalPosition() const {
                return subpartitionOrdinalPosition;
            }

            // Get the value of partitionMethod
            const std::string &getPartitionMethod() const {
                return partitionMethod;
            }

            // Get the value of subpartitionMethod
            const std::string &getSubpartitionMethod() const {
                return subpartitionMethod;
            }

            // Get the value of partitionExpression
            const std::string &getPartitionExpression() const {
                return partitionExpression;
            }

            // Get the value of subpartitionExpression
            const std::string &getSubpartitionExpression() const {
                return subpartitionExpression;
            }

            // Get the value of partitionDescription
            const std::string &getPartitionDescription() const {
                return partitionDescription;
            }

            // Get the value of tableRows
            long getTableRows() const {
                return tableRows;
            }

            // Get the value of avgRowLength
            long getAvgRowLength() const {
                return avgRowLength;
            }

            // Get the value of dataLength
            long getDataLength() const {
                return dataLength;
            }

            // Get the value of maxDataLength
            long getMaxDataLength() const {
                return maxDataLength;
            }

            // Get the value of indexLength
            long getIndexLength() const {
                return indexLength;
            }

            // Get the value of dataFree
            long getDataFree() const {
                return dataFree;
            }

            // Get the value of createTime
            const std::string &getCreateTime() const {
                return createTime;
            }

            // Get the value of updateTime
            const std::string &getUpdateTime() const {
                return updateTime;
            }

            // Get the value of checkTime
            const std::string &getCheckTime() const {
                return checkTime;
            }

            // Get the value of checksum
            long getChecksum() const {
                return checksum;
            }

            // Get the value of partitionComment
            const std::string &getPartitionComment() const {
                return partitionComment;
            }

            // Get the value of nodegroup
            const std::string &getNodegroup() const {
                return nodegroup;
            }

            // Get the value of tablespaceName
            const std::string &getTablespaceName() const {
                return tablespaceName;
            }

            /**
            * Returns the table name 'PARTITIONS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_PARTITIONS_H
