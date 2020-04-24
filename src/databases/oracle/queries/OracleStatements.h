//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/18/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLESTATEMENTS_H
#define DBCRUDGEN_CPP_ORACLESTATEMENTS_H

namespace dbcrudgen {
    namespace db {
        namespace oracle {

            //
            // OracleStatements
            // //
            class OracleStatements {

            public:
                constexpr static const char *GET_ALL_USERS = "SELECT * FROM ALL_USERS";
                constexpr static const char *GET_DBA_USERS = "SELECT * FROM DBA_USERS";
                constexpr static const char *GET_USER_ALL_TABLES = "SELECT * FROM ALL_TABLES WHERE OWNER = '${OWNER}'";
                constexpr static const char *GET_ALL_TABLES = "SELECT * FROM ALL_TABLES";
                constexpr static const char *GET_DBA_TABLES = "SELECT * FROM DBA_TABLES";
                constexpr static const char *GET_OBJECT_DDL = "SELECT DBMS_METADATA.GET_DDL('${OBJECT}', '${OBJECT_NAME}', '${SCHEMA}') FROM DUAL";
                constexpr static const char *GET_TABLE_DDL = "SELECT DBMS_METADATA.GET_DDL('TABLE', '${SCHEMA}', '${TABLE_NAME}') FROM DUAL";
                constexpr static const char *GET_TABLE_COLUMNS = "SELECT * FROM COLS WHERE TABLE_NAME = '${TABLE_NAME}'";
                constexpr static const char *GET_TABLE_COLUMNS_DBA = "SELECT * FROM DBA_TAB_COLS WHERE TABLE_NAME = '${TABLE_NAME}'";

            };
        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLESTATEMENTS_H
