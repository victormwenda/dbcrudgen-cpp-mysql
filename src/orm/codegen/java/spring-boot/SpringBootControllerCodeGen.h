//
// Created by victor on 7/7/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTCONTROLLERCODEGEN_H
#define DBCRUDGEN_CPP_SPRINGBOOTCONTROLLERCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../projects/SpringBootProjectModel.h"
#include "../../../templates/java/spring-boot/SpringBootClassApplicationTemplate.h"
#include "../../../parsers/java/SpringBootApplicationParser.h"
#include "../../../templates/java/spring-boot/SpringBootClassControllerTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootControllerCodeGen : public JavaProjectCodeGen {
        public:
            /**
             *  Create Jax-RS API Resources File Source Code
             * @param projectModel
             * @param table
             * @param apiClass
             * @param entityClass
             * @param trxClass
             * @return
             */
            static std::string
            createControllerSource(dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                   const dbcrudgen::db::generic::Table &table,
                                   const std::string &apiClass, const std::string &entityClass,
                                   const std::string &trxClass) {
                SpringBootClassControllerTemplate ctlTemplate;
                std::string apiSource = ctlTemplate.getTemplate();

                std::string apiResName = SyntaxParser::toKebabCase(table.getTableName());
                apiSource = SpringBootApplicationParser::substituteControllerDetails(projectModel, apiSource, apiClass,
                                                                                     entityClass,
                                                                                     trxClass, apiResName);
                return apiSource;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTCONTROLLERCODEGEN_H
