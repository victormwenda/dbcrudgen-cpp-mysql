//
// Created by vrwanda on 3/12/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLQUERIES_H
#define DBCRUDGEN_CPP_MYSQLQUERIES_H

namespace dbcrudgen {
    namespace mysql {
        class MYSQLQueries {
        public:
            struct Tags {
                static constexpr const char *TABLE_SCHEMA = "${TABLE_SCHEMA}";
                static constexpr const char *TABLE_NAME = "${TABLE_NAME}";
            };

            static constexpr const char *GET_SCHEMAS = "SELECT * FROM information_schema.schemata";
            static constexpr const char *GET_SCHEMA_TABLES = "SELECT * FROM information_schema.tables WHERE table_schema = '${TABLE_SCHEMA}';";
            static constexpr const char *GET_SCHEMA_TABLE_COLUMNS =
                    "SELECT * FROM information_schema.columns WHERE table_schema = '${TABLE_SCHEMA}' AND table_name='${TABLE_NAME}';";
            static constexpr const char *GET_TABLE_CREATE_STATEMENT = "SHOW CREATE TABLE ${TABLE_SCHEMA}.${TABLE_NAME}";

            static constexpr const char *GET_CHARACTER_SETS = "SELECT * FROM CHARACTER_SETS";
            static constexpr const char *GET_COLLATIONS = "SELECT * FROM COLLATIONS";
            static constexpr const char *GET_COLLATION_CHARACTER_SET_APPLICABILITY = "SELECT * FROM COLLATION_CHARACTER_SET_APPLICABILITY";
            static constexpr const char *GET_COLUMNS = "SELECT * FROM COLUMNS";
            static constexpr const char *GET_COLUMN_PRIVILEGES = "SELECT * FROM COLUMN_PRIVILEGES";
            static constexpr const char *GET_ENGINES = "SELECT * FROM ENGINES";
            static constexpr const char *GET_EVENTS = "SELECT * FROM EVENTS";
            static constexpr const char *GET_FILES = "SELECT * FROM FILES";
            static constexpr const char *GET_GLOBAL_STATUS = "SELECT * FROM GLOBAL_STATUS";
            static constexpr const char *GET_GLOBAL_VARIABLES = "SELECT * FROM GLOBAL_VARIABLES";
            static constexpr const char *GET_KEY_COLUMN_USAGE = "SELECT * FROM KEY_COLUMN_USAGE";
            static constexpr const char *GET_OPTIMIZER_TRACE = "SELECT * FROM OPTIMIZER_TRACE";
            static constexpr const char *GET_PARAMETERS = "SELECT * FROM PARAMETERS";
            static constexpr const char *GET_PARTITIONS = "SELECT * FROM PARTITIONS";
            static constexpr const char *GET_PLUGINS = "SELECT * FROM PLUGINS";
            static constexpr const char *GET_PROCESSLIST = "SELECT * FROM PROCESSLIST";
            static constexpr const char *GET_PROFILING = "SELECT * FROM PROFILING";
            static constexpr const char *GET_REFERENTIAL_CONSTRAINTS = "SELECT * FROM REFERENTIAL_CONSTRAINTS";
            static constexpr const char *GET_ROUTINES = "SELECT * FROM ROUTINES";
            static constexpr const char *GET_SCHEMATA = "SELECT * FROM SCHEMATA";
            static constexpr const char *GET_SCHEMA_PRIVILEGES = "SELECT * FROM SCHEMA_PRIVILEGES";
            static constexpr const char *GET_SESSION_STATUS = "SELECT * FROM SESSION_STATUS";
            static constexpr const char *GET_SESSION_VARIABLES = "SELECT * FROM SESSION_VARIABLES";
            static constexpr const char *GET_STATISTICS = "SELECT * FROM STATISTICS";
            static constexpr const char *GET_TABLES = "SELECT * FROM TABLES";
            static constexpr const char *GET_TABLESPACES = "SELECT * FROM TABLESPACES";
            static constexpr const char *GET_TABLE_CONSTRAINTS = "SELECT * FROM TABLE_CONSTRAINTS";
            static constexpr const char *GET_TABLE_PRIVILEGES = "SELECT * FROM TABLE_PRIVILEGES";
            static constexpr const char *GET_TRIGGERS = "SELECT * FROM TRIGGERS";
            static constexpr const char *GET_USER_PRIVILEGES = "SELECT * FROM USER_PRIVILEGES";
            static constexpr const char *GET_VIEWS = "SELECT * FROM VIEWS";
            static constexpr const char *GET_INNODB_LOCKS = "SELECT * FROM INNODB_LOCKS";
            static constexpr const char *GET_INNODB_TRX = "SELECT * FROM INNODB_TRX";
            static constexpr const char *GET_INNODB_SYS_DATAFILES = "SELECT * FROM INNODB_SYS_DATAFILES";
            static constexpr const char *GET_INNODB_FT_CONFIG = "SELECT * FROM INNODB_FT_CONFIG";
            static constexpr const char *GET_INNODB_SYS_VIRTUAL = "SELECT * FROM INNODB_SYS_VIRTUAL";
            static constexpr const char *GET_INNODB_CMP = "SELECT * FROM INNODB_CMP";
            static constexpr const char *GET_INNODB_FT_BEING_DELETED = "SELECT * FROM INNODB_FT_BEING_DELETED";
            static constexpr const char *GET_INNODB_CMP_RESET = "SELECT * FROM INNODB_CMP_RESET";
            static constexpr const char *GET_INNODB_CMP_PER_INDEX = "SELECT * FROM INNODB_CMP_PER_INDEX";
            static constexpr const char *GET_INNODB_CMPMEM_RESET = "SELECT * FROM INNODB_CMPMEM_RESET";
            static constexpr const char *GET_INNODB_FT_DELETED = "SELECT * FROM INNODB_FT_DELETED";
            static constexpr const char *GET_INNODB_BUFFER_PAGE_LRU = "SELECT * FROM INNODB_BUFFER_PAGE_LRU";
            static constexpr const char *GET_INNODB_LOCK_WAITS = "SELECT * FROM INNODB_LOCK_WAITS";
            static constexpr const char *GET_INNODB_TEMP_TABLE_INFO = "SELECT * FROM INNODB_TEMP_TABLE_INFO";
            static constexpr const char *GET_INNODB_SYS_INDEXES = "SELECT * FROM INNODB_SYS_INDEXES";
            static constexpr const char *GET_INNODB_SYS_TABLES = "SELECT * FROM INNODB_SYS_TABLES";
            static constexpr const char *GET_INNODB_SYS_FIELDS = "SELECT * FROM INNODB_SYS_FIELDS";
            static constexpr const char *GET_INNODB_CMP_PER_INDEX_RESET = "SELECT * FROM INNODB_CMP_PER_INDEX_RESET";
            static constexpr const char *GET_INNODB_BUFFER_PAGE = "SELECT * FROM INNODB_BUFFER_PAGE";
            static constexpr const char *GET_INNODB_FT_DEFAULT_STOPWORD = "SELECT * FROM INNODB_FT_DEFAULT_STOPWORD";
            static constexpr const char *GET_INNODB_FT_INDEX_TABLE = "SELECT * FROM INNODB_FT_INDEX_TABLE";
            static constexpr const char *GET_INNODB_FT_INDEX_CACHE = "SELECT * FROM INNODB_FT_INDEX_CACHE";
            static constexpr const char *GET_INNODB_SYS_TABLESPACES = "SELECT * FROM INNODB_SYS_TABLESPACES";
            static constexpr const char *GET_INNODB_METRICS = "SELECT * FROM INNODB_METRICS";
            static constexpr const char *GET_INNODB_SYS_FOREIGN_COLS = "SELECT * FROM INNODB_SYS_FOREIGN_COLS";
            static constexpr const char *GET_INNODB_CMPMEM = "SELECT * FROM INNODB_CMPMEM";
            static constexpr const char *GET_INNODB_BUFFER_POOL_STATS = "SELECT * FROM INNODB_BUFFER_POOL_STATS";
            static constexpr const char *GET_INNODB_SYS_COLUMNS = "SELECT * FROM INNODB_SYS_COLUMNS";
            static constexpr const char *GET_INNODB_SYS_FOREIGN = "SELECT * FROM INNODB_SYS_FOREIGN";
            static constexpr const char *GET_INNODB_SYS_TABLESTATS = "SELECT * FROM INNODB_SYS_TABLESTATS";
        };
    }
}


#endif //DBCRUDGEN_CPP_MYSQLQUERIES_H
