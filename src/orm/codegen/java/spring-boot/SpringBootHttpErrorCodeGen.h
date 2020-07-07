//
// Created by victor on 7/7/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTHTTPERRORCODEGEN_H
#define DBCRUDGEN_CPP_SPRINGBOOTHTTPERRORCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../projects/SpringBootProjectModel.h"
#include "../../../templates/java/spring-boot/SpringBootClassApplicationTemplate.h"
#include "../../../parsers/java/SpringBootApplicationParser.h"
#include "../../../templates/java/spring-boot/SpringBootHttpErrorTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootHttpErrorCodeGen : public JavaProjectCodeGen {

        public:
            static std::string createErrorPage(const SpringBootProjectModel &projectModel, const std::string& error) {
                SpringBootHttpErrorTemplate errorTemplate;
                return "<html><body></body></html>";
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_SPRINGBOOTHTTPERRORCODEGEN_H
