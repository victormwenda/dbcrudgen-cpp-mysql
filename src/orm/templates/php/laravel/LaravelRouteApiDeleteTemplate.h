//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELROUTEAPIDELETETEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELROUTEAPIDELETETEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelRouteApiDeleteTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::METHOD_ROUTE_API_DELETE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_LARAVELROUTEAPIDELETETEMPLATE_H
