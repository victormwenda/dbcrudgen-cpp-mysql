//
// Created by victor on 6/1/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARPARSER_H
#define DBCRUDGEN_CPP_ANGULARPARSER_H

#include "../SyntaxParser.h"
#include "../../../databases/generic/Table.h"
#include "../../templates/angular/AngularClassTableModelTemplate.h"
#include "../../templates/angular/AngularComponentCssTemplate.h"
#include "../../templates/angular/AngularComponentTsTemplate.h"
#include "../../templates/angular/AngularComponentTsSpecTemplate.h"
#include "../../templates/angular/AngularComponentHtmlTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class AngularParser : public SyntaxParser {

        private:
            static std::string getDataType(const std::string &dataType) {
                if (dataType == "bool") {
                    return "bool";
                }
                if (dataType == "int") {
                    return "number";
                }
                if (dataType == "bigint") {
                    return "number";
                }
                if (dataType == "integer") {
                    return "number";
                }
                if (dataType == "double") {
                    return "number";
                }
                if (dataType == "float") {
                    return "number";
                }
                if (dataType == "longtext") {
                    return "string";
                }
                if (dataType == "varchar") {
                    return "string";
                }
                if (dataType == "string") {
                    return "string";
                }
                if (dataType == "timestamp") {
                    return "string";
                }


                return "any";
            }

        public:
            //Create Table Model source
            static std::string createModelSource(const std::string &className, const std::string modelInstanceVars) {
                dbcrudgen::orm::AngularClassTableModelTemplate srcTemplate;
                std::string src = srcTemplate.getTemplate();

                src = replace(src, "${CLASS_NAME}", className);
                src = replace(src, "${TABLE_COLUMN_INSTANCE_VARIABLES}", modelInstanceVars);

                return src;
            }

            //Create model table instance variable. The instance variable is deduced from the column
            static std::string createModelInstanceVariable(const db::generic::Column &column) {

                std::string dataType = getDataType(column.getDataType());
                std::string columnName = toCamelCase(column.getColumnName());

                return columnName + ":" + dataType + ";";
            }

            static std::string createComponentCssSrc(const std::string &componentName) {
                dbcrudgen::orm::AngularComponentCssTemplate cssTemplate;
                return cssTemplate.getTemplate();
            }

            static std::string createComponentHtmlSrc(const std::string &componentName) {
                dbcrudgen::orm::AngularComponentHtmlTemplate htmlTemplate;
                std::string src = htmlTemplate.getTemplate();

                src = replace(src, "${COMPONENT_NAME}", componentName);

                return src;
            }

            static std::string
            createComponentSpecSrc(const std::string &componentName, const std::string &componentClass) {
                dbcrudgen::orm::AngularComponentTsSpecTemplate specTemplate;
                std::string src = specTemplate.getTemplate();

                src = replace(src, "${COMPONENT_NAME}", componentName);
                src = replace(src, "${COMPONENT_CLASS}", componentClass);

                return src;
            }

            static std::string
            createComponentTsSrc(const std::string &moduleName, const std::string &componentName,
                                 const std::string &componentClass) {
                dbcrudgen::orm::AngularComponentTsTemplate tsTemplate;
                std::string src = tsTemplate.getTemplate();

                src = replace(src, "${MODULE_NAME}", moduleName);
                src = replace(src, "${COMPONENT_NAME}", componentName);
                src = replace(src, "${CLASS_NAME}", componentClass);

                return src;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_ANGULARPARSER_H
