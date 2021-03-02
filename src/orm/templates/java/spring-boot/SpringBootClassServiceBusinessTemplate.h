//
// Created by victor on 3/2/21.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTCLASSSERVICEBUSINESSTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTCLASSSERVICEBUSINESSTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootClassServiceBusinessTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::CLASS_SERVICE_BUSINESS_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_SPRINGBOOTCLASSSERVICEBUSINESSTEMPLATE_H
