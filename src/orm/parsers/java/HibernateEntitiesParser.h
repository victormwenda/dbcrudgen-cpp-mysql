//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATEENTITIESPARSER_H
#define DBCRUDGEN_CPP_HIBERNATEENTITIESPARSER_H

#include "JavaParser.h"
#include "../../projects/JaxRsProjectModel.h"
#include "../../../databases/generic/Column.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateEntitiesParser : public HibernateParser {

        public:

            /**
             * Set the class name and other general class details
             * @param model
             * @param sourceTemplate
             * @param className
             */
            static void parseClassDetails(dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate,
                                          const std::string &tableName,
                                          const std::string &className) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${ENTITIES_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", className);
                StringUtils::replace(sourceTemplate, "${TABLE_NAME}", tableName);
            }

            /**
             * Set the class name and other general class details
             * @param model
             * @param sourceTemplate
             * @param className
             */
            static void parseClassDetails(dbcrudgen::orm::SpringBootProjectModel &model, std::string &sourceTemplate,
                                          const std::string &tableName,
                                          const std::string &className) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${ENTITIES_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", className);
                StringUtils::replace(sourceTemplate, "${TABLE_NAME}", tableName);
            }

            /**
             * Add the entity instance variables
             * @param sourceTemplate
             * @param instanceVars
             */
            static void parseColumnInstanceVariables(std::string &sourceTemplate, const std::string &instanceVars) {
                StringUtils::replace(sourceTemplate, "${TABLE_COLUMN_INSTANCE_VARIABLES}", instanceVars);
            }

            /**
             * Add the entity getter setters
             * @param sourceTemplate
             * @param getterSetters
             */
            static void parseColumnGetterSetters(std::string &sourceTemplate, const std::string &getterSetters) {
                StringUtils::replace(sourceTemplate, "${TABLE_COLUMN_GETTER_SETTERS}", getterSetters);
            }

            /**
             * Create an instance variable
             * @param column
             * @return
             */
            static std::string createInstanceVariable(const dbcrudgen::db::generic::Column &column) {
                std::string srcTemplate = R"( ${ANNOTATIONS} @Column(name="${COLUMN_NAME}")  ${VISIBILITY} ${DATA_TYPE} ${VARIABLE_NAME}; )";

                StringUtils::replace(srcTemplate, "${COLUMN_NAME}", column.getColumnName());
                StringUtils::replace(srcTemplate, "${VISIBILITY}", "private");
                StringUtils::replace(srcTemplate, "${DATA_TYPE}", JavaParser::toJavaDataType(column.getDataType()));
                StringUtils::replace(srcTemplate, "${VARIABLE_NAME}",
                                     JavaParser::toJavaVariableInstance(column.getColumnName()));

                std::string misc{};

                //Inject Id for primary key cols
                if (column.isPrimary()) {
                    misc.append(" @Id ");
                }

                StringUtils::replace(srcTemplate, "${ANNOTATIONS}", misc);

                return srcTemplate;
            }

            /**
             * Create a getter setter
             * @param column
             * @return
             */
            static std::string createGetterSetter(const db::generic::Column &column) {
                std::string srcTemplate = R"(${VISIBILITY} ${DATA_TYPE} get${METHOD_NAME} () { return ${VARIABLE_NAME};}
                    ${VISIBILITY} void set${METHOD_NAME} (${DATA_TYPE} ${VARIABLE_NAME}) { this.${VARIABLE_NAME} =  ${VARIABLE_NAME};})";

                const std::string columnName = column.getColumnName();

                StringUtils::replace(srcTemplate, "${COLUMN_NAME}", columnName);
                StringUtils::replace(srcTemplate, "${VISIBILITY}", "public");
                StringUtils::replace(srcTemplate, "${METHOD_NAME}", JavaParser::toJavaClassName(columnName));
                StringUtils::replace(srcTemplate, "${DATA_TYPE}", JavaParser::toJavaDataType(column.getDataType()));
                StringUtils::replace(srcTemplate, "${VARIABLE_NAME}",
                                     JavaParser::toJavaVariableInstance(columnName));

                return srcTemplate;
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATEENTITIESPARSER_H
