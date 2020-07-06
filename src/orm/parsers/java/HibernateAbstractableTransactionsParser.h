//
// Created by victor on 4/20/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATEABSTRACTABLETRANSACTIONSPARSER_H
#define DBCRUDGEN_CPP_HIBERNATEABSTRACTABLETRANSACTIONSPARSER_H

#include "HibernateParser.h"
#include "../../projects/JaxRsProjectModel.h"
#include "../../projects/SpringBootProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateAbstractableTransactionsParser : public HibernateParser {
        public:

            /**
              * Set the class name and other general class details
              * @param model
              * @param sourceTemplate
              * @param className
              */
            static void parseClassDetails(const dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${TRANSACTIONS_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(sourceTemplate, "${DB_CONN_PACKAGE}", model.getDbConnPkg());
                StringUtils::replace(sourceTemplate, "${DB_CONN_CLASS}", model.getDbConnClassName());
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
            }

            /**
              * Set the class name and other general class details
              * @param model
              * @param sourceTemplate
              * @param className
              */
            static void
            parseClassDetails(const dbcrudgen::orm::SpringBootProjectModel &model, std::string &sourceTemplate) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${TRANSACTIONS_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(sourceTemplate, "${DB_CONN_PACKAGE}", model.getDbConnPkg());
                StringUtils::replace(sourceTemplate, "${DB_CONN_CLASS}", model.getDbConnClassName());
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATEABSTRACTABLETRANSACTIONSPARSER_H
