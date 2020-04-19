//
// Created by victor on 4/19/20.
//

#ifndef DBCRUDGEN_CPP_JAXBCLASSTEMPLATE_H
#define DBCRUDGEN_CPP_JAXBCLASSTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class JaxbClassTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::JaxB::CLASS_BEAN_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXBCLASSTEMPLATE_H
