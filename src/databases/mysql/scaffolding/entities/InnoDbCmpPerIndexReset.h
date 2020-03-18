//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBCMPPERINDEXRESET_H
#define DBCRUDGEN_CPP_INNODBCMPPERINDEXRESET_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbCmpPerIndexReset {

        private:
            std::string databaseName;
            std::string tableName;
            std::string indexName;
            int compressOps;
            int compressOpsOk;
            int compressTime;
            int uncompressOps;
            int uncompressTime;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_CMP_PER_INDEX_RESET";

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
                struct COMPRESS_OPS {
                    static constexpr const char *NAME = "compress_ops";
                    static const int INDEX = 4;
                };
                struct COMPRESS_OPS_OK {
                    static constexpr const char *NAME = "compress_ops_ok";
                    static const int INDEX = 5;
                };
                struct COMPRESS_TIME {
                    static constexpr const char *NAME = "compress_time";
                    static const int INDEX = 6;
                };
                struct UNCOMPRESS_OPS {
                    static constexpr const char *NAME = "uncompress_ops";
                    static const int INDEX = 7;
                };
                struct UNCOMPRESS_TIME {
                    static constexpr const char *NAME = "uncompress_time";
                    static const int INDEX = 8;
                };
            };

            InnoDbCmpPerIndexReset (std::string
            & databaseName ,
            std::string &tableName, std::string
            & indexName ,
            int compressOps,
            int compressOpsOk,
            int compressTime,
            int uncompressOps,
            int uncompressTime
            ) : databaseName{ databaseName } ,tableName{ tableName } ,indexName{ indexName } ,compressOps{ compressOps } ,compressOpsOk{ compressOpsOk } ,compressTime{ compressTime } ,uncompressOps{ uncompressOps } ,uncompressTime{ uncompressTime }  {}

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

            // Get the value of compressOps
            int getCompressOps() const {
                return compressOps;
            }

            // Get the value of compressOpsOk
            int getCompressOpsOk() const {
                return compressOpsOk;
            }

            // Get the value of compressTime
            int getCompressTime() const {
                return compressTime;
            }

            // Get the value of uncompressOps
            int getUncompressOps() const {
                return uncompressOps;
            }

            // Get the value of uncompressTime
            int getUncompressTime() const {
                return uncompressTime;
            }

            /**
            * Returns the table name 'INNODB_CMP_PER_INDEX_RESET';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBCMPPERINDEXRESET_H
