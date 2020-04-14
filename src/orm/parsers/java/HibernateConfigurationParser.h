//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATECONFIGURATIONPARSER_H
#define DBCRUDGEN_CPP_HIBERNATECONFIGURATIONPARSER_H

#include "JavaParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateConfigurationParser : public JavaParser {

        public:

            /**
             * Parse Configuration file
             *  - Set the project package name
             *  - Set the transactions class package name
             * @param model
             * @param sourceTemplate
             */
            static void
            parseConfigurationFile(const dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${TRANSACTIONS_PACKAGE}", model.getTransactionsPkg());
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
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATECONFIGURATIONPARSER_H
