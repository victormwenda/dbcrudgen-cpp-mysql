//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELPARSER_H
#define DBCRUDGEN_CPP_LARAVELPARSER_H

#include "PHPParser.h"
#include "PHPMYSQLParser.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelParser : public PHPParser {

        public:

            /**
             * Convert path name to name space
             * @param pathName
             * @return
             */
            static std::string toNamespace(const std::string pathName) {
                std::string nsName;

                int index = 0;
                while (index < pathName.length()) {

                    char c = pathName[index];

                    if (index == 0) {
                        c = toupper(c);
                    }

                    if (c == '/') {
                        nsName += "\\";
                    } else {
                        nsName += c;
                    }

                    index++;
                }

                return nsName;
            }

            /**
             * Create the column names for fill to fillables parameter in a model
             * @param columns
             * @param isBeforeLast
             * @return
             */
            static std::string createModelFillableColumns(const mysql::Columns &column, bool isBeforeLast) {
                if (isBeforeLast) {
                    return std::string{"'" + column.getColumnName() + "', "};
                }
                return std::string{"'" + column.getColumnName() + "'"};
            }

            /**
             * Deserialize submitted form data
             * @param column
             * @return
             */
            static std::string deserializeSubmittedFormData(const mysql::Columns &column) {

                std::string sourceTemplate = "$${OBJECT} = $request->get('${OBJECT}');";

                replace(sourceTemplate, "${OBJECT}", toPHPVariableName(column.getColumnName()));

                return sourceTemplate;
            }

            /**
             * Create validation candidates
             * @param column
             * @param isBeforeLast
             * @return
             */
            static std::string createValidationCandidates(const mysql::Columns &column, bool isBeforeLast) {
                std::string sourceTemplate = "'${COLUMN_NAME}' => $${OBJECT}${DELIMETER} ";

                replace(sourceTemplate, "${COLUMN_NAME}", column.getColumnName());
                replace(sourceTemplate, "${OBJECT}", toPHPVariableName(column.getColumnName()));

                std::string delimiter = isBeforeLast ? "," : "";
                replace(sourceTemplate, "${DELIMETER}", delimiter);

                return sourceTemplate;
            }

            /**
             * Prepare table columns for insert
             * @param column
             * @param isBeforeLast
             * @return
             */
            static std::string packTableAttributesForInsert(const mysql::Columns &column, bool isBeforeLast) {
                std::string sourceTemplate = "'${COLUMN_NAME}' => $${OBJECT}${DELIMETER} ";

                replace(sourceTemplate, "${COLUMN_NAME}", column.getColumnName());
                replace(sourceTemplate, "${OBJECT}", toPHPVariableName(column.getColumnName()));

                std::string delimiter = isBeforeLast ? "," : "";
                replace(sourceTemplate, "${DELIMETER}", delimiter);

                return sourceTemplate;
            }

            /**
             * Create insert validation rules
             * @param column
             * @param isBeforeLast
             * @return
             */
            static std::string createInsertValidationRules(const mysql::Columns &column, bool isBeforeLast) {
                std::string sourceTemplate = "'${COLUMN_NAME}' => [${RULES}] ${DELIMETER}";
                replace(sourceTemplate, "${COLUMN_NAME}", column.getColumnName());

                std::string rules;

                //Add nullable
                if (column.getIsNullable() == "YES") {
                    rules.append("'nullable',");
                } else {
                    rules.append("'required',");
                }

                //Add data type
                const char *mysqlDataType = column.getDataType().c_str();
                std::string dataType = PHPMYSQLParser::toPHPDataType(mysqlDataType);
                rules.append("'").append(dataType).append("',");

                //Add max value
                long maxLength = column.getCharacterMaximumLength();
                if (maxLength > 0) {
                    rules.append("'max:").append(std::to_string(maxLength)).append("',");
                }

                //Add all rules
                replace(sourceTemplate, "${RULES}", rules);

                std::string delimiter = isBeforeLast ? "," : "";
                replace(sourceTemplate, "${DELIMETER}", delimiter);

                return sourceTemplate;
            }

            /**
             * Create update validation rules
             * @param column
             * @param isBeforeLast
             * @return
             */
            static std::string createUpdateValidationRules(const mysql::Columns &column, bool isBeforeLast) {
                std::string sourceTemplate = "'${COLUMN_NAME}' => [${RULES}] ${DELIMETER}";
                replace(sourceTemplate, "${COLUMN_NAME}", column.getColumnName());

                std::string rules;

                //Add nullable
                if (column.getIsNullable() == "YES") {
                    rules.append("'nullable',");
                } else {
                    rules.append("'required',");
                }

                //Add data type
                const char *mysqlDataType = column.getDataType().c_str();
                std::string dataType = PHPMYSQLParser::toPHPDataType(mysqlDataType);
                rules.append("'").append(dataType).append("',");

                //Add max value
                long maxLength = column.getCharacterMaximumLength();
                if (maxLength > 0) {
                    rules.append("'max:").append(std::to_string(maxLength)).append("',");
                }

                //Add all rules
                replace(sourceTemplate, "${RULES}", rules);

                std::string delimiter = isBeforeLast ? "," : "";
                replace(sourceTemplate, "${DELIMETER}", delimiter);

                return sourceTemplate;
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELPARSER_H
