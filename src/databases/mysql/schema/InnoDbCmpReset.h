//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBCMPRESET_H
#define DBCRUDGEN_CPP_INNODBCMPRESET_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbCmpReset {

        private:
            int pageSize;
            int compressOps;
            int compressOpsOk;
            int compressTime;
            int uncompressOps;
            int uncompressTime;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_CMP_RESET";

            struct COLUMNS {
                struct PAGE_SIZE {
                    static constexpr const char *NAME = "page_size";
                    static const int INDEX = 1;
                };
                struct COMPRESS_OPS {
                    static constexpr const char *NAME = "compress_ops";
                    static const int INDEX = 2;
                };
                struct COMPRESS_OPS_OK {
                    static constexpr const char *NAME = "compress_ops_ok";
                    static const int INDEX = 3;
                };
                struct COMPRESS_TIME {
                    static constexpr const char *NAME = "compress_time";
                    static const int INDEX = 4;
                };
                struct UNCOMPRESS_OPS {
                    static constexpr const char *NAME = "uncompress_ops";
                    static const int INDEX = 5;
                };
                struct UNCOMPRESS_TIME {
                    static constexpr const char *NAME = "uncompress_time";
                    static const int INDEX = 6;
                };
            };

            InnoDbCmpReset(int pageSize, int compressOps, int compressOpsOk, int compressTime, int uncompressOps,
                           int uncompressTime) : pageSize{pageSize}, compressOps{compressOps},
                                                 compressOpsOk{compressOpsOk}, compressTime{compressTime},
                                                 uncompressOps{uncompressOps}, uncompressTime{uncompressTime} {}

            // Get the value of pageSize
            int getPageSize() const {
                return pageSize;
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
            * Returns the table name 'INNODB_CMP_RESET';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBCMPRESET_H
