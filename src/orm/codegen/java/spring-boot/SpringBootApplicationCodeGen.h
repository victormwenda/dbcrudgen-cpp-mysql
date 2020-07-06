//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONCODEGEN_H
#define DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../projects/SpringBootProjectModel.h"
#include "../../../templates/java/spring-boot/SpringBootClassApplicationTemplate.h"
#include "../../../parsers/java/SpringBootApplicationParser.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootApplicationCodeGen : public JavaProjectCodeGen {

        public:
            static std::string createWebApplication(const SpringBootProjectModel &projectModel) {
                SpringBootClassApplicationTemplate webAppTemplate;
                std::string webAppSrc = webAppTemplate.getTemplate();

                SpringBootApplicationParser::substituteProjectDetails(projectModel, webAppSrc);

                return webAppSrc;
            }

            static void addApisResources(std::string &webApiClassSrc, const std::string &webApiClassesImports,
                                         const std::string &webApiClasses) {
                SpringBootApplicationParser::substituteWebResources(webApiClassSrc, webApiClassesImports, webApiClasses);
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

#endif //DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONCODEGEN_H
