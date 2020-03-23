//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELMODELTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELMODELTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelModelTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::CLASS_MODEL_TEMPLATE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELMODELTEMPLATE_H
