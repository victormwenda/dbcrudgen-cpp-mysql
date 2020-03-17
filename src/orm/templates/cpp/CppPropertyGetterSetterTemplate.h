//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_CPPPROPERTYGETTERSETTERTEMPLATE_H
#define DBCRUDGEN_CPP_CPPPROPERTYGETTERSETTERTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "CppTemplateFiles.h"
#include "../../codegen/Languages.h"

namespace dbcrudgen {
    namespace orm {
        class CppPropertyGetterSetterTemplate : public FileSourceCodeTemplate {

            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::PROPERTY_GETTER_SETTER};
            }

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }

        };
    }
}


#endif //DBCRUDGEN_CPP_CPPPROPERTYGETTERSETTERTEMPLATE_H
