//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/19/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLETAGS_H
#define DBCRUDGEN_CPP_ORACLETAGS_H

namespace dbcrudgen {
    namespace db {
        namespace oracle {
            //
            // OracleTags
            // //
            class OracleTags {
            public :
                constexpr static char const *OWNER = "${OWNER}";
                constexpr static char const *OBJECT = "${OBJECT}";
                constexpr static char const *SCHEMA = "${SCHEMA}";
                constexpr static char const *OBJECT_NAME = "${OBJECT_NAME}";
                constexpr static char const *TABLE_NAME = "${TABLE_NAME}";
            };

        }
    }
}




#endif //DBCRUDGEN_CPP_ORACLETAGS_H
