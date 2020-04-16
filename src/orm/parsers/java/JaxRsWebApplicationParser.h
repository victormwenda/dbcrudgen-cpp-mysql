//
// Created by victor on 4/16/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSWEBAPPLICATIONPARSER_H
#define DBCRUDGEN_CPP_JAXRSWEBAPPLICATIONPARSER_H

#include "JavaParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class JaxRsWebApplicationParser : public JavaParser {

        public:

            /**
             *
             * @param model
             * @param webXml
             */
            static void substituteProjectDetails(const JaxRsProjectModel &model, std::string &webXml) {

                StringUtils::replace(webXml, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(webXml, "${WEB_APPLICATION_PACKAGE}", model.getWebAppPkg());
                StringUtils::replace(webXml, "${CLASS_NAME}", model.getWebAppClassName());


            }

            /**
             * Substitute the Web Resources files
             * @param webApiClassSrc
             * @param webApiClassesImports
             * @param webApiClasses
             */
            static void
            substituteWebResources(std::string &webApiClassSrc, const std::string &webApiClassesImports,
                                   const std::string &webApiClasses) {
                StringUtils::replace(webApiClassSrc, "${RESOURCES_IMPORTS}", webApiClassesImports);
                StringUtils::replace(webApiClassSrc, "${RESOURCES_BINDINGS}", webApiClasses);
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSWEBAPPLICATIONPARSER_H
