//
// Created by victor on 8/31/21.
//

#ifndef DBCRUDGEN_CPP_SYSDATABASES_H
#define DBCRUDGEN_CPP_SYSDATABASES_H

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class SysDatabases {
            public:
                static constexpr const char *TABLE_NAME = "sys.databases";

                struct COLUMNS {
                    struct NAME{static constexpr const char *NAME = "name";static const int INDEX = 0;};
                    struct DATABASE_ID{static constexpr const char *NAME = "database_id";static const int INDEX = 1;};
                    struct SOURCE_DATABASE_ID{static constexpr const char *NAME = "source_database_id";static const int INDEX = 2;};
                    struct OWNER_SID{static constexpr const char *NAME = "owner_sid";static const int INDEX = 3;};
                    struct CREATE_DATE{static constexpr const char *NAME = "create_date";static const int INDEX = 4;};
                    struct COMPATIBILITY_LEVEL{static constexpr const char *NAME = "compatibility_level";static const int INDEX = 5;};
                    struct COLLATION_NAME{static constexpr const char *NAME = "collation_name";static const int INDEX = 6;};
                    struct USER_ACCESS{static constexpr const char *NAME = "user_access";static const int INDEX = 7;};
                    struct USER_ACCESS_DESC{static constexpr const char *NAME = "user_access_desc";static const int INDEX = 8;};
                    struct IS_READ_ONLY{static constexpr const char *NAME = "is_read_only";static const int INDEX = 9;};
                    struct IS_AUTO_CLOSE_ON{static constexpr const char *NAME = "is_auto_close_on";static const int INDEX = 10;};
                    struct IS_AUTO_SHRINK_ON{static constexpr const char *NAME = "is_auto_shrink_on";static const int INDEX = 11;};
                    struct STATE{static constexpr const char *NAME = "state";static const int INDEX = 12;};
                    struct STATE_DESC{static constexpr const char *NAME = "state_desc";static const int INDEX = 13;};
                    struct IS_IN_STANDBY{static constexpr const char *NAME = "is_in_standby";static const int INDEX = 14;};
                    struct IS_CLEANLY_SHUTDOWN{static constexpr const char *NAME = "is_cleanly_shutdown";static const int INDEX = 15;};
                    struct IS_SUPPLEMENTAL_LOGGING_ENABLED{static constexpr const char *NAME = "is_supplemental_logging_enabled";static const int INDEX = 16;};
                    struct SNAPSHOT_ISOLATION_STATE{static constexpr const char *NAME = "snapshot_isolation_state";static const int INDEX = 17;};
                    struct SNAPSHOT_ISOLATION_STATE_DESC{static constexpr const char *NAME = "snapshot_isolation_state_desc";static const int INDEX = 18;};
                    struct IS_READ_COMMITTED_SNAPSHOT_ON{static constexpr const char *NAME = "is_read_committed_snapshot_on";static const int INDEX = 19;};
                    struct RECOVERY_MODEL{static constexpr const char *NAME = "recovery_model";static const int INDEX = 20;};
                    struct RECOVERY_MODEL_DESC{static constexpr const char *NAME = "recovery_model_desc";static const int INDEX = 21;};
                    struct PAGE_VERIFY_OPTION{static constexpr const char *NAME = "page_verify_option";static const int INDEX = 22;};
                    struct PAGE_VERIFY_OPTION_DESC{static constexpr const char *NAME = "page_verify_option_desc";static const int INDEX = 23;};
                    struct IS_AUTO_CREATE_STATS_ON{static constexpr const char *NAME = "is_auto_create_stats_on";static const int INDEX = 24;};
                    struct IS_AUTO_CREATE_STATS_INCREMENTAL_ON{static constexpr const char *NAME = "is_auto_create_stats_incremental_on";static const int INDEX = 25;};
                    struct IS_AUTO_UPDATE_STATS_ON{static constexpr const char *NAME = "is_auto_update_stats_on";static const int INDEX = 26;};
                    struct IS_AUTO_UPDATE_STATS_ASYNC_ON{static constexpr const char *NAME = "is_auto_update_stats_async_on";static const int INDEX = 27;};
                    struct IS_ANSI_NULL_DEFAULT_ON{static constexpr const char *NAME = "is_ansi_null_default_on";static const int INDEX = 28;};
                    struct IS_ANSI_NULLS_ON{static constexpr const char *NAME = "is_ansi_nulls_on";static const int INDEX = 29;};
                    struct IS_ANSI_PADDING_ON{static constexpr const char *NAME = "is_ansi_padding_on";static const int INDEX = 30;};
                    struct IS_ANSI_WARNINGS_ON{static constexpr const char *NAME = "is_ansi_warnings_on";static const int INDEX = 31;};
                    struct IS_ARITHABORT_ON{static constexpr const char *NAME = "is_arithabort_on";static const int INDEX = 32;};
                    struct IS_CONCAT_NULL_YIELDS_NULL_ON{static constexpr const char *NAME = "is_concat_null_yields_null_on";static const int INDEX = 33;};
                    struct IS_NUMERIC_ROUNDABORT_ON{static constexpr const char *NAME = "is_numeric_roundabort_on";static const int INDEX = 34;};
                    struct IS_QUOTED_IDENTIFIER_ON{static constexpr const char *NAME = "is_quoted_identifier_on";static const int INDEX = 35;};
                    struct IS_RECURSIVE_TRIGGERS_ON{static constexpr const char *NAME = "is_recursive_triggers_on";static const int INDEX = 36;};
                    struct IS_CURSOR_CLOSE_ON_COMMIT_ON{static constexpr const char *NAME = "is_cursor_close_on_commit_on";static const int INDEX = 37;};
                    struct IS_LOCAL_CURSOR_DEFAULT{static constexpr const char *NAME = "is_local_cursor_default";static const int INDEX = 38;};
                    struct IS_FULLTEXT_ENABLED{static constexpr const char *NAME = "is_fulltext_enabled";static const int INDEX = 39;};
                    struct IS_TRUSTWORTHY_ON{static constexpr const char *NAME = "is_trustworthy_on";static const int INDEX = 40;};
                    struct IS_DB_CHAINING_ON{static constexpr const char *NAME = "is_db_chaining_on";static const int INDEX = 41;};
                    struct IS_PARAMETERIZATION_FORCED{static constexpr const char *NAME = "is_parameterization_forced";static const int INDEX = 42;};
                    struct IS_MASTER_KEY_ENCRYPTED_BY_SERVER{static constexpr const char *NAME = "is_master_key_encrypted_by_server";static const int INDEX = 43;};
                    struct IS_QUERY_STORE_ON{static constexpr const char *NAME = "is_query_store_on";static const int INDEX = 44;};
                    struct IS_PUBLISHED{static constexpr const char *NAME = "is_published";static const int INDEX = 45;};
                    struct IS_SUBSCRIBED{static constexpr const char *NAME = "is_subscribed";static const int INDEX = 46;};
                    struct IS_MERGE_PUBLISHED{static constexpr const char *NAME = "is_merge_published";static const int INDEX = 47;};
                    struct IS_DISTRIBUTOR{static constexpr const char *NAME = "is_distributor";static const int INDEX = 48;};
                    struct IS_SYNC_WITH_BACKUP{static constexpr const char *NAME = "is_sync_with_backup";static const int INDEX = 49;};
                    struct SERVICE_BROKER_GUID{static constexpr const char *NAME = "service_broker_guid";static const int INDEX = 50;};
                    struct IS_BROKER_ENABLED{static constexpr const char *NAME = "is_broker_enabled";static const int INDEX = 51;};
                    struct LOG_REUSE_WAIT{static constexpr const char *NAME = "log_reuse_wait";static const int INDEX = 52;};
                    struct LOG_REUSE_WAIT_DESC{static constexpr const char *NAME = "log_reuse_wait_desc";static const int INDEX = 53;};
                    struct IS_DATE_CORRELATION_ON{static constexpr const char *NAME = "is_date_correlation_on";static const int INDEX = 54;};
                    struct IS_CDC_ENABLED{static constexpr const char *NAME = "is_cdc_enabled";static const int INDEX = 55;};
                    struct IS_ENCRYPTED{static constexpr const char *NAME = "is_encrypted";static const int INDEX = 56;};
                    struct IS_HONOR_BROKER_PRIORITY_ON{static constexpr const char *NAME = "is_honor_broker_priority_on";static const int INDEX = 57;};
                    struct REPLICA_ID{static constexpr const char *NAME = "replica_id";static const int INDEX = 58;};
                    struct GROUP_DATABASE_ID{static constexpr const char *NAME = "group_database_id";static const int INDEX = 59;};
                    struct RESOURCE_POOL_ID{static constexpr const char *NAME = "resource_pool_id";static const int INDEX = 60;};
                    struct DEFAULT_LANGUAGE_LCID{static constexpr const char *NAME = "default_language_lcid";static const int INDEX = 61;};
                    struct DEFAULT_LANGUAGE_NAME{static constexpr const char *NAME = "default_language_name";static const int INDEX = 62;};
                    struct DEFAULT_FULLTEXT_LANGUAGE_LCID{static constexpr const char *NAME = "default_fulltext_language_lcid";static const int INDEX = 63;};
                    struct DEFAULT_FULLTEXT_LANGUAGE_NAME{static constexpr const char *NAME = "default_fulltext_language_name";static const int INDEX = 64;};
                    struct IS_NESTED_TRIGGERS_ON{static constexpr const char *NAME = "is_nested_triggers_on";static const int INDEX = 65;};
                    struct IS_TRANSFORM_NOISE_WORDS_ON{static constexpr const char *NAME = "is_transform_noise_words_on";static const int INDEX = 66;};
                    struct TWO_DIGIT_YEAR_CUTOFF{static constexpr const char *NAME = "two_digit_year_cutoff";static const int INDEX = 67;};
                    struct CONTAINMENT{static constexpr const char *NAME = "containment";static const int INDEX = 68;};
                    struct CONTAINMENT_DESC{static constexpr const char *NAME = "containment_desc";static const int INDEX = 69;};
                    struct TARGET_RECOVERY_TIME_IN_SECONDS{static constexpr const char *NAME = "target_recovery_time_in_seconds";static const int INDEX = 70;};
                    struct DELAYED_DURABILITY{static constexpr const char *NAME = "delayed_durability";static const int INDEX = 71;};
                    struct DELAYED_DURABILITY_DESC{static constexpr const char *NAME = "delayed_durability_desc";static const int INDEX = 72;};
                    struct IS_MEMORY_OPTIMIZED_ELEVATE_TO_SNAPSHOT_ON{static constexpr const char *NAME = "is_memory_optimized_elevate_to_snapshot_on";static const int INDEX = 73;};
                    struct IS_FEDERATION_MEMBER{static constexpr const char *NAME = "is_federation_member";static const int INDEX = 74;};
                    struct IS_REMOTE_DATA_ARCHIVE_ENABLED{static constexpr const char *NAME = "is_remote_data_archive_enabled";static const int INDEX = 75;};
                    struct IS_MIXED_PAGE_ALLOCATION_ON{static constexpr const char *NAME = "is_mixed_page_allocation_on";static const int INDEX = 76;};
                    struct IS_TEMPORAL_HISTORY_RETENTION_ENABLED{static constexpr const char *NAME = "is_temporal_history_retention_enabled";static const int INDEX = 77;};
                };


               /**
              * Returns the table name 'CHARACTER_SETS';
              */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }

            };
        }
    }
}

#endif //DBCRUDGEN_CPP_SYSDATABASES_H
