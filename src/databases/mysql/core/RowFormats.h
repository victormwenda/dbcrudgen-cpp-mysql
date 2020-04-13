/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/15/17.
* C/C++ Laptop
*/


#ifndef DBCRUDGEN_CPP_ROWFORMATS_H
#define DBCRUDGEN_CPP_ROWFORMATS_H
namespace dbcrudgen {
    namespace db {
        namespace mysql {
            enum class MYSQLRowFormats {
                FIXED, DYNAMIC, COMPRESSED, REDUNDANT, COMPACT
            };
        }
    }
};

#endif //DBCRUDGEN_CPP_ROWFORMATS_H
