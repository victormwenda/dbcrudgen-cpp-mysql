//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTCLASSAPPLICATIONTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTCLASSAPPLICATIONTEMPLATE_H


#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootClassApplicationTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::CLASS_APPLICATION_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_SPRINGBOOTCLASSAPPLICATIONTEMPLATE_H
