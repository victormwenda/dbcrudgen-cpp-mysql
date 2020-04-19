//
// Created by victor on 4/19/20.
//

#ifndef DBCRUDGEN_CPP_JAXBELEMENTTEMPLATE_H
#define DBCRUDGEN_CPP_JAXBELEMENTTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class JaxbElementTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::JaxB::VARIABLE_BEAN_ELEMENT_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXBELEMENTTEMPLATE_H
