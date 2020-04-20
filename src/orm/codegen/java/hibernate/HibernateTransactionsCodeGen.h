//
// Created by victor on 4/20/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATETRANSACTIONSCODEGEN_H
#define DBCRUDGEN_CPP_HIBERNATETRANSACTIONSCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../templates/java/jax-rs/JaxRsScriptWebXMLTemplate.h"
#include "../../../parsers/java/JaxRsWebXMLParser.h"
#include "../../../templates/java/jax-rs/JaxRsClassWebApplicationTemplate.h"
#include "../../../parsers/java/JaxRsWebApplicationParser.h"
#include "../../../templates/java/crud/hibernate/HibernateClassAbstractableTransactionsTemplate.h"
#include "../../../parsers/java/HibernateAbstractableTransactionsParser.h"
#include "../../../templates/java/crud/hibernate/HibernateClassTransactionsTemplate.h"
#include "../../../parsers/java/HibernateTransactionsParser.h"
#include "../../../../databases/generic/Table.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Generates the source code for the class that extends Application in Jax-RS
         */
        class HibernateTransactionsCodeGen : public JavaProjectCodeGen {

        public:
            /**
             * Get Table Primary Key Column
             * @param table
             * @return
             */
            static const db::generic::Column &getTablePrimaryKeyColumn(const db::generic::Table &table) {

                const db::generic::Column &defaultColumn = table.getTableColumns()[0];

                for (const db::generic::Column &column : table.getTableColumns()) {
                    if (column.isPrimary()) {
                        return column;
                    }
                }

                return defaultColumn;
            }

            static std::string
            createHibernateTrxSource(const dbcrudgen::orm::JaxRsProjectModel &projectModel,
                                     const dbcrudgen::db::generic::Table &table,
                                     const std::string &trxClass,
                                     const std::string &entityClass) {

                HibernateClassTransactionsTemplate hTrxTemplate;
                std::string trxSource = hTrxTemplate.getTemplate();

                const dbcrudgen::db::generic::Column primaryKeyColumn = getTablePrimaryKeyColumn(table);

                return HibernateTransactionsParser::parseClassDetails(projectModel, trxSource, trxClass, entityClass,
                                                                      primaryKeyColumn);
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_HIBERNATETRANSACTIONSCODEGEN_H
