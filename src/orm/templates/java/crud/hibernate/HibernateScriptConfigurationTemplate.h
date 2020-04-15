//
// Created by victor on 4/15/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATESCRIPTCONFIGURATIONTEMPLATE_H
#define DBCRUDGEN_CPP_HIBERNATESCRIPTCONFIGURATIONTEMPLATE_H

#include "../../../FileSourceCodeTemplate.h"
#include "../../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateScriptConfigurationTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::Hibernate::SCRIPT_HIBERNATE_MAPPING};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_HIBERNATESCRIPTCONFIGURATIONTEMPLATE_H
