//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODCREATETEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODCREATETEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelPHPTemplateFiles.h"
#include "../../../codegen/Languages.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelControllerMethodCreateTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelPHPTemplateFiles::METHOD_CONTROLLER_CREATE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODCREATETEMPLATE_H
