//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_REFERENTIALCONSTRAINTS_H
#define DBCRUDGEN_CPP_REFERENTIALCONSTRAINTS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class ReferentialConstraints {

        private:
            std::string constraintCatalog;
            std::string constraintSchema;
            std::string constraintName;
            std::string uniqueConstraintCatalog;
            std::string uniqueConstraintSchema;
            std::string uniqueConstraintName;
            std::string matchOption;
            std::string updateRule;
            std::string deleteRule;
            std::string tableName;
            std::string referencedTableName;

        public:

            static constexpr const char *TABLE_NAME = "REFERENTIAL_CONSTRAINTS";

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
                struct UNIQUE_CONSTRAINT_CATALOG {
                    static constexpr const char *NAME = "UNIQUE_CONSTRAINT_CATALOG";
                    static const int INDEX = 4;
                };
                struct UNIQUE_CONSTRAINT_SCHEMA {
                    static constexpr const char *NAME = "UNIQUE_CONSTRAINT_SCHEMA";
                    static const int INDEX = 5;
                };
                struct UNIQUE_CONSTRAINT_NAME {
                    static constexpr const char *NAME = "UNIQUE_CONSTRAINT_NAME";
                    static const int INDEX = 6;
                };
                struct MATCH_OPTION {
                    static constexpr const char *NAME = "MATCH_OPTION";
                    static const int INDEX = 7;
                };
                struct UPDATE_RULE {
                    static constexpr const char *NAME = "UPDATE_RULE";
                    static const int INDEX = 8;
                };
                struct DELETE_RULE {
                    static constexpr const char *NAME = "DELETE_RULE";
                    static const int INDEX = 9;
                };
                struct TABLE_NAME {
                    static constexpr const char *NAME = "TABLE_NAME";
                    static const int INDEX = 10;
                };
                struct REFERENCED_TABLE_NAME {
                    static constexpr const char *NAME = "REFERENCED_TABLE_NAME";
                    static const int INDEX = 11;
                };
            };

            ReferentialConstraints(std::string &constraintCatalog, std::string &constraintSchema,
                                   std::string &constraintName, std::string &uniqueConstraintCatalog,
                                   std::string &uniqueConstraintSchema, std::string &uniqueConstraintName,
                                   std::string &matchOption, std::string &updateRule, std::string &deleteRule,
                                   std::string &tableName, std::string &referencedTableName) :
                    constraintCatalog{constraintCatalog}, constraintSchema{constraintSchema},
                    constraintName{constraintName}, uniqueConstraintCatalog{uniqueConstraintCatalog},
                    uniqueConstraintSchema{uniqueConstraintSchema}, uniqueConstraintName{uniqueConstraintName},
                    matchOption{matchOption}, updateRule{updateRule}, deleteRule{deleteRule}, tableName{tableName},
                    referencedTableName{referencedTableName} {}

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

            // Get the value of uniqueConstraintCatalog
            const std::string &getUniqueConstraintCatalog() const {
                return uniqueConstraintCatalog;
            }

            // Get the value of uniqueConstraintSchema
            const std::string &getUniqueConstraintSchema() const {
                return uniqueConstraintSchema;
            }

            // Get the value of uniqueConstraintName
            const std::string &getUniqueConstraintName() const {
                return uniqueConstraintName;
            }

            // Get the value of matchOption
            const std::string &getMatchOption() const {
                return matchOption;
            }

            // Get the value of updateRule
            const std::string &getUpdateRule() const {
                return updateRule;
            }

            // Get the value of deleteRule
            const std::string &getDeleteRule() const {
                return deleteRule;
            }

            // Get the value of tableName
            const std::string &getTableName() const {
                return tableName;
            }

            // Get the value of referencedTableName
            const std::string &getReferencedTableName() const {
                return referencedTableName;
            }


            /**
            * Returns the table name 'REFERENTIAL_CONSTRAINTS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_REFERENTIALCONSTRAINTS_H
