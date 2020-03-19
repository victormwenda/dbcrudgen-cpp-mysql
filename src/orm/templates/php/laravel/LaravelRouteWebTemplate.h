//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELROUTEWEBTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELROUTEWEBTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelPHPTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelRouteWebTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelPHPTemplateFiles::SCRIPT_ROUTE_WEB};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELROUTEWEBTEMPLATE_H
