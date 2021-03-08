//
// Created by victor on 3/8/21.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPRESWITHLISTTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPRESWITHLISTTEMPLATE_H


#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootClassHttpResWithListTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::CLASS_HTTP_RES_LIST_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPRESWITHLISTTEMPLATE_H
