//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 4/14/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLRELATIONTYPES_H
#define DBCRUDGEN_CPP_MYSQLRELATIONTYPES_H


//
// MysqlRelationTypes
// //
class MysqlRelationTypes {

public:
    /**
     * MYSQL Relation types
     */
    constexpr static char const *TABLE_TYPE = "TABLE_TYPE";
    /**
     * MYSQL default table relation type
     */
    constexpr static char const * TABLE_TYPE_BASE_TABLE = "BASE TABLE";
    /**
     * MYSQL view relation type
     */
    constexpr static char const * TABLE_TYPE_VIEW = "VIEW";

};


#endif //DBCRUDGEN_CPP_MYSQLRELATIONTYPES_H
