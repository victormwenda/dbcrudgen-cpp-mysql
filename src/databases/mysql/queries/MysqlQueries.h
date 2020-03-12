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
        };
    }
}


#endif //DBCRUDGEN_CPP_MYSQLQUERIES_H
