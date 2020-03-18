//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_KEYCOLUMNUSAGE_H
#define DBCRUDGEN_CPP_KEYCOLUMNUSAGE_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class KeyColumnUsage {

        private:
            std::string constraintCatalog;
            std::string constraintSchema;
            std::string constraintName;
            std::string tableCatalog;
            std::string tableSchema;
            std::string tableName;
            std::string columnName;
            long ordinalPosition;
            long positionInUniqueConstraint;
            std::string referencedTableSchema;
            std::string referencedTableName;
            std::string referencedColumnName;

        public:

            static constexpr const char *TABLE_NAME = "KEY_COLUMN_USAGE";

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
                struct TABLE_CATALOG {
                    static constexpr const char *NAME = "TABLE_CATALOG";
                    static const int INDEX = 4;
                };
                struct TABLE_SCHEMA {
                    static constexpr const char *NAME = "TABLE_SCHEMA";
                    static const int INDEX = 5;
                };
                struct TABLE_NAME {
                    static constexpr const char *NAME = "TABLE_NAME";
                    static const int INDEX = 6;
                };
                struct COLUMN_NAME {
                    static constexpr const char *NAME = "COLUMN_NAME";
                    static const int INDEX = 7;
                };
                struct ORDINAL_POSITION {
                    static constexpr const char *NAME = "ORDINAL_POSITION";
                    static const int INDEX = 8;
                };
                struct POSITION_IN_UNIQUE_CONSTRAINT {
                    static constexpr const char *NAME = "POSITION_IN_UNIQUE_CONSTRAINT";
                    static const int INDEX = 9;
                };
                struct REFERENCED_TABLE_SCHEMA {
                    static constexpr const char *NAME = "REFERENCED_TABLE_SCHEMA";
                    static const int INDEX = 10;
                };
                struct REFERENCED_TABLE_NAME {
                    static constexpr const char *NAME = "REFERENCED_TABLE_NAME";
                    static const int INDEX = 11;
                };
                struct REFERENCED_COLUMN_NAME {
                    static constexpr const char *NAME = "REFERENCED_COLUMN_NAME";
                    static const int INDEX = 12;
                };
            };

            KeyColumnUsage(std::string &constraintCatalog, std::string &constraintSchema, std::string &constraintName,
                           std::string &tableCatalog, std::string &tableSchema, std::string &tableName,
                           std::string &columnName, long ordinalPosition, long positionInUniqueConstraint,
                           std::string &referencedTableSchema, std::string &referencedTableName,
                           std::string &referencedColumnName) : constraintCatalog{constraintCatalog},
                                                                constraintSchema{constraintSchema},
                                                                constraintName{constraintName},
                                                                tableCatalog{tableCatalog}, tableSchema{tableSchema},
                                                                tableName{tableName}, columnName{columnName},
                                                                ordinalPosition{ordinalPosition},
                                                                positionInUniqueConstraint{positionInUniqueConstraint},
                                                                referencedTableSchema{referencedTableSchema},
                                                                referencedTableName{referencedTableName},
                                                                referencedColumnName{referencedColumnName} {}

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

            // Get the value of tableCatalog
            const std::string &getTableCatalog() const {
                return tableCatalog;
            }

            // Get the value of tableSchema
            const std::string &getTableSchema() const {
                return tableSchema;
            }

            // Get the value of tableName
            const std::string &getTableName() const {
                return tableName;
            }

            // Get the value of columnName
            const std::string &getColumnName() const {
                return columnName;
            }

            // Get the value of ordinalPosition
            long getOrdinalPosition() const {
                return ordinalPosition;
            }

            // Get the value of positionInUniqueConstraint
            long getPositionInUniqueConstraint() const {
                return positionInUniqueConstraint;
            }

            // Get the value of referencedTableSchema
            const std::string &getReferencedTableSchema() const {
                return referencedTableSchema;
            }

            // Get the value of referencedTableName
            const std::string &getReferencedTableName() const {
                return referencedTableName;
            }

            // Get the value of referencedColumnName
            const std::string &getReferencedColumnName() const {
                return referencedColumnName;
            }

            /**
            * Returns the table name 'KEY_COLUMN_USAGE';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_KEYCOLUMNUSAGE_H
