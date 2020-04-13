#ifndef INFORMATION_SCHEMA_CPP_INNODB_INDEX_STATS_H
#define INFORMATION_SCHEMA_CPP_INNODB_INDEX_STATS_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbIndexStats {

            private:
                std::string databaseName;
                std::string tableName;
                std::string indexName;
                std::string lastUpdate;
                std::string statName;
                long statValue;
                long sampleSize;
                std::string statDescription;

            public:

                static constexpr const char *TABLE_NAME = "innodb_index_stats";

                struct COLUMNS {
                    struct DATABASE_NAME {
                        static constexpr const char *NAME = "database_name";
                        static const int INDEX = 1;
                    };
                    struct TABLE_NAME {
                        static constexpr const char *NAME = "table_name";
                        static const int INDEX = 2;
                    };
                    struct INDEX_NAME {
                        static constexpr const char *NAME = "index_name";
                        static const int INDEX = 3;
                    };
                    struct LAST_UPDATE {
                        static constexpr const char *NAME = "last_update";
                        static const int INDEX = 4;
                    };
                    struct STAT_NAME {
                        static constexpr const char *NAME = "stat_name";
                        static const int INDEX = 5;
                    };
                    struct STAT_VALUE {
                        static constexpr const char *NAME = "stat_value";
                        static const int INDEX = 6;
                    };
                    struct SAMPLE_SIZE {
                        static constexpr const char *NAME = "sample_size";
                        static const int INDEX = 7;
                    };
                    struct STAT_DESCRIPTION {
                        static constexpr const char *NAME = "stat_description";
                        static const int INDEX = 8;
                    };
                };

                InnoDbIndexStats(std::string &databaseName, std::string &tableName, std::string &indexName,
                                 std::string &lastUpdate, std::string &statName, long statValue, long sampleSize,
                                 std::string &statDescription) : databaseName{databaseName}, tableName{tableName},
                                                                 indexName{indexName}, lastUpdate{lastUpdate},
                                                                 statName{statName}, statValue{statValue},
                                                                 sampleSize{sampleSize},
                                                                 statDescription{statDescription} {}

                // Get the value of databaseName
                const std::string &getDatabaseName() const {
                    return databaseName;
                }

                // Get the value of tableName
                const std::string &getTableName() const {
                    return tableName;
                }

                // Get the value of indexName
                const std::string &getIndexName() const {
                    return indexName;
                }

                // Get the value of lastUpdate
                const std::string &getLastUpdate() const {
                    return lastUpdate;
                }

                // Get the value of statName
                const std::string &getStatName() const {
                    return statName;
                }

                // Get the value of statValue
                long getStatValue() const {
                    return statValue;
                }

                // Get the value of sampleSize
                long getSampleSize() const {
                    return sampleSize;
                }

                // Get the value of statDescription
                const std::string &getStatDescription() const {
                    return statDescription;
                }


                /**
                * Returns the table name 'innodb_index_stats';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_INNODB_INDEX_STATS_H