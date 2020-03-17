//
// Created by vrwanda on 3/5/20.
//


#ifndef DBCRUDGEN_CPP_CPPORACLECONNECTORTEMPLATE_H
#define DBCRUDGEN_CPP_CPPORACLECONNECTORTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "../../codegen/Languages.h"
#include "CppTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class CppOracleConnectorTemplate : public FileSourceCodeTemplate {

            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::MYSQL::DATABASE_CONNECTOR};
            }

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_CPPORACLECONNECTORTEMPLATE_H
