//
// Created by victor on 4/15/20.
//

#ifndef DBCRUDGEN_CPP_JAVAORACLESIDCONNECTIONSTRINGTEMPLATE_H
#define DBCRUDGEN_CPP_JAVAORACLESIDCONNECTIONSTRINGTEMPLATE_H


#include "../../../FileSourceCodeTemplate.h"
#include "../../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class  JavaOracleSIDConnectionStringTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::Connections::ORACLE_SID_CONNECTION_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_JAVAORACLESIDCONNECTIONSTRINGTEMPLATE_H
