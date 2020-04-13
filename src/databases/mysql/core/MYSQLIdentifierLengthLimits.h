//
// Created by vrwanda on 3/5/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLIDENTIFIERLENGTHLIMITS_H
#define DBCRUDGEN_CPP_MYSQLIDENTIFIERLENGTHLIMITS_H

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class MYSQLIdentifierLengthLimits {

            public:
                struct Database {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct Table {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct Column {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct Index {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct Constraint {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct StoredProgram {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct View {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct Tablespace {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct Server {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct LogFileGroup {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct Alias {
                    static constexpr int MAX_LIMIT = 256;
                };
                struct CompoundStatementLabel {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct UserDefinedVariable {
                    static constexpr int MAX_LIMIT = 64;
                };
                struct ResourceGroup {
                    static constexpr int MAX_LIMIT = 64;
                };
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_MYSQLIDENTIFIERLENGTHLIMITS_H
