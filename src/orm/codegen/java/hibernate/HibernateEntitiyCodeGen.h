//
// Created by victor on 4/20/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATEENTITIYCODEGEN_H
#define DBCRUDGEN_CPP_HIBERNATEENTITIYCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../templates/java/jax-rs/JaxRsScriptWebXMLTemplate.h"
#include "../../../parsers/java/JaxRsWebXMLParser.h"
#include "../../../templates/java/jax-rs/JaxRsClassWebApplicationTemplate.h"
#include "../../../parsers/java/JaxRsWebApplicationParser.h"
#include "../../../templates/java/crud/hibernate/HibernateClassAbstractableTransactionsTemplate.h"
#include "../../../parsers/java/HibernateAbstractableTransactionsParser.h"
#include "../../../parsers/java/HibernateEntitiesParser.h"
#include "../../../templates/java/crud/hibernate/HibernateClassEntityTemplate.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Generates the source code for the class that extends Application in Jax-RS
         */
        class HibernateEntityCodeGen : public JavaProjectCodeGen {

        public:

            /**
             * Create hibernate entity source
             * @param projectModel
             * @param tableName
             * @param entityClass
             * @return
             */
            static std::string
            createHibernateEntitySource(dbcrudgen::orm::JaxRsProjectModel &projectModel, const std::string &tableName,
                                        const std::string &entityClass) {
                HibernateClassEntityTemplate hEntityTemplate;
                std::string entitySource = hEntityTemplate.getTemplate();
                HibernateEntitiesParser::parseClassDetails(projectModel, entitySource, tableName, entityClass);
                return entitySource;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_HIBERNATEENTITIYCODEGEN_H
