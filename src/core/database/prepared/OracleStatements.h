//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/18/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLESTATEMENTS_H
#define DBCRUDGEN_CPP_ORACLESTATEMENTS_H


//
// OracleStatements
// //
class OracleStatements {

public:
    constexpr static const char *GET_ALL_USERS = "SELECT * FROM ALL_USERS";
    constexpr static const char *GET_DBA_USERS = "SELECT * FROM DBA_USERS";
};


#endif //DBCRUDGEN_CPP_ORACLESTATEMENTS_H
