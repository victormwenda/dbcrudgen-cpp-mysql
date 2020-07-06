//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATECONFIGURATIONPARSER_H
#define DBCRUDGEN_CPP_HIBERNATECONFIGURATIONPARSER_H

#include "HibernateParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateConfigurationParser : public HibernateParser {

        public:

            /**
             * Parse Database Connection Class Configuration file
             *  - Set the project package name
             *  - Set the transactions class package name
             * @param model
             * @param sourceTemplate
             */
            static void
            parseConfigurationClass(const dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${DB_CONN_PACKAGE}", model.getDbConnPkg());
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", model.getDbConnClassName());
            }

            /**
             * Set the class name and other general class details
             * @param model
             * @param sourceTemplate
             * @param className
             */
            static void parseClassDetails(dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate,
                                          const std::string &className) {
                StringUtils::replace(sourceTemplate, "${PACKAGE_NAME}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", className);
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
            }

            /**
            * Parse Database Configuration Script file
            *  - Set the project package name
            *  - Set the transactions class package name
            * @param model
            * @param sourceTemplate
            */
            static void
            parseConfigurationScript(const dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${TRANSACTIONS_PACKAGE}", model.getTransactionsPkg());
            }

            /**
             * Parse Database Connection Class Configuration file
             *  - Set the project package name
             *  - Set the transactions class package name
             * @param model
             * @param sourceTemplate
             */
            static void
            parseConfigurationClass(const dbcrudgen::orm::SpringBootProjectModel &model, std::string &sourceTemplate) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${DB_CONN_PACKAGE}", model.getDbConnPkg());
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", model.getDbConnClassName());
            }

            /**
             * Set the class name and other general class details
             * @param model
             * @param sourceTemplate
             * @param className
             */
            static void parseClassDetails(dbcrudgen::orm::SpringBootProjectModel &model, std::string &sourceTemplate,
                                          const std::string &className) {
                StringUtils::replace(sourceTemplate, "${PACKAGE_NAME}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", className);
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
            }

            /**
            * Parse Database Configuration Script file
            *  - Set the project package name
            *  - Set the transactions class package name
            * @param model
            * @param sourceTemplate
            */
            static void
            parseConfigurationScript(const dbcrudgen::orm::SpringBootProjectModel &model, std::string &sourceTemplate) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${TRANSACTIONS_PACKAGE}", model.getTransactionsPkg());
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATECONFIGURATIONPARSER_H
