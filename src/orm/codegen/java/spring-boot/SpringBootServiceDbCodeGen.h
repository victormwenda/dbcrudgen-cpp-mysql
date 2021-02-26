//
// Created by victor on 2/26/21.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTSERVICEDBCODEGEN_H
#define DBCRUDGEN_CPP_SPRINGBOOTSERVICEDBCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../projects/SpringBootProjectModel.h"
#include "../../../templates/java/spring-boot/SpringBootClassApplicationTemplate.h"
#include "../../../parsers/java/SpringBootApplicationParser.h"
#include "../../../templates/java/spring-boot/SpringBootClassControllerTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassHttpReqTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassRepoTemplate.h"
#include "../../../templates/java/spring-boot/SpringBootClassServiceDbTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootServiceDbCodeGen : public JavaProjectCodeGen {
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
            createServiceDbSource(dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                  const dbcrudgen::db::generic::Table &table,
                                  const std::string &apiClass, const std::string &entityClass,
                                  const std::string &trxClass, const std::string &modelClass,
                                  const std::string &repoClass, const std::string &httpReqPostClass) {

                SpringBootClassServiceDbTemplate serviceTemplate;
                std::string serviceSource = serviceTemplate.getTemplate();

                const db::generic::Column &pkColumn = getTablePrimaryKeyColumn(table);

                std::string apiResName = SyntaxParser::toKebabCase(table.getTableName());
                serviceSource = SpringBootApplicationParser::substituteDbServiceDetails(projectModel,
                                                                                        table,
                                                                                        pkColumn,
                                                                                        serviceSource,
                                                                                        apiClass,
                                                                                        entityClass,
                                                                                        trxClass,
                                                                                        modelClass,
                                                                                        repoClass,
                                                                                        httpReqPostClass,
                                                                                        apiResName);
                return serviceSource;
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
#endif //DBCRUDGEN_CPP_SPRINGBOOTSERVICEDBCODEGEN_H
