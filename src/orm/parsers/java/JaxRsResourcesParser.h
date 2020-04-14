//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSRESOURCESPARSER_H
#define DBCRUDGEN_CPP_JAXRSRESOURCESPARSER_H

#include "JavaParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class JaxRsResourcesParser : public JavaParser {

        public:

            /**
             * Set the class name and other general class details
             * @param model
             * @param sourceTemplate
             * @param className
             */
            static void parseClassDetails(dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate,
                                          const std::string &tableName, const std::string &className) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${RESOURCES_PACKAGE}", model.getApisPkg());
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", className);
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
                StringUtils::replace(sourceTemplate, "${RESOURCE-NAME}", toKebabCase(tableName));
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSRESOURCESPARSER_H
