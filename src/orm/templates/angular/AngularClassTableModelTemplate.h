//
// Created by victor on 6/2/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARCLASSTABLEMODELTEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARCLASSTABLEMODELTEMPLATE_H


#include "../FileSourceCodeTemplate.h"
#include "../TemplateFiles.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class AngularClassTableModelTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Classes::ANGULAR_CLASS_TABLE_MODEL};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_ANGULARCLASSTABLEMODELTEMPLATE_H
