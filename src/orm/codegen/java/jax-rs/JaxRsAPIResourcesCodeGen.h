//
// Created by victor on 4/20/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSAPIRESOURCESCODEGEN_H
#define DBCRUDGEN_CPP_JAXRSAPIRESOURCESCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../templates/java/jax-rs/JaxRsScriptWebXMLTemplate.h"
#include "../../../parsers/java/JaxRsWebXMLParser.h"
#include "../../../templates/java/jax-rs/JaxRsClassWebApplicationTemplate.h"
#include "../../../parsers/java/JaxRsWebApplicationParser.h"
#include "../../../templates/java/crud/hibernate/HibernateClassAbstractableTransactionsTemplate.h"
#include "../../../parsers/java/HibernateAbstractableTransactionsParser.h"
#include "../../../parsers/java/JaxRsResourcesParser.h"
#include "../../../templates/java/jax-rs/JaxRsClassResourcesTemplate.h"
#include "../../../../databases/generic/Table.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Generates the source code for the class that extends Application in Jax-RS
         */
        class JaxRSAPIResourcesCodeGen : public JavaProjectCodeGen {

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
            createAPIResourceSource(dbcrudgen::orm::JaxRsProjectModel &projectModel,
                                    const dbcrudgen::db::generic::Table &table,
                                    const std::string &apiClass, const std::string &entityClass,
                                    const std::string &trxClass) {
                JaxRsClassResourcesTemplate rsClassResourcesTemplate;
                std::string apiSource = rsClassResourcesTemplate.getTemplate();
                const db::generic::Column &pkColumn = getTablePrimaryKeyColumn(table);

                return JaxRsResourcesParser::parseClassDetails(projectModel, apiSource, table, pkColumn, apiClass,
                                                               entityClass, trxClass);
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
#endif //DBCRUDGEN_CPP_JAXRSAPIRESOURCESCODEGEN_H
