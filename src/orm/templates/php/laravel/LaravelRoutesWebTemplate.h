//
// Created by victor on 3/20/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELROUTESWEBTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELROUTESWEBTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelPHPTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelRoutesWebTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelPHPTemplateFiles::SCRIPT_ROUTES_WEB};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELROUTESWEBTEMPLATE_H
