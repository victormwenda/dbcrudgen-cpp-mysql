//
// Created by victor on 6/1/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARPARSER_H
#define DBCRUDGEN_CPP_ANGULARPARSER_H

#include "../SyntaxParser.h"
#include "../../../databases/generic/Table.h"
#include "../../templates/angular/AngularClassTableModelTemplate.h"

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
        };
    }
}

#endif //DBCRUDGEN_CPP_ANGULARPARSER_H
