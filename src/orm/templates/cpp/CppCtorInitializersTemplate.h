//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_CPPCTORINITIALIZERSTEMPLATE_H
#define DBCRUDGEN_CPP_CPPCTORINITIALIZERSTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "../../codegen/Languages.h"
#include "CppTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class CppCtorInitializersTemplate : public FileSourceCodeTemplate {

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }

            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::CTOR_PROPERTY_INITIALIZER_TEMPLATE};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_CPPCTORINITIALIZERSTEMPLATE_H
