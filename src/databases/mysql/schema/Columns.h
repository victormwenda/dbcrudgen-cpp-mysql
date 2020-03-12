//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_COLUMNS_H
#define DBCRUDGEN_CPP_COLUMNS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class Columns {

        private:
            std::string table_catalog;
            std::string table_schema;
            std::string table_name;
            std::string column_name;
            long ordinal_position;
            std::string column_default;
            std::string is_nullable;
            std::string data_type;
            long character_maximum_length;
            long character_octet_length;
            long numeric_precision;
            long numeric_scale;
            long datetime_precision;
            std::string character_set_name;
            std::string collation_name;
            std::string column_type;
            std::string column_key;
            std::string extra;
            std::string privileges;
            std::string column_comment;
            std::string generation_expression;

        public:
            Columns(std::string &tableCatalog, std::string &tableSchema, std::string &tableName,
                    std::string &columnName, long ordinalPosition, std::string &columnDefault, std::string &isNullable,
                    std::string &dataType, long characterMaximumLength, long characterOctetLength,
                    long numericPrecision, long numericScale, long datetimePrecision, std::string &characterSetName,
                    std::string &collationName, std::string &columnType, std::string &columnKey, std::string &extra,
                    std::string &privileges, std::string &columnComment, std::string &generationExpression)
                    : table_catalog(tableCatalog), table_schema(tableSchema), table_name(tableName),
                      column_name(columnName), ordinal_position(ordinalPosition), column_default(columnDefault),
                      is_nullable(isNullable), data_type(dataType), character_maximum_length(characterMaximumLength),
                      character_octet_length(characterOctetLength), numeric_precision(numericPrecision),
                      numeric_scale(numericScale), datetime_precision(datetimePrecision),
                      character_set_name(characterSetName), collation_name(collationName), column_type(columnType),
                      column_key(columnKey), extra(extra), privileges(privileges), column_comment(columnComment),
                      generation_expression(generationExpression) {}

            const std::string &getTableCatalog() const {
                return table_catalog;
            }

            const std::string &getTableSchema() const {
                return table_schema;
            }

            const std::string &getTableName() const {
                return table_name;
            }

            const std::string &getColumnName() const {
                return column_name;
            }

            long getOrdinalPosition() const {
                return ordinal_position;
            }

            const std::string &getColumnDefault() const {
                return column_default;
            }

            const std::string &getIsNullable() const {
                return is_nullable;
            }

            const std::string &getDataType() const {
                return data_type;
            }

            long getCharacterMaximumLength() const {
                return character_maximum_length;
            }

            long getCharacterOctetLength() const {
                return character_octet_length;
            }

            long getNumericPrecision() const {
                return numeric_precision;
            }

            long getNumericScale() const {
                return numeric_scale;
            }

            long getDatetimePrecision() const {
                return datetime_precision;
            }

            const std::string &getCharacterSetName() const {
                return character_set_name;
            }

            const std::string &getCollationName() const {
                return collation_name;
            }

            const std::string &getColumnType() const {
                return column_type;
            }

            const std::string &getColumnKey() const {
                return column_key;
            }

            const std::string &getExtra() const {
                return extra;
            }

            const std::string &getPrivileges() const {
                return privileges;
            }

            const std::string &getColumnComment() const {
                return column_comment;
            }

            const std::string &getGenerationExpression() const {
                return generation_expression;
            }

            struct TABLE_CATALOG {
                static constexpr const int INDEX = 1;
                static constexpr const char *NAME = "TABLE_CATALOG";
            };
            struct TABLE_SCHEMA {
                static constexpr const int INDEX = 2;
                static constexpr const char *NAME = "TABLE_SCHEMA";
            };
            struct TABLE_NAME {
                static constexpr const int INDEX = 3;
                static constexpr const char *NAME = "TABLE_NAME";
            };
            struct COLUMN_NAME {
                static constexpr const int INDEX = 4;
                static constexpr const char *NAME = "COLUMN_NAME";
            };
            struct ORDINAL_POSITION {
                static constexpr const int INDEX = 5;
                static constexpr const char *NAME = "ORDINAL_POSITION";
            };
            struct COLUMN_DEFAULT {
                static constexpr const int INDEX = 6;
                static constexpr const char *NAME = "COLUMN_DEFAULT";
            };
            struct IS_NULLABLE {
                static constexpr const int INDEX = 7;
                static constexpr const char *NAME = "IS_NULLABLE";
            };
            struct DATA_TYPE {
                static constexpr const int INDEX = 8;
                static constexpr const char *NAME = "DATA_TYPE";
            };
            struct CHARACTER_MAXIMUM_LENGTH {
                static constexpr const int INDEX = 9;
                static constexpr const char *NAME = "CHARACTER_MAXIMUM_LENGTH";
            };
            struct CHARACTER_OCTET_LENGTH {
                static constexpr const int INDEX = 10;
                static constexpr const char *NAME = "CHARACTER_OCTET_LENGTH";
            };
            struct NUMERIC_PRECISION {
                static constexpr const int INDEX = 11;
                static constexpr const char *NAME = "NUMERIC_PRECISION";
            };
            struct NUMERIC_SCALE {
                static constexpr const int INDEX = 12;
                static constexpr const char *NAME = "NUMERIC_SCALE";
            };
            struct DATETIME_PRECISION {
                static constexpr const int INDEX = 13;
                static constexpr const char *NAME = "DATETIME_PRECISION";
            };
            struct CHARACTER_SET_NAME {
                static constexpr const int INDEX = 14;
                static constexpr const char *NAME = "CHARACTER_SET_NAME";
            };
            struct COLLATION_NAME {
                static constexpr const int INDEX = 15;
                static constexpr const char *NAME = "COLLATION_NAME";
            };
            struct COLUMN_TYPE {
                static constexpr const int INDEX = 16;
                static constexpr const char *NAME = "COLUMN_TYPE";
            };
            struct COLUMN_KEY {
                static constexpr const int INDEX = 17;
                static constexpr const char *NAME = "COLUMN_KEY";
            };
            struct EXTRA {
                static constexpr const int INDEX = 18;
                static constexpr const char *NAME = "EXTRA";
            };
            struct PRIVILEGES {
                static constexpr const int INDEX = 19;
                static constexpr const char *NAME = "PRIVILEGES";
            };
            struct COLUMN_COMMENT {
                static constexpr const int INDEX = 20;
                static constexpr const char *NAME = "COLUMN_COMMENT";
            };
            struct GENERATION_EXPRESSION {
                static constexpr const int INDEX = 21;
                static constexpr const char *NAME = "GENERATION_EXPRESSION";
            };
        };
    }
}


#endif //DBCRUDGEN_CPP_COLUMNS_H
