//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBBUFFERPOOLSTATS_H
#define DBCRUDGEN_CPP_INNODBBUFFERPOOLSTATS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbBufferPoolStats {

        private:
            long poolId;
            long poolSize;
            long freeBuffers;
            long databasePages;
            long oldDatabasePages;
            long modifiedDatabasePages;
            long pendingDecompress;
            long pendingReads;
            long pendingFlushLru;
            long pendingFlushList;
            long pagesMadeYoung;
            long pagesNotMadeYoung;
            long double pagesMadeYoungRate;
            long double pagesMadeNotYoungRate;
            long numberPagesRead;
            long numberPagesCreated;
            long numberPagesWritten;
            long double pagesReadRate;
            long double pagesCreateRate;
            long double pagesWrittenRate;
            long numberPagesGet;
            long hitRate;
            long youngMakePerThousandGets;
            long notYoungMakePerThousandGets;
            long numberPagesReadAhead;
            long numberReadAheadEvicted;
            long double readAheadRate;
            long double readAheadEvictedRate;
            long lruIoTotal;
            long lruIoCurrent;
            long uncompressTotal;
            long uncompressCurrent;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_BUFFER_POOL_STATS";

            struct COLUMNS {
                struct POOL_ID {
                    static constexpr const char *NAME = "POOL_ID";
                    static const int INDEX = 1;
                };
                struct POOL_SIZE {
                    static constexpr const char *NAME = "POOL_SIZE";
                    static const int INDEX = 2;
                };
                struct FREE_BUFFERS {
                    static constexpr const char *NAME = "FREE_BUFFERS";
                    static const int INDEX = 3;
                };
                struct DATABASE_PAGES {
                    static constexpr const char *NAME = "DATABASE_PAGES";
                    static const int INDEX = 4;
                };
                struct OLD_DATABASE_PAGES {
                    static constexpr const char *NAME = "OLD_DATABASE_PAGES";
                    static const int INDEX = 5;
                };
                struct MODIFIED_DATABASE_PAGES {
                    static constexpr const char *NAME = "MODIFIED_DATABASE_PAGES";
                    static const int INDEX = 6;
                };
                struct PENDING_DECOMPRESS {
                    static constexpr const char *NAME = "PENDING_DECOMPRESS";
                    static const int INDEX = 7;
                };
                struct PENDING_READS {
                    static constexpr const char *NAME = "PENDING_READS";
                    static const int INDEX = 8;
                };
                struct PENDING_FLUSH_LRU {
                    static constexpr const char *NAME = "PENDING_FLUSH_LRU";
                    static const int INDEX = 9;
                };
                struct PENDING_FLUSH_LIST {
                    static constexpr const char *NAME = "PENDING_FLUSH_LIST";
                    static const int INDEX = 10;
                };
                struct PAGES_MADE_YOUNG {
                    static constexpr const char *NAME = "PAGES_MADE_YOUNG";
                    static const int INDEX = 11;
                };
                struct PAGES_NOT_MADE_YOUNG {
                    static constexpr const char *NAME = "PAGES_NOT_MADE_YOUNG";
                    static const int INDEX = 12;
                };
                struct PAGES_MADE_YOUNG_RATE {
                    static constexpr const char *NAME = "PAGES_MADE_YOUNG_RATE";
                    static const int INDEX = 13;
                };
                struct PAGES_MADE_NOT_YOUNG_RATE {
                    static constexpr const char *NAME = "PAGES_MADE_NOT_YOUNG_RATE";
                    static const int INDEX = 14;
                };
                struct NUMBER_PAGES_READ {
                    static constexpr const char *NAME = "NUMBER_PAGES_READ";
                    static const int INDEX = 15;
                };
                struct NUMBER_PAGES_CREATED {
                    static constexpr const char *NAME = "NUMBER_PAGES_CREATED";
                    static const int INDEX = 16;
                };
                struct NUMBER_PAGES_WRITTEN {
                    static constexpr const char *NAME = "NUMBER_PAGES_WRITTEN";
                    static const int INDEX = 17;
                };
                struct PAGES_READ_RATE {
                    static constexpr const char *NAME = "PAGES_READ_RATE";
                    static const int INDEX = 18;
                };
                struct PAGES_CREATE_RATE {
                    static constexpr const char *NAME = "PAGES_CREATE_RATE";
                    static const int INDEX = 19;
                };
                struct PAGES_WRITTEN_RATE {
                    static constexpr const char *NAME = "PAGES_WRITTEN_RATE";
                    static const int INDEX = 20;
                };
                struct NUMBER_PAGES_GET {
                    static constexpr const char *NAME = "NUMBER_PAGES_GET";
                    static const int INDEX = 21;
                };
                struct HIT_RATE {
                    static constexpr const char *NAME = "HIT_RATE";
                    static const int INDEX = 22;
                };
                struct YOUNG_MAKE_PER_THOUSAND_GETS {
                    static constexpr const char *NAME = "YOUNG_MAKE_PER_THOUSAND_GETS";
                    static const int INDEX = 23;
                };
                struct NOT_YOUNG_MAKE_PER_THOUSAND_GETS {
                    static constexpr const char *NAME = "NOT_YOUNG_MAKE_PER_THOUSAND_GETS";
                    static const int INDEX = 24;
                };
                struct NUMBER_PAGES_READ_AHEAD {
                    static constexpr const char *NAME = "NUMBER_PAGES_READ_AHEAD";
                    static const int INDEX = 25;
                };
                struct NUMBER_READ_AHEAD_EVICTED {
                    static constexpr const char *NAME = "NUMBER_READ_AHEAD_EVICTED";
                    static const int INDEX = 26;
                };
                struct READ_AHEAD_RATE {
                    static constexpr const char *NAME = "READ_AHEAD_RATE";
                    static const int INDEX = 27;
                };
                struct READ_AHEAD_EVICTED_RATE {
                    static constexpr const char *NAME = "READ_AHEAD_EVICTED_RATE";
                    static const int INDEX = 28;
                };
                struct LRU_IO_TOTAL {
                    static constexpr const char *NAME = "LRU_IO_TOTAL";
                    static const int INDEX = 29;
                };
                struct LRU_IO_CURRENT {
                    static constexpr const char *NAME = "LRU_IO_CURRENT";
                    static const int INDEX = 30;
                };
                struct UNCOMPRESS_TOTAL {
                    static constexpr const char *NAME = "UNCOMPRESS_TOTAL";
                    static const int INDEX = 31;
                };
                struct UNCOMPRESS_CURRENT {
                    static constexpr const char *NAME = "UNCOMPRESS_CURRENT";
                    static const int INDEX = 32;
                };
            };

            InnoDbBufferPoolStats(long poolId, long poolSize, long freeBuffers, long databasePages,
                                  long oldDatabasePages, long modifiedDatabasePages, long pendingDecompress,
                                  long pendingReads, long pendingFlushLru, long pendingFlushList, long pagesMadeYoung,
                                  long pagesNotMadeYoung, long double pagesMadeYoungRate,
                                  long double pagesMadeNotYoungRate, long numberPagesRead, long numberPagesCreated,
                                  long numberPagesWritten, long double pagesReadRate, long double pagesCreateRate,
                                  long double pagesWrittenRate, long numberPagesGet, long hitRate,
                                  long youngMakePerThousandGets, long notYoungMakePerThousandGets,
                                  long numberPagesReadAhead, long numberReadAheadEvicted, long double readAheadRate,
                                  long double readAheadEvictedRate, long lruIoTotal, long lruIoCurrent,
                                  long uncompressTotal, long uncompressCurrent) : poolId{poolId}, poolSize{poolSize},
                                                                                  freeBuffers{freeBuffers},
                                                                                  databasePages{databasePages},
                                                                                  oldDatabasePages{oldDatabasePages},
                                                                                  modifiedDatabasePages{
                                                                                          modifiedDatabasePages},
                                                                                  pendingDecompress{pendingDecompress},
                                                                                  pendingReads{pendingReads},
                                                                                  pendingFlushLru{pendingFlushLru},
                                                                                  pendingFlushList{pendingFlushList},
                                                                                  pagesMadeYoung{pagesMadeYoung},
                                                                                  pagesNotMadeYoung{pagesNotMadeYoung},
                                                                                  pagesMadeYoungRate{
                                                                                          pagesMadeYoungRate},
                                                                                  pagesMadeNotYoungRate{
                                                                                          pagesMadeNotYoungRate},
                                                                                  numberPagesRead{numberPagesRead},
                                                                                  numberPagesCreated{
                                                                                          numberPagesCreated},
                                                                                  numberPagesWritten{
                                                                                          numberPagesWritten},
                                                                                  pagesReadRate{pagesReadRate},
                                                                                  pagesCreateRate{pagesCreateRate},
                                                                                  pagesWrittenRate{pagesWrittenRate},
                                                                                  numberPagesGet{numberPagesGet},
                                                                                  hitRate{hitRate},
                                                                                  youngMakePerThousandGets{
                                                                                          youngMakePerThousandGets},
                                                                                  notYoungMakePerThousandGets{
                                                                                          notYoungMakePerThousandGets},
                                                                                  numberPagesReadAhead{
                                                                                          numberPagesReadAhead},
                                                                                  numberReadAheadEvicted{
                                                                                          numberReadAheadEvicted},
                                                                                  readAheadRate{readAheadRate},
                                                                                  readAheadEvictedRate{
                                                                                          readAheadEvictedRate},
                                                                                  lruIoTotal{lruIoTotal},
                                                                                  lruIoCurrent{lruIoCurrent},
                                                                                  uncompressTotal{uncompressTotal},
                                                                                  uncompressCurrent{
                                                                                          uncompressCurrent} {}

            // Get the value of poolId
            long getPoolId() const {
                return poolId;
            }

            // Get the value of poolSize
            long getPoolSize() const {
                return poolSize;
            }

            // Get the value of freeBuffers
            long getFreeBuffers() const {
                return freeBuffers;
            }

            // Get the value of databasePages
            long getDatabasePages() const {
                return databasePages;
            }

            // Get the value of oldDatabasePages
            long getOldDatabasePages() const {
                return oldDatabasePages;
            }

            // Get the value of modifiedDatabasePages
            long getModifiedDatabasePages() const {
                return modifiedDatabasePages;
            }

            // Get the value of pendingDecompress
            long getPendingDecompress() const {
                return pendingDecompress;
            }

            // Get the value of pendingReads
            long getPendingReads() const {
                return pendingReads;
            }

            // Get the value of pendingFlushLru
            long getPendingFlushLru() const {
                return pendingFlushLru;
            }

            // Get the value of pendingFlushList
            long getPendingFlushList() const {
                return pendingFlushList;
            }

            // Get the value of pagesMadeYoung
            long getPagesMadeYoung() const {
                return pagesMadeYoung;
            }

            // Get the value of pagesNotMadeYoung
            long getPagesNotMadeYoung() const {
                return pagesNotMadeYoung;
            }

            // Get the value of pagesMadeYoungRate
            long double getPagesMadeYoungRate() const {
                return pagesMadeYoungRate;
            }

            // Get the value of pagesMadeNotYoungRate
            long double getPagesMadeNotYoungRate() const {
                return pagesMadeNotYoungRate;
            }

            // Get the value of numberPagesRead
            long getNumberPagesRead() const {
                return numberPagesRead;
            }

            // Get the value of numberPagesCreated
            long getNumberPagesCreated() const {
                return numberPagesCreated;
            }

            // Get the value of numberPagesWritten
            long getNumberPagesWritten() const {
                return numberPagesWritten;
            }

            // Get the value of pagesReadRate
            long double getPagesReadRate() const {
                return pagesReadRate;
            }

            // Get the value of pagesCreateRate
            long double getPagesCreateRate() const {
                return pagesCreateRate;
            }

            // Get the value of pagesWrittenRate
            long double getPagesWrittenRate() const {
                return pagesWrittenRate;
            }

            // Get the value of numberPagesGet
            long getNumberPagesGet() const {
                return numberPagesGet;
            }

            // Get the value of hitRate
            long getHitRate() const {
                return hitRate;
            }

            // Get the value of youngMakePerThousandGets
            long getYoungMakePerThousandGets() const {
                return youngMakePerThousandGets;
            }

            // Get the value of notYoungMakePerThousandGets
            long getNotYoungMakePerThousandGets() const {
                return notYoungMakePerThousandGets;
            }

            // Get the value of numberPagesReadAhead
            long getNumberPagesReadAhead() const {
                return numberPagesReadAhead;
            }

            // Get the value of numberReadAheadEvicted
            long getNumberReadAheadEvicted() const {
                return numberReadAheadEvicted;
            }

            // Get the value of readAheadRate
            long double getReadAheadRate() const {
                return readAheadRate;
            }

            // Get the value of readAheadEvictedRate
            long double getReadAheadEvictedRate() const {
                return readAheadEvictedRate;
            }

            // Get the value of lruIoTotal
            long getLruIoTotal() const {
                return lruIoTotal;
            }

            // Get the value of lruIoCurrent
            long getLruIoCurrent() const {
                return lruIoCurrent;
            }

            // Get the value of uncompressTotal
            long getUncompressTotal() const {
                return uncompressTotal;
            }

            // Get the value of uncompressCurrent
            long getUncompressCurrent() const {
                return uncompressCurrent;
            }

            /**
            * Returns the table name 'INNODB_BUFFER_POOL_STATS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_INNODBBUFFERPOOLSTATS_H
