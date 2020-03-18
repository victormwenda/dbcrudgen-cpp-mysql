//
// Created by vrwanda on 3/13/20.
//

#include <string>
#include <cstring>
#include "../../../databases/mysql/models/DataType.h"
#include "../../../databases/mysql/core/MYSQLDataType.h"
#include "../../templates/cpp/CppPropertyGetterTemplate.h"
#include "../SyntaxParser.h"
#include "../../templates/cpp/CppVariableTemplate.h"
#include "../../templates/cpp/CppCtorInitializersTemplate.h"
#include "../../templates/cpp/CppStructTableColumnModelTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class CppMYSQLParser : public SyntaxParser {

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
                    return std::string{"long double"};
                }
                if (strcmp(mysqlDataType, "DOUBLE") == 0 || strcmp(mysqlDataType, "double") == 0) {
                    return std::string{"long double"};
                }
                if (strcmp(mysqlDataType, "BIT") == 0 || strcmp(mysqlDataType, "bit") == 0) {
                    return std::string{"int"};
                }
                if (strcmp(mysqlDataType, "BOOLEAN") == 0 || strcmp(mysqlDataType, "boolean") == 0) {
                    return std::string{"bool"};
                }
                if (strcmp(mysqlDataType, "CHAR") == 0 || strcmp(mysqlDataType, "char") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "VARCHAR") == 0 || strcmp(mysqlDataType, "varchar") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "BINARY") == 0 || strcmp(mysqlDataType, "binary") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "VARBINARY") == 0 || strcmp(mysqlDataType, "varbinary") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "TINYBLOB") == 0 || strcmp(mysqlDataType, "tinyblob") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "BLOB") == 0 || strcmp(mysqlDataType, "blob") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "MEDIUMBLOB") == 0 || strcmp(mysqlDataType, "mediumblob") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "LONGBLOB") == 0 || strcmp(mysqlDataType, "longblob") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "TINYTEXT") == 0 || strcmp(mysqlDataType, "tinytext") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "TEXT") == 0 || strcmp(mysqlDataType, "text") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "MEDIUMTEXT") == 0 || strcmp(mysqlDataType, "mediumtext") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "LONGTEXT") == 0 || strcmp(mysqlDataType, "longtext") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "ENUM") == 0 || strcmp(mysqlDataType, "enum") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "SET") == 0 || strcmp(mysqlDataType, "set") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "DATE") == 0 || strcmp(mysqlDataType, "date") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "TIME") == 0 || strcmp(mysqlDataType, "time") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "DATETIME") == 0 || strcmp(mysqlDataType, "datetime") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "TIMESTAMP") == 0 || strcmp(mysqlDataType, "timestamp") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "YEAR") == 0 || strcmp(mysqlDataType, "year") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "GEOMETRY") == 0 || strcmp(mysqlDataType, "geometry") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "POINT") == 0 || strcmp(mysqlDataType, "point") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "LINESTRING") == 0 || strcmp(mysqlDataType, "linestring") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "POLYGON") == 0 || strcmp(mysqlDataType, "polygon") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "GEOMETRYCOLLECTION") == 0 ||
                    strcmp(mysqlDataType, "geometrycollection") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "MULTILINESTRING") == 0 || strcmp(mysqlDataType, "multilinestring") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "MULTIPOINT") == 0 || strcmp(mysqlDataType, "multipoint") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "MULTIPOLYGON") == 0 || strcmp(mysqlDataType, "multipolygon") == 0) {
                    return std::string{"std::string"};
                }
                if (strcmp(mysqlDataType, "JSON") == 0 || strcmp(mysqlDataType, "json") == 0) {
                    return std::string{"std::string"};
                }
                return std::string{"null"};
            }

            /**
             * Parse table column getters
             *
             * @param codeTemplate
             * @param column
             * @return
             */
            static std::string
            parseTableColumnsGetters(CppPropertyGetterTemplate &codeTemplate, mysql::Columns &column) {

                std::string source = codeTemplate.getTemplate();
                const std::string &dataType = column.getDataType();
                const std::string &columnName = column.getColumnName();

                std::string className = toCppClassName(columnName);
                std::string columnNameProperty = toCppVariableName(columnName);
                std::string methodName = toCppMethodName(columnName);

                source = StringUtils::replace(source, "${DATA_TYPE}", toCppDataType(dataType.c_str()));
                source = StringUtils::replace(source, "${COLUMN_NAME}", className);
                source = StringUtils::replace(source, "${COLUMN_NAME_PROPERTY}", columnNameProperty);
                source = StringUtils::replace(source, "${METHOD_NAME}", methodName);


                return source;
            }

            /**
             * Parse Table Column Properties. Or Variables
             * @param codeTemplate
             * @param column
             * @param delimiter
             * @return
             */
            static std::string
            parseTableColumnVariables(CppVariableTemplate &codeTemplate, mysql::Columns &column,
                                      std::string &delimiter) {

                std::string source = codeTemplate.getTemplate();

                const std::string &dataType = column.getDataType();
                const std::string &columnName = column.getColumnName();

                std::string className = toCppClassName(columnName);
                std::string columnNameProperty = toCppVariableName(columnName);


                std::string cppDataType = toCppDataType(dataType.c_str());

                if (cppDataType == "std::string") {
                    source = StringUtils::replace(source, "${DATA_TYPE}", cppDataType + "&");
                } else {
                    source = StringUtils::replace(source, "${DATA_TYPE}", cppDataType);
                }

                source = StringUtils::replace(source, "${PROPERTY_NAME}", columnNameProperty);
                source = StringUtils::replace(source, "${DELIMITER}", delimiter);

                return source;
            }

            /**
             * Parse Table Column Properties. Or Variables
             * @param codeTemplate
             * @param column
             * @param delimiter
             * @return
             */
            static std::string
            parseClassConstructorInitializerProperties(CppCtorInitializersTemplate &codeTemplate,
                                                       mysql::Columns &column, std::string &delimiter) {

                std::string source = codeTemplate.getTemplate();

                const std::string &columnName = column.getColumnName();

                std::string columnNameProperty = toCppVariableName(columnName);

                source = StringUtils::replace(source, "${PROPERTY_NAME}", columnNameProperty);
                source = StringUtils::replace(source, "${PROPERTY_NAME}", columnNameProperty);
                source = StringUtils::replace(source, "${DELIMITER}", delimiter);

                return source;
            }

            /**
             * Parse Table columns meta data
             * @param codeTemplate
             * @param column
             * @param index
             * @return
             */
            static std::string
            parseTableColumnsMetaData(CppStructTableColumnModelTemplate &codeTemplate,
                                      mysql::Columns &column, int index) {

                std::string source = codeTemplate.getTemplate();

                const std::string &columnName = column.getColumnName();

                source = StringUtils::replace(source, "${COLUMN__STRUCT}", StringUtils::to_upper(columnName));
                source = StringUtils::replace(source, "${COLUMN_NAME}", columnName);
                source = StringUtils::replace(source, "${COLUMN_INDEX}", std::to_string(index));

                return source;
            }

            /**
             * Get the resultSet Getter method for c++ data type
             * @param dataType
             * @return
             */
            static std::string getResultSetGetterSource(std::string cppDataType) {

                if (cppDataType == "bool") {
                    return std::string{"resultSet->getBoolean(${COLUMN_LABEL});"};
                }
                if (cppDataType == "char") {
                    return std::string{"resultSet->getString(${COLUMN_LABEL});"};
                }
                if (cppDataType == "int") {
                    return std::string{"resultSet->getInt(${COLUMN_LABEL});"};
                }
                if (cppDataType == "std::string") {
                    return std::string{"resultSet->getString(${COLUMN_LABEL});"};
                }
                if (cppDataType == "long") {
                    return std::string{"resultSet->getInt(${COLUMN_LABEL});"};
                }
                if (cppDataType == "float") {
                    return std::string{"resultSet->getDouble(${COLUMN_LABEL});"};
                }
                if (cppDataType == "double") {
                    return std::string{"resultSet->getDouble(${COLUMN_LABEL});"};
                }
                if (cppDataType == "long double") {
                    return std::string{"resultSet->getDouble(${COLUMN_LABEL});"};
                }

                std::cout << "Data type : " << cppDataType << std::endl;

                return std::string{"null"};
            }
        };
    }
}