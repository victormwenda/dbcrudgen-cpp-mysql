//
// Created by vrwanda on 3/13/20.
//

#include <string>
#include <cstring>
#include "../../../databases/mysql/models/DataType.h"
#include "../../../databases/mysql/core/MYSQLDataType.h"

namespace dbcrudgen {
    namespace mysql {
        class CppMYSQLParser {

        public:

            CppMYSQLParser() = default;

            /**
             * Convert MYSQL Data Type to Cpp Data Type
             * @param dataType
             * @return
             */
            static std::string toCppDataType(const dbcrudgen::mysql::MYSQLDataType dataType) {
                return toCppDataType(dataType.getName());
            }

            /**
             * Convert MYSQL Data Type to Cpp Data Type
             * @param mysqlDataType
             * @return
             */
            static std::string toCppDataType(const char *mysqlDataType) {
                if (strcmp(mysqlDataType, "TINYINT") == 0 || strcmp(mysqlDataType, "tinyint") == 0) {
                    return std::string{"int"};
                }
                if (strcmp(mysqlDataType, "SMALLINT") == 0 || strcmp(mysqlDataType, "smallint") == 0) {
                    return std::string{"int"};
                }
                if (strcmp(mysqlDataType, "MEDIUMINT") == 0 || strcmp(mysqlDataType, "mediumint") == 0) {
                    return std::string{"int"};
                }
                if (strcmp(mysqlDataType, "INT") == 0 || strcmp(mysqlDataType, "int") == 0) {
                    return std::string{"int"};
                }
                if (strcmp(mysqlDataType, "BIGINT") == 0 || strcmp(mysqlDataType, "bigint") == 0) {
                    return std::string{"long"};
                }
                if (strcmp(mysqlDataType, "DECIMAL") == 0 || strcmp(mysqlDataType, "decimal") == 0) {
                    return std::string{"long"};
                }
                if (strcmp(mysqlDataType, "FLOAT") == 0 || strcmp(mysqlDataType, "float") == 0) {
                    return std::string{"float"};
                }
                if (strcmp(mysqlDataType, "DOUBLE") == 0 || strcmp(mysqlDataType, "double") == 0) {
                    return std::string{"double"};
                }
                if (strcmp(mysqlDataType, "BIT") == 0 || strcmp(mysqlDataType, "bit") == 0) {
                    return std::string{"int"};
                }
                if (strcmp(mysqlDataType, "BOOLEAN") == 0 || strcmp(mysqlDataType, "boolean") == 0) {
                    return std::string{"bool"};
                }
                if (strcmp(mysqlDataType, "CHAR") == 0 || strcmp(mysqlDataType, "char") == 0) {
                    return std::string{"char"};
                }
                if (strcmp(mysqlDataType, "VARCHAR") == 0 || strcmp(mysqlDataType, "varchar") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "BINARY") == 0 || strcmp(mysqlDataType, "binary") == 0) {
                    return std::string{"byte"};
                }
                if (strcmp(mysqlDataType, "VARBINARY") == 0 || strcmp(mysqlDataType, "varbinary") == 0) {
                    return std::string{"byte"};
                }
                if (strcmp(mysqlDataType, "TINYBLOB") == 0 || strcmp(mysqlDataType, "tinyblob") == 0) {
                    return std::string{"byte"};
                }
                if (strcmp(mysqlDataType, "BLOB") == 0 || strcmp(mysqlDataType, "blob") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "MEDIUMBLOB") == 0 || strcmp(mysqlDataType, "mediumblob") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "LONGBLOB") == 0 || strcmp(mysqlDataType, "longblob") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "TINYTEXT") == 0 || strcmp(mysqlDataType, "tinytext") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "TEXT") == 0 || strcmp(mysqlDataType, "text") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "MEDIUMTEXT") == 0 || strcmp(mysqlDataType, "mediumtext") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "LONGTEXT") == 0 || strcmp(mysqlDataType, "longtext") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "ENUM") == 0 || strcmp(mysqlDataType, "enum") == 0) {
                    return std::string{"enum"};
                }
                if (strcmp(mysqlDataType, "SET") == 0 || strcmp(mysqlDataType, "set") == 0) {
                    return std::string{"enum"};
                }
                if (strcmp(mysqlDataType, "DATE") == 0 || strcmp(mysqlDataType, "date") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "TIME") == 0 || strcmp(mysqlDataType, "time") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "DATETIME") == 0 || strcmp(mysqlDataType, "datetime") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "TIMESTAMP") == 0 || strcmp(mysqlDataType, "timestamp") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "YEAR") == 0 || strcmp(mysqlDataType, "year") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "GEOMETRY") == 0 || strcmp(mysqlDataType, "geometry") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "POINT") == 0 || strcmp(mysqlDataType, "point") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "LINESTRING") == 0 || strcmp(mysqlDataType, "linestring") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "POLYGON") == 0 || strcmp(mysqlDataType, "polygon") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "GEOMETRYCOLLECCTION") == 0 ||
                    strcmp(mysqlDataType, "geometrycollecction") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "MULTILINESTRING") == 0 || strcmp(mysqlDataType, "multilinestring") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "MULTIPOINT") == 0 || strcmp(mysqlDataType, "multipoint") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "MULTIPOLYGON") == 0 || strcmp(mysqlDataType, "multipolygon") == 0) {
                    return std::string{"string"};
                }
                if (strcmp(mysqlDataType, "JSON") == 0 || strcmp(mysqlDataType, "json") == 0) {
                    return std::string{"string"};
                }
                return std::string{"null"};
            }
        };
    }
}