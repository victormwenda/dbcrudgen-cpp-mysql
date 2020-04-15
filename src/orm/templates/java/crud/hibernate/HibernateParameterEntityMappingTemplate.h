//
// Created by victor on 4/15/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATEPARAMETERENTITYMAPPINGTEMPLATE_H
#define DBCRUDGEN_CPP_HIBERNATEPARAMETERENTITYMAPPINGTEMPLATE_H

#include "../../../FileSourceCodeTemplate.h"
#include "../../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateParameterEntityMappingTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::Hibernate::PARAMETER_ENTITY_MAPPING};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATEPARAMETERENTITYMAPPINGTEMPLATE_H
