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
    constexpr static char * TABLE_SCHEMA_STATEMENT = "SELECT * FROM `INFORMATION_SCHEMA`.`TABLES` WHERE TABLE_NAME LIKE '${TABLE_NAME}'";

    constexpr static char *  TABLE_COLUMNS_FULL = "SHOW FULL COLUMNS IN ${TABLE_NAME}";
};


#endif //DBCRUDGEN_CPP_STATEMENTS_H
