//
// Created by victor on 2/26/21.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTCLASSSERVICEDAOTEMPLATE_H
#define DBCRUDGEN_CPP_SPRINGBOOTCLASSSERVICEDAOTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootClassServiceDaoTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::SpringBoot::CLASS_SERVICE_DAO_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_SPRINGBOOTCLASSSERVICEDAOTEMPLATE_H
