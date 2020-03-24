//
// Created by victor on 3/24/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELTABLESCRUDJSTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELTABLESCRUDJSTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelTableScrudJSTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::SCRIPT_SCRUD_JS};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::JAVASCRIPT};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELTABLESCRUDJSTEMPLATE_H
