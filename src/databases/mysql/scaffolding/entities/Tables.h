//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_TABLES_H
#define DBCRUDGEN_CPP_TABLES_H

#include <string>

#include <string>

namespace dbcrudgen {
    namespace mysql {

        class Tables {

        private:
            std::string tableCatalog;
            std::string tableSchema;
            std::string tableName;
            std::string tableType;
            std::string engine;
            long version;
            std::string rowFormat;
            long tableRows;
            long avgRowLength;
            long dataLength;
            long maxDataLength;
            long indexLength;
            long dataFree;
            long autoIncrement;
            std::string createTime;
            std::string updateTime;
            std::string checkTime;
            std::string tableCollation;
            long checksum;
            std::string createOptions;
            std::string tableComment;

        public:

            static constexpr const char *TABLE_NAME = "TABLES";

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
                struct TABLE_TYPE {
                    static constexpr const char *NAME = "TABLE_TYPE";
                    static const int INDEX = 4;
                };
                struct ENGINE {
                    static constexpr const char *NAME = "ENGINE";
                    static const int INDEX = 5;
                };
                struct VERSION {
                    static constexpr const char *NAME = "VERSION";
                    static const int INDEX = 6;
                };
                struct ROW_FORMAT {
                    static constexpr const char *NAME = "ROW_FORMAT";
                    static const int INDEX = 7;
                };
                struct TABLE_ROWS {
                    static constexpr const char *NAME = "TABLE_ROWS";
                    static const int INDEX = 8;
                };
                struct AVG_ROW_LENGTH {
                    static constexpr const char *NAME = "AVG_ROW_LENGTH";
                    static const int INDEX = 9;
                };
                struct DATA_LENGTH {
                    static constexpr const char *NAME = "DATA_LENGTH";
                    static const int INDEX = 10;
                };
                struct MAX_DATA_LENGTH {
                    static constexpr const char *NAME = "MAX_DATA_LENGTH";
                    static const int INDEX = 11;
                };
                struct INDEX_LENGTH {
                    static constexpr const char *NAME = "INDEX_LENGTH";
                    static const int INDEX = 12;
                };
                struct DATA_FREE {
                    static constexpr const char *NAME = "DATA_FREE";
                    static const int INDEX = 13;
                };
                struct AUTO_INCREMENT {
                    static constexpr const char *NAME = "AUTO_INCREMENT";
                    static const int INDEX = 14;
                };
                struct CREATE_TIME {
                    static constexpr const char *NAME = "CREATE_TIME";
                    static const int INDEX = 15;
                };
                struct UPDATE_TIME {
                    static constexpr const char *NAME = "UPDATE_TIME";
                    static const int INDEX = 16;
                };
                struct CHECK_TIME {
                    static constexpr const char *NAME = "CHECK_TIME";
                    static const int INDEX = 17;
                };
                struct TABLE_COLLATION {
                    static constexpr const char *NAME = "TABLE_COLLATION";
                    static const int INDEX = 18;
                };
                struct CHECKSUM {
                    static constexpr const char *NAME = "CHECKSUM";
                    static const int INDEX = 19;
                };
                struct CREATE_OPTIONS {
                    static constexpr const char *NAME = "CREATE_OPTIONS";
                    static const int INDEX = 20;
                };
                struct TABLE_COMMENT {
                    static constexpr const char *NAME = "TABLE_COMMENT";
                    static const int INDEX = 21;
                };
            };

            Tables(std::string &tableCatalog, std::string &tableSchema, std::string &tableName, std::string &tableType,
                   std::string &engine, long version, std::string &rowFormat, long tableRows, long avgRowLength,
                   long dataLength, long maxDataLength, long indexLength, long dataFree, long autoIncrement,
                   std::string &createTime, std::string &updateTime, std::string &checkTime,
                   std::string &tableCollation, long checksum, std::string &createOptions, std::string &tableComment)
                    : tableCatalog{tableCatalog}, tableSchema{tableSchema}, tableName{tableName}, tableType{tableType},
                      engine{engine}, version{version}, rowFormat{rowFormat}, tableRows{tableRows},
                      avgRowLength{avgRowLength}, dataLength{dataLength}, maxDataLength{maxDataLength},
                      indexLength{indexLength}, dataFree{dataFree}, autoIncrement{autoIncrement},
                      createTime{createTime}, updateTime{updateTime}, checkTime{checkTime},
                      tableCollation{tableCollation}, checksum{checksum}, createOptions{createOptions},
                      tableComment{tableComment} {}

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

            // Get the value of tableType
            const std::string &getTableType() const {
                return tableType;
            }

            // Get the value of engine
            const std::string &getEngine() const {
                return engine;
            }

            // Get the value of version
            long getVersion() const {
                return version;
            }

            // Get the value of rowFormat
            const std::string &getRowFormat() const {
                return rowFormat;
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

            // Get the value of autoIncrement
            long getAutoIncrement() const {
                return autoIncrement;
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

            // Get the value of tableCollation
            const std::string &getTableCollation() const {
                return tableCollation;
            }

            // Get the value of checksum
            long getChecksum() const {
                return checksum;
            }

            // Get the value of createOptions
            const std::string &getCreateOptions() const {
                return createOptions;
            }

            // Get the value of tableComment
            const std::string &getTableComment() const {
                return tableComment;
            }

            /**
            * Returns the table name 'TABLES';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_TABLES_H
