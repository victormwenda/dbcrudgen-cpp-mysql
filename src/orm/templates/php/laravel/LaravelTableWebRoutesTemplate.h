//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELTABLEWEBROUTESTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELTABLEWEBROUTESTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelPHPTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelTableWebRoutesTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelPHPTemplateFiles::METHODS_ROUTES_WEB_TABLE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELTABLEWEBROUTESTEMPLATE_H
