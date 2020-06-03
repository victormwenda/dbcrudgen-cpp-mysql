//
// Created by victor on 6/3/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARSERVICESPECTEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARSERVICESPECTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class AngularServiceSpecTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Service::SERVICE_CLASS_SPEC};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_ANGULARSERVICESPECTEMPLATE_H
