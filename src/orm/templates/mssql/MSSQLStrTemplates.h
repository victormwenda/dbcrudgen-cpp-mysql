//
// Created by victor on 12/26/20.
//

#ifndef DBCRUDGEN_CPP_MSSQLSTRTEMPLATES_H
#define DBCRUDGEN_CPP_MSSQLSTRTEMPLATES_H

namespace dbcrudgen {
    namespace orm {
        namespace mssql {
            class MSSQLStrTemplates {
            public:
                struct CONN_STR {
                    static constexpr const char *TEMPLATE = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=${HOST},${PORT};DATABASE=${DATABASE};UID=${USER};PWD=${PASSWORD}";
                };
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_MSSQLSTRTEMPLATES_H
