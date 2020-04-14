//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATECLASSCONFIGURATIONTEMPLATE_H
#define DBCRUDGEN_CPP_HIBERNATECLASSCONFIGURATIONTEMPLATE_H

#include "../../../FileSourceCodeTemplate.h"
#include "../../../TemplateFiles.h"
#include "../../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateClassConfigurationTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::Hibernate::CLASS_CONFIGURATION_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATECLASSCONFIGURATIONTEMPLATE_H
