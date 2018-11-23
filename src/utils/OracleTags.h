//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/19/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLETAGS_H
#define DBCRUDGEN_CPP_ORACLETAGS_H


//
// OracleTags
// //
class OracleTags {
public :
    constexpr static char *OWNER = "${OWNER}";
    constexpr static char *OBJECT = "${OBJECT}";
    constexpr static char *SCHEMA = "${SCHEMA}";
    constexpr static char *OBJECT_NAME = "${OBJECT_NAME}";
    constexpr static char *TABLE_NAME = "${TABLE_NAME}";
};


#endif //DBCRUDGEN_CPP_ORACLETAGS_H
