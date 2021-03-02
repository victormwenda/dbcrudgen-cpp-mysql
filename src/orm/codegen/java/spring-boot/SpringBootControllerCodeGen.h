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
#include "../../../templates/java/spring-boot/SpringBootClassHttpReqTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassRepoTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootControllerCodeGen : public JavaProjectCodeGen {
        public:
            /**
             *  Create Jax-RS API Resources File Source Code
             * @param projectModel
             * @param table
             * @param ctlClass
             * @param entityClass
             * @param bzLogicClass
             * @return
             */
            static std::string
            createControllerSource(dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                   const dbcrudgen::db::generic::Table &table,
                                   const std::string &ctlClass, const std::string &entityClass,
                                   const std::string &bzLogicClass, const std::string &modelClass) {
                SpringBootClassControllerTemplate ctlTemplate;
                std::string ctlSource = ctlTemplate.getTemplate();

                const db::generic::Column &pkColumn = getTablePrimaryKeyColumn(table);

                std::string apiResName = SyntaxParser::toKebabCase(table.getTableName());
                ctlSource = SpringBootApplicationParser::substituteControllerDetails(projectModel, table, pkColumn,
                                                                                     ctlSource, ctlClass, entityClass,
                                                                                     bzLogicClass, modelClass,
                                                                                     apiResName);
                return ctlSource;
            }

            /**
             * Get Table Primary Key Column
             * @param table
             * @return
             */
            static db::generic::Column getTablePrimaryKeyColumn(const db::generic::Table &table) {

                db::generic::Column defaultColumn = table.getTableColumns()[0];

                for (db::generic::Column column : table.getPrimaryColumns()) {
                    defaultColumn = column;
                    break;
                }

                return defaultColumn;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTCONTROLLERCODEGEN_H
