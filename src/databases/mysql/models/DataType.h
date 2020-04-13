//
// Created by vrwanda on 3/13/20.
//

#ifndef DBCRUDGEN_CPP_DATATYPE_H
#define DBCRUDGEN_CPP_DATATYPE_H

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            enum class DataType : char {
                BOOLEAN, DATE_TIME, JSON, NUMERICAL, SPATIAL, STRING
            };
        }
    }
}

#endif //DBCRUDGEN_CPP_DATATYPE_H
