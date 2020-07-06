//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTWEBERRORFILETEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTWEBERRORFILETEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootWebErrorFileTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::HTML_ERROR_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTWEBERRORFILETEMPLATE_H
