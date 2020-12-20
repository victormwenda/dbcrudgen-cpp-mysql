//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
#define DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H


#include "JavaParser.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootApplicationParser : public JavaParser {
        public:

            /**
            * substitute project details
            * @param model
            * @param sbAppClassSrc
            */
            static void substituteProjectDetails(const SpringBootProjectModel &model, std::string &sbAppClassSrc) {

                StringUtils::replace(sbAppClassSrc, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sbAppClassSrc, "${SB_APPLICATION_PACKAGE}", model.getSBAppClassPkg());
                StringUtils::replace(sbAppClassSrc, "${CONTROLLERS_PACKAGE}", model.getControllersPkg());
                StringUtils::replace(sbAppClassSrc, "${CLASS_NAME}", model.getSBAppClassName());

            }

            /**
             * Substitute controller details
             * @param model
             * @param ctrlSource
             * @param ctrlClass
             * @param entityClass
             * @param trxClass
             * @param apiResName
             * @return
             */
            static std::string
            substituteControllerDetails(const SpringBootProjectModel &model, const db::generic::Column &column,
                                        std::string ctrlSource,
                                        const std::string &ctrlClass,
                                        const std::string &entityClass,
                                        const std::string &trxClass, const std::string &apiResName) {
                StringUtils::replace(ctrlSource, "${PROJECT_PACKAGE}", model.getPackageName());

                StringUtils::replace(ctrlSource, "${CONTROLLER_PACKAGE}", model.getControllersPkg());
                StringUtils::replace(ctrlSource, "${CONTROLLER_CLASS}", ctrlClass);

                StringUtils::replace(ctrlSource, "${TRX_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(ctrlSource, "${TRX_CLASS}", trxClass);
                std::string trxObject = toJavaVariableLocal(trxClass);
                StringUtils::replace(ctrlSource, "${TRX_OBJECT}", trxObject);

                StringUtils::replace(ctrlSource, "${ENTITY_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(ctrlSource, "${ENTITY_CLASS}", entityClass);
                std::string entityObject = toJavaVariableLocal(entityClass);
                StringUtils::replace(ctrlSource, "${ENTITY_OBJECT}", entityObject);

                StringUtils::replace(ctrlSource, "${PK_COLUMN_NAME}", column.getColumnName());
                StringUtils::replace(ctrlSource, "${PK_COLUMN_DATATYPE}", toJavaDataType(column.getDataType()));

                std::string methodGetter = "get";
                methodGetter = methodGetter.append(toJavaClassName(column.getColumnName()));
                StringUtils::replace(ctrlSource, "${PK_METHOD_GETTER}", methodGetter);

                StringUtils::replace(ctrlSource, "${RESOURCE-NAME}", apiResName);
                return ctrlSource;
            }

            /**
            * Substitute http req class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpReqClassDetails(const SpringBootProjectModel &model, std::string httpReqClsSource,
                                          const std::string &httpReqClsName) {
                StringUtils::replace(httpReqClsSource, "${CLASS_NAME}", httpReqClsName);
                StringUtils::replace(httpReqClsSource, "${VISIBILITY}", "public");
                StringUtils::replace(httpReqClsSource, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(httpReqClsSource, "${HTTP_REQ_PACKAGE}", model.getHttpReqsPkg());
                return httpReqClsSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpResClassDetails(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                          std::string httpResClsSource, const std::string &httpResClsName) {
                StringUtils::replace(httpResClsSource, "${CLASS_NAME}", httpResClsName);
                StringUtils::replace(httpResClsSource, "${VISIBILITY}", "public");
                StringUtils::replace(httpResClsSource, "${PROJECT_PACKAGE}", projectModel.getPackageName());
                StringUtils::replace(httpResClsSource, "${HTTP_RES_PACKAGE}", projectModel.getHttpResPkg());
                return httpResClsSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpResClassDetails(std::string &httpReqSource, const std::string &httpReqInstanceVars) {
                StringUtils::replace(httpReqSource, "${TABLE_COLUMN_INSTANCE_VARIABLES}", httpReqInstanceVars);
                return httpReqSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpRequestInstanceVariables(std::string &httpReqSource, const std::string &httpReqInstanceVars) {
                StringUtils::replace(httpReqSource, "${TABLE_COLUMN_INSTANCE_VARIABLES}", httpReqInstanceVars);
                return httpReqSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteRepoClassDetails(const SpringBootProjectModel &model, std::string &repoClsSource,
                                       const std::string &repoClass, const std::string &entityClass) {
                StringUtils::replace(repoClsSource, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(repoClsSource, "${SB_REPOSITORIES_PACKAGE}", model.getRepositoriesPkg());
                StringUtils::replace(repoClsSource, "${ENTITIES_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(repoClsSource, "${CLASS_NAME}", repoClass);
                StringUtils::replace(repoClsSource, "${ENTITY_CLASS}", entityClass);
                return repoClsSource;
            }

            static std::string
            substituteRepoPrimaryKeyCol(std::string &repoSource, const std::string &pkDataType) {
                StringUtils::replace(repoSource, "${PK_DATATYPE}", pkDataType);
                return repoSource;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
