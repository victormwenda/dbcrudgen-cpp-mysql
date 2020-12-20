//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPRESTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPRESTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootClassHttpResTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::CLASS_HTTP_RES_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPRESTEMPLATE_H
