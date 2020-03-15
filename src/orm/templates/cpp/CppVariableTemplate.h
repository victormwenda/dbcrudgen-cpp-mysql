//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_CPPVARIABLETEMPLATE_H
#define DBCRUDGEN_CPP_CPPVARIABLETEMPLATE_H

#include "../StringSourceCodeTemplate.h"
#include "../../codegen/Languages.h"
#include "../FileSourceCodeTemplate.h"
#include "CppTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class CppVariableTemplate : public FileSourceCodeTemplate {

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }

            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::VARIABLE_TEMPLATE};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_CPPVARIABLETEMPLATE_H
