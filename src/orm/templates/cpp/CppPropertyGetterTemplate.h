//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_CPPPROPERTYGETTERTEMPLATE_H
#define DBCRUDGEN_CPP_CPPPROPERTYGETTERTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "../../codegen/Languages.h"
#include "CppTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class CppPropertyGetterTemplate : public FileSourceCodeTemplate {

            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::PROPERTY_GETTER};
            }

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_CPPPROPERTYGETTERTEMPLATE_H
