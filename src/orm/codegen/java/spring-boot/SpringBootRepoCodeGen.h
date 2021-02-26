//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTREPOCODEGEN_H
#define DBCRUDGEN_CPP_SPRINGBOOTREPOCODEGEN_H


#include "../JavaProjectCodeGen.h"
#include "../../../projects/SpringBootProjectModel.h"
#include "../../../parsers/java/SpringBootApplicationParser.h"
#include "../../../templates/java/spring-boot/SpringBootClassRepoTemplate.h"
#include "../../../templates/java/JavaVariableInstanceTemplate.h"
#include "../../../templates/java/JavaGetterTemplate.h"
#include "../../../templates/java/JavaSetterTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootRepoCodeGen : public JavaProjectCodeGen {
        public:
            static std::string
            createRepositorySource(dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                   const std::string &repoClass, const std::string &entityClass) {
                SpringBootClassRepoTemplate repoTemplate;
                std::string repoSource = repoTemplate.getTemplate();

                repoSource = SpringBootApplicationParser::substituteRepoClassDetails(projectModel, repoSource,
                                                                                     repoClass, entityClass);
                return repoSource;
            }

            /**
             * Create an instance variable
             * @param column
             * @param visibility
             * @return
             */
            static std::string
            createColumnInstanceVariable(const dbcrudgen::db::generic::Column &column,
                                         std::string visibility = "private") {
                const std::string &dataType = JavaParser::toJavaPrimitiveDataTypeFromSQL(column.getDataType());
                const std::string &objectName = JavaParser::toJavaVariableInstance(column.getColumnName());

                return createInstanceVariable(dataType, objectName);
            }

            /**
           * Create model getter
           * @param column
           * @param visibility
           * @return
           */
            static std::string
            createHttpParamsGetter(const dbcrudgen::db::generic::Column &column, std::string visibility = "public") {
                JavaGetterTemplate getterTemplate;
                std::string srcTemplate = getterTemplate.getTemplate();

                StringUtils::replace(srcTemplate, "${VISIBILITY}", visibility);
                StringUtils::replace(srcTemplate, "${DATA_TYPE}",
                                     JavaParser::toJavaPrimitiveDataTypeFromSQL(column.getDataType()));
                StringUtils::replace(srcTemplate, "${METHOD_NAME}",
                                     JavaParser::toJavaClassName(column.getColumnName()));
                StringUtils::replace(srcTemplate, "${VARIABLE_NAME}",
                                     JavaParser::toJavaVariableInstance(column.getColumnName()));

                return srcTemplate;
            }

            /**
           * Create model getter
           * @param column
           * @param visibility
           * @return
           */
            static std::string
            createModelSetters(const dbcrudgen::db::generic::Column &column, std::string visibility = "public") {
                JavaSetterTemplate setterTemplate;
                std::string srcTemplate = setterTemplate.getTemplate();

                StringUtils::replace(srcTemplate, "${VISIBILITY}", visibility);
                StringUtils::replace(srcTemplate, "${DATA_TYPE}",
                                     JavaParser::toJavaPrimitiveDataTypeFromSQL(column.getDataType()));
                StringUtils::replace(srcTemplate, "${METHOD_NAME}",
                                     JavaParser::toJavaClassName(column.getColumnName()));
                StringUtils::replace(srcTemplate, "${VARIABLE_NAME}",
                                     JavaParser::toJavaVariableInstance(column.getColumnName()));

                return srcTemplate;
            }

            static std::string
            createEntityDataFromRequest(const std::string &entityClass, const std::string &httpReqClass,
                                        const db::generic::Column &column) {

                std::string methodName = JavaParser::toJavaClassName(column.getColumnName());
                std::string requestObject = JavaParser::toJavaVariableLocal(httpReqClass);
                std::string entityObject = JavaParser::toJavaVariableLocal(entityClass);

                std::string srcTemplate = "${ENTITY_OBJECT}.set${METHOD_NAME}(${REQUEST_OBJECT}.get${METHOD_NAME}());";
                StringUtils::replace(srcTemplate, "${ENTITY_OBJECT}", entityObject);
                StringUtils::replace(srcTemplate, "${METHOD_NAME}", methodName);
                StringUtils::replace(srcTemplate, "${REQUEST_OBJECT}", requestObject);

                StringUtils::replace(srcTemplate, "${COLUMN_SETTER}", column.getColumnName());
                return srcTemplate;
            }


            static std::string
            createModelDataFromEntity(const std::string &entityClass,const std::string &modelClass, const db::generic::Column &column) {
                std::string methodName = JavaParser::toJavaClassName(column.getColumnName());
                std::string modelObject = JavaParser::toJavaVariableLocal(modelClass);
                std::string entityObject = JavaParser::toJavaVariableLocal(entityClass);

                std::string srcTemplate = "${MODEL_OBJECT}.set${METHOD_NAME}(${ENTITY_OBJECT}.get${METHOD_NAME}());";
                StringUtils::replace(srcTemplate, "${ENTITY_OBJECT}", entityObject);
                StringUtils::replace(srcTemplate, "${METHOD_NAME}", methodName);
                StringUtils::replace(srcTemplate, "${MODEL_OBJECT}", modelObject);

                StringUtils::replace(srcTemplate, "${COLUMN_SETTER}", column.getColumnName());
                return srcTemplate;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTREPOCODEGEN_H
