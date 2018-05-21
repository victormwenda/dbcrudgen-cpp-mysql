//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/10/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_TAGS_H
#define DBCRUDGEN_CPP_TAGS_H

#include <string>

//
// Tags
// //
class Tags {

public :
    constexpr static char * SCHEMAS = "${SCHEMAS}";
    constexpr static char * SCHEMA = "${SCHEMA}";
    constexpr static char * TABLE_NAME = "${TABLE_NAME}";
    constexpr static char * VIEW_NAME = "${VIEW_NAME}";
};


#endif //DBCRUDGEN_CPP_TAGS_H
