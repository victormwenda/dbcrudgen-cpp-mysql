//
// Created by victor on 4/15/20.
//

#ifndef DBCRUDGEN_CPP_FLAVOR_H
#define DBCRUDGEN_CPP_FLAVOR_H

namespace dbcrudgen {
    namespace db {
        namespace generic {
            enum class Flavor {
                DB2,
                DB2_AS_400,
                DB2_OS390,
                INGRES,
                MYSQL,
                MSSQL,
                ORACLE,
                ORACLE_9I,
                ORACLE_10G,
                POSTGRESQL,
                SAP_DB,
                SYBASE,
                SYBASE_ANYWHERE,
                SQLITE
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_FLAVOR_H
