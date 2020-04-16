//
// Created by victor on 4/16/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSCLASSWEBAPPLICATIONTEMPLATE_H
#define DBCRUDGEN_CPP_JAXRSCLASSWEBAPPLICATIONTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class JaxRsClassWebApplicationTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::JaxRs::CLASS_WEB_APPLICATION_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::XML};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSCLASSWEBAPPLICATIONTEMPLATE_H
