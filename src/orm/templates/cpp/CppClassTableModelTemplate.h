//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_CPPCLASSTABLEMODELTEMPLATE_H
#define DBCRUDGEN_CPP_CPPCLASSTABLEMODELTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "CppTemplateFiles.h"
#include "../../codegen/Languages.h"

namespace dbcrudgen {
    namespace orm {

        class CppClassTableModelTemplate : public FileSourceCodeTemplate {

        public:
            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::CLASS_TABLE_TEMPLATE};
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
#endif //DBCRUDGEN_CPP_CPPCLASSTABLEMODELTEMPLATE_H
