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


namespace dbcrudgen {
    namespace orm {
        class SpringBootHttpCodeGen : public JavaProjectCodeGen {
        public:

            static std::string
            createHttpReqSource(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                const std::string &httpReqClass) {
                SpringBootClassHttpReqTemplate reqTemplate;
                std::string reqSource = reqTemplate.getTemplate();

                reqSource = SpringBootApplicationParser::substituteHttpReqClassDetails(projectModel, reqSource,
                                                                                       httpReqClass);
                return reqSource;
            }

            static std::string
            createHttpResSource(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                const std::string &httpResClass) {
                SpringBootClassHttpResTemplate resTemplate;
                std::string resSource = resTemplate.getTemplate();

                resSource = SpringBootApplicationParser::substituteHttpResClassDetails(projectModel, resSource,
                                                                                       httpResClass);
                return resSource;
            }

            static std::string
            addReqModelInstanceVariables(std::string &httpReqSource, const std::string &instanceVariables) {

                return SpringBootApplicationParser::substituteHttpRequestInstanceVariables(httpReqSource,
                                                                                           instanceVariables);
            }

            static std::string
            addRepositoryPrimaryKey(std::string &httpReqSource, const dbcrudgen::db::generic::Column *pkColumn) {
                if (pkColumn == nullptr) {
                    return SpringBootApplicationParser::substituteRepoPrimaryKeyCol(httpReqSource, "Object");
                }
                std::string dataType = JavaParser::toJavaDataType(pkColumn->getDataType());
                std::string objectType = JavaParser::primitiveToObject(dataType);
                return SpringBootApplicationParser::substituteRepoPrimaryKeyCol(httpReqSource, objectType);
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTHTTPCODEGEN_H
