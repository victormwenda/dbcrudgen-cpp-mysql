//
// Created by victor on 3/20/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELROUTESAPITEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELROUTESAPITEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelRoutesApiTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::SCRIPT_ROUTES_API};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELROUTESAPITEMPLATE_H
