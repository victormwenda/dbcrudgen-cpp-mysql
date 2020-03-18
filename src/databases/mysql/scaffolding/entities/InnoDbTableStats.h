#ifndef INFORMATION_SCHEMA_CPP_INNODB_TABLE_STATS_H
#define INFORMATION_SCHEMA_CPP_INNODB_TABLE_STATS_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbTableStats {

        private:
            std::string databaseName;
            std::string tableName;
            std::string lastUpdate;
            long nRows;
            long clusteredIndexSize;
            long sumOfOtherIndexSizes;

        public:

            static constexpr const char *TABLE_NAME = "innodb_table_stats";

            struct COLUMNS {
                struct DATABASE_NAME {
                    static constexpr const char *NAME = "database_name";
                    static const int INDEX = 1;
                };
                struct TABLE_NAME {
                    static constexpr const char *NAME = "table_name";
                    static const int INDEX = 2;
                };
                struct LAST_UPDATE {
                    static constexpr const char *NAME = "last_update";
                    static const int INDEX = 3;
                };
                struct N_ROWS {
                    static constexpr const char *NAME = "n_rows";
                    static const int INDEX = 4;
                };
                struct CLUSTERED_INDEX_SIZE {
                    static constexpr const char *NAME = "clustered_index_size";
                    static const int INDEX = 5;
                };
                struct SUM_OF_OTHER_INDEX_SIZES {
                    static constexpr const char *NAME = "sum_of_other_index_sizes";
                    static const int INDEX = 6;
                };
            };

            InnoDbTableStats(std::string &databaseName, std::string &tableName, std::string &lastUpdate, long nRows,
                             long clusteredIndexSize, long sumOfOtherIndexSizes) : databaseName{databaseName},
                                                                                   tableName{tableName},
                                                                                   lastUpdate{lastUpdate}, nRows{nRows},
                                                                                   clusteredIndexSize{
                                                                                           clusteredIndexSize},
                                                                                   sumOfOtherIndexSizes{
                                                                                           sumOfOtherIndexSizes} {}

            // Get the value of databaseName
            const std::string &getDatabaseName() const {
                return databaseName;
            }

            // Get the value of tableName
            const std::string &getTableName() const {
                return tableName;
            }

            // Get the value of lastUpdate
            const std::string &getLastUpdate() const {
                return lastUpdate;
            }

            // Get the value of nRows
            long getNRows() const {
                return nRows;
            }

            // Get the value of clusteredIndexSize
            long getClusteredIndexSize() const {
                return clusteredIndexSize;
            }

            // Get the value of sumOfOtherIndexSizes
            long getSumOfOtherIndexSizes() const {
                return sumOfOtherIndexSizes;
            }


            /**
            * Returns the table name 'innodb_table_stats';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_INNODB_TABLE_STATS_H