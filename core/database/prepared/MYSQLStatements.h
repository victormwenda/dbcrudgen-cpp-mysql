//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/10/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_STATEMENTS_H
#define DBCRUDGEN_CPP_STATEMENTS_H

#include <string>

//
// statements
// //
class MYSQLStatements {

public:
    constexpr static char *SHOW_SCHEMAS_QUERY = "SHOW DATABASES";

    constexpr static char *TABLE_SCHEMA_STATEMENT = "SELECT * FROM `INFORMATION_SCHEMA`.`TABLES` WHERE TABLE_NAME LIKE '${TABLE_NAME}'";

    constexpr static char *TABLE_COLUMNS_FULL = "SHOW FULL COLUMNS IN ${TABLE_NAME}";

    constexpr static char *SCHEMAS_TABLES_QUERY = "SHOW TABLES IN ${SCHEMA}";

    constexpr static char *TABLES_CREATE_QUERY = "SHOW CREATE TABLE ${SCHEMAS}.${TABLE_NAME}";

    constexpr static char *SCHEMAS_VIEWS_QUERY = "SHOW FULL TABLES IN ${SCHEMA} WHERE TABLE_TYPE LIKE '${TABLE_TYPE_VIEW}'";

    constexpr static char *SCHEMAS_TABLES_QUERY2 = "SHOW FULL TABLES IN ${SCHEMA} WHERE TABLE_TYPE LIKE '${TABLE_TYPE_BASE_TABLE}'";
};


#endif //DBCRUDGEN_CPP_STATEMENTS_H
