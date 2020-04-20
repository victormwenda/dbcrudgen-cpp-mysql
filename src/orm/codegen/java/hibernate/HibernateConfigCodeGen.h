//
// Created by victor on 4/20/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATECONFIGCODEGEN_H
#define DBCRUDGEN_CPP_HIBERNATECONFIGCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../templates/java/jax-rs/JaxRsScriptWebXMLTemplate.h"
#include "../../../parsers/java/JaxRsWebXMLParser.h"
#include "../../../templates/java/jax-rs/JaxRsClassWebApplicationTemplate.h"
#include "../../../parsers/java/JaxRsWebApplicationParser.h"
#include "../../../templates/java/crud/hibernate/HibernateClassAbstractableTransactionsTemplate.h"
#include "../../../parsers/java/HibernateAbstractableTransactionsParser.h"
#include "../../../parsers/java/HibernateEntitiesParser.h"
#include "../../../templates/java/crud/hibernate/HibernateClassEntityTemplate.h"
#include "../../../templates/java/crud/hibernate/HibernateParameterEntityMappingTemplate.h"
#include "../../../templates/java/crud/hibernate/HibernateScriptConfigurationTemplate.h"
#include "../../../../databases/generic/Database.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Generates the source code for the class that extends Application in Jax-RS
         */
        class HibernateConfigCodeGen : public JavaProjectCodeGen {

        public:
            /**
             * Get hibernate config source file
             * @return
             */
            static std::string createEntityTableMappingSource() {
                HibernateParameterEntityMappingTemplate hEntityParamTemplate;
                return hEntityParamTemplate.getTemplate();
            }

            /**
             * Create hibernate config file
             * @param projectModel
             * @param database
             * @param entityMappings
             * @return
             */
            static std::string createHibernateConfigSource(const JaxRsProjectModel &projectModel,
                                                           const db::generic::Database &database,
                                                           const std::string &entityMappings) {
                HibernateScriptConfigurationTemplate hConnConfigTemplate;
                std::string configSource = hConnConfigTemplate.getTemplate();
                return HibernateParser::parseConnectionScript(configSource, projectModel, database, entityMappings);
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_HIBERNATECONFIGCODEGEN_H
