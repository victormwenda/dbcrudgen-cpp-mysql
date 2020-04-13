//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBLOCKS_H
#define DBCRUDGEN_CPP_INNODBLOCKS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbLocks {

            private:
                std::string lockId;
                std::string lockTrxId;
                std::string lockMode;
                std::string lockType;
                std::string lockTable;
                std::string lockIndex;
                long lockSpace;
                long lockPage;
                long lockRec;
                std::string lockData;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_LOCKS";

                struct COLUMNS {
                    struct LOCK_ID {
                        static constexpr const char *NAME = "lock_id";
                        static const int INDEX = 1;
                    };
                    struct LOCK_TRX_ID {
                        static constexpr const char *NAME = "lock_trx_id";
                        static const int INDEX = 2;
                    };
                    struct LOCK_MODE {
                        static constexpr const char *NAME = "lock_mode";
                        static const int INDEX = 3;
                    };
                    struct LOCK_TYPE {
                        static constexpr const char *NAME = "lock_type";
                        static const int INDEX = 4;
                    };
                    struct LOCK_TABLE {
                        static constexpr const char *NAME = "lock_table";
                        static const int INDEX = 5;
                    };
                    struct LOCK_INDEX {
                        static constexpr const char *NAME = "lock_index";
                        static const int INDEX = 6;
                    };
                    struct LOCK_SPACE {
                        static constexpr const char *NAME = "lock_space";
                        static const int INDEX = 7;
                    };
                    struct LOCK_PAGE {
                        static constexpr const char *NAME = "lock_page";
                        static const int INDEX = 8;
                    };
                    struct LOCK_REC {
                        static constexpr const char *NAME = "lock_rec";
                        static const int INDEX = 9;
                    };
                    struct LOCK_DATA {
                        static constexpr const char *NAME = "lock_data";
                        static const int INDEX = 10;
                    };
                };

                InnoDbLocks(std::string &lockId, std::string &lockTrxId, std::string &lockMode, std::string &lockType,
                            std::string &lockTable, std::string &lockIndex, long lockSpace, long lockPage, long lockRec,
                            std::string &lockData) : lockId{lockId}, lockTrxId{lockTrxId}, lockMode{lockMode},
                                                     lockType{lockType}, lockTable{lockTable}, lockIndex{lockIndex},
                                                     lockSpace{lockSpace}, lockPage{lockPage}, lockRec{lockRec},
                                                     lockData{lockData} {}

                // Get the value of lockId
                const std::string &getLockId() const {
                    return lockId;
                }

                // Get the value of lockTrxId
                const std::string &getLockTrxId() const {
                    return lockTrxId;
                }

                // Get the value of lockMode
                const std::string &getLockMode() const {
                    return lockMode;
                }

                // Get the value of lockType
                const std::string &getLockType() const {
                    return lockType;
                }

                // Get the value of lockTable
                const std::string &getLockTable() const {
                    return lockTable;
                }

                // Get the value of lockIndex
                const std::string &getLockIndex() const {
                    return lockIndex;
                }

                // Get the value of lockSpace
                long getLockSpace() const {
                    return lockSpace;
                }

                // Get the value of lockPage
                long getLockPage() const {
                    return lockPage;
                }

                // Get the value of lockRec
                long getLockRec() const {
                    return lockRec;
                }

                // Get the value of lockData
                const std::string &getLockData() const {
                    return lockData;
                }


                /**
                * Returns the table name 'INNODB_LOCKS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBLOCKS_H
