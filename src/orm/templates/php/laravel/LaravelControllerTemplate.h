//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELCONTROLLERTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELCONTROLLERTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelPHPTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelControllerTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelPHPTemplateFiles::CLASS_CONTROLLER_TEMPLATE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELCONTROLLERTEMPLATE_H
