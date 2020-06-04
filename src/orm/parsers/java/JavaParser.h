//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAVAPARSER_H
#define DBCRUDGEN_CPP_JAVAPARSER_H

#include "../SyntaxParser.h"

#include "../../templates/java/crud/connections/JavaMYSQLConnectionStringTemplate.h"
#include "../../templates/java/crud/connections/JavaMSSQLConnectionStringTemplate.h"
#include "../../templates/java/crud/connections/JavaSQLiteConnectionStringTemplate.h"
#include "../../templates/java/crud/connections/JavaOracleSIDConnectionStringTemplate.h"

#include "../../templates/java/crud/drivers/JavaOracleConnectionDriverTemplate.h"
#include "../../templates/java/crud/drivers/JavaMYSQLConnectionDriverTemplate.h"
#include "../../templates/java/crud/drivers/JavaMSSQLConnectionDriverTemplate.h"
#include "../../templates/java/crud/drivers/JavaSQLiteConnectionDriverTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class JavaParser : public SyntaxParser {

        public:
            /**
             * Create Java Class name
             * @param name
             * @return
             */
            static std::string toJavaClassName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return SyntaxParser::createClassNameCamelCase(name);
            }

            /**
             * Convert a data type to java data type
             * @param name
             * @return
             */
            static std::string toJavaDataType(std::string name) {
                if (name == "TINYINT" || name == "tinyint") {
                    return std::string{"int"};
                }
                if (name == "SMALLINT" || name == "smallint") {
                    return std::string{"int"};
                }
                if (name == "MEDIUMINT" || name == "mediumint") {
                    return std::string{"int"};
                }
                if (name == "INT" || name == "int") {
                    return std::string{"int"};
                }
                if (name == "BIGINT" || name == "bigint") {
                    return std::string{"long"};
                }
                if (name == "DECIMAL" || name == "decimal") {
                    return std::string{"long"};
                }
                if (name == "FLOAT" || name == "float") {
                    return std::string{"float"};
                }
                if (name == "DOUBLE" || name == "double") {
                    return std::string{"float"};
                }
                if (name == "BIT" || name == "bit") {
                    return std::string{"int"};
                }
                if (name == "BOOLEAN" || name == "boolean") {
                    return std::string{"boolean"};
                }
                if (name == "CHAR" || name == "char") {
                    return std::string{"char"};
                }
                if (name == "VARCHAR" || name == "varchar") {
                    return std::string{"String"};
                }
                if (name == "BINARY" || name == "binary") {
                    return std::string{"String"};
                }
                if (name == "VARBINARY" || name == "varbinary") {
                    return std::string{"String"};
                }
                if (name == "TINYBLOB" || name == "tinyblob") {
                    return std::string{"String"};
                }
                if (name == "BLOB" || name == "blob") {
                    return std::string{"String"};
                }
                if (name == "MEDIUMBLOB" || name == "mediumblob") {
                    return std::string{"String"};
                }
                if (name == "LONGBLOB" || name == "longblob") {
                    return std::string{"String"};
                }
                if (name == "TINYTEXT" || name == "tinytext") {
                    return std::string{"String"};
                }
                if (name == "TEXT" || name == "text") {
                    return std::string{"String"};
                }
                if (name == "MEDIUMTEXT" || name == "mediumtext") {
                    return std::string{"String"};
                }
                if (name == "LONGTEXT" || name == "longtext") {
                    return std::string{"String"};
                }
                if (name == "ENUM" || name == "enum") {
                    return std::string{"String"};
                }
                if (name == "SET" || name == "set") {
                    return std::string{"String"};
                }
                if (name == "DATE" || name == "date") {
                    return std::string{"String"};
                }
                if (name == "TIME" || name == "time") {
                    return std::string{"String"};
                }
                if (name == "DATETIME" || name == "datetime") {
                    return std::string{"String"};
                }
                if (name == "TIMESTAMP" || name == "timestamp") {
                    return std::string{"String"};
                }
                if (name == "YEAR" || name == "year") {
                    return std::string{"String"};
                }
                if (name == "GEOMETRY" || name == "geometry") {
                    return std::string{"String"};
                }
                if (name == "POINT" || name == "point") {
                    return std::string{"String"};
                }
                if (name == "LINESTRING" || name == "linestring") {
                    return std::string{"String"};
                }
                if (name == "POLYGON" || name == "polygon") {
                    return std::string{"String"};
                }
                if (name == "GEOMETRYCOLLECTION" ||
                    name == "geometrycollection") {
                    return std::string{"String"};
                }
                if (name == "MULTILINESTRING" || name == "multilinestring") {
                    return std::string{"String"};
                }
                if (name == "MULTIPOINT" || name == "multipoint") {
                    return std::string{"String"};
                }
                if (name == "MULTIPOLYGON" || name == "multipolygon") {
                    return std::string{"String"};
                }
                if (name == "JSON" || name == "json") {
                    return std::string{"String"};
                }
                return std::string{"null"};
            }

            /**
             * Convert a name to a java instance name
             * @param name
             * @return
             */
            static std::string toJavaVariableInstance(std::string name) {
                std::string variableName = "m" + toJavaClassName(name);
                return variableName;
            }

            /**
             * Convert a name to a java static name
             * @param name
             * @return
             */
            static std::string toJavaVariableStatic(std::string name) {
                std::string variableName = "s" + toJavaClassName(name);
                return variableName;
            }

            /**
             * Convert a name to a java local variable name
             * @param name
             * @return
             */
            static std::string toJavaVariableLocal(std::string name) {
                std::string variableName = toCamelCase(name);
                return variableName;
            }

            /**
             * Get database connection string
             * @param flavor
             * @return
             */
            static std::string getDatabaseDriverManager(db::generic::Flavor &flavor) {
                switch (flavor) {
                    case db::generic::Flavor::MYSQL: {
                        JavaMYSQLConnectionDriverTemplate drivTpl;
                        return drivTpl.getTemplate();
                    }
                    case db::generic::Flavor::MSSQL: {
                        JavaMSSQLConnectionDriverTemplate drivTpl;
                        return drivTpl.getTemplate();
                    }
                    case db::generic::Flavor::ORACLE: {
                        JavaOracleConnectionDriverTemplate drivTpl;
                        return drivTpl.getTemplate();
                    }
                    case db::generic::Flavor::SQLITE: {
                        JavaSQLiteConnectionDriverTemplate drivTpl;
                        return drivTpl.getTemplate();
                    }
                }
            }

            /**
             * Get Database Driver Manager class
             * @param flavor
             * @return
             */
            static std::string getDatabaseConnectionString(db::generic::Flavor &flavor) {

                switch (flavor) {
                    case db::generic::Flavor::MYSQL: {
                        JavaMYSQLConnectionStringTemplate connStrTpl;
                        return connStrTpl.getTemplate();
                    }
                    case db::generic::Flavor::MSSQL: {
                        JavaMSSQLConnectionStringTemplate connStrTpl;
                        return connStrTpl.getTemplate();
                    }
                    case db::generic::Flavor::ORACLE: {
                        JavaOracleSIDConnectionStringTemplate connStrTpl;
                        return connStrTpl.getTemplate();
                    }
                    case db::generic::Flavor::SQLITE: {
                        JavaSQLiteConnectionStringTemplate connStrTpl;
                        return connStrTpl.getTemplate();
                    }
                }
            }

            /**
             * Get java data type default value
             * @param dataType
             * @return
             */
            static std::string getJavaDataTypeDefaultValue(std::string dataType) {

                if (dataType == "boolean") {
                    return "false";
                }
                if (dataType == "char") {
                    return "''";
                }
                if (dataType == "int") {
                    return "0";
                }
                if (dataType == "double") {
                    return "0.0";
                }
                if (dataType == "float") {
                    return "0.0f";
                }
                if (dataType == "long") {
                    return "0L";
                }
                if (dataType == "String") {
                    return R"("")";
                }
                return "null";
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_JAVAPARSER_H
