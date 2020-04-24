//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 4/14/18.
// C/C++ Laptop
//

#ifndef DBCRUDGEN_CPP_MYSQLTAGS_H
#define DBCRUDGEN_CPP_MYSQLTAGS_H

namespace dbcrudgen {
    namespace db {
        namespace oracle {
            //
            // MysqlTags
            // //
            class MysqlTags {
            public:
                constexpr static char const * TABLE_TYPE = "${TABLE_TYPE}";
                constexpr static char const * TABLE_TYPE_VIEW = "${TABLE_TYPE_VIEW}";
                constexpr static char const * TABLE_TYPE_BASE_TABLE = "${TABLE_TYPE_BASE_TABLE}";
            };

        }
    }
}

#endif //DBCRUDGEN_CPP_MYSQLTAGS_H
