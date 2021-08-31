//
// Created by victor on 8/31/21.
//

#ifndef DBCRUDGEN_CPP_MSSQLQUERIES_H
#define DBCRUDGEN_CPP_MSSQLQUERIES_H

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLQueries {
            public:
                /////////////////////////////////////////////////////////////////////////////////
                // SYS OBJECTS
                ////////////////////////////////////////////////////////////////////////////////
                static constexpr const char *GET_SYS_DATABASES = "select * from sys.databases;";
            };
        }
    }
}

#endif //DBCRUDGEN_CPP_MSSQLQUERIES_H
