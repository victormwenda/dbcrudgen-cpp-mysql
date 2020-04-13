//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBLOCKWAITS_H
#define DBCRUDGEN_CPP_INNODBLOCKWAITS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbLockWaits {

            private:
                std::string requestingTrxId;
                std::string requestedLockId;
                std::string blockingTrxId;
                std::string blockingLockId;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_LOCK_WAITS";

                struct COLUMNS {
                    struct REQUESTING_TRX_ID {
                        static constexpr const char *NAME = "requesting_trx_id";
                        static const int INDEX = 1;
                    };
                    struct REQUESTED_LOCK_ID {
                        static constexpr const char *NAME = "requested_lock_id";
                        static const int INDEX = 2;
                    };
                    struct BLOCKING_TRX_ID {
                        static constexpr const char *NAME = "blocking_trx_id";
                        static const int INDEX = 3;
                    };
                    struct BLOCKING_LOCK_ID {
                        static constexpr const char *NAME = "blocking_lock_id";
                        static const int INDEX = 4;
                    };
                };

                InnoDbLockWaits(std::string &requestingTrxId, std::string &requestedLockId, std::string &blockingTrxId,
                                std::string &blockingLockId) : requestingTrxId{requestingTrxId},
                                                               requestedLockId{requestedLockId},
                                                               blockingTrxId{blockingTrxId},
                                                               blockingLockId{blockingLockId} {}

                // Get the value of requestingTrxId
                const std::string &getRequestingTrxId() const {
                    return requestingTrxId;
                }

                // Get the value of requestedLockId
                const std::string &getRequestedLockId() const {
                    return requestedLockId;
                }

                // Get the value of blockingTrxId
                const std::string &getBlockingTrxId() const {
                    return blockingTrxId;
                }

                // Get the value of blockingLockId
                const std::string &getBlockingLockId() const {
                    return blockingLockId;
                }

                /**
                * Returns the table name 'INNODB_LOCK_WAITS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBLOCKWAITS_H
