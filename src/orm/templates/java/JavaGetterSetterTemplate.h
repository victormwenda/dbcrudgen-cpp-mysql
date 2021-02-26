//
// Created by victor on 2/26/21.
//

#ifndef DBCRUDGEN_CPP_JAVAGETTERSETTERTEMPLATE_H
#define DBCRUDGEN_CPP_JAVAGETTERSETTERTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class JavaGetterSetterTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::GETTER_SETTER_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    };
}

#endif //DBCRUDGEN_CPP_JAVAGETTERSETTERTEMPLATE_H
