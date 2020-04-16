//
// Created by victor on 4/16/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSWEBAPPLICATIONCODEGEN_H
#define DBCRUDGEN_CPP_JAXRSWEBAPPLICATIONCODEGEN_H

#include "JavaProjectCodeGen.h"
#include "../../templates/java/jax-rs/JaxRsScriptWebXMLTemplate.h"
#include "../../parsers/java/JaxRsWebXMLParser.h"
#include "../../templates/java/jax-rs/JaxRsClassWebApplicationTemplate.h"
#include "../../parsers/java/JaxRsWebApplicationParser.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Generates the source code for the class that extends Application in Jax-RS
         */
        class JaxRsWebApplicationCodeGen : public JavaProjectCodeGen {

        public:

            static std::string createWebApplication(const JaxRsProjectModel &projectModel) {
                JaxRsClassWebApplicationTemplate webAppTemplate;
                std::string webAppSrc = webAppTemplate.getTemplate();

                JaxRsWebApplicationParser::substituteProjectDetails(projectModel, webAppSrc);

                return webAppSrc;
            }

            static void addApisResources(std::string &webApiClassSrc, const std::string &webApiClassesImports,
                                         const std::string &webApiClasses) {
                JaxRsWebApplicationParser::substituteWebResources(webApiClassSrc, webApiClassesImports, webApiClasses);
            }

            /**
             * Substitute web resource class and imports
             * @param apisPkg
             * @param apiClass
             * @return
             */
            static std::string
            parseWebAPIResourceClassImport(const std::string &projectPkg, const std::string &apisPkg,
                                           std::string &apiClass) {
                std::string importTemplate = R"(import ${PROJECT_PACKAGE}.${RESOURCE_PACKAGE}.${RESOURCE_CLASS};)";
                StringUtils::replace(importTemplate, "${PROJECT_PACKAGE}", projectPkg);
                StringUtils::replace(importTemplate, "${RESOURCE_PACKAGE}", apisPkg);
                StringUtils::replace(importTemplate, "${RESOURCE_CLASS}", apiClass);
                return importTemplate;
            }

            /**
             * Substitute web resource class
             * @param apiClass
             * @return
             */
            static std::string parseWebAPIResourceClass(std::string &apiClass) {
                std::string addResourceTemplate = R"(mClasses.add(${RESOURCE_CLASS}.class);)";
                StringUtils::replace(addResourceTemplate, "${RESOURCE_CLASS}", apiClass);
                return addResourceTemplate;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_JAXRSWEBAPPLICATIONCODEGEN_H
