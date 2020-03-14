//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_DATABASES_H
#define DBCRUDGEN_CPP_DATABASES_H
namespace dbcrudgen {
    namespace orm {
        class Databases {
        public:
            static constexpr const char *MYSQL = "MySQL";
            static constexpr const char *ORACLE = "Oracle";
            static constexpr const char *SQLite = "SQLite";
            static constexpr const char *MsSQL = "MsSQL";
        };
    }
}
#endif //DBCRUDGEN_CPP_DATABASES_H
