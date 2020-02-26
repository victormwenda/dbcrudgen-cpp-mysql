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
    constexpr static char const * SCHEMAS = "${SCHEMAS}";
    constexpr static char const * SCHEMA = "${SCHEMA}";
    constexpr static char const * TABLE_NAME = "${TABLE_NAME}";
    constexpr static char const * VIEW_NAME = "${VIEW_NAME}";
};


#endif //DBCRUDGEN_CPP_TAGS_H
