//
// Created by victor on 6/1/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARENUMTEMPLATE_H
#define DBCRUDGEN_CPP_ANGULARENUMTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class AngularEnumTemplate : public dbcrudgen::orm::FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{dbcrudgen::orm::AngularTemplateFiles::Enums::ANGULAR_ENUM_DEFAULT};
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_ANGULARENUMTEMPLATE_H
