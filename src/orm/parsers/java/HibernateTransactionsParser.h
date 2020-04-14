//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATETRANSACTIONSPARSER_H
#define DBCRUDGEN_CPP_HIBERNATETRANSACTIONSPARSER_H

#include "JavaParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateTransactionsParser : public JavaParser {
        public:

            /**
              * Set the class name and other general class details
              * @param model
              * @param sourceTemplate
              * @param className
              */
            static void parseClassDetails(dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate,
                                          const std::string &className) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${TRANSACTIONS_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", className);
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATETRANSACTIONSPARSER_H
