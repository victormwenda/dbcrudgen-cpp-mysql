//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAVAPARSER_H
#define DBCRUDGEN_CPP_JAVAPARSER_H

#include "../SyntaxParser.h"

#include "../../templates/java/crud/connections/JavaMYSQLConnectionStringTemplate.h"
#include "../../templates/java/crud/drivers/JavaMYSQLConnectionDriverTemplate.h"


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
             * Convert SQL data type to java primitive data type
             * @param name
             * @return
             */
            static std::string toJavaPrimitiveDataTypeFromSQL(std::string name) {
                if (name == "TINYINT" || name == "tinyint") {
                    return std::string{"boolean"};
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
           * Convert SQL data type to java class data type
           * @param name
           * @return
           */
            static std::string toJavaClassDataTypeFromSQL(std::string name) {
                if (name == "TINYINT" || name == "tinyint") {
                    return std::string{"Boolean"};
                }
                if (name == "SMALLINT" || name == "smallint") {
                    return std::string{"Integer"};
                }
                if (name == "MEDIUMINT" || name == "mediumint") {
                    return std::string{"Integer"};
                }
                if (name == "INT" || name == "int") {
                    return std::string{"Integer"};
                }
                if (name == "BIGINT" || name == "bigint") {
                    return std::string{"Long"};
                }
                if (name == "DECIMAL" || name == "decimal") {
                    return std::string{"Long"};
                }
                if (name == "FLOAT" || name == "float") {
                    return std::string{"Float"};
                }
                if (name == "DOUBLE" || name == "double") {
                    return std::string{"Float"};
                }
                if (name == "BIT" || name == "bit") {
                    return std::string{"Integer"};
                }
                if (name == "BOOLEAN" || name == "boolean") {
                    return std::string{"Boolean"};
                }
                if (name == "CHAR" || name == "char") {
                    return std::string{"Character"};
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

                    case db::generic::Flavor::DB2:
                        return std::string{};
                    case db::generic::Flavor::DB2_AS_400:
                        return std::string{};
                    case db::generic::Flavor::DB2_OS390:
                        return std::string{};
                    case db::generic::Flavor::INGRES:
                        return std::string{};
                    case db::generic::Flavor::ORACLE_9I:
                        return std::string{};
                    case db::generic::Flavor::ORACLE_10G:
                        return std::string{};
                    case db::generic::Flavor::POSTGRESQL:
                        return std::string{};
                    case db::generic::Flavor::SAP_DB:
                        return std::string{};
                    case db::generic::Flavor::SYBASE:
                        return std::string{};
                    case db::generic::Flavor::SYBASE_ANYWHERE:
                        return std::string{};

                }

                return std::string{};
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

                    case db::generic::Flavor::DB2:
                        return std::string{};
                    case db::generic::Flavor::DB2_AS_400:
                        return std::string{};
                    case db::generic::Flavor::DB2_OS390:
                        return std::string{};
                    case db::generic::Flavor::INGRES:
                        return std::string{};
                    case db::generic::Flavor::ORACLE_9I:
                        return std::string{};
                    case db::generic::Flavor::ORACLE_10G:
                        return std::string{};
                    case db::generic::Flavor::POSTGRESQL:
                        return std::string{};
                    case db::generic::Flavor::SAP_DB:
                        return std::string{};
                    case db::generic::Flavor::SYBASE:
                        return std::string{};

                    case db::generic::Flavor::SYBASE_ANYWHERE:
                        return std::string{};
                }

                return std::string{};
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

            /**
             * Convert a data type to java data type
             * @param name
             * @return
             */
            static std::string primitiveToObject(std::string primitiveDataType) {
                if (primitiveDataType == "int") {
                    return "Integer";
                }
                if (primitiveDataType == "double") {
                    return "Double";
                }
                if (primitiveDataType == "long") {
                    return "Long";
                }
                return std::string{"Object"};
            }

            /**
             * Get java Database drivers for different databases
             * @param flavor
             * @return
             */
            static std::string getDatabaseDriver(const db::generic::Flavor &flavor) {
                switch (flavor) {
                    case db::generic::Flavor::MSSQL:
                        return std::string{"com.microsoft.sqlserver.jdbc.SQLServerDriver"};

                    case db::generic::Flavor::MYSQL:
                        return std::string{"com.mysql.cj.jdbc.Driver"};

                    case db::generic::Flavor::ORACLE:
                        return std::string{"oracle.jdbc.OracleDriver"};

                    case db::generic::Flavor::SQLITE:
                        return std::string{"org.sqlite.JDBC"};
                    case db::generic::Flavor::DB2:
                        return std::string{};
                    case db::generic::Flavor::DB2_AS_400:
                        return std::string{};
                    case db::generic::Flavor::DB2_OS390:
                        return std::string{};
                    case db::generic::Flavor::INGRES:
                        return std::string{};
                    case db::generic::Flavor::ORACLE_9I:
                        return std::string{};
                    case db::generic::Flavor::ORACLE_10G:
                        return std::string{};
                    case db::generic::Flavor::POSTGRESQL:
                        return std::string{};
                    case db::generic::Flavor::SAP_DB:
                        return std::string{};
                    case db::generic::Flavor::SYBASE:
                        return std::string{};
                    case db::generic::Flavor::SYBASE_ANYWHERE:
                        return std::string{};

                }
                return std::string{};
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_JAVAPARSER_H
