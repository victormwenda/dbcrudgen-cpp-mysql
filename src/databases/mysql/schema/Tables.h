//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_TABLES_H
#define DBCRUDGEN_CPP_TABLES_H

#include <string>

namespace dbcrudgen {
    namespace mysql {

        class Tables {

        private:
            std::string table_catalog;
            std::string table_schema;
            std::string table_name;
            std::string table_type;
            std::string engine;
            long version;
            std::string row_format;
            long table_rows;
            std::string avg_row_length;
            std::string data_length;
            std::string max_data_length;
            std::string index_length;
            std::string data_free;
            std::string auto_increment;
            std::string create_time;
            std::string update_time;
            std::string check_time;
            std::string table_collation;
            long checksum;
            std::string create_options;
            std::string table_comment;

        public:

            struct TABLE_CATALOG {
                static constexpr const int INDEX = 1;
                static constexpr const char *NAME = "TABLE_CATALOG";
            };
            struct TABLE_SCHEMA {
                static constexpr const int INDEX = 2;
                static constexpr const char *NAME = "TABLE_SCHEMA";
            };
            struct TABLE_NAME {
                static constexpr const int INDEX = 3;
                static constexpr const char *NAME = "TABLE_NAME";
            };
            struct TABLE_TYPE {
                static constexpr const int INDEX = 4;
                static constexpr const char *NAME = "TABLE_TYPE";
            };
            struct ENGINE {
                static constexpr const int INDEX = 5;
                static constexpr const char *NAME = "ENGINE";
            };
            struct VERSION {
                static constexpr const int INDEX = 6;
                static constexpr const char *NAME = "VERSION";
            };
            struct ROW_FORMAT {
                static constexpr const int INDEX = 7;
                static constexpr const char *NAME = "ROW_FORMAT";
            };
            struct TABLE_ROWS {
                static constexpr const int INDEX = 8;
                static constexpr const char *NAME = "TABLE_ROWS";
            };
            struct AVG_ROW_LENGTH {
                static constexpr const int INDEX = 9;
                static constexpr const char *NAME = "AVG_ROW_LENGTH";
            };
            struct DATA_LENGTH {
                static constexpr const int INDEX = 10;
                static constexpr const char *NAME = "DATA_LENGTH";
            };
            struct MAX_DATA_LENGTH {
                static constexpr const int INDEX = 11;
                static constexpr const char *NAME = "MAX_DATA_LENGTH";
            };
            struct INDEX_LENGTH {
                static constexpr const int INDEX = 12;
                static constexpr const char *NAME = "INDEX_LENGTH";
            };
            struct DATA_FREE {
                static constexpr const int INDEX = 13;
                static constexpr const char *NAME = "DATA_FREE";
            };
            struct AUTO_INCREMENT {
                static constexpr const int INDEX = 14;
                static constexpr const char *NAME = "AUTO_INCREMENT";
            };
            struct CREATE_TIME {
                static constexpr const int INDEX = 15;
                static constexpr const char *NAME = "CREATE_TIME";
            };
            struct UPDATE_TIME {
                static constexpr const int INDEX = 16;
                static constexpr const char *NAME = "UPDATE_TIME";
            };
            struct CHECK_TIME {
                static constexpr const int INDEX = 17;
                static constexpr const char *NAME = "CHECK_TIME";
            };
            struct TABLE_COLLATION {
                static constexpr const int INDEX = 18;
                static constexpr const char *NAME = "TABLE_COLLATION";
            };
            struct CHECKSUM {
                static constexpr const int INDEX = 19;
                static constexpr const char *NAME = "CHECKSUM";
            };
            struct CREATE_OPTIONS {
                static constexpr const int INDEX = 1;
                static constexpr const char *NAME = "CREATE_OPTIONS";
            };
            struct TABLE_COMMENT {
                static constexpr const int INDEX = 20;
                static constexpr const char *NAME = "TABLE_COMMENT";
            };

            Tables(std::string &tableCatalog, std::string &tableSchema, std::string &tableName, std::string &tableType,
                   std::string &engine, long &version, std::string &rowFormat, long &tableRows,
                   std::string &avgRowLength, std::string &dataLength, std::string &maxDataLength,
                   std::string &indexLength, std::string &dataFree, std::string &autoIncrement, std::string &createTime,
                   std::string &updateTime, std::string &checkTime, std::string &tableCollation, long &checksum,
                   std::string &createOptions, std::string &tableComment)
                    : table_catalog(tableCatalog), table_schema(tableSchema), table_name(tableName),
                      table_type(tableType), engine(engine), version(version), row_format(rowFormat),
                      table_rows(tableRows), avg_row_length(avgRowLength), data_length(dataLength),
                      max_data_length(maxDataLength), index_length(indexLength), data_free(dataFree),
                      auto_increment(autoIncrement), create_time(createTime), update_time(updateTime),
                      check_time(checkTime), table_collation(tableCollation), checksum(checksum),
                      create_options(createOptions), table_comment(tableComment) {}

            const std::string &getTableCatalog() const {
                return table_catalog;
            }

            const std::string &getTableSchema() const {
                return table_schema;
            }

            const std::string &getTableName() const {
                return table_name;
            }

            const std::string &getTableType() const {
                return table_type;
            }

            const std::string &getEngine() const {
                return engine;
            }

            const long &getVersion() const {
                return version;
            }

            const std::string &getRowFormat() const {
                return row_format;
            }

            const long &getTableRows() const {
                return table_rows;
            }

            const std::string &getAvgRowLength() const {
                return avg_row_length;
            }

            const std::string &getDataLength() const {
                return data_length;
            }

            const std::string &getMaxDataLength() const {
                return max_data_length;
            }

            const std::string &getIndexLength() const {
                return index_length;
            }

            const std::string &getDataFree() const {
                return data_free;
            }

            const std::string &getAutoIncrement() const {
                return auto_increment;
            }

            const std::string &getCreateTime() const {
                return create_time;
            }

            const std::string &getUpdateTime() const {
                return update_time;
            }

            const std::string &getCheckTime() const {
                return check_time;
            }

            const std::string &getTableCollation() const {
                return table_collation;
            }

            const long &getChecksum() const {
                return checksum;
            }

            const std::string &getCreateOptions() const {
                return create_options;
            }

            const std::string &getTableComment() const {
                return table_comment;
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_TABLES_H
