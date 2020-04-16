//
// Created by victor on 4/16/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSSCRIPTWEBXMLTEMPLATE_H
#define DBCRUDGEN_CPP_JAXRSSCRIPTWEBXMLTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class JaxRsScriptWebXMLTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::JaxRs::SCRIPT_WEB_XML_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::XML};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSSCRIPTWEBXMLTEMPLATE_H
