//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTHTTPCODEGEN_H
#define DBCRUDGEN_CPP_SPRINGBOOTHTTPCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../projects/SpringBootProjectModel.h"

#include "../../../parsers/java/SpringBootApplicationParser.h"
#include "../../../templates/java/spring-boot/SpringBootClassHttpReqTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassHttpResTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassModelTemplate.h"


namespace dbcrudgen {
    namespace orm {
        class SpringBootHttpCodeGen : public JavaProjectCodeGen {
        public:
            static std::string
            createModelSource(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                              const std::string &httpResClass) {
                SpringBootClassModelTemplate resTemplate;
                std::string resSource = resTemplate.getTemplate();

                resSource = SpringBootApplicationParser::substituteModelClassDetails(projectModel, resSource,
                                                                                     httpResClass);
                return resSource;
            }

            static std::string
            addHttpReqInstanceVariables(std::string &httpReqSource, const std::string &instanceVariables) {

                return SpringBootApplicationParser::substituteHttpRequestInstanceVariables(httpReqSource,
                                                                                           instanceVariables);
            }

            static std::string
            addModelInstanceVariables(std::string &modelSource, const std::string &instanceVariables) {

                return SpringBootApplicationParser::substituteModelInstanceVariables(modelSource,
                                                                                     instanceVariables);
            }

            static std::string
            addModelGetterSetters(std::string &modelSource, const std::string &modelSetters) {

                return SpringBootApplicationParser::substituteModelGetterSetters(modelSource,
                                                                                 modelSetters);
            }

            static std::string
            addHttpRequestParamsGetters(std::string &modelSource, const std::string &modelGetters) {

                return SpringBootApplicationParser::substituteModelGetters(modelSource,
                                                                           modelGetters);
            }

            static std::string
            addRepositoryPrimaryKey(std::string &httpReqSource, const dbcrudgen::db::generic::Column *pkColumn) {
                if (pkColumn == nullptr) {
                    return SpringBootApplicationParser::substituteRepoPrimaryKeyCol(httpReqSource, "Object");
                }
                std::string dataType = JavaParser::toJavaPrimitiveDataTypeFromSQL(pkColumn->getDataType());
                std::string objectType = JavaParser::primitiveToObject(dataType);
                return SpringBootApplicationParser::substituteRepoPrimaryKeyCol(httpReqSource, objectType);
            }

            static std::string
            createReqPostSrc(SpringBootProjectModel &model, std::string &pkgName, std::string &httpReqPostClass,
                             std::string &modelClass) {
                SpringBootClassHttpReqTemplate reqTemplate;
                std::string resSource = reqTemplate.getTemplate();

                resSource = SpringBootApplicationParser::substituteHttpReqClassDetails(model, pkgName, resSource,
                                                                                       httpReqPostClass, modelClass);
                return resSource;
            }

            static std::string
            createReqPutSrc(SpringBootProjectModel &model, std::string &pkgName, std::string &httpReqPutClass,
                            std::string &modelClass) {
                SpringBootClassHttpReqTemplate reqTemplate;
                std::string resSource = reqTemplate.getTemplate();

                resSource = SpringBootApplicationParser::substituteHttpReqClassDetails(model, pkgName, resSource,
                                                                                       httpReqPutClass, modelClass);
                return resSource;
            }

            static std::string
            createResGetSrc(SpringBootProjectModel &model,
                            const dbcrudgen::db::generic::Table &table,
                            std::string &httpResGetClass,
                            std::string &modelClass) {
                SpringBootClassHttpResTemplate resTemplate;
                std::string resSource = resTemplate.getTemplate();

                resSource = SpringBootApplicationParser::substituteHttpResClassDetails(model, table, resSource,
                                                                                       httpResGetClass, modelClass);
                return resSource;
            }

            static std::string
            createResDelSrc(SpringBootProjectModel &model,
                            const dbcrudgen::db::generic::Table &table,
                            std::string &httpResDelClass,
                            std::string &modelClass) {
                SpringBootClassHttpResTemplate resTemplate;
                std::string resSource = resTemplate.getTemplate();

                resSource = SpringBootApplicationParser::substituteHttpResClassDetails(model, table, resSource,
                                                                                       httpResDelClass, modelClass);
                return resSource;
            }

            static std::string
            createResPostSrc(SpringBootProjectModel &model, const dbcrudgen::db::generic::Table &table,
                             std::string &httpResPostClass,
                             std::string &modelClass) {
                SpringBootClassHttpResTemplate resTemplate;
                std::string resSource = resTemplate.getTemplate();

                resSource = SpringBootApplicationParser::substituteHttpResClassDetails(model, table, resSource,
                                                                                       httpResPostClass, modelClass);
                return resSource;
            }

            static std::string
            createResPutSrc(SpringBootProjectModel &model, const dbcrudgen::db::generic::Table &table,
                            std::string &httpResPutClass,
                            std::string &modelClass) {
                SpringBootClassHttpResTemplate resTemplate;
                std::string resSource = resTemplate.getTemplate();

                resSource = SpringBootApplicationParser::substituteHttpResClassDetails(model, table, resSource,
                                                                                       httpResPutClass, modelClass);
                return resSource;
            }

            static void
            addTrxServicePostRequestEntityData(std::string &trxServiceSource, const std::string &modelData) {
                SpringBootApplicationParser::substituteTrxClassPostRequestEntityData(trxServiceSource, modelData);
            }

            static void addTrxServicePutRequestEntityData(std::string &trxServiceSource, const std::string &modelData) {
                SpringBootApplicationParser::substituteTrxClassPutRequestEntityData(trxServiceSource, modelData);
            }

            static void addTrxServiceModelData(std::string &trxServiceSource, const std::string &entityData) {
                SpringBootApplicationParser::substituteTrxClassModelData(trxServiceSource, entityData);
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTHTTPCODEGEN_H
