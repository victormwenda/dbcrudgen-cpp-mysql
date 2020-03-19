//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELROUTEWEBGETTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELROUTEWEBGETTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelPHPTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelRouteWebGetTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelPHPTemplateFiles::METHOD_ROUTE_WEB_GET};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELROUTEWEBGETTEMPLATE_H
