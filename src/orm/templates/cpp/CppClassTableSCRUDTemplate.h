//
// Created by victor on 3/16/20.
//

#ifndef DBCRUDGEN_CPP_CPPCLASSTABLESCRUDTEMPLATE_H
#define DBCRUDGEN_CPP_CPPCLASSTABLESCRUDTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "../../codegen/Languages.h"
#include "CppTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class CppClassTableSCRUDTemplate : public FileSourceCodeTemplate {
            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::MYSQL::CLASS_SCRUD};
            }

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_CPPCLASSTABLESCRUDTEMPLATE_H
