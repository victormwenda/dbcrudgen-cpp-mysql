//
// Created by vrwanda on 3/5/20.
//


#ifndef DBCRUDGEN_CPP_CPPSQLITECONNECTORTEMPLATE_H
#define DBCRUDGEN_CPP_CPPSQLITECONNECTORTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "CppTemplateFiles.h"
#include "../../codegen/Languages.h"

namespace dbcrudgen {
    namespace orm {
        class CppSQLiteConnectorTemplate : public FileSourceCodeTemplate {

            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::MYSQL::DATABASE_CONNECTOR};
            }

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_CPPSQLITECONNECTORTEMPLATE_H