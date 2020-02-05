//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/19/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEUSERTABLESCOLUMNS_H
#define DBCRUDGEN_CPP_ORACLEUSERTABLESCOLUMNS_H


#include "OracleAllTablesColumns.h"

//
// OracleUserTablesColumns
// The columns for the table 'ALL_TABLES'
//
// SELECT * FROM ALL_TABLES WHERE OWNER = 'VICTOR';
//
class OracleUserTablesColumns : public OracleAllTablesColumns{

public:

    OracleUserTablesColumns() {}

};


#endif //DBCRUDGEN_CPP_ORACLEUSERTABLESCOLUMNS_H
