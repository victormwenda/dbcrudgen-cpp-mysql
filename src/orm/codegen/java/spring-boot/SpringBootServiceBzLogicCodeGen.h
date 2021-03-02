//
// Created by victor on 3/2/21.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTSERVICEBZLOGICCODEGEN_H
#define DBCRUDGEN_CPP_SPRINGBOOTSERVICEBZLOGICCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../projects/SpringBootProjectModel.h"
#include "../../../templates/java/spring-boot/SpringBootClassApplicationTemplate.h"
#include "../../../parsers/java/SpringBootApplicationParser.h"
#include "../../../templates/java/spring-boot/SpringBootClassControllerTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassHttpReqTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassRepoTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassServiceDaoTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassServiceBusinessTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootServiceBzLogicCodeGen : public JavaProjectCodeGen {
        public:

            static std::string
            createBzLogicSource(dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                const dbcrudgen::db::generic::Table &table, const std::string &bzLogicClass,
                                const std::string &trxClass, const std::string &modelClass,
                                const std::string &httpReqPostClass, const std::string &httpReqPutClass) {

                SpringBootClassServiceBusinessTemplate serviceTemplate;
                std::string bzLogicSource = serviceTemplate.getTemplate();

                const db::generic::Column &pkColumn = getTablePrimaryKeyColumn(table);

                std::string apiResName = SyntaxParser::toKebabCase(table.getTableName());
                bzLogicSource =
                        SpringBootApplicationParser::substituteBusinessLogicServiceDetails(projectModel, table,
                                                                                           pkColumn, bzLogicSource,
                                                                                           bzLogicClass,
                                                                                           trxClass, modelClass,
                                                                                           httpReqPostClass,
                                                                                           httpReqPutClass);
                return bzLogicSource;
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

#endif //DBCRUDGEN_CPP_SPRINGBOOTSERVICEBZLOGICCODEGEN_H
