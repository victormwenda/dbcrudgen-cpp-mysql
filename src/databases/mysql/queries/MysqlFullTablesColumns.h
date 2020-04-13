// Victor Mwenda
// E: vmwenda.vm@gmail.com
// P: +254718034449
//
//C++ Dev Computer
// Created by victor on 6/16/18.
//

#ifndef DBCRUDGEN_CPP_MYSQLFULLTABLESCOLUMNS_H
#define DBCRUDGEN_CPP_MYSQLFULLTABLESCOLUMNS_H

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class MysqlFullTablesColumns {
            public:
                constexpr static const char *TABLE_NAME = "Tables_in_${SCHEMA}";
                constexpr static const char *TABLE_TYPE = "Table_type";
            };


        }
    }
}

#endif //DBCRUDGEN_CPP_MYSQLFULLTABLESCOLUMNS_H
