//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBTRX_H
#define DBCRUDGEN_CPP_INNODBTRX_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbTrx {

        private:
            std::string trxId;
            std::string trxState;
            std::string trxStarted;
            std::string trxRequestedLockId;
            std::string trxWaitStarted;
            long trxWeight;
            long trxMysqlThreadId;
            std::string trxQuery;
            std::string trxOperationState;
            long trxTablesInUse;
            long trxTablesLocked;
            long trxLockStructs;
            long trxLockMemoryBytes;
            long trxRowsLocked;
            long trxRowsModified;
            long trxConcurrencyTickets;
            std::string trxIsolationLevel;
            int trxUniqueChecks;
            int trxForeignKeyChecks;
            std::string trxLastForeignKeyError;
            int trxAdaptiveHashLatched;
            long trxAdaptiveHashTimeout;
            int trxIsReadOnly;
            int trxAutocommitNonLocking;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_TRX";

            struct COLUMNS {
                struct TRX_ID {
                    static constexpr const char *NAME = "trx_id";
                    static const int INDEX = 1;
                };
                struct TRX_STATE {
                    static constexpr const char *NAME = "trx_state";
                    static const int INDEX = 2;
                };
                struct TRX_STARTED {
                    static constexpr const char *NAME = "trx_started";
                    static const int INDEX = 3;
                };
                struct TRX_REQUESTED_LOCK_ID {
                    static constexpr const char *NAME = "trx_requested_lock_id";
                    static const int INDEX = 4;
                };
                struct TRX_WAIT_STARTED {
                    static constexpr const char *NAME = "trx_wait_started";
                    static const int INDEX = 5;
                };
                struct TRX_WEIGHT {
                    static constexpr const char *NAME = "trx_weight";
                    static const int INDEX = 6;
                };
                struct TRX_MYSQL_THREAD_ID {
                    static constexpr const char *NAME = "trx_mysql_thread_id";
                    static const int INDEX = 7;
                };
                struct TRX_QUERY {
                    static constexpr const char *NAME = "trx_query";
                    static const int INDEX = 8;
                };
                struct TRX_OPERATION_STATE {
                    static constexpr const char *NAME = "trx_operation_state";
                    static const int INDEX = 9;
                };
                struct TRX_TABLES_IN_USE {
                    static constexpr const char *NAME = "trx_tables_in_use";
                    static const int INDEX = 10;
                };
                struct TRX_TABLES_LOCKED {
                    static constexpr const char *NAME = "trx_tables_locked";
                    static const int INDEX = 11;
                };
                struct TRX_LOCK_STRUCTS {
                    static constexpr const char *NAME = "trx_lock_structs";
                    static const int INDEX = 12;
                };
                struct TRX_LOCK_MEMORY_BYTES {
                    static constexpr const char *NAME = "trx_lock_memory_bytes";
                    static const int INDEX = 13;
                };
                struct TRX_ROWS_LOCKED {
                    static constexpr const char *NAME = "trx_rows_locked";
                    static const int INDEX = 14;
                };
                struct TRX_ROWS_MODIFIED {
                    static constexpr const char *NAME = "trx_rows_modified";
                    static const int INDEX = 15;
                };
                struct TRX_CONCURRENCY_TICKETS {
                    static constexpr const char *NAME = "trx_concurrency_tickets";
                    static const int INDEX = 16;
                };
                struct TRX_ISOLATION_LEVEL {
                    static constexpr const char *NAME = "trx_isolation_level";
                    static const int INDEX = 17;
                };
                struct TRX_UNIQUE_CHECKS {
                    static constexpr const char *NAME = "trx_unique_checks";
                    static const int INDEX = 18;
                };
                struct TRX_FOREIGN_KEY_CHECKS {
                    static constexpr const char *NAME = "trx_foreign_key_checks";
                    static const int INDEX = 19;
                };
                struct TRX_LAST_FOREIGN_KEY_ERROR {
                    static constexpr const char *NAME = "trx_last_foreign_key_error";
                    static const int INDEX = 20;
                };
                struct TRX_ADAPTIVE_HASH_LATCHED {
                    static constexpr const char *NAME = "trx_adaptive_hash_latched";
                    static const int INDEX = 21;
                };
                struct TRX_ADAPTIVE_HASH_TIMEOUT {
                    static constexpr const char *NAME = "trx_adaptive_hash_timeout";
                    static const int INDEX = 22;
                };
                struct TRX_IS_READ_ONLY {
                    static constexpr const char *NAME = "trx_is_read_only";
                    static const int INDEX = 23;
                };
                struct TRX_AUTOCOMMIT_NON_LOCKING {
                    static constexpr const char *NAME = "trx_autocommit_non_locking";
                    static const int INDEX = 24;
                };
            };

            InnoDbTrx(std::string &trxId, std::string &trxState, std::string &trxStarted,
                      std::string &trxRequestedLockId, std::string &trxWaitStarted, long trxWeight,
                      long trxMysqlThreadId, std::string &trxQuery, std::string &trxOperationState, long trxTablesInUse,
                      long trxTablesLocked, long trxLockStructs, long trxLockMemoryBytes, long trxRowsLocked,
                      long trxRowsModified, long trxConcurrencyTickets, std::string &trxIsolationLevel,
                      int trxUniqueChecks, int trxForeignKeyChecks, std::string &trxLastForeignKeyError,
                      int trxAdaptiveHashLatched, long trxAdaptiveHashTimeout, int trxIsReadOnly,
                      int trxAutocommitNonLocking) : trxId{trxId}, trxState{trxState}, trxStarted{trxStarted},
                                                     trxRequestedLockId{trxRequestedLockId},
                                                     trxWaitStarted{trxWaitStarted}, trxWeight{trxWeight},
                                                     trxMysqlThreadId{trxMysqlThreadId}, trxQuery{trxQuery},
                                                     trxOperationState{trxOperationState},
                                                     trxTablesInUse{trxTablesInUse}, trxTablesLocked{trxTablesLocked},
                                                     trxLockStructs{trxLockStructs},
                                                     trxLockMemoryBytes{trxLockMemoryBytes},
                                                     trxRowsLocked{trxRowsLocked}, trxRowsModified{trxRowsModified},
                                                     trxConcurrencyTickets{trxConcurrencyTickets},
                                                     trxIsolationLevel{trxIsolationLevel},
                                                     trxUniqueChecks{trxUniqueChecks},
                                                     trxForeignKeyChecks{trxForeignKeyChecks},
                                                     trxLastForeignKeyError{trxLastForeignKeyError},
                                                     trxAdaptiveHashLatched{trxAdaptiveHashLatched},
                                                     trxAdaptiveHashTimeout{trxAdaptiveHashTimeout},
                                                     trxIsReadOnly{trxIsReadOnly},
                                                     trxAutocommitNonLocking{trxAutocommitNonLocking} {}

            // Get the value of trxId
            const std::string &getTrxId() const {
                return trxId;
            }

            // Get the value of trxState
            const std::string &getTrxState() const {
                return trxState;
            }

            // Get the value of trxStarted
            const std::string &getTrxStarted() const {
                return trxStarted;
            }

            // Get the value of trxRequestedLockId
            const std::string &getTrxRequestedLockId() const {
                return trxRequestedLockId;
            }

            // Get the value of trxWaitStarted
            const std::string &getTrxWaitStarted() const {
                return trxWaitStarted;
            }

            // Get the value of trxWeight
            long getTrxWeight() const {
                return trxWeight;
            }

            // Get the value of trxMysqlThreadId
            long getTrxMysqlThreadId() const {
                return trxMysqlThreadId;
            }

            // Get the value of trxQuery
            const std::string &getTrxQuery() const {
                return trxQuery;
            }

            // Get the value of trxOperationState
            const std::string &getTrxOperationState() const {
                return trxOperationState;
            }

            // Get the value of trxTablesInUse
            long getTrxTablesInUse() const {
                return trxTablesInUse;
            }

            // Get the value of trxTablesLocked
            long getTrxTablesLocked() const {
                return trxTablesLocked;
            }

            // Get the value of trxLockStructs
            long getTrxLockStructs() const {
                return trxLockStructs;
            }

            // Get the value of trxLockMemoryBytes
            long getTrxLockMemoryBytes() const {
                return trxLockMemoryBytes;
            }

            // Get the value of trxRowsLocked
            long getTrxRowsLocked() const {
                return trxRowsLocked;
            }

            // Get the value of trxRowsModified
            long getTrxRowsModified() const {
                return trxRowsModified;
            }

            // Get the value of trxConcurrencyTickets
            long getTrxConcurrencyTickets() const {
                return trxConcurrencyTickets;
            }

            // Get the value of trxIsolationLevel
            const std::string &getTrxIsolationLevel() const {
                return trxIsolationLevel;
            }

            // Get the value of trxUniqueChecks
            int getTrxUniqueChecks() const {
                return trxUniqueChecks;
            }

            // Get the value of trxForeignKeyChecks
            int getTrxForeignKeyChecks() const {
                return trxForeignKeyChecks;
            }

            // Get the value of trxLastForeignKeyError
            const std::string &getTrxLastForeignKeyError() const {
                return trxLastForeignKeyError;
            }

            // Get the value of trxAdaptiveHashLatched
            int getTrxAdaptiveHashLatched() const {
                return trxAdaptiveHashLatched;
            }

            // Get the value of trxAdaptiveHashTimeout
            long getTrxAdaptiveHashTimeout() const {
                return trxAdaptiveHashTimeout;
            }

            // Get the value of trxIsReadOnly
            int getTrxIsReadOnly() const {
                return trxIsReadOnly;
            }

            // Get the value of trxAutocommitNonLocking
            int getTrxAutocommitNonLocking() const {
                return trxAutocommitNonLocking;
            }

            /**
            * Returns the table name 'INNODB_TRX';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_INNODBTRX_H
