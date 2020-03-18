//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBBUFFERPAGELRU_H
#define DBCRUDGEN_CPP_INNODBBUFFERPAGELRU_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbBufferPageLRU {

        private:
            long poolId;
            long lruPosition;
            long space;
            long pageNumber;
            std::string pageType;
            long flushType;
            long fixCount;
            std::string isHashed;
            long newestModification;
            long oldestModification;
            long accessTime;
            std::string tableName;
            std::string indexName;
            long numberRecords;
            long dataSize;
            long compressedSize;
            std::string compressed;
            std::string ioFix;
            std::string isOld;
            long freePageClock;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_BUFFER_PAGE_LRU";

            struct COLUMNS {
                struct POOL_ID {
                    static constexpr const char *NAME = "POOL_ID";
                    static const int INDEX = 1;
                };
                struct LRU_POSITION {
                    static constexpr const char *NAME = "LRU_POSITION";
                    static const int INDEX = 2;
                };
                struct SPACE {
                    static constexpr const char *NAME = "SPACE";
                    static const int INDEX = 3;
                };
                struct PAGE_NUMBER {
                    static constexpr const char *NAME = "PAGE_NUMBER";
                    static const int INDEX = 4;
                };
                struct PAGE_TYPE {
                    static constexpr const char *NAME = "PAGE_TYPE";
                    static const int INDEX = 5;
                };
                struct FLUSH_TYPE {
                    static constexpr const char *NAME = "FLUSH_TYPE";
                    static const int INDEX = 6;
                };
                struct FIX_COUNT {
                    static constexpr const char *NAME = "FIX_COUNT";
                    static const int INDEX = 7;
                };
                struct IS_HASHED {
                    static constexpr const char *NAME = "IS_HASHED";
                    static const int INDEX = 8;
                };
                struct NEWEST_MODIFICATION {
                    static constexpr const char *NAME = "NEWEST_MODIFICATION";
                    static const int INDEX = 9;
                };
                struct OLDEST_MODIFICATION {
                    static constexpr const char *NAME = "OLDEST_MODIFICATION";
                    static const int INDEX = 10;
                };
                struct ACCESS_TIME {
                    static constexpr const char *NAME = "ACCESS_TIME";
                    static const int INDEX = 11;
                };
                struct TABLE_NAME {
                    static constexpr const char *NAME = "TABLE_NAME";
                    static const int INDEX = 12;
                };
                struct INDEX_NAME {
                    static constexpr const char *NAME = "INDEX_NAME";
                    static const int INDEX = 13;
                };
                struct NUMBER_RECORDS {
                    static constexpr const char *NAME = "NUMBER_RECORDS";
                    static const int INDEX = 14;
                };
                struct DATA_SIZE {
                    static constexpr const char *NAME = "DATA_SIZE";
                    static const int INDEX = 15;
                };
                struct COMPRESSED_SIZE {
                    static constexpr const char *NAME = "COMPRESSED_SIZE";
                    static const int INDEX = 16;
                };
                struct COMPRESSED {
                    static constexpr const char *NAME = "COMPRESSED";
                    static const int INDEX = 17;
                };
                struct IO_FIX {
                    static constexpr const char *NAME = "IO_FIX";
                    static const int INDEX = 18;
                };
                struct IS_OLD {
                    static constexpr const char *NAME = "IS_OLD";
                    static const int INDEX = 19;
                };
                struct FREE_PAGE_CLOCK {
                    static constexpr const char *NAME = "FREE_PAGE_CLOCK";
                    static const int INDEX = 20;
                };
            };

            InnoDbBufferPageLRU(long poolId, long lruPosition, long space, long pageNumber, std::string &pageType,
                                long flushType, long fixCount, std::string &isHashed, long newestModification,
                                long oldestModification, long accessTime, std::string &tableName,
                                std::string &indexName, long numberRecords, long dataSize, long compressedSize,
                                std::string &compressed, std::string &ioFix, std::string &isOld, long freePageClock)
                    : poolId{poolId}, lruPosition{lruPosition}, space{space}, pageNumber{pageNumber},
                      pageType{pageType}, flushType{flushType}, fixCount{fixCount}, isHashed{isHashed},
                      newestModification{newestModification}, oldestModification{oldestModification},
                      accessTime{accessTime}, tableName{tableName}, indexName{indexName}, numberRecords{numberRecords},
                      dataSize{dataSize}, compressedSize{compressedSize}, compressed{compressed}, ioFix{ioFix},
                      isOld{isOld}, freePageClock{freePageClock} {}

            // Get the value of poolId
            long getPoolId() const {
                return poolId;
            }

            // Get the value of lruPosition
            long getLruPosition() const {
                return lruPosition;
            }

            // Get the value of space
            long getSpace() const {
                return space;
            }

            // Get the value of pageNumber
            long getPageNumber() const {
                return pageNumber;
            }

            // Get the value of pageType
            const std::string &getPageType() const {
                return pageType;
            }

            // Get the value of flushType
            long getFlushType() const {
                return flushType;
            }

            // Get the value of fixCount
            long getFixCount() const {
                return fixCount;
            }

            // Get the value of isHashed
            const std::string &getIsHashed() const {
                return isHashed;
            }

            // Get the value of newestModification
            long getNewestModification() const {
                return newestModification;
            }

            // Get the value of oldestModification
            long getOldestModification() const {
                return oldestModification;
            }

            // Get the value of accessTime
            long getAccessTime() const {
                return accessTime;
            }

            // Get the value of tableName
            const std::string &getTableName() const {
                return tableName;
            }

            // Get the value of indexName
            const std::string &getIndexName() const {
                return indexName;
            }

            // Get the value of numberRecords
            long getNumberRecords() const {
                return numberRecords;
            }

            // Get the value of dataSize
            long getDataSize() const {
                return dataSize;
            }

            // Get the value of compressedSize
            long getCompressedSize() const {
                return compressedSize;
            }

            // Get the value of compressed
            const std::string &getCompressed() const {
                return compressed;
            }

            // Get the value of ioFix
            const std::string &getIoFix() const {
                return ioFix;
            }

            // Get the value of isOld
            const std::string &getIsOld() const {
                return isOld;
            }

            // Get the value of freePageClock
            long getFreePageClock() const {
                return freePageClock;
            }

            /**
            * Returns the table name 'INNODB_BUFFER_PAGE_LRU';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_INNODBBUFFERPAGELRU_H
