//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSMETHODPUTTEMPLATE_H
#define DBCRUDGEN_CPP_JAXRSMETHODPUTTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class JaxRsMethodPutTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::JaxRs::METHOD_RESOURCES_PUT_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSMETHODPUTTEMPLATE_H
