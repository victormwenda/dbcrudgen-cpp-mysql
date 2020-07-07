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
            static std::string createApplicationClass(const SpringBootProjectModel &projectModel) {
                SpringBootClassApplicationTemplate appTemplate;
                std::string appSrc = appTemplate.getTemplate();

                SpringBootApplicationParser::substituteProjectDetails(projectModel, appSrc);

                return appSrc;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONCODEGEN_H
