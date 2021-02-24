//
// Created by victor on 2/24/21.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTFILEAPPLICATIONPROPERTIESTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTFILEAPPLICATIONPROPERTIESTEMPLATE_H
#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootFileApplicationPropertiesTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::FILE_APPLICATION_PROPERTIES_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTFILEAPPLICATIONPROPERTIESTEMPLATE_H
