//
// Created by victor on 6/4/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARHTMLTABLETEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARHTMLTABLETEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "../TemplateFiles.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class AngularHtmlTableTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Html::HTML_TABLE};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_ANGULARHTMLTABLETEMPLATE_H
