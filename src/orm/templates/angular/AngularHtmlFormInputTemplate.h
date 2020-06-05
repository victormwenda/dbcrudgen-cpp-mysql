//
// Created by victor on 6/5/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARHTMLFORMINPUTTEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARHTMLFORMINPUTTEMPLATE_H


#include "../FileSourceCodeTemplate.h"
#include "../TemplateFiles.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class AngularHtmlFormInputTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Forms::HTML_FORM_INPUT};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_ANGULARHTMLFORMINPUTTEMPLATE_H
