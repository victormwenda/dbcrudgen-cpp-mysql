//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPREQTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPREQTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootClassHttpReqTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::CLASS_HTTP_REQ_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTCLASSHTTPREQTEMPLATE_H
