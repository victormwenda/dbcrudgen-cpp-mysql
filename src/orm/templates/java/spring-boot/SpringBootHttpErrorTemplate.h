//
// Created by victor on 7/7/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTHTTPERRORTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTHTTPERRORTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootHttpErrorTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::HTTP_ERROR_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_SPRINGBOOTHTTPERRORTEMPLATE_H
