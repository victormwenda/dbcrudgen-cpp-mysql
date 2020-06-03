//
// Created by victor on 6/2/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARCOMPONENTTEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARCOMPONENTTEMPLATE_H


#include "../FileSourceCodeTemplate.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class AngularComponentTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Component::COMPONENT_CLASS};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_ANGULARCOMPONENTTEMPLATE_H
