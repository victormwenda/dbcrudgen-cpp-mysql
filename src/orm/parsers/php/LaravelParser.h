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
            static std::string
            createModelFillableColumns(const dbcrudgen::db::generic::Column &column, bool isBeforeLast) {
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
            static std::string deserializeSubmittedFormData(const dbcrudgen::db::generic::Column &column) {

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
            static std::string
            createValidationCandidates(const dbcrudgen::db::generic::Column &column, bool isBeforeLast) {
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
            static std::string
            packTableAttributesForInsert(const dbcrudgen::db::generic::Column &column, bool isBeforeLast) {
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
            static std::string
            createInsertValidationRules(const dbcrudgen::db::generic::Column &column, bool isBeforeLast) {
                std::string sourceTemplate = "'${COLUMN_NAME}' => [${RULES}] ${DELIMETER}";
                replace(sourceTemplate, "${COLUMN_NAME}", column.getColumnName());

                std::string rules;

                //Add nullable
                if (column.isNullable()) {
                    rules.append("'nullable',");
                } else {
                    rules.append("'required',");
                }

                //Add data type
                const char *mysqlDataType = column.getDataType().c_str();
                std::string dataType = PHPMYSQLParser::toPHPDataType(mysqlDataType);

                std::string dataTypeValidator = getDataTypeValidator(dataType);

                rules.append("'").append(dataTypeValidator).append("',");

                //Add max value
                long maxLength = column.getLength();
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
            static std::string
            createUpdateValidationRules(const dbcrudgen::db::generic::Column &column, bool isBeforeLast) {
                std::string sourceTemplate = "'${COLUMN_NAME}' => [${RULES}] ${DELIMETER}";
                replace(sourceTemplate, "${COLUMN_NAME}", column.getColumnName());

                std::string rules;

                //Add nullable
                if (column.isNullable()) {
                    rules.append("'nullable',");
                } else {
                    rules.append("'required',");
                }

                //Add data type
                const char *mysqlDataType = column.getDataType().c_str();
                std::string dataType = PHPMYSQLParser::toPHPDataType(mysqlDataType);

                std::string dataTypeValidator = getDataTypeValidator(dataType);

                rules.append("'").append(dataTypeValidator).append("',");

                //Add max value
                long maxLength = column.getLength();
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
             * Create the table row columns
             * @param table
             * @param column
             * @return
             */
            static std::string
            createTableRowsColumns(const db::generic::Table &table, const db::generic::Column &column) {
                std::string sourceTemplate = "<td>{{$item->${COLUMN_NAME}}}</td>";
                replace(sourceTemplate, "${COLUMN_NAME}", column.getColumnName());
                return sourceTemplate;
            }

            /**
             * Create the table row columns
             * @param table
             * @param column
             * @return
             */
            static std::string
            createFormItems(const db::generic::Column &column) {

                std::string sourceTemplate = R"(<div class="form-group"><label for="${INPUT_ID}">${INPUT_PLACEHOLDER}</label><input class="form-control" id="${INPUT_ID}" placeholder="${INPUT_PLACEHOLDER}"></div>)";

                std::string inputKey = StringUtils::toKebabCase(column.getColumnName());
                std::string inputTitle = StringUtils::toTitle(column.getColumnName());
                replace(sourceTemplate, "${INPUT_PLACEHOLDER}", inputTitle);
                replace(sourceTemplate, "${INPUT_ID}", inputKey);
                return sourceTemplate.append("\r\n");
            }

            /**
             * Create the table header columns
             * @param table
             * @param column
             * @return
             */
            static std::string
            createTableHeaderColumns(const db::generic::Table &table, const db::generic::Column &column) {
                std::string sourceTemplate = "<th>${COLUMN_NAME}</th>";
                replace(sourceTemplate, "${COLUMN_NAME}", StringUtils::toTitle(column.getColumnName()));
                return sourceTemplate;
            }

            /**
             * Pack form data from DOM
             * @param column
             * @return
             */
            static std::string
            packJSFormItems(const db::generic::Column &column) {
                std::string sourceTemplate = "let ${FORM_ITEM} = $('#${DOCUMENT-ID}').val();";
                replace(sourceTemplate, "${FORM_ITEM}", StringUtils::toCamelCase(column.getColumnName()));
                replace(sourceTemplate, "${DOCUMENT-ID}", StringUtils::toKebabCase(column.getColumnName()));
                return sourceTemplate;
            }

            static std::string
            packRequestParams(const db::generic::Column &column, bool isBeforeLast) {
                std::string sourceTemplate = R"('${KEY}':${VALUE} ${DELIMITER})";

                std::string requestParam = StringUtils::toCamelCase(column.getColumnName());

                replace(sourceTemplate, "${KEY}", requestParam);
                replace(sourceTemplate, "${VALUE}", requestParam);

                if (isBeforeLast) {
                    replace(sourceTemplate, "${DELIMITER}", ",");
                } else {
                    replace(sourceTemplate, "${DELIMITER}", "");
                }

                return sourceTemplate;
            }

            /**
             * Unpack item data from the server
             * @param column
             * @return
             */
            static std::string
            unpackItemData(const db::generic::Column &column) {
                std::string sourceTemplate = "let ${ITEM_VALUE} = jqXHRData.${ITEM_KEY};";
                replace(sourceTemplate, "${ITEM_KEY}", column.getColumnName());
                replace(sourceTemplate, "${ITEM_VALUE}", StringUtils::toCamelCase(column.getColumnName()));
                return sourceTemplate;
            }

            /**
             * Bind/Inject item data (data from the server) to the HTML DOM
             * @param column
             * @return
             */
            static std::string
            bindItemDataToDocument(const db::generic::Column &column) {
                std::string sourceTemplate = "$('#${DOCUMENT_ID}').val(${ITEM_VALUE});";
                replace(sourceTemplate, "${DOCUMENT_ID}", StringUtils::toKebabCase(column.getColumnName()));
                replace(sourceTemplate, "${ITEM_VALUE}", StringUtils::toCamelCase(column.getColumnName()));
                return sourceTemplate;
            }

            /**
             * Get PHP Data type laravel validator
             * @param phpDataType
             * @return
             */
            static std::string getDataTypeValidator(std::string &phpDataType) {


                if (phpDataType == "int") {
                    return "integer";
                }
                if (phpDataType == "double") {
                    return "double";
                }
                if (phpDataType == "float") {
                    return "numeric";
                }
                if (phpDataType == "string") {
                    return "string";
                }
                if (phpDataType == "bool") {
                    return "bool";
                }

                return "nullable";
            }

        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELPARSER_H
