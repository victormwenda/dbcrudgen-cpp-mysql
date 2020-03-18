//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_FILES_H
#define DBCRUDGEN_CPP_FILES_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class Files {

        private:
            long fileId;
            std::string fileName;
            std::string fileType;
            std::string tablespaceName;
            std::string tableCatalog;
            std::string tableSchema;
            std::string tableName;
            std::string logfileGroupName;
            long logfileGroupNumber;
            std::string engine;
            std::string fulltextKeys;
            long deletedRows;
            long updateCount;
            long freeExtents;
            long totalExtents;
            long extentSize;
            long initialSize;
            long maximumSize;
            long autoextendSize;
            std::string creationTime;
            std::string lastUpdateTime;
            std::string lastAccessTime;
            long recoverTime;
            long transactionCounter;
            long version;
            std::string rowFormat;
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
            std::string status;
            std::string extra;

        public:

            static constexpr const char *TABLE_NAME = "FILES";

            struct COLUMNS {
                struct FILE_ID {
                    static constexpr const char *NAME = "FILE_ID";
                    static const int INDEX = 1;
                };
                struct FILE_NAME {
                    static constexpr const char *NAME = "FILE_NAME";
                    static const int INDEX = 2;
                };
                struct FILE_TYPE {
                    static constexpr const char *NAME = "FILE_TYPE";
                    static const int INDEX = 3;
                };
                struct TABLESPACE_NAME {
                    static constexpr const char *NAME = "TABLESPACE_NAME";
                    static const int INDEX = 4;
                };
                struct TABLE_CATALOG {
                    static constexpr const char *NAME = "TABLE_CATALOG";
                    static const int INDEX = 5;
                };
                struct TABLE_SCHEMA {
                    static constexpr const char *NAME = "TABLE_SCHEMA";
                    static const int INDEX = 6;
                };
                struct TABLE_NAME {
                    static constexpr const char *NAME = "TABLE_NAME";
                    static const int INDEX = 7;
                };
                struct LOGFILE_GROUP_NAME {
                    static constexpr const char *NAME = "LOGFILE_GROUP_NAME";
                    static const int INDEX = 8;
                };
                struct LOGFILE_GROUP_NUMBER {
                    static constexpr const char *NAME = "LOGFILE_GROUP_NUMBER";
                    static const int INDEX = 9;
                };
                struct ENGINE {
                    static constexpr const char *NAME = "ENGINE";
                    static const int INDEX = 10;
                };
                struct FULLTEXT_KEYS {
                    static constexpr const char *NAME = "FULLTEXT_KEYS";
                    static const int INDEX = 11;
                };
                struct DELETED_ROWS {
                    static constexpr const char *NAME = "DELETED_ROWS";
                    static const int INDEX = 12;
                };
                struct UPDATE_COUNT {
                    static constexpr const char *NAME = "UPDATE_COUNT";
                    static const int INDEX = 13;
                };
                struct FREE_EXTENTS {
                    static constexpr const char *NAME = "FREE_EXTENTS";
                    static const int INDEX = 14;
                };
                struct TOTAL_EXTENTS {
                    static constexpr const char *NAME = "TOTAL_EXTENTS";
                    static const int INDEX = 15;
                };
                struct EXTENT_SIZE {
                    static constexpr const char *NAME = "EXTENT_SIZE";
                    static const int INDEX = 16;
                };
                struct INITIAL_SIZE {
                    static constexpr const char *NAME = "INITIAL_SIZE";
                    static const int INDEX = 17;
                };
                struct MAXIMUM_SIZE {
                    static constexpr const char *NAME = "MAXIMUM_SIZE";
                    static const int INDEX = 18;
                };
                struct AUTOEXTEND_SIZE {
                    static constexpr const char *NAME = "AUTOEXTEND_SIZE";
                    static const int INDEX = 19;
                };
                struct CREATION_TIME {
                    static constexpr const char *NAME = "CREATION_TIME";
                    static const int INDEX = 20;
                };
                struct LAST_UPDATE_TIME {
                    static constexpr const char *NAME = "LAST_UPDATE_TIME";
                    static const int INDEX = 21;
                };
                struct LAST_ACCESS_TIME {
                    static constexpr const char *NAME = "LAST_ACCESS_TIME";
                    static const int INDEX = 22;
                };
                struct RECOVER_TIME {
                    static constexpr const char *NAME = "RECOVER_TIME";
                    static const int INDEX = 23;
                };
                struct TRANSACTION_COUNTER {
                    static constexpr const char *NAME = "TRANSACTION_COUNTER";
                    static const int INDEX = 24;
                };
                struct VERSION {
                    static constexpr const char *NAME = "VERSION";
                    static const int INDEX = 25;
                };
                struct ROW_FORMAT {
                    static constexpr const char *NAME = "ROW_FORMAT";
                    static const int INDEX = 26;
                };
                struct TABLE_ROWS {
                    static constexpr const char *NAME = "TABLE_ROWS";
                    static const int INDEX = 27;
                };
                struct AVG_ROW_LENGTH {
                    static constexpr const char *NAME = "AVG_ROW_LENGTH";
                    static const int INDEX = 28;
                };
                struct DATA_LENGTH {
                    static constexpr const char *NAME = "DATA_LENGTH";
                    static const int INDEX = 29;
                };
                struct MAX_DATA_LENGTH {
                    static constexpr const char *NAME = "MAX_DATA_LENGTH";
                    static const int INDEX = 30;
                };
                struct INDEX_LENGTH {
                    static constexpr const char *NAME = "INDEX_LENGTH";
                    static const int INDEX = 31;
                };
                struct DATA_FREE {
                    static constexpr const char *NAME = "DATA_FREE";
                    static const int INDEX = 32;
                };
                struct CREATE_TIME {
                    static constexpr const char *NAME = "CREATE_TIME";
                    static const int INDEX = 33;
                };
                struct UPDATE_TIME {
                    static constexpr const char *NAME = "UPDATE_TIME";
                    static const int INDEX = 34;
                };
                struct CHECK_TIME {
                    static constexpr const char *NAME = "CHECK_TIME";
                    static const int INDEX = 35;
                };
                struct CHECKSUM {
                    static constexpr const char *NAME = "CHECKSUM";
                    static const int INDEX = 36;
                };
                struct STATUS {
                    static constexpr const char *NAME = "STATUS";
                    static const int INDEX = 37;
                };
                struct EXTRA {
                    static constexpr const char *NAME = "EXTRA";
                    static const int INDEX = 38;
                };
            };

            Files(long fileId, std::string &fileName, std::string &fileType, std::string &tablespaceName,
                  std::string &tableCatalog, std::string &tableSchema, std::string &tableName,
                  std::string &logfileGroupName, long logfileGroupNumber, std::string &engine,
                  std::string &fulltextKeys, long deletedRows, long updateCount, long freeExtents, long totalExtents,
                  long extentSize, long initialSize, long maximumSize, long autoextendSize, std::string &creationTime,
                  std::string &lastUpdateTime, std::string &lastAccessTime, long recoverTime, long transactionCounter,
                  long version, std::string &rowFormat, long tableRows, long avgRowLength, long dataLength,
                  long maxDataLength, long indexLength, long dataFree, std::string &createTime, std::string &updateTime,
                  std::string &checkTime, long checksum, std::string &status, std::string &extra) : fileId{fileId},
                                                                                                    fileName{fileName},
                                                                                                    fileType{fileType},
                                                                                                    tablespaceName{
                                                                                                            tablespaceName},
                                                                                                    tableCatalog{
                                                                                                            tableCatalog},
                                                                                                    tableSchema{
                                                                                                            tableSchema},
                                                                                                    tableName{
                                                                                                            tableName},
                                                                                                    logfileGroupName{
                                                                                                            logfileGroupName},
                                                                                                    logfileGroupNumber{
                                                                                                            logfileGroupNumber},
                                                                                                    engine{engine},
                                                                                                    fulltextKeys{
                                                                                                            fulltextKeys},
                                                                                                    deletedRows{
                                                                                                            deletedRows},
                                                                                                    updateCount{
                                                                                                            updateCount},
                                                                                                    freeExtents{
                                                                                                            freeExtents},
                                                                                                    totalExtents{
                                                                                                            totalExtents},
                                                                                                    extentSize{
                                                                                                            extentSize},
                                                                                                    initialSize{
                                                                                                            initialSize},
                                                                                                    maximumSize{
                                                                                                            maximumSize},
                                                                                                    autoextendSize{
                                                                                                            autoextendSize},
                                                                                                    creationTime{
                                                                                                            creationTime},
                                                                                                    lastUpdateTime{
                                                                                                            lastUpdateTime},
                                                                                                    lastAccessTime{
                                                                                                            lastAccessTime},
                                                                                                    recoverTime{
                                                                                                            recoverTime},
                                                                                                    transactionCounter{
                                                                                                            transactionCounter},
                                                                                                    version{version},
                                                                                                    rowFormat{
                                                                                                            rowFormat},
                                                                                                    tableRows{
                                                                                                            tableRows},
                                                                                                    avgRowLength{
                                                                                                            avgRowLength},
                                                                                                    dataLength{
                                                                                                            dataLength},
                                                                                                    maxDataLength{
                                                                                                            maxDataLength},
                                                                                                    indexLength{
                                                                                                            indexLength},
                                                                                                    dataFree{dataFree},
                                                                                                    createTime{
                                                                                                            createTime},
                                                                                                    updateTime{
                                                                                                            updateTime},
                                                                                                    checkTime{
                                                                                                            checkTime},
                                                                                                    checksum{checksum},
                                                                                                    status{status},
                                                                                                    extra{extra} {}

            // Get the value of fileId
            long getFileId() const {
                return fileId;
            }

            // Get the value of fileName
            const std::string &getFileName() const {
                return fileName;
            }

            // Get the value of fileType
            const std::string &getFileType() const {
                return fileType;
            }

            // Get the value of tablespaceName
            const std::string &getTablespaceName() const {
                return tablespaceName;
            }

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

            // Get the value of logfileGroupName
            const std::string &getLogfileGroupName() const {
                return logfileGroupName;
            }

            // Get the value of logfileGroupNumber
            long getLogfileGroupNumber() const {
                return logfileGroupNumber;
            }

            // Get the value of engine
            const std::string &getEngine() const {
                return engine;
            }

            // Get the value of fulltextKeys
            const std::string &getFulltextKeys() const {
                return fulltextKeys;
            }

            // Get the value of deletedRows
            long getDeletedRows() const {
                return deletedRows;
            }

            // Get the value of updateCount
            long getUpdateCount() const {
                return updateCount;
            }

            // Get the value of freeExtents
            long getFreeExtents() const {
                return freeExtents;
            }

            // Get the value of totalExtents
            long getTotalExtents() const {
                return totalExtents;
            }

            // Get the value of extentSize
            long getExtentSize() const {
                return extentSize;
            }

            // Get the value of initialSize
            long getInitialSize() const {
                return initialSize;
            }

            // Get the value of maximumSize
            long getMaximumSize() const {
                return maximumSize;
            }

            // Get the value of autoextendSize
            long getAutoextendSize() const {
                return autoextendSize;
            }

            // Get the value of creationTime
            const std::string &getCreationTime() const {
                return creationTime;
            }

            // Get the value of lastUpdateTime
            const std::string &getLastUpdateTime() const {
                return lastUpdateTime;
            }

            // Get the value of lastAccessTime
            const std::string &getLastAccessTime() const {
                return lastAccessTime;
            }

            // Get the value of recoverTime
            long getRecoverTime() const {
                return recoverTime;
            }

            // Get the value of transactionCounter
            long getTransactionCounter() const {
                return transactionCounter;
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

            // Get the value of status
            const std::string &getStatus() const {
                return status;
            }

            // Get the value of extra
            const std::string &getExtra() const {
                return extra;
            }


            /**
            * Returns the table name 'FILES';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_FILES_H
