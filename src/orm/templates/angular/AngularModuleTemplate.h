//
// Created by victor on 6/3/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARMODULETEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARMODULETEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class AngularModuleTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Module::MODULE_CLASS};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_ANGULARMODULETEMPLATE_H
