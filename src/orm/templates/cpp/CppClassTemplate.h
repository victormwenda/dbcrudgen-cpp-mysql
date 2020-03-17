//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_CPPCLASSTEMPLATE_H
#define DBCRUDGEN_CPP_CPPCLASSTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "../../codegen/Languages.h"
#include "CppTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class CppClassTemplate : public FileSourceCodeTemplate {

        public:
            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::CLASS_TEMPLATE};
            }

            std::string getTemplate() override {
                return FileSourceCodeTemplate::getTemplate();
            }

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_CPPCLASSTEMPLATE_H
