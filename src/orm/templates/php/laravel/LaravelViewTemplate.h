//
// Created by victor on 3/23/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELVIEWTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELVIEWTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelViewTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::SCRIPT_VIEW};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELVIEWTEMPLATE_H
