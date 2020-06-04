//
// Created by victor on 6/4/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARHTMLTABLEBODYTEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARHTMLTABLEBODYTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "../TemplateFiles.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class AngularHtmlTableBodyTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Html::HTML_TABLE_BODY};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_ANGULARHTMLTABLEBODYTEMPLATE_H
