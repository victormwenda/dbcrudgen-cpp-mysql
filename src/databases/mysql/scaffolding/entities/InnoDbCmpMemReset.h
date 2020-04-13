//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBCMPMEMRESET_H
#define DBCRUDGEN_CPP_INNODBCMPMEMRESET_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbCmpMemReset {

            private:
                int pageSize;
                int bufferPoolInstance;
                int pagesUsed;
                int pagesFree;
                long relocationOps;
                int relocationTime;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_CMPMEM_RESET";

                struct COLUMNS {
                    struct PAGE_SIZE {
                        static constexpr const char *NAME = "page_size";
                        static const int INDEX = 1;
                    };
                    struct BUFFER_POOL_INSTANCE {
                        static constexpr const char *NAME = "buffer_pool_instance";
                        static const int INDEX = 2;
                    };
                    struct PAGES_USED {
                        static constexpr const char *NAME = "pages_used";
                        static const int INDEX = 3;
                    };
                    struct PAGES_FREE {
                        static constexpr const char *NAME = "pages_free";
                        static const int INDEX = 4;
                    };
                    struct RELOCATION_OPS {
                        static constexpr const char *NAME = "relocation_ops";
                        static const int INDEX = 5;
                    };
                    struct RELOCATION_TIME {
                        static constexpr const char *NAME = "relocation_time";
                        static const int INDEX = 6;
                    };
                };

                InnoDbCmpMemReset(int pageSize, int bufferPoolInstance, int pagesUsed, int pagesFree,
                                  long relocationOps,
                                  int relocationTime) : pageSize{pageSize}, bufferPoolInstance{bufferPoolInstance},
                                                        pagesUsed{pagesUsed}, pagesFree{pagesFree},
                                                        relocationOps{relocationOps}, relocationTime{relocationTime} {}

                // Get the value of pageSize
                int getPageSize() const {
                    return pageSize;
                }

                // Get the value of bufferPoolInstance
                int getBufferPoolInstance() const {
                    return bufferPoolInstance;
                }

                // Get the value of pagesUsed
                int getPagesUsed() const {
                    return pagesUsed;
                }

                // Get the value of pagesFree
                int getPagesFree() const {
                    return pagesFree;
                }

                // Get the value of relocationOps
                long getRelocationOps() const {
                    return relocationOps;
                }

                // Get the value of relocationTime
                int getRelocationTime() const {
                    return relocationTime;
                }

                /**
                * Returns the table name 'INNODB_CMPMEM_RESET';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBCMPMEMRESET_H
