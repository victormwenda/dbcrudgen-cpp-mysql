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
    constexpr static const char *SHOW_SCHEMAS_QUERY = "SHOW DATABASES";

    constexpr static const char *TABLE_SCHEMA_STATEMENT = "SELECT * FROM `INFORMATION_SCHEMA`.`TABLES` WHERE TABLE_NAME LIKE '${TABLE_NAME}'";

    constexpr static const char *TABLE_COLUMNS_FULL = "SHOW FULL COLUMNS IN ${TABLE_NAME}";

    constexpr static const char *SCHEMAS_TABLES_QUERY = "SHOW TABLES IN ${SCHEMA}";

    constexpr static const char *SCHEMAS_FULL_TABLES_QUERY = "SHOW FULL TABLES IN ${SCHEMA}";

    constexpr static const char *TABLES_CREATE_QUERY = "SHOW CREATE TABLE ${SCHEMAS}.${TABLE_NAME}";

    constexpr static const char *SCHEMAS_VIEWS_QUERY = "SHOW FULL TABLES IN ${SCHEMA} WHERE TABLE_TYPE LIKE '${TABLE_TYPE_VIEW}'";

    constexpr static const char *SCHEMAS_TABLES_QUERY2 = "SHOW FULL TABLES IN ${SCHEMA} WHERE TABLE_TYPE LIKE '${TABLE_TYPE_BASE_TABLE}'";
  
    constexpr static const char *VIEW_CREATE_QUERY = "SHOW CREATE VIEW ${SCHEMAS}.${VIEW_NAME}";

    constexpr static const char *KEY_COLUMN_USAGES = "SELECT * FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE TABLE_SCHEMA = '${SCHEMA}'";

    constexpr static const char *GET_USERS = "SELECT * FROM mysql.user";

};


#endif //DBCRUDGEN_CPP_STATEMENTS_H
