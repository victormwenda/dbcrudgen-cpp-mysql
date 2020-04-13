//
// Created by vrwanda on 3/5/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLOBJECTS_H
#define DBCRUDGEN_CPP_MYSQLOBJECTS_H
namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class MYSQLObjects {
            public:

                struct Alias {
                    static constexpr int IDENTIFIER_MAX_LENGTH = 256;
                };

                struct Column {
                    static constexpr bool CASE_SENSITIVE = false;
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct CompoundStatementLabel {
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct Condition {
                    static constexpr bool CASE_SENSITIVE = true;
                };

                struct Constraint {
                    static constexpr bool CASE_SENSITIVE = true;
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct Cursor {
                    static constexpr bool CASE_SENSITIVE = true;
                };

                struct Database {
                    static constexpr bool CASE_SENSITIVE = true;
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                    static constexpr const char *TYPE = "directory";
                };

                struct Event {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct Function {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct Index {
                    static constexpr bool CASE_SENSITIVE = false;
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct LogFile {
                    static constexpr bool CASE_SENSITIVE = true;
                };

                struct LogFileGroup {
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct ResourceGroup {
                    static constexpr bool CASE_SENSITIVE = false;
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct Partition {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct Plugin {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct Procedure {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct Savepoint {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct Server {
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct SubPartition {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct StoredProgram {
                    static constexpr bool CASE_SENSITIVE = false;
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct StoredRoutine {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct StoredRoutineParams {
                    static constexpr bool CASE_SENSITIVE = false;
                };

                struct Table {
                    static constexpr bool CASE_SENSITIVE = true;
                    static constexpr const char *TYPE = "file";
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct TableAlias {
                    static constexpr bool CASE_SENSITIVE = true;
                };

                struct Tablespace {
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct Trigger {
                    static constexpr bool CASE_SENSITIVE = true;
                    static constexpr const char *TYPE = "file";
                };

                struct UserDefinedVariable {
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };

                struct Users {
                    static constexpr bool CASE_SENSITIVE = true;
                };

                struct View {
                    static constexpr int IDENTIFIER_MAX_LENGTH = 64;
                };
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_MYSQLOBJECTS_H
