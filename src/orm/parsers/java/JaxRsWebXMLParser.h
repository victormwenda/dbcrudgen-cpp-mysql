//
// Created by victor on 4/16/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSWEBXMLPARSER_H
#define DBCRUDGEN_CPP_JAXRSWEBXMLPARSER_H

#include "JavaParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class JaxRsWebXMLParser : public JavaParser {

        public:

            /**
             *
             * @param model
             * @param webXml
             */
            static void substituteProjectDetails(const JaxRsProjectModel &model, std::string &webXml) {

                StringUtils::replace(webXml, "${PROJECT_NAME}", model.getProjectName());

                StringUtils::replace(webXml, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(webXml, "${RESOURCES_PACKAGE}", model.getApisPkg());

                StringUtils::replace(webXml, "${APPLICATION_PACKAGE}", model.getWebAppPkg());
                StringUtils::replace(webXml, "${APPLICATION_CLASS}", model.getWebAppClassName());

                StringUtils::replace(webXml, "${SERVLET_CONTAINER}", "org.glassfish.jersey.servlet.ServletContainer");
                StringUtils::replace(webXml, "${SERVLET_PACKAGES_PROVIDER}", "jersey.config.server.provider.packages");


                StringUtils::replace(webXml, "${SERVLET_NAME}", toKebabCase(model.getProjectName()));
                StringUtils::replace(webXml, "${VISIBILITY}", "public");
                StringUtils::replace(webXml, "${URL_PATTERN}", model.getUrlPattern());
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSWEBXMLPARSER_H
