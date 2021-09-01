//
// Created by victor on 8/31/21.
//

#ifndef DBCRUDGEN_CPP_SYSDATABASES_H
#define DBCRUDGEN_CPP_SYSDATABASES_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            /**
             * SysDatabases
             * Represents the table sys.databases;
             */
            class SysDatabases {
            private:
                std::string name;
                int database_id;
                int source_database_id;
                std::string owner_sid;
                std::string create_date;
                int compatibility_level;
                std::string collation_name;
                int user_access;
                std::string user_access_desc;
                bool is_read_only;
                bool is_auto_close_on;
                bool is_auto_shrink_on;
                int state;
                std::string state_desc;
                bool is_in_standby;
                bool is_cleanly_shutdown;
                bool is_supplemental_logging_enabled;
                int snapshot_isolation_state;
                std::string snapshot_isolation_state_desc;
                bool is_read_committed_snapshot_on;
                int recovery_model;
                std::string recovery_model_desc;
                int page_verify_option;
                std::string page_verify_option_desc;
                bool is_auto_create_stats_on;
                bool is_auto_create_stats_incremental_on;
                bool is_auto_update_stats_on;
                bool is_auto_update_stats_async_on;
                bool is_ansi_null_default_on;
                bool is_ansi_nulls_on;
                bool is_ansi_padding_on;
                bool is_ansi_warnings_on;
                bool is_arithabort_on;
                bool is_concat_null_yields_null_on;
                bool is_numeric_roundabort_on;
                bool is_quoted_identifier_on;
                bool is_recursive_triggers_on;
                bool is_cursor_close_on_commit_on;
                bool is_local_cursor_default;
                bool is_fulltext_enabled;
                bool is_trustworthy_on;
                bool is_db_chaining_on;
                bool is_parameterization_forced;
                bool is_master_key_encrypted_by_server;
                bool is_query_store_on;
                bool is_published;
                bool is_subscribed;
                bool is_merge_published;
                bool is_distributor;
                bool is_sync_with_backup;
                std::string service_broker_guid;
                bool is_broker_enabled;
                int log_reuse_wait;
                std::string log_reuse_wait_desc;
                bool is_date_correlation_on;
                bool is_cdc_enabled;
                bool is_encrypted;
                bool is_honor_broker_priority_on;
                std::string replica_id;
                std::string group_database_id;
                int resource_pool_id;
                int default_language_lcid;
                std::string default_language_name;
                int default_fulltext_language_lcid;
                std::string default_fulltext_language_name;
                bool is_nested_triggers_on;
                bool is_transform_noise_words_on;
                int two_digit_year_cutoff;
                int containment;
                std::string containment_desc;
                int target_recovery_time_in_seconds;
                int delayed_durability;
                std::string delayed_durability_desc;
                bool is_memory_optimized_elevate_to_snapshot_on;
                bool is_federation_member;
                bool is_remote_data_archive_enabled;
                bool is_mixed_page_allocation_on;
                bool is_temporal_history_retention_enabled;
            public:
                static constexpr const char *TABLE_NAME = "sys.databases";

                struct COLUMNS {
                    struct NAME {
                        static constexpr const char *NAME_ = "name";
                        static const int INDEX = 1;
                        static constexpr const char *DATA_TYPE = "sysname";
                    };
                    struct DATABASE_ID {
                        static constexpr const char *NAME = "database_id";
                        static const int INDEX = 2;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct SOURCE_DATABASE_ID {
                        static constexpr const char *NAME = "source_database_id";
                        static const int INDEX = 3;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct OWNER_SID {
                        static constexpr const char *NAME = "owner_sid";
                        static const int INDEX = 4;
                        static constexpr const char *DATA_TYPE = "varbinary";
                    };
                    struct CREATE_DATE {
                        static constexpr const char *NAME = "create_date";
                        static const int INDEX = 5;
                        static constexpr const char *DATA_TYPE = "datetime";
                    };
                    struct COMPATIBILITY_LEVEL {
                        static constexpr const char *NAME = "compatibility_level";
                        static const int INDEX = 6;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                    struct COLLATION_NAME {
                        static constexpr const char *NAME = "collation_name";
                        static const int INDEX = 6;
                        static constexpr const char *DATA_TYPE = "sysname";
                    };
                    struct USER_ACCESS {
                        static constexpr const char *NAME = "user_access";
                        static const int INDEX = 7;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                    struct USER_ACCESS_DESC {
                        static constexpr const char *NAME = "user_access_desc";
                        static const int INDEX = 8;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct IS_READ_ONLY {
                        static constexpr const char *NAME = "is_read_only";
                        static const int INDEX = 9;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_AUTO_CLOSE_ON {
                        static constexpr const char *NAME = "is_auto_close_on";
                        static const int INDEX = 10;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_AUTO_SHRINK_ON {
                        static constexpr const char *NAME = "is_auto_shrink_on";
                        static const int INDEX = 11;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct STATE {
                        static constexpr const char *NAME = "state";
                        static const int INDEX = 12;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                    struct STATE_DESC {
                        static constexpr const char *NAME = "state_desc";
                        static const int INDEX = 13;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct IS_IN_STANDBY {
                        static constexpr const char *NAME = "is_in_standby";
                        static const int INDEX = 14;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_CLEANLY_SHUTDOWN {
                        static constexpr const char *NAME = "is_cleanly_shutdown";
                        static const int INDEX = 15;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_SUPPLEMENTAL_LOGGING_ENABLED {
                        static constexpr const char *NAME = "is_supplemental_logging_enabled";
                        static const int INDEX = 16;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct SNAPSHOT_ISOLATION_STATE {
                        static constexpr const char *NAME = "snapshot_isolation_state";
                        static const int INDEX = 17;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                    struct SNAPSHOT_ISOLATION_STATE_DESC {
                        static constexpr const char *NAME = "snapshot_isolation_state_desc";
                        static const int INDEX = 18;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct IS_READ_COMMITTED_SNAPSHOT_ON {
                        static constexpr const char *NAME = "is_read_committed_snapshot_on";
                        static const int INDEX = 19;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct RECOVERY_MODEL {
                        static constexpr const char *NAME = "recovery_model";
                        static const int INDEX = 20;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                    struct RECOVERY_MODEL_DESC {
                        static constexpr const char *NAME = "recovery_model_desc";
                        static const int INDEX = 21;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct PAGE_VERIFY_OPTION {
                        static constexpr const char *NAME = "page_verify_option";
                        static const int INDEX = 22;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                    struct PAGE_VERIFY_OPTION_DESC {
                        static constexpr const char *NAME = "page_verify_option_desc";
                        static const int INDEX = 23;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct IS_AUTO_CREATE_STATS_ON {
                        static constexpr const char *NAME = "is_auto_create_stats_on";
                        static const int INDEX = 24;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_AUTO_CREATE_STATS_INCREMENTAL_ON {
                        static constexpr const char *NAME = "is_auto_create_stats_incremental_on";
                        static const int INDEX = 25;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_AUTO_UPDATE_STATS_ON {
                        static constexpr const char *NAME = "is_auto_update_stats_on";
                        static const int INDEX = 26;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_AUTO_UPDATE_STATS_ASYNC_ON {
                        static constexpr const char *NAME = "is_auto_update_stats_async_on";
                        static const int INDEX = 27;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_ANSI_NULL_DEFAULT_ON {
                        static constexpr const char *NAME = "is_ansi_null_default_on";
                        static const int INDEX = 28;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_ANSI_NULLS_ON {
                        static constexpr const char *NAME = "is_ansi_nulls_on";
                        static const int INDEX = 29;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_ANSI_PADDING_ON {
                        static constexpr const char *NAME = "is_ansi_padding_on";
                        static const int INDEX = 30;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_ANSI_WARNINGS_ON {
                        static constexpr const char *NAME = "is_ansi_warnings_on";
                        static const int INDEX = 31;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_ARITHABORT_ON {
                        static constexpr const char *NAME = "is_arithabort_on";
                        static const int INDEX = 32;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_CONCAT_NULL_YIELDS_NULL_ON {
                        static constexpr const char *NAME = "is_concat_null_yields_null_on";
                        static const int INDEX = 33;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_NUMERIC_ROUNDABORT_ON {
                        static constexpr const char *NAME = "is_numeric_roundabort_on";
                        static const int INDEX = 34;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_QUOTED_IDENTIFIER_ON {
                        static constexpr const char *NAME = "is_quoted_identifier_on";
                        static const int INDEX = 35;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_RECURSIVE_TRIGGERS_ON {
                        static constexpr const char *NAME = "is_recursive_triggers_on";
                        static const int INDEX = 36;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_CURSOR_CLOSE_ON_COMMIT_ON {
                        static constexpr const char *NAME = "is_cursor_close_on_commit_on";
                        static const int INDEX = 37;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_LOCAL_CURSOR_DEFAULT {
                        static constexpr const char *NAME = "is_local_cursor_default";
                        static const int INDEX = 38;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_FULLTEXT_ENABLED {
                        static constexpr const char *NAME = "is_fulltext_enabled";
                        static const int INDEX = 39;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_TRUSTWORTHY_ON {
                        static constexpr const char *NAME = "is_trustworthy_on";
                        static const int INDEX = 40;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_DB_CHAINING_ON {
                        static constexpr const char *NAME = "is_db_chaining_on";
                        static const int INDEX = 41;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_PARAMETERIZATION_FORCED {
                        static constexpr const char *NAME = "is_parameterization_forced";
                        static const int INDEX = 42;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_MASTER_KEY_ENCRYPTED_BY_SERVER {
                        static constexpr const char *NAME = "is_master_key_encrypted_by_server";
                        static const int INDEX = 43;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_QUERY_STORE_ON {
                        static constexpr const char *NAME = "is_query_store_on";
                        static const int INDEX = 44;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_PUBLISHED {
                        static constexpr const char *NAME = "is_published";
                        static const int INDEX = 45;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_SUBSCRIBED {
                        static constexpr const char *NAME = "is_subscribed";
                        static const int INDEX = 46;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_MERGE_PUBLISHED {
                        static constexpr const char *NAME = "is_merge_published";
                        static const int INDEX = 47;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_DISTRIBUTOR {
                        static constexpr const char *NAME = "is_distributor";
                        static const int INDEX = 48;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_SYNC_WITH_BACKUP {
                        static constexpr const char *NAME = "is_sync_with_backup";
                        static const int INDEX = 49;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct SERVICE_BROKER_GUID {
                        static constexpr const char *NAME = "service_broker_guid";
                        static const int INDEX = 50;
                        static constexpr const char *DATA_TYPE = "uniqueidentifier";
                    };
                    struct IS_BROKER_ENABLED {
                        static constexpr const char *NAME = "is_broker_enabled";
                        static const int INDEX = 51;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct LOG_REUSE_WAIT {
                        static constexpr const char *NAME = "log_reuse_wait";
                        static const int INDEX = 52;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                    struct LOG_REUSE_WAIT_DESC {
                        static constexpr const char *NAME = "log_reuse_wait_desc";
                        static const int INDEX = 53;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct IS_DATE_CORRELATION_ON {
                        static constexpr const char *NAME = "is_date_correlation_on";
                        static const int INDEX = 54;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_CDC_ENABLED {
                        static constexpr const char *NAME = "is_cdc_enabled";
                        static const int INDEX = 55;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_ENCRYPTED {
                        static constexpr const char *NAME = "is_encrypted";
                        static const int INDEX = 56;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_HONOR_BROKER_PRIORITY_ON {
                        static constexpr const char *NAME = "is_honor_broker_priority_on";
                        static const int INDEX = 57;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct REPLICA_ID {
                        static constexpr const char *NAME = "replica_id";
                        static const int INDEX = 58;
                        static constexpr const char *DATA_TYPE = "uniqueidentifier";
                    };
                    struct GROUP_DATABASE_ID {
                        static constexpr const char *NAME = "group_database_id";
                        static const int INDEX = 59;
                        static constexpr const char *DATA_TYPE = "uniqueidentifier";
                    };
                    struct RESOURCE_POOL_ID {
                        static constexpr const char *NAME = "resource_pool_id";
                        static const int INDEX = 60;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct DEFAULT_LANGUAGE_LCID {
                        static constexpr const char *NAME = "default_language_lcid";
                        static const int INDEX = 61;
                        static constexpr const char *DATA_TYPE = "smallint";
                    };
                    struct DEFAULT_LANGUAGE_NAME {
                        static constexpr const char *NAME = "default_language_name";
                        static const int INDEX = 62;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct DEFAULT_FULLTEXT_LANGUAGE_LCID {
                        static constexpr const char *NAME = "default_fulltext_language_lcid";
                        static const int INDEX = 63;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct DEFAULT_FULLTEXT_LANGUAGE_NAME {
                        static constexpr const char *NAME = "default_fulltext_language_name";
                        static const int INDEX = 64;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct IS_NESTED_TRIGGERS_ON {
                        static constexpr const char *NAME = "is_nested_triggers_on";
                        static const int INDEX = 65;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_TRANSFORM_NOISE_WORDS_ON {
                        static constexpr const char *NAME = "is_transform_noise_words_on";
                        static const int INDEX = 66;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct TWO_DIGIT_YEAR_CUTOFF {
                        static constexpr const char *NAME = "two_digit_year_cutoff";
                        static const int INDEX = 67;
                        static constexpr const char *DATA_TYPE = "smallint";
                    };
                    struct CONTAINMENT {
                        static constexpr const char *NAME = "containment";
                        static const int INDEX = 68;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                    struct CONTAINMENT_DESC {
                        static constexpr const char *NAME = "containment_desc";
                        static const int INDEX = 69;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct TARGET_RECOVERY_TIME_IN_SECONDS {
                        static constexpr const char *NAME = "target_recovery_time_in_seconds";
                        static const int INDEX = 70;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct DELAYED_DURABILITY {
                        static constexpr const char *NAME = "delayed_durability";
                        static const int INDEX = 71;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct DELAYED_DURABILITY_DESC {
                        static constexpr const char *NAME = "delayed_durability_desc";
                        static const int INDEX = 72;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct IS_MEMORY_OPTIMIZED_ELEVATE_TO_SNAPSHOT_ON {
                        static constexpr const char *NAME = "is_memory_optimized_elevate_to_snapshot_on";
                        static const int INDEX = 73;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_FEDERATION_MEMBER {
                        static constexpr const char *NAME = "is_federation_member";
                        static const int INDEX = 74;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_REMOTE_DATA_ARCHIVE_ENABLED {
                        static constexpr const char *NAME = "is_remote_data_archive_enabled";
                        static const int INDEX = 75;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_MIXED_PAGE_ALLOCATION_ON {
                        static constexpr const char *NAME = "is_mixed_page_allocation_on";
                        static const int INDEX = 76;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                    struct IS_TEMPORAL_HISTORY_RETENTION_ENABLED {
                        static constexpr const char *NAME = "is_temporal_history_retention_enabled";
                        static const int INDEX = 77;
                        static constexpr const char *DATA_TYPE = "bit";
                    };
                };

                SysDatabases(std::string &name, int databaseId, int sourceDatabaseId, std::string &ownerSid,
                             std::string &createDate, int compatibilityLevel, std::string &collationName,
                             int userAccess, std::string &userAccessDesc, bool isReadOnly, bool isAutoCloseOn,
                             bool isAutoShrinkOn, int state, std::string &stateDesc, bool isInStandby,
                             bool isCleanlyShutdown, bool isSupplementalLoggingEnabled, int snapshotIsolationState,
                             std::string &snapshotIsolationStateDesc, bool isReadCommittedSnapshotOn,
                             int recoveryModel, std::string &recoveryModelDesc, int pageVerifyOption,
                             std::string &pageVerifyOptionDesc, bool isAutoCreateStatsOn,
                             bool isAutoCreateStatsIncrementalOn, bool isAutoUpdateStatsOn,
                             bool isAutoUpdateStatsAsyncOn, bool isAnsiNullDefaultOn, bool isAnsiNullsOn,
                             bool isAnsiPaddingOn, bool isAnsiWarningsOn, bool isArithabortOn,
                             bool isConcatNullYieldsNullOn, bool isNumericRoundabortOn, bool isQuotedIdentifierOn,
                             bool isRecursiveTriggersOn, bool isCursorCloseOnCommitOn, bool isLocalCursorDefault,
                             bool isFulltextEnabled, bool isTrustworthyOn, bool isDbChainingOn,
                             bool isParameterizationForced, bool isMasterKeyEncryptedByServer, bool isQueryStoreOn,
                             bool isPublished, bool isSubscribed, bool isMergePublished, bool isDistributor,
                             bool isSyncWithBackup, std::string &serviceBrokerGuid, bool isBrokerEnabled,
                             int logReuseWait, std::string &logReuseWaitDesc, bool isDateCorrelationOn,
                             bool isCdcEnabled, bool isEncrypted, bool isHonorBrokerPriorityOn,
                             std::string &replicaId, std::string &groupDatabaseId, int resourcePoolId,
                             int defaultLanguageLcid, std::string &defaultLanguageName,
                             int defaultFulltextLanguageLcid, std::string &defaultFulltextLanguageName,
                             bool isNestedTriggersOn, bool isTransformNoiseWordsOn, int twoDigitYearCutoff,
                             int containment, std::string &containmentDesc, int targetRecoveryTimeInSeconds,
                             int delayedDurability, std::string &delayedDurabilityDesc,
                             bool isMemoryOptimizedElevateToSnapshotOn, bool isFederationMember,
                             bool isRemoteDataArchiveEnabled, bool isMixedPageAllocationOn,
                             bool isTemporalHistoryRetentionEnabled)
                        : name(name), database_id(databaseId), source_database_id(sourceDatabaseId),
                          owner_sid(ownerSid), create_date(createDate), compatibility_level(compatibilityLevel),
                          collation_name(collationName), user_access(userAccess), user_access_desc(userAccessDesc),
                          is_read_only(isReadOnly), is_auto_close_on(isAutoCloseOn), is_auto_shrink_on(isAutoShrinkOn),
                          state(state), state_desc(stateDesc), is_in_standby(isInStandby),
                          is_cleanly_shutdown(isCleanlyShutdown),
                          is_supplemental_logging_enabled(isSupplementalLoggingEnabled),
                          snapshot_isolation_state(snapshotIsolationState),
                          snapshot_isolation_state_desc(snapshotIsolationStateDesc),
                          is_read_committed_snapshot_on(isReadCommittedSnapshotOn), recovery_model(recoveryModel),
                          recovery_model_desc(recoveryModelDesc), page_verify_option(pageVerifyOption),
                          page_verify_option_desc(pageVerifyOptionDesc), is_auto_create_stats_on(isAutoCreateStatsOn),
                          is_auto_create_stats_incremental_on(isAutoCreateStatsIncrementalOn),
                          is_auto_update_stats_on(isAutoUpdateStatsOn),
                          is_auto_update_stats_async_on(isAutoUpdateStatsAsyncOn),
                          is_ansi_null_default_on(isAnsiNullDefaultOn), is_ansi_nulls_on(isAnsiNullsOn),
                          is_ansi_padding_on(isAnsiPaddingOn), is_ansi_warnings_on(isAnsiWarningsOn),
                          is_arithabort_on(isArithabortOn), is_concat_null_yields_null_on(isConcatNullYieldsNullOn),
                          is_numeric_roundabort_on(isNumericRoundabortOn),
                          is_quoted_identifier_on(isQuotedIdentifierOn),
                          is_recursive_triggers_on(isRecursiveTriggersOn),
                          is_cursor_close_on_commit_on(isCursorCloseOnCommitOn),
                          is_local_cursor_default(isLocalCursorDefault), is_fulltext_enabled(isFulltextEnabled),
                          is_trustworthy_on(isTrustworthyOn), is_db_chaining_on(isDbChainingOn),
                          is_parameterization_forced(isParameterizationForced),
                          is_master_key_encrypted_by_server(isMasterKeyEncryptedByServer),
                          is_query_store_on(isQueryStoreOn), is_published(isPublished), is_subscribed(isSubscribed),
                          is_merge_published(isMergePublished), is_distributor(isDistributor),
                          is_sync_with_backup(isSyncWithBackup), service_broker_guid(serviceBrokerGuid),
                          is_broker_enabled(isBrokerEnabled), log_reuse_wait(logReuseWait),
                          log_reuse_wait_desc(logReuseWaitDesc), is_date_correlation_on(isDateCorrelationOn),
                          is_cdc_enabled(isCdcEnabled), is_encrypted(isEncrypted),
                          is_honor_broker_priority_on(isHonorBrokerPriorityOn), replica_id(replicaId),
                          group_database_id(groupDatabaseId), resource_pool_id(resourcePoolId),
                          default_language_lcid(defaultLanguageLcid), default_language_name(defaultLanguageName),
                          default_fulltext_language_lcid(defaultFulltextLanguageLcid),
                          default_fulltext_language_name(defaultFulltextLanguageName),
                          is_nested_triggers_on(isNestedTriggersOn),
                          is_transform_noise_words_on(isTransformNoiseWordsOn),
                          two_digit_year_cutoff(twoDigitYearCutoff), containment(containment),
                          containment_desc(containmentDesc),
                          target_recovery_time_in_seconds(targetRecoveryTimeInSeconds),
                          delayed_durability(delayedDurability), delayed_durability_desc(delayedDurabilityDesc),
                          is_memory_optimized_elevate_to_snapshot_on(isMemoryOptimizedElevateToSnapshotOn),
                          is_federation_member(isFederationMember),
                          is_remote_data_archive_enabled(isRemoteDataArchiveEnabled),
                          is_mixed_page_allocation_on(isMixedPageAllocationOn),
                          is_temporal_history_retention_enabled(isTemporalHistoryRetentionEnabled) {}

                /**
               * Returns the table name 'CHARACTER_SETS';
               */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }

                const std::string &getName() const {
                    return name;
                }

                void setName(const std::string &name) {
                    SysDatabases::name = name;
                }

                int getDatabaseId() const {
                    return database_id;
                }

                void setDatabaseId(int databaseId) {
                    database_id = databaseId;
                }

                int getSourceDatabaseId() const {
                    return source_database_id;
                }

                void setSourceDatabaseId(int sourceDatabaseId) {
                    source_database_id = sourceDatabaseId;
                }

                const std::string &getOwnerSid() const {
                    return owner_sid;
                }

                void setOwnerSid(const std::string &ownerSid) {
                    owner_sid = ownerSid;
                }

                const std::string &getCreateDate() const {
                    return create_date;
                }

                void setCreateDate(const std::string &createDate) {
                    create_date = createDate;
                }

                int getCompatibilityLevel() const {
                    return compatibility_level;
                }

                void setCompatibilityLevel(int compatibilityLevel) {
                    compatibility_level = compatibilityLevel;
                }

                const std::string &getCollationName() const {
                    return collation_name;
                }

                void setCollationName(const std::string &collationName) {
                    collation_name = collationName;
                }

                int getUserAccess() const {
                    return user_access;
                }

                void setUserAccess(int userAccess) {
                    user_access = userAccess;
                }

                const std::string &getUserAccessDesc() const {
                    return user_access_desc;
                }

                void setUserAccessDesc(const std::string &userAccessDesc) {
                    user_access_desc = userAccessDesc;
                }

                bool isReadOnly() const {
                    return is_read_only;
                }

                void setIsReadOnly(bool isReadOnly) {
                    is_read_only = isReadOnly;
                }

                bool isAutoCloseOn() const {
                    return is_auto_close_on;
                }

                void setIsAutoCloseOn(bool isAutoCloseOn) {
                    is_auto_close_on = isAutoCloseOn;
                }

                bool isAutoShrinkOn() const {
                    return is_auto_shrink_on;
                }

                void setIsAutoShrinkOn(bool isAutoShrinkOn) {
                    is_auto_shrink_on = isAutoShrinkOn;
                }

                int getState() const {
                    return state;
                }

                void setState(int state) {
                    SysDatabases::state = state;
                }

                const std::string &getStateDesc() const {
                    return state_desc;
                }

                void setStateDesc(const std::string &stateDesc) {
                    state_desc = stateDesc;
                }

                bool isInStandby() const {
                    return is_in_standby;
                }

                void setIsInStandby(bool isInStandby) {
                    is_in_standby = isInStandby;
                }

                bool isCleanlyShutdown() const {
                    return is_cleanly_shutdown;
                }

                void setIsCleanlyShutdown(bool isCleanlyShutdown) {
                    is_cleanly_shutdown = isCleanlyShutdown;
                }

                bool isSupplementalLoggingEnabled() const {
                    return is_supplemental_logging_enabled;
                }

                void setIsSupplementalLoggingEnabled(bool isSupplementalLoggingEnabled) {
                    is_supplemental_logging_enabled = isSupplementalLoggingEnabled;
                }

                int getSnapshotIsolationState() const {
                    return snapshot_isolation_state;
                }

                void setSnapshotIsolationState(int snapshotIsolationState) {
                    snapshot_isolation_state = snapshotIsolationState;
                }

                const std::string &getSnapshotIsolationStateDesc() const {
                    return snapshot_isolation_state_desc;
                }

                void setSnapshotIsolationStateDesc(const std::string &snapshotIsolationStateDesc) {
                    snapshot_isolation_state_desc = snapshotIsolationStateDesc;
                }

                bool isReadCommittedSnapshotOn() const {
                    return is_read_committed_snapshot_on;
                }

                void setIsReadCommittedSnapshotOn(bool isReadCommittedSnapshotOn) {
                    is_read_committed_snapshot_on = isReadCommittedSnapshotOn;
                }

                int getRecoveryModel() const {
                    return recovery_model;
                }

                void setRecoveryModel(int recoveryModel) {
                    recovery_model = recoveryModel;
                }

                const std::string &getRecoveryModelDesc() const {
                    return recovery_model_desc;
                }

                void setRecoveryModelDesc(const std::string &recoveryModelDesc) {
                    recovery_model_desc = recoveryModelDesc;
                }

                int getPageVerifyOption() const {
                    return page_verify_option;
                }

                void setPageVerifyOption(int pageVerifyOption) {
                    page_verify_option = pageVerifyOption;
                }

                const std::string &getPageVerifyOptionDesc() const {
                    return page_verify_option_desc;
                }

                void setPageVerifyOptionDesc(const std::string &pageVerifyOptionDesc) {
                    page_verify_option_desc = pageVerifyOptionDesc;
                }

                bool isAutoCreateStatsOn() const {
                    return is_auto_create_stats_on;
                }

                void setIsAutoCreateStatsOn(bool isAutoCreateStatsOn) {
                    is_auto_create_stats_on = isAutoCreateStatsOn;
                }

                bool isAutoCreateStatsIncrementalOn() const {
                    return is_auto_create_stats_incremental_on;
                }

                void setIsAutoCreateStatsIncrementalOn(bool isAutoCreateStatsIncrementalOn) {
                    is_auto_create_stats_incremental_on = isAutoCreateStatsIncrementalOn;
                }

                bool isAutoUpdateStatsOn() const {
                    return is_auto_update_stats_on;
                }

                void setIsAutoUpdateStatsOn(bool isAutoUpdateStatsOn) {
                    is_auto_update_stats_on = isAutoUpdateStatsOn;
                }

                bool isAutoUpdateStatsAsyncOn() const {
                    return is_auto_update_stats_async_on;
                }

                void setIsAutoUpdateStatsAsyncOn(bool isAutoUpdateStatsAsyncOn) {
                    is_auto_update_stats_async_on = isAutoUpdateStatsAsyncOn;
                }

                bool isAnsiNullDefaultOn() const {
                    return is_ansi_null_default_on;
                }

                void setIsAnsiNullDefaultOn(bool isAnsiNullDefaultOn) {
                    is_ansi_null_default_on = isAnsiNullDefaultOn;
                }

                bool isAnsiNullsOn() const {
                    return is_ansi_nulls_on;
                }

                void setIsAnsiNullsOn(bool isAnsiNullsOn) {
                    is_ansi_nulls_on = isAnsiNullsOn;
                }

                bool isAnsiPaddingOn() const {
                    return is_ansi_padding_on;
                }

                void setIsAnsiPaddingOn(bool isAnsiPaddingOn) {
                    is_ansi_padding_on = isAnsiPaddingOn;
                }

                bool isAnsiWarningsOn() const {
                    return is_ansi_warnings_on;
                }

                void setIsAnsiWarningsOn(bool isAnsiWarningsOn) {
                    is_ansi_warnings_on = isAnsiWarningsOn;
                }

                bool isArithabortOn() const {
                    return is_arithabort_on;
                }

                void setIsArithabortOn(bool isArithabortOn) {
                    is_arithabort_on = isArithabortOn;
                }

                bool isConcatNullYieldsNullOn() const {
                    return is_concat_null_yields_null_on;
                }

                void setIsConcatNullYieldsNullOn(bool isConcatNullYieldsNullOn) {
                    is_concat_null_yields_null_on = isConcatNullYieldsNullOn;
                }

                bool isNumericRoundabortOn() const {
                    return is_numeric_roundabort_on;
                }

                void setIsNumericRoundabortOn(bool isNumericRoundabortOn) {
                    is_numeric_roundabort_on = isNumericRoundabortOn;
                }

                bool isQuotedIdentifierOn() const {
                    return is_quoted_identifier_on;
                }

                void setIsQuotedIdentifierOn(bool isQuotedIdentifierOn) {
                    is_quoted_identifier_on = isQuotedIdentifierOn;
                }

                bool isRecursiveTriggersOn() const {
                    return is_recursive_triggers_on;
                }

                void setIsRecursiveTriggersOn(bool isRecursiveTriggersOn) {
                    is_recursive_triggers_on = isRecursiveTriggersOn;
                }

                bool isCursorCloseOnCommitOn() const {
                    return is_cursor_close_on_commit_on;
                }

                void setIsCursorCloseOnCommitOn(bool isCursorCloseOnCommitOn) {
                    is_cursor_close_on_commit_on = isCursorCloseOnCommitOn;
                }

                bool isLocalCursorDefault() const {
                    return is_local_cursor_default;
                }

                void setIsLocalCursorDefault(bool isLocalCursorDefault) {
                    is_local_cursor_default = isLocalCursorDefault;
                }

                bool isFulltextEnabled() const {
                    return is_fulltext_enabled;
                }

                void setIsFulltextEnabled(bool isFulltextEnabled) {
                    is_fulltext_enabled = isFulltextEnabled;
                }

                bool isTrustworthyOn() const {
                    return is_trustworthy_on;
                }

                void setIsTrustworthyOn(bool isTrustworthyOn) {
                    is_trustworthy_on = isTrustworthyOn;
                }

                bool isDbChainingOn() const {
                    return is_db_chaining_on;
                }

                void setIsDbChainingOn(bool isDbChainingOn) {
                    is_db_chaining_on = isDbChainingOn;
                }

                bool isParameterizationForced() const {
                    return is_parameterization_forced;
                }

                void setIsParameterizationForced(bool isParameterizationForced) {
                    is_parameterization_forced = isParameterizationForced;
                }

                bool isMasterKeyEncryptedByServer() const {
                    return is_master_key_encrypted_by_server;
                }

                void setIsMasterKeyEncryptedByServer(bool isMasterKeyEncryptedByServer) {
                    is_master_key_encrypted_by_server = isMasterKeyEncryptedByServer;
                }

                bool isQueryStoreOn() const {
                    return is_query_store_on;
                }

                void setIsQueryStoreOn(bool isQueryStoreOn) {
                    is_query_store_on = isQueryStoreOn;
                }

                bool isPublished() const {
                    return is_published;
                }

                void setIsPublished(bool isPublished) {
                    is_published = isPublished;
                }

                bool isSubscribed() const {
                    return is_subscribed;
                }

                void setIsSubscribed(bool isSubscribed) {
                    is_subscribed = isSubscribed;
                }

                bool isMergePublished() const {
                    return is_merge_published;
                }

                void setIsMergePublished(bool isMergePublished) {
                    is_merge_published = isMergePublished;
                }

                bool isDistributor() const {
                    return is_distributor;
                }

                void setIsDistributor(bool isDistributor) {
                    is_distributor = isDistributor;
                }

                bool isSyncWithBackup() const {
                    return is_sync_with_backup;
                }

                void setIsSyncWithBackup(bool isSyncWithBackup) {
                    is_sync_with_backup = isSyncWithBackup;
                }

                const std::string &getServiceBrokerGuid() const {
                    return service_broker_guid;
                }

                void setServiceBrokerGuid(const std::string &serviceBrokerGuid) {
                    service_broker_guid = serviceBrokerGuid;
                }

                bool isBrokerEnabled() const {
                    return is_broker_enabled;
                }

                void setIsBrokerEnabled(bool isBrokerEnabled) {
                    is_broker_enabled = isBrokerEnabled;
                }

                int getLogReuseWait() const {
                    return log_reuse_wait;
                }

                void setLogReuseWait(int logReuseWait) {
                    log_reuse_wait = logReuseWait;
                }

                const std::string &getLogReuseWaitDesc() const {
                    return log_reuse_wait_desc;
                }

                void setLogReuseWaitDesc(const std::string &logReuseWaitDesc) {
                    log_reuse_wait_desc = logReuseWaitDesc;
                }

                bool isDateCorrelationOn() const {
                    return is_date_correlation_on;
                }

                void setIsDateCorrelationOn(bool isDateCorrelationOn) {
                    is_date_correlation_on = isDateCorrelationOn;
                }

                bool isCdcEnabled() const {
                    return is_cdc_enabled;
                }

                void setIsCdcEnabled(bool isCdcEnabled) {
                    is_cdc_enabled = isCdcEnabled;
                }

                bool isEncrypted() const {
                    return is_encrypted;
                }

                void setIsEncrypted(bool isEncrypted) {
                    is_encrypted = isEncrypted;
                }

                bool isHonorBrokerPriorityOn() const {
                    return is_honor_broker_priority_on;
                }

                void setIsHonorBrokerPriorityOn(bool isHonorBrokerPriorityOn) {
                    is_honor_broker_priority_on = isHonorBrokerPriorityOn;
                }

                const std::string &getReplicaId() const {
                    return replica_id;
                }

                void setReplicaId(const std::string &replicaId) {
                    replica_id = replicaId;
                }

                const std::string &getGroupDatabaseId() const {
                    return group_database_id;
                }

                void setGroupDatabaseId(const std::string &groupDatabaseId) {
                    group_database_id = groupDatabaseId;
                }

                int getResourcePoolId() const {
                    return resource_pool_id;
                }

                void setResourcePoolId(int resourcePoolId) {
                    resource_pool_id = resourcePoolId;
                }

                int getDefaultLanguageLcid() const {
                    return default_language_lcid;
                }

                void setDefaultLanguageLcid(int defaultLanguageLcid) {
                    default_language_lcid = defaultLanguageLcid;
                }

                const std::string &getDefaultLanguageName() const {
                    return default_language_name;
                }

                void setDefaultLanguageName(const std::string &defaultLanguageName) {
                    default_language_name = defaultLanguageName;
                }

                int getDefaultFulltextLanguageLcid() const {
                    return default_fulltext_language_lcid;
                }

                void setDefaultFulltextLanguageLcid(int defaultFulltextLanguageLcid) {
                    default_fulltext_language_lcid = defaultFulltextLanguageLcid;
                }

                const std::string &getDefaultFulltextLanguageName() const {
                    return default_fulltext_language_name;
                }

                void setDefaultFulltextLanguageName(const std::string &defaultFulltextLanguageName) {
                    default_fulltext_language_name = defaultFulltextLanguageName;
                }

                bool isNestedTriggersOn() const {
                    return is_nested_triggers_on;
                }

                void setIsNestedTriggersOn(bool isNestedTriggersOn) {
                    is_nested_triggers_on = isNestedTriggersOn;
                }

                bool isTransformNoiseWordsOn() const {
                    return is_transform_noise_words_on;
                }

                void setIsTransformNoiseWordsOn(bool isTransformNoiseWordsOn) {
                    is_transform_noise_words_on = isTransformNoiseWordsOn;
                }

                int getTwoDigitYearCutoff() const {
                    return two_digit_year_cutoff;
                }

                void setTwoDigitYearCutoff(int twoDigitYearCutoff) {
                    two_digit_year_cutoff = twoDigitYearCutoff;
                }

                int getContainment() const {
                    return containment;
                }

                void setContainment(int containment) {
                    SysDatabases::containment = containment;
                }

                const std::string &getContainmentDesc() const {
                    return containment_desc;
                }

                void setContainmentDesc(const std::string &containmentDesc) {
                    containment_desc = containmentDesc;
                }

                int getTargetRecoveryTimeInSeconds() const {
                    return target_recovery_time_in_seconds;
                }

                void setTargetRecoveryTimeInSeconds(int targetRecoveryTimeInSeconds) {
                    target_recovery_time_in_seconds = targetRecoveryTimeInSeconds;
                }

                int getDelayedDurability() const {
                    return delayed_durability;
                }

                void setDelayedDurability(int delayedDurability) {
                    delayed_durability = delayedDurability;
                }

                const std::string &getDelayedDurabilityDesc() const {
                    return delayed_durability_desc;
                }

                void setDelayedDurabilityDesc(const std::string &delayedDurabilityDesc) {
                    delayed_durability_desc = delayedDurabilityDesc;
                }

                bool isMemoryOptimizedElevateToSnapshotOn() const {
                    return is_memory_optimized_elevate_to_snapshot_on;
                }

                void setIsMemoryOptimizedElevateToSnapshotOn(bool isMemoryOptimizedElevateToSnapshotOn) {
                    is_memory_optimized_elevate_to_snapshot_on = isMemoryOptimizedElevateToSnapshotOn;
                }

                bool isFederationMember() const {
                    return is_federation_member;
                }

                void setIsFederationMember(bool isFederationMember) {
                    is_federation_member = isFederationMember;
                }

                bool isRemoteDataArchiveEnabled() const {
                    return is_remote_data_archive_enabled;
                }

                void setIsRemoteDataArchiveEnabled(bool isRemoteDataArchiveEnabled) {
                    is_remote_data_archive_enabled = isRemoteDataArchiveEnabled;
                }

                bool isMixedPageAllocationOn() const {
                    return is_mixed_page_allocation_on;
                }

                void setIsMixedPageAllocationOn(bool isMixedPageAllocationOn) {
                    is_mixed_page_allocation_on = isMixedPageAllocationOn;
                }

                bool isTemporalHistoryRetentionEnabled() const {
                    return is_temporal_history_retention_enabled;
                }

                void setIsTemporalHistoryRetentionEnabled(bool isTemporalHistoryRetentionEnabled) {
                    is_temporal_history_retention_enabled = isTemporalHistoryRetentionEnabled;
                }

            };
        }
    }
}

#endif //DBCRUDGEN_CPP_SYSDATABASES_H
