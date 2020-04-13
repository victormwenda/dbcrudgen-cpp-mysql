//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_TABLECONSTRAINTS_H
#define DBCRUDGEN_CPP_TABLECONSTRAINTS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class TableConstraints {

            private:
                std::string constraintCatalog;
                std::string constraintSchema;
                std::string constraintName;
                std::string tableSchema;
                std::string tableName;
                std::string constraintType;

            public:

                static constexpr const char *TABLE_NAME = "TABLE_CONSTRAINTS";

                struct COLUMNS {
                    struct CONSTRAINT_CATALOG {
                        static constexpr const char *NAME = "CONSTRAINT_CATALOG";
                        static const int INDEX = 1;
                    };
                    struct CONSTRAINT_SCHEMA {
                        static constexpr const char *NAME = "CONSTRAINT_SCHEMA";
                        static const int INDEX = 2;
                    };
                    struct CONSTRAINT_NAME {
                        static constexpr const char *NAME = "CONSTRAINT_NAME";
                        static const int INDEX = 3;
                    };
                    struct TABLE_SCHEMA {
                        static constexpr const char *NAME = "TABLE_SCHEMA";
                        static const int INDEX = 4;
                    };
                    struct TABLE_NAME {
                        static constexpr const char *NAME = "TABLE_NAME";
                        static const int INDEX = 5;
                    };
                    struct CONSTRAINT_TYPE {
                        static constexpr const char *NAME = "CONSTRAINT_TYPE";
                        static const int INDEX = 6;
                    };
                };

                TableConstraints(std::string &constraintCatalog, std::string &constraintSchema,
                                 std::string &constraintName,
                                 std::string &tableSchema, std::string &tableName, std::string &constraintType)
                        : constraintCatalog{constraintCatalog}, constraintSchema{constraintSchema},
                          constraintName{constraintName}, tableSchema{tableSchema}, tableName{tableName},
                          constraintType{constraintType} {}

                // Get the value of constraintCatalog
                const std::string &getConstraintCatalog() const {
                    return constraintCatalog;
                }

                // Get the value of constraintSchema
                const std::string &getConstraintSchema() const {
                    return constraintSchema;
                }

                // Get the value of constraintName
                const std::string &getConstraintName() const {
                    return constraintName;
                }

                // Get the value of tableSchema
                const std::string &getTableSchema() const {
                    return tableSchema;
                }

                // Get the value of tableName
                const std::string &getTableName() const {
                    return tableName;
                }

                // Get the value of constraintType
                const std::string &getConstraintType() const {
                    return constraintType;
                }

                /**
                * Returns the table name 'TABLE_CONSTRAINTS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };

        }
    }

}


#endif //DBCRUDGEN_CPP_TABLECONSTRAINTS_H
