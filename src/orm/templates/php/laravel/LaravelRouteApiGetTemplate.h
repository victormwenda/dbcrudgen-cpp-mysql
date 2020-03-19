//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELROUTEAPIGETTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELROUTEAPIGETTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelPHPTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelRouteApiGetTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelPHPTemplateFiles::METHOD_ROUTE_API_GET};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELROUTEAPIGETTEMPLATE_H
