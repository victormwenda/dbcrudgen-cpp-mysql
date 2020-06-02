//
// Created by victor on 6/2/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARCOMPONENTTSTEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARCOMPONENTTSTEMPLATE_H


#include "../FileSourceCodeTemplate.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class AngularComponentTsTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Component::COMPONENT_TS};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_ANGULARCOMPONENTTSTEMPLATE_H
