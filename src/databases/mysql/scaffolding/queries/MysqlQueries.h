//
// Created by vrwanda on 3/12/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLQUERIES_H
#define DBCRUDGEN_CPP_MYSQLQUERIES_H

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class MYSQLQueries {
            public:

                struct Tags {
                    static constexpr const char *TABLE_SCHEMA = "${TABLE_SCHEMA}";
                    static constexpr const char *TABLE_NAME = "${TABLE_NAME}";
                    static constexpr const char *COLUMN_NAME = "${COLUMN_NAME}";
                };


                struct Prepared {
                    static constexpr const char *GET_SCHEMA_TABLES = "SELECT * FROM information_schema.tables WHERE table_schema = '${TABLE_SCHEMA}';";

                    static constexpr const char *GET_TABLE_CREATE_STATEMENT = "SHOW CREATE TABLE ${TABLE_SCHEMA}.${TABLE_NAME}";

                    static constexpr const char *GET_SCHEMA_TABLE_COLUMNS =
                            "SELECT * FROM information_schema.columns WHERE table_schema = '${TABLE_SCHEMA}' AND table_name='${TABLE_NAME}';";

                    static constexpr const char *GET_SCHEMA_TABLE_COLUMN =
                            "SELECT * FROM information_schema.columns WHERE table_schema = '${TABLE_SCHEMA}' AND table_name='${TABLE_NAME}' and COLUMN_NAME = '${COLUMN_NAME}';";

                    static constexpr const char *GET_TABLE_PRIMARY_KEY_COLUMNS =
                            "SELECT * FROM information_schema.STATISTICS WHERE TABLE_SCHEMA='${TABLE_SCHEMA}' AND TABLE_NAME='${TABLE_NAME}' AND INDEX_NAME = 'PRIMARY'";

                    static constexpr const char *GET_TABLE_KEY_COLUMNS =
                            "SELECT * FROM information_schema.STATISTICS WHERE TABLE_SCHEMA='${TABLE_SCHEMA}' AND TABLE_NAME='${TABLE_NAME}'";

                    static constexpr const char *GET_TABLE_CONSTRAINTS = "SELECT * FROM information_schema.TABLE_CONSTRAINTS WHERE TABLE_SCHEMA='${TABLE_SCHEMA}' AND TABLE_NAME='${TABLE_NAME}'";

                    static constexpr const char *GET_TABLE_FOREIGN_KEYS
                            = "SELECT * FROM information_schema.KEY_COLUMN_USAGE WHERE TABLE_SCHEMA='${TABLE_SCHEMA}' AND TABLE_NAME='${TABLE_NAME}' ";
                };

                ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // SELECT DATA FROM INFORMATION SCHEMAS
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                static constexpr const char *GET_CHARACTER_SETS = "SELECT * FROM information_schema.CHARACTER_SETS";
                static constexpr const char *GET_COLLATIONS = "SELECT * FROM information_schema.COLLATIONS";
                static constexpr const char *GET_COLLATION_CHARACTER_SET_APPLICABILITY = "SELECT * FROM information_schema.COLLATION_CHARACTER_SET_APPLICABILITY";
                static constexpr const char *GET_COLUMNS = "SELECT * FROM information_schema.COLUMNS";
                static constexpr const char *GET_COLUMN_PRIVILEGES = "SELECT * FROM information_schema.COLUMN_PRIVILEGES";
                static constexpr const char *GET_ENGINES = "SELECT * FROM information_schema.ENGINES";
                static constexpr const char *GET_EVENTS = "SELECT * FROM information_schema.EVENTS";
                static constexpr const char *GET_FILES = "SELECT * FROM information_schema.FILES";
                static constexpr const char *GET_GLOBAL_STATUS = "SELECT * FROM information_schema.GLOBAL_STATUS";
                static constexpr const char *GET_GLOBAL_VARIABLES = "SELECT * FROM information_schema.GLOBAL_VARIABLES";
                static constexpr const char *GET_KEY_COLUMN_USAGE = "SELECT * FROM information_schema.KEY_COLUMN_USAGE";
                static constexpr const char *GET_OPTIMIZER_TRACE = "SELECT * FROM information_schema.OPTIMIZER_TRACE";
                static constexpr const char *GET_PARAMETERS = "SELECT * FROM information_schema.PARAMETERS";
                static constexpr const char *GET_PARTITIONS = "SELECT * FROM information_schema.PARTITIONS";
                static constexpr const char *GET_PLUGINS = "SELECT * FROM information_schema.PLUGINS";
                static constexpr const char *GET_PROCESSLIST = "SELECT * FROM information_schema.PROCESSLIST";
                static constexpr const char *GET_PROFILING = "SELECT * FROM information_schema.PROFILING";
                static constexpr const char *GET_REFERENTIAL_CONSTRAINTS = "SELECT * FROM information_schema.REFERENTIAL_CONSTRAINTS";
                static constexpr const char *GET_ROUTINES = "SELECT * FROM information_schema.ROUTINES";
                static constexpr const char *GET_SCHEMATA = "SELECT * FROM information_schema.SCHEMATA";
                static constexpr const char *GET_SCHEMA_PRIVILEGES = "SELECT * FROM information_schema.SCHEMA_PRIVILEGES";
                static constexpr const char *GET_SCHEMA_TABLES = "SELECT * FROM information_schema.tables";
                static constexpr const char *GET_SESSION_STATUS = "SELECT * FROM information_schema.SESSION_STATUS";
                static constexpr const char *GET_SESSION_VARIABLES = "SELECT * FROM information_schema.SESSION_VARIABLES";
                static constexpr const char *GET_STATISTICS = "SELECT * FROM information_schema.STATISTICS";
                static constexpr const char *GET_TABLES = "SELECT * FROM information_schema.TABLES";
                static constexpr const char *GET_TABLESPACES = "SELECT * FROM information_schema.TABLESPACES";
                static constexpr const char *GET_TABLE_CONSTRAINTS = "SELECT * FROM information_schema.TABLE_CONSTRAINTS";
                static constexpr const char *GET_TABLE_PRIVILEGES = "SELECT * FROM information_schema.TABLE_PRIVILEGES";
                static constexpr const char *GET_TRIGGERS = "SELECT * FROM information_schema.TRIGGERS";
                static constexpr const char *GET_USER_PRIVILEGES = "SELECT * FROM information_schema.USER_PRIVILEGES";
                static constexpr const char *GET_VIEWS = "SELECT * FROM information_schema.VIEWS";
                static constexpr const char *GET_INNODB_LOCKS = "SELECT * FROM information_schema.INNODB_LOCKS";
                static constexpr const char *GET_INNODB_TRX = "SELECT * FROM information_schema.INNODB_TRX";
                static constexpr const char *GET_INNODB_SYS_DATAFILES = "SELECT * FROM information_schema.INNODB_SYS_DATAFILES";
                static constexpr const char *GET_INNODB_FT_CONFIG = "SELECT * FROM information_schema.INNODB_FT_CONFIG";
                static constexpr const char *GET_INNODB_SYS_VIRTUAL = "SELECT * FROM information_schema.INNODB_SYS_VIRTUAL";
                static constexpr const char *GET_INNODB_CMP = "SELECT * FROM information_schema.INNODB_CMP";
                static constexpr const char *GET_INNODB_FT_BEING_DELETED = "SELECT * FROM information_schema.INNODB_FT_BEING_DELETED";
                static constexpr const char *GET_INNODB_CMP_RESET = "SELECT * FROM information_schema.INNODB_CMP_RESET";
                static constexpr const char *GET_INNODB_CMP_PER_INDEX = "SELECT * FROM information_schema.INNODB_CMP_PER_INDEX";
                static constexpr const char *GET_INNODB_CMPMEM_RESET = "SELECT * FROM information_schema.INNODB_CMPMEM_RESET";
                static constexpr const char *GET_INNODB_FT_DELETED = "SELECT * FROM information_schema.INNODB_FT_DELETED";
                static constexpr const char *GET_INNODB_BUFFER_PAGE_LRU = "SELECT * FROM information_schema.INNODB_BUFFER_PAGE_LRU";
                static constexpr const char *GET_INNODB_LOCK_WAITS = "SELECT * FROM information_schema.INNODB_LOCK_WAITS";
                static constexpr const char *GET_INNODB_TEMP_TABLE_INFO = "SELECT * FROM information_schema.INNODB_TEMP_TABLE_INFO";
                static constexpr const char *GET_INNODB_SYS_INDEXES = "SELECT * FROM information_schema.INNODB_SYS_INDEXES";
                static constexpr const char *GET_INNODB_SYS_TABLES = "SELECT * FROM information_schema.INNODB_SYS_TABLES";
                static constexpr const char *GET_INNODB_SYS_FIELDS = "SELECT * FROM information_schema.INNODB_SYS_FIELDS";
                static constexpr const char *GET_INNODB_CMP_PER_INDEX_RESET = "SELECT * FROM information_schema.INNODB_CMP_PER_INDEX_RESET";
                static constexpr const char *GET_INNODB_BUFFER_PAGE = "SELECT * FROM information_schema.INNODB_BUFFER_PAGE";
                static constexpr const char *GET_INNODB_FT_DEFAULT_STOPWORD = "SELECT * FROM information_schema.INNODB_FT_DEFAULT_STOPWORD";
                static constexpr const char *GET_INNODB_FT_INDEX_TABLE = "SELECT * FROM information_schema.INNODB_FT_INDEX_TABLE";
                static constexpr const char *GET_INNODB_FT_INDEX_CACHE = "SELECT * FROM information_schema.INNODB_FT_INDEX_CACHE";
                static constexpr const char *GET_INNODB_SYS_TABLESPACES = "SELECT * FROM information_schema.INNODB_SYS_TABLESPACES";
                static constexpr const char *GET_INNODB_METRICS = "SELECT * FROM information_schema.INNODB_METRICS";
                static constexpr const char *GET_INNODB_SYS_FOREIGN_COLS = "SELECT * FROM information_schema.INNODB_SYS_FOREIGN_COLS";
                static constexpr const char *GET_INNODB_CMPMEM = "SELECT * FROM information_schema.INNODB_CMPMEM";
                static constexpr const char *GET_INNODB_BUFFER_POOL_STATS = "SELECT * FROM information_schema.INNODB_BUFFER_POOL_STATS";
                static constexpr const char *GET_INNODB_SYS_COLUMNS = "SELECT * FROM information_schema.INNODB_SYS_COLUMNS";
                static constexpr const char *GET_INNODB_SYS_FOREIGN = "SELECT * FROM information_schema.INNODB_SYS_FOREIGN";
                static constexpr const char *GET_INNODB_SYS_TABLESTATS = "SELECT * FROM information_schema.INNODB_SYS_TABLESTATS";

                ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // SELECT DATA FROM MYSQL DATABASE
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                static constexpr const char *GET_COLUMNS_PRIV = "SELECT * FROM mysql.columns_priv";
                static constexpr const char *GET_DB = "SELECT * FROM mysql.db";
                static constexpr const char *GET_ENGINE_COST = "SELECT * FROM mysql.engine_cost";
                static constexpr const char *GET_EVENT = "SELECT * FROM mysql.event";
                static constexpr const char *GET_FUNC = "SELECT * FROM mysql.func";
                static constexpr const char *GET_GENERAL_LOG = "SELECT * FROM mysql.general_log";
                static constexpr const char *GET_GTID_EXECUTED = "SELECT * FROM mysql.gtid_executed";
                static constexpr const char *GET_HELP_CATEGORY = "SELECT * FROM mysql.help_category";
                static constexpr const char *GET_HELP_KEYWORD = "SELECT * FROM mysql.help_keyword";
                static constexpr const char *GET_HELP_RELATION = "SELECT * FROM mysql.help_relation";
                static constexpr const char *GET_HELP_TOPIC = "SELECT * FROM mysql.help_topic";
                static constexpr const char *GET_INNODB_INDEX_STATS = "SELECT * FROM mysql.innodb_index_stats";
                static constexpr const char *GET_INNODB_TABLE_STATS = "SELECT * FROM mysql.innodb_table_stats";
                static constexpr const char *GET_NDB_BINLOG_INDEX = "SELECT * FROM mysql.ndb_binlog_index";
                static constexpr const char *GET_PLUGIN = "SELECT * FROM mysql.plugin";
                static constexpr const char *GET_PROC = "SELECT * FROM mysql.proc";
                static constexpr const char *GET_PROCS_PRIV = "SELECT * FROM mysql.procs_priv";
                static constexpr const char *GET_PROXIES_PRIV = "SELECT * FROM mysql.proxies_priv";
                static constexpr const char *GET_SERVER_COST = "SELECT * FROM mysql.server_cost";
                static constexpr const char *GET_SERVERS = "SELECT * FROM mysql.servers";
                static constexpr const char *GET_SLAVE_MASTER_INFO = "SELECT * FROM mysql.slave_master_info";
                static constexpr const char *GET_SLAVE_RELAY_LOG_INFO = "SELECT * FROM mysql.slave_relay_log_info";
                static constexpr const char *GET_SLAVE_WORKER_INFO = "SELECT * FROM mysql.slave_worker_info";
                static constexpr const char *GET_SLOW_LOG = "SELECT * FROM mysql.slow_log";
                static constexpr const char *GET_TABLES_PRIV = "SELECT * FROM mysql.tables_priv";
                static constexpr const char *GET_TIME_ZONE = "SELECT * FROM mysql.time_zone";
                static constexpr const char *GET_TIME_ZONE_LEAP_SECOND = "SELECT * FROM mysql.time_zone_leap_second";
                static constexpr const char *GET_TIME_ZONE_NAME = "SELECT * FROM mysql.time_zone_name";
                static constexpr const char *GET_TIME_ZONE_TRANSITION = "SELECT * FROM mysql.time_zone_transition";
                static constexpr const char *GET_TIME_ZONE_TRANSITION_TYPE = "SELECT * FROM mysql.time_zone_transition_type";
                static constexpr const char *GET_USER = "SELECT * FROM mysql.user";
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_MYSQLQUERIES_H
