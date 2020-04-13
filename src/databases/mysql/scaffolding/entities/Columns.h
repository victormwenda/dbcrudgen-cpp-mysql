//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_COLUMNS_H
#define DBCRUDGEN_CPP_COLUMNS_H

#include <string>

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class Columns {

            private:
                std::string tableCatalog;
                std::string tableSchema;
                std::string tableName;
                std::string columnName;
                long ordinalPosition;
                std::string columnDefault;
                std::string isNullable;
                std::string dataType;
                long characterMaximumLength;
                long characterOctetLength;
                long numericPrecision;
                long numericScale;
                long datetimePrecision;
                std::string characterSetName;
                std::string collationName;
                std::string columnType;
                std::string columnKey;
                std::string extra;
                std::string privileges;
                std::string columnComment;
                std::string generationExpression;

            public:

                static constexpr const char *TABLE_NAME = "COLUMNS";

                struct COLUMNS {
                    struct TABLE_CATALOG {
                        static constexpr const char *NAME = "TABLE_CATALOG";
                        static const int INDEX = 1;
                    };
                    struct TABLE_SCHEMA {
                        static constexpr const char *NAME = "TABLE_SCHEMA";
                        static const int INDEX = 2;
                    };
                    struct TABLE_NAME {
                        static constexpr const char *NAME = "TABLE_NAME";
                        static const int INDEX = 3;
                    };
                    struct COLUMN_NAME {
                        static constexpr const char *NAME = "COLUMN_NAME";
                        static const int INDEX = 4;
                    };
                    struct ORDINAL_POSITION {
                        static constexpr const char *NAME = "ORDINAL_POSITION";
                        static const int INDEX = 5;
                    };
                    struct COLUMN_DEFAULT {
                        static constexpr const char *NAME = "COLUMN_DEFAULT";
                        static const int INDEX = 6;
                    };
                    struct IS_NULLABLE {
                        static constexpr const char *NAME = "IS_NULLABLE";
                        static const int INDEX = 7;
                    };
                    struct DATA_TYPE {
                        static constexpr const char *NAME = "DATA_TYPE";
                        static const int INDEX = 8;
                    };
                    struct CHARACTER_MAXIMUM_LENGTH {
                        static constexpr const char *NAME = "CHARACTER_MAXIMUM_LENGTH";
                        static const int INDEX = 9;
                    };
                    struct CHARACTER_OCTET_LENGTH {
                        static constexpr const char *NAME = "CHARACTER_OCTET_LENGTH";
                        static const int INDEX = 10;
                    };
                    struct NUMERIC_PRECISION {
                        static constexpr const char *NAME = "NUMERIC_PRECISION";
                        static const int INDEX = 11;
                    };
                    struct NUMERIC_SCALE {
                        static constexpr const char *NAME = "NUMERIC_SCALE";
                        static const int INDEX = 12;
                    };
                    struct DATETIME_PRECISION {
                        static constexpr const char *NAME = "DATETIME_PRECISION";
                        static const int INDEX = 13;
                    };
                    struct CHARACTER_SET_NAME {
                        static constexpr const char *NAME = "CHARACTER_SET_NAME";
                        static const int INDEX = 14;
                    };
                    struct COLLATION_NAME {
                        static constexpr const char *NAME = "COLLATION_NAME";
                        static const int INDEX = 15;
                    };
                    struct COLUMN_TYPE {
                        static constexpr const char *NAME = "COLUMN_TYPE";
                        static const int INDEX = 16;
                    };
                    struct COLUMN_KEY {
                        static constexpr const char *NAME = "COLUMN_KEY";
                        static const int INDEX = 17;
                    };
                    struct EXTRA {
                        static constexpr const char *NAME = "EXTRA";
                        static const int INDEX = 18;
                    };
                    struct PRIVILEGES {
                        static constexpr const char *NAME = "PRIVILEGES";
                        static const int INDEX = 19;
                    };
                    struct COLUMN_COMMENT {
                        static constexpr const char *NAME = "COLUMN_COMMENT";
                        static const int INDEX = 20;
                    };
                    struct GENERATION_EXPRESSION {
                        static constexpr const char *NAME = "GENERATION_EXPRESSION";
                        static const int INDEX = 21;
                    };
                };

                Columns(std::string &tableCatalog, std::string &tableSchema, std::string &tableName,
                        std::string &columnName,
                        long ordinalPosition, std::string &columnDefault, std::string &isNullable,
                        std::string &dataType,
                        long characterMaximumLength, long characterOctetLength, long numericPrecision,
                        long numericScale,
                        long datetimePrecision, std::string &characterSetName, std::string &collationName,
                        std::string &columnType,
                        std::string &columnKey, std::string &extra, std::string &privileges, std::string &columnComment,
                        std::string &generationExpression) : tableCatalog{tableCatalog}, tableSchema{tableSchema},
                                                             tableName{tableName}, columnName{columnName},
                                                             ordinalPosition{ordinalPosition},
                                                             columnDefault{columnDefault},
                                                             isNullable{isNullable}, dataType{dataType},
                                                             characterMaximumLength{characterMaximumLength},
                                                             characterOctetLength{characterOctetLength},
                                                             numericPrecision{numericPrecision},
                                                             numericScale{numericScale},
                                                             datetimePrecision{datetimePrecision},
                                                             characterSetName{characterSetName},
                                                             collationName{collationName},
                                                             columnType{columnType}, columnKey{columnKey}, extra{extra},
                                                             privileges{privileges}, columnComment{columnComment},
                                                             generationExpression{generationExpression} {}

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

                // Get the value of columnDefault
                const std::string &getColumnDefault() const {
                    return columnDefault;
                }

                // Get the value of isNullable
                const std::string &getIsNullable() const {
                    return isNullable;
                }

                // Get the value of dataType
                const std::string &getDataType() const {
                    return dataType;
                }

                // Get the value of characterMaximumLength
                long getCharacterMaximumLength() const {
                    return characterMaximumLength;
                }

                // Get the value of characterOctetLength
                long getCharacterOctetLength() const {
                    return characterOctetLength;
                }

                // Get the value of numericPrecision
                long getNumericPrecision() const {
                    return numericPrecision;
                }

                // Get the value of numericScale
                long getNumericScale() const {
                    return numericScale;
                }

                // Get the value of datetimePrecision
                long getDatetimePrecision() const {
                    return datetimePrecision;
                }

                // Get the value of characterSetName
                const std::string &getCharacterSetName() const {
                    return characterSetName;
                }

                // Get the value of collationName
                const std::string &getCollationName() const {
                    return collationName;
                }

                // Get the value of columnType
                const std::string &getColumnType() const {
                    return columnType;
                }

                // Get the value of columnKey
                const std::string &getColumnKey() const {
                    return columnKey;
                }

                // Get the value of extra
                const std::string &getExtra() const {
                    return extra;
                }

                // Get the value of privileges
                const std::string &getPrivileges() const {
                    return privileges;
                }

                // Get the value of columnComment
                const std::string &getColumnComment() const {
                    return columnComment;
                }

                // Get the value of generationExpression
                const std::string &getGenerationExpression() const {
                    return generationExpression;
                }


                /**
                * Returns the table name 'COLUMNS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_COLUMNS_H
