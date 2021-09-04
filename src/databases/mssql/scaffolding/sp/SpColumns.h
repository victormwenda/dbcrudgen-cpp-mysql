//
// Created by victor on 9/4/21.
//

#ifndef DBCRUDGEN_CPP_SPCOLUMNS_H
#define DBCRUDGEN_CPP_SPCOLUMNS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            /**
             * Returns column information for the specified objects that can be queried in the current environment.
             * sp_columns [ @table_name = ] object
             *  [ , [ @table_owner = ] owner ]
             *  [ , [ @table_qualifier = ] qualifier ]
             *  [ , [ @column_name = ] column ]
             *  [ , [ @ODBCVer = ] ODBCVer ]
             * https://docs.microsoft.com/en-us/sql/relational-databases/system-stored-procedures/sp-columns-transact-sql?view=sql-server-ver15
             */
            class SpColumns {
            private:
                std::string table_qualifier;
                std::string table_owner;
                std::string table_name;
                std::string column_name;
                signed int data_type;
                std::string type_name;
                int precision;
                int length;
                int scale;
                int radix;
                bool nullable;
                std::string remarks;
                std::string column_def;
                int sql_data_type;
                int sql_datetime_sub;
                int char_octet_length;
                int ordinal_position;
                std::string is_nullable;
                int ss_data_type;
            public:
                static constexpr const char *TABLE_NAME = "sp_columns";

                struct COLUMNS {
                    struct TABLE_QUALIFIER {
                        static constexpr const char *NAME = "table_qualifier";
                        static const int INDEX = 1;
                        static constexpr const char *DATA_TYPE = "sysname";
                    };
                    struct TABLE_OWNER {
                        static constexpr const char *NAME = "table_owner";
                        static const int INDEX = 2;
                        static constexpr const char *DATA_TYPE = "sysname";
                    };
                    struct TABLE_NAME {
                        static constexpr const char *NAME = "table_name";
                        static const int INDEX = 3;
                        static constexpr const char *DATA_TYPE = "sysname";
                    };
                    struct COLUMN_NAME {
                        static constexpr const char *NAME = "column_name";
                        static const int INDEX = 4;
                        static constexpr const char *DATA_TYPE = "sysname";
                    };
                    struct DATA_TYPE {
                        static constexpr const char *NAME = "data_type";
                        static const int INDEX = 5;
                        static constexpr const char *DATA_TYPE_ = "smallint";
                    };
                    struct TYPE_NAME {
                        static constexpr const char *NAME = "type_name";
                        static const int INDEX = 6;
                        static constexpr const char *DATA_TYPE = "sysname";
                    };
                    struct PRECISION {
                        static constexpr const char *NAME = "precision";
                        static const int INDEX = 7;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct LENGTH {
                        static constexpr const char *NAME = "length";
                        static const int INDEX = 8;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct SCALE {
                        static constexpr const char *NAME = "scale";
                        static const int INDEX = 9;
                        static constexpr const char *DATA_TYPE = "smallint";
                    };
                    struct RADIX {
                        static constexpr const char *NAME = "radix";
                        static const int INDEX = 10;
                        static constexpr const char *DATA_TYPE = "smallint";
                    };
                    struct NULLABLE {
                        static constexpr const char *NAME = "nullable";
                        static const int INDEX = 11;
                        static constexpr const char *DATA_TYPE = "sysname";
                    };
                    struct REMARKS {
                        static constexpr const char *NAME = "remarks";
                        static const int INDEX = 12;
                        static constexpr const char *DATA_TYPE = "varchar";
                    };
                    struct COLUMN_DEF {
                        static constexpr const char *NAME = "column_def";
                        static const int INDEX = 13;
                        static constexpr const char *DATA_TYPE = "nvarchar";
                    };
                    struct SQL_DATA_TYPE {
                        static constexpr const char *NAME = "sql_data_type";
                        static const int INDEX = 14;
                        static constexpr const char *DATA_TYPE = "smallint";
                    };
                    struct SQL_DATETIME_SUB {
                        static constexpr const char *NAME = "sql_datetime_sub";
                        static const int INDEX = 15;
                        static constexpr const char *DATA_TYPE = "smallint";
                    };
                    struct CHAR_OCTET_LENGTH {
                        static constexpr const char *NAME = "char_octet_length";
                        static const int INDEX = 16;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct ORDINAL_POSITION {
                        static constexpr const char *NAME = "ordinal_position";
                        static const int INDEX = 17;
                        static constexpr const char *DATA_TYPE = "int";
                    };
                    struct IS_NULLABLE {
                        static constexpr const char *NAME = "is_nullable";
                        static const int INDEX = 18;
                        static constexpr const char *DATA_TYPE = "varchar";
                    };
                    struct SS_DATA_TYPE {
                        static constexpr const char *NAME = "ss_data_type";
                        static const int INDEX = 19;
                        static constexpr const char *DATA_TYPE = "tinyint";
                    };
                };

                SpColumns(std::string &tableQualifier, std::string &tableOwner, std::string &tableName,
                          std::string &columnName, int dataType, std::string &typeName, int precision, int length,
                          int scale, int radix, bool nullable, std::string &remarks, std::string &columnDef,
                          int sqlDataType, int sqlDatetimeSub, int charOctetLength, int ordinalPosition,
                          std::string &isNullable, int ssDataType)
                        : table_qualifier(tableQualifier), table_owner(tableOwner), table_name(tableName),
                          column_name(columnName), data_type(dataType), type_name(typeName), precision(precision),
                          length(length), scale(scale), radix(radix), nullable(nullable), remarks(remarks),
                          column_def(columnDef), sql_data_type(sqlDataType), sql_datetime_sub(sqlDatetimeSub),
                          char_octet_length(charOctetLength), ordinal_position(ordinalPosition),
                          is_nullable(isNullable), ss_data_type(ssDataType) {}

                const std::string &getTableQualifier() const {
                    return table_qualifier;
                }

                void setTableQualifier(const std::string &tableQualifier) {
                    table_qualifier = tableQualifier;
                }

                const std::string &getTableOwner() const {
                    return table_owner;
                }

                void setTableOwner(const std::string &tableOwner) {
                    table_owner = tableOwner;
                }

                const std::string &getTableName() const {
                    return table_name;
                }

                void setTableName(const std::string &tableName) {
                    table_name = tableName;
                }

                const std::string &getColumnName() const {
                    return column_name;
                }

                void setColumnName(const std::string &columnName) {
                    column_name = columnName;
                }

                int getDataType() const {
                    return data_type;
                }

                void setDataType(int dataType) {
                    data_type = dataType;
                }

                const std::string &getTypeName() const {
                    return type_name;
                }

                void setTypeName(const std::string &typeName) {
                    type_name = typeName;
                }

                int getPrecision() const {
                    return precision;
                }

                void setPrecision(int precision) {
                    SpColumns::precision = precision;
                }

                int getLength() const {
                    return length;
                }

                void setLength(int length) {
                    SpColumns::length = length;
                }

                int getScale() const {
                    return scale;
                }

                void setScale(int scale) {
                    SpColumns::scale = scale;
                }

                int getRadix() const {
                    return radix;
                }

                void setRadix(int radix) {
                    SpColumns::radix = radix;
                }

                bool isNullable() const {
                    return nullable;
                }

                void setNullable(bool nullable) {
                    SpColumns::nullable = nullable;
                }

                const std::string &getRemarks() const {
                    return remarks;
                }

                void setRemarks(const std::string &remarks) {
                    SpColumns::remarks = remarks;
                }

                const std::string &getColumnDef() const {
                    return column_def;
                }

                void setColumnDef(const std::string &columnDef) {
                    column_def = columnDef;
                }

                int getSqlDataType() const {
                    return sql_data_type;
                }

                void setSqlDataType(int sqlDataType) {
                    sql_data_type = sqlDataType;
                }

                const int getSqlDatetimeSub() const {
                    return sql_datetime_sub;
                }

                void setSqlDatetimeSub(int sqlDatetimeSub) {
                    sql_datetime_sub = sqlDatetimeSub;
                }

                int getCharOctetLength() const {
                    return char_octet_length;
                }

                void setCharOctetLength(int charOctetLength) {
                    char_octet_length = charOctetLength;
                }

                int getOrdinalPosition() const {
                    return ordinal_position;
                }

                void setOrdinalPosition(int ordinalPosition) {
                    ordinal_position = ordinalPosition;
                }

                const std::string &getIsNullable() const {
                    return is_nullable;
                }

                void setIsNullable(const std::string &isNullable) {
                    is_nullable = isNullable;
                }

                int getSsDataType() const {
                    return ss_data_type;
                }

                void setSsDataType(int ssDataType) {
                    ss_data_type = ssDataType;
                }
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_SPCOLUMNS_H
