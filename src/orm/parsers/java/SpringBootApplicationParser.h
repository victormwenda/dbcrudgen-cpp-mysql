//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
#define DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H


#include "JavaParser.h"
#include "../../../databases/utils/DatabaseUtils.h"

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
            substituteControllerDetails(const SpringBootProjectModel &model, const dbcrudgen::db::generic::Table &table,
                                        const db::generic::Column &column, std::string ctrlSource,
                                        const std::string &ctrlClass,
                                        const std::string &entityClass,
                                        const std::string &trxClass, const std::string &modelClass,
                                        const std::string &apiResName) {

                std::string tableClassName = JavaParser::toJavaClassName(table.getTableName());
                std::string tablePkgName = StringUtils::to_lower(tableClassName);
                std::string requestsPksName = model.getHttpReqPkg() + '.' + tablePkgName;
                std::string responsesPksName = model.getHttpReqPkg() + '.' + tablePkgName;

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

                StringUtils::replace(ctrlSource, "${MODEL_PACKAGE}", model.getModelsPkg());
                StringUtils::replace(ctrlSource, "${MODEL_CLASS}", modelClass);
                std::string modelObject = toJavaVariableLocal(modelClass);
                StringUtils::replace(ctrlSource, "${MODEL_OBJECT}", modelObject);

                StringUtils::replace(ctrlSource, "${TABLE_CLASS}", tableClassName);
                StringUtils::replace(ctrlSource, "${REQUEST_TABLE_PACKAGE}", requestsPksName);
                StringUtils::replace(ctrlSource, "${RESPONSE_TABLE_PACKAGE}", responsesPksName);

                StringUtils::replace(ctrlSource, "${PK_COLUMN_NAME}", column.getColumnName());
                StringUtils::replace(ctrlSource, "${PK_COLUMN_DATATYPE}",
                                     toJavaPrimitiveDataTypeFromSQL(column.getDataType()));

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
            substituteHttpReqClassDetails(const SpringBootProjectModel &model, std::string &pkgName,
                                          std::string httpReqClsSource,
                                          const std::string &httpReqClsName, const std::string &modelClass) {
                StringUtils::replace(httpReqClsSource, "${CLASS_NAME}", httpReqClsName);
                StringUtils::replace(httpReqClsSource, "${VISIBILITY}", "public");
                StringUtils::replace(httpReqClsSource, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(httpReqClsSource, "${HTTP_REQ_PACKAGE}", model.getHttpReqPkg());
                StringUtils::replace(httpReqClsSource, "${TABLE_PACKAGE}", pkgName);
                return httpReqClsSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpResClassDetails(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                          std::string &pkgName,
                                          std::string httpResClsSource, const std::string &httpResClsName,
                                          const std::string &modelClass) {
                StringUtils::replace(httpResClsSource, "${CLASS_NAME}", httpResClsName);
                StringUtils::replace(httpResClsSource, "${VISIBILITY}", "public");
                StringUtils::replace(httpResClsSource, "${PROJECT_PACKAGE}", projectModel.getPackageName());
                StringUtils::replace(httpResClsSource, "${HTTP_RES_PACKAGE}", projectModel.getHttpResPkg());
                StringUtils::replace(httpResClsSource, "${TABLE_PACKAGE}", pkgName);
                StringUtils::replace(httpResClsSource, "${MODEL_PACKAGE}", projectModel.getModelsPkg());
                StringUtils::replace(httpResClsSource, "${MODEL_CLASS}", modelClass);
                return httpResClsSource;
            }

            /**
            * Substitute models class details
            * @param model
            * @return
            */
            static std::string
            substituteModelClassDetails(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                        std::string modelClsSrc, const std::string &modelClassName) {
                StringUtils::replace(modelClsSrc, "${CLASS_NAME}", modelClassName);
                StringUtils::replace(modelClsSrc, "${VISIBILITY}", "public");
                StringUtils::replace(modelClsSrc, "${PROJECT_PACKAGE}", projectModel.getPackageName());
                StringUtils::replace(modelClsSrc, "${MODELS_PACKAGE}", projectModel.getModelsPkg());
                return modelClsSrc;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpRequestInstanceVariables(std::string &httpReqSource, const std::string &httpReqInstanceVars) {
                StringUtils::replace(httpReqSource, "${INSTANCE_VARIABLES}", httpReqInstanceVars);
                return httpReqSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteModelInstanceVariables(std::string &modelSource, const std::string &instanceVars) {
                StringUtils::replace(modelSource, "${INSTANCE_VARIABLES}", instanceVars);
                return modelSource;
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


            static std::string
            parseApplicationProperties(const SpringBootProjectModel &model, const db::generic::Database &database,
                                       std::string &propertiesSrc) {
                const db::generic::Connection &connection = database.getConnection();
                const std::string &dbHost = connection.getHost();
                const std::string &user = connection.getUser();
                int port = connection.getPort();
                const std::string &dbName = connection.getDatabase();
                const db::generic::Flavor &flavor = database.getFlavor();
                const std::string &password = connection.getPassword();
                std::string connStr = dbcrudgen::db::DatabaseUtils::genDbConnStrJava(flavor, dbHost, port, user,
                                                                                     password, dbName);

                const std::string dbType = dbcrudgen::db::DatabaseUtils::getDbType(flavor);
                const std::string hibernateDialect = dbcrudgen::db::DatabaseUtils::getHibernateDialect(flavor);

                propertiesSrc = StringUtils::replace(propertiesSrc, "${SERVER_PORT}",
                                                     std::to_string(model.getServerPort()));
                propertiesSrc = StringUtils::replace(propertiesSrc, "${DATABASE_DRIVER}", getDatabaseDriver(flavor));
                propertiesSrc = StringUtils::replace(propertiesSrc, "${DATABASE_CONNECTION_STRING}", connStr);
                propertiesSrc = StringUtils::replace(propertiesSrc, "${DATABASE_USER}", user);
                propertiesSrc = StringUtils::replace(propertiesSrc, "${USER_PASSWORD}", password);
                propertiesSrc = StringUtils::replace(propertiesSrc, "${DATABASE_TYPE}", dbType);
                propertiesSrc = StringUtils::replace(propertiesSrc, "${HIBERNATE_DIALECT}", hibernateDialect);


                return propertiesSrc;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
