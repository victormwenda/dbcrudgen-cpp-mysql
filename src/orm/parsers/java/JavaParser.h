//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAVAPARSER_H
#define DBCRUDGEN_CPP_JAVAPARSER_H

#include "../SyntaxParser.h"

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
                return StringUtils::createClassNameCamelCase(name);
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

            static std::string toJavaVariableInstance(std::string name) {
                std::string variableName = "m" + toJavaClassName(name);
                return variableName;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_JAVAPARSER_H
