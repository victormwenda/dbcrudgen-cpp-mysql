//
// Created by victor on 2/24/21.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTCLASSMODELTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTCLASSMODELTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootClassModelTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::CLASS_TABLE_MODEL_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_SPRINGBOOTCLASSMODELTEMPLATE_H
