//
// Created by victor on 4/19/20.
//

#ifndef DBCRUDGEN_CPP_JAXBCODEGEN_H
#define DBCRUDGEN_CPP_JAXBCODEGEN_H

#include "JavaProjectCodeGen.h"
#include "../../parsers/java/JaxbParser.h"
#include "../../templates/java/jax-b/JaxbClassTemplate.h"
#include "../../../databases/generic/Column.h"
#include "../../templates/java/jax-b/JaxbAttributeTemplate.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Generates the source code for the java xml beans
         */
        class JaxbCodeGen : public JavaProjectCodeGen {

        public:

            /**
             * Create a java bean source code
             * @param model
             * @param beanClassName
             * @return
             */
            static std::string
            createBeansSource(const dbcrudgen::orm::JaxRsProjectModel &model, const std::string &beanClassName) {
                JaxbClassTemplate beanTpl;
                std::string beanSource = beanTpl.getTemplate();
                return JaxbParser::substituteClassDetails(model, beanClassName, beanSource);
            }

            /**
             * Substitute instance variables
             * @param beanSource
             * @param instanceVars
             * @return
             */
            static std::string addInstanceVariables(std::string &beanSource, const std::string &instanceVars) {
                return JaxbParser::substituteInstanceVariables(beanSource, instanceVars);
            }

            /**
             * Create an instance variable
             * @param column
             * @return
             */
            static std::string createInstanceVariable(const dbcrudgen::db::generic::Column &column) {
                JaxbAttributeTemplate jaxbAttributeTemplate;
                std::string srcTemplate = jaxbAttributeTemplate.getTemplate();

                StringUtils::replace(srcTemplate, "${VISIBILITY}", "private");
                StringUtils::replace(srcTemplate, "${DATA_TYPE}", JavaParser::toJavaDataType(column.getDataType()));
                StringUtils::replace(srcTemplate, "${VARIABLE_NAME}",
                                     JavaParser::toJavaVariableInstance(column.getColumnName()));

                return srcTemplate;
            }

            /**
             * Add Getters and Setters
             * @param beanSource
             * @param gettersSetters
             * @return
             */
            static std::string addGetterSetters(std::string &beanSource, const std::string &gettersSetters) {
                return JaxbParser::substituteGetterSetters(beanSource, gettersSetters);
            }

            /**
             * Create a getter setter
             * @param column
             * @return
             */
            static std::string createGetterSetter(const db::generic::Column &column) {
                std::string srcTemplate = R"(${VISIBILITY} ${DATA_TYPE} get${METHOD_NAME} () { return ${VARIABLE_NAME};}
                    ${VISIBILITY} void set${METHOD_NAME} (${DATA_TYPE} ${VARIABLE_NAME}) { this.${VARIABLE_NAME} =  ${VARIABLE_NAME};})";

                const std::string &columnName = column.getColumnName();

                StringUtils::replace(srcTemplate, "${COLUMN_NAME}", columnName);
                StringUtils::replace(srcTemplate, "${VISIBILITY}", "public");
                StringUtils::replace(srcTemplate, "${METHOD_NAME}", JavaParser::toJavaClassName(columnName));
                StringUtils::replace(srcTemplate, "${DATA_TYPE}", JavaParser::toJavaDataType(column.getDataType()));
                StringUtils::replace(srcTemplate, "${VARIABLE_NAME}",
                                     JavaParser::toJavaVariableInstance(columnName));

                return srcTemplate;
            }

            /**
             * Add constructor variables
             * @param beanSource
             * @param constVars
             * @return
             */
            static std::string addConstructorVariables(std::string &beanSource, const std::string &constVars) {
                return JaxbParser::substituteConstructorVariables(beanSource, constVars);
            }

            /**
             * Substitute instance varibles initialization in the constructor
             * @param beanSource
             * @param constVarsInit
             * @return
             */
            static std::string
            addConstructorVariablesInitialization(std::string &beanSource, const std::string &constVarsInit) {
                return JaxbParser::substituteInstanceVariablesInitialization(beanSource, constVarsInit);
            }

            /**
             * Add default instance variables initialization
             * @param beanSource
             * @param defaultInstanceVarsInit
             * @return
             */
            static std::string
            addDefaultInstanceVariablesInitialization(std::string &beanSource,
                                                      const std::string &defaultInstanceVarsInit) {
                return JaxbParser::substituteDefaultInstanceVariablesInitialization(beanSource,
                                                                                    defaultInstanceVarsInit);
            }

            /**
             * Create a constructor variable
             * @param column
             * @param isBeforeLast
             * @return
             */
            static std::string createConstructorVariable(const db::generic::Column &column, bool isBeforeLast) {
                std::string source = R"(${DATA_TYPE} ${VARIABLE_NAME} ${DELIMITER})";
                const std::string &colDataType = column.getDataType();
                const std::string &colName = column.getColumnName();

                std::string javaDataType = JaxbParser::toJavaDataType(colDataType);
                std::string variableName = JaxbParser::toJavaVariableLocal(colName);

                StringUtils::replace(source, "${DATA_TYPE}", javaDataType);
                StringUtils::replace(source, "${VARIABLE_NAME}", variableName);
                StringUtils::replace(source, "${DELIMITER}", isBeforeLast ? "," : "");

                return source;
            }

            /**
             * Create a instance variable constructor initialization
             * @param column
             * @return
             */
            static std::string
            createInstanceVariableConstructorInitialization(const db::generic::Column &column) {
                std::string source = R"(this.${INSTANCE_VARIABLE_NAME} = ${LOCAL_VARIABLE_NAME};)";

                const std::string &colName = column.getColumnName();

                std::string instanceVariable = JaxbParser::toJavaVariableInstance(colName);
                std::string localVariable = JaxbParser::toJavaVariableLocal(colName);

                StringUtils::replace(source, "${INSTANCE_VARIABLE_NAME}", instanceVariable);
                StringUtils::replace(source, "${LOCAL_VARIABLE_NAME}", localVariable);

                return source;
            }

            /**
             * Create a instance variable default constructor initialization
             * @param column
             * @return
             */
            static std::string
            createInstanceVariableDefaultBeanConstructorInitialization(const db::generic::Column &column) {
                std::string source = R"(this.${INSTANCE_VARIABLE_NAME} = ${JAVA_DEFAULT_VALUE};)";

                const std::string &dataType = column.getDataType();
                const std::string &colName = column.getColumnName();

                std::string instanceVariable = JaxbParser::toJavaVariableInstance(colName);
                std::string javaDataType = JaxbParser::toJavaDataType(dataType);
                std::string defaultInitValue = JaxbParser::getJavaDataTypeDefaultValue(javaDataType);


                StringUtils::replace(source, "${INSTANCE_VARIABLE_NAME}", instanceVariable);
                StringUtils::replace(source, "${JAVA_DEFAULT_VALUE}", defaultInitValue);

                return source;
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXBCODEGEN_H
