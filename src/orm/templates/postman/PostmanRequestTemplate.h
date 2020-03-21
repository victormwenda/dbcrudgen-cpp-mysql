//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_POSTMANREQUESTTEMPLATE_H
#define DBCRUDGEN_CPP_POSTMANREQUESTTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "PostmanTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Postman Request Template
         */
        class PostmanRequestTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{PostmanTemplateFiles::REQUEST_TEMPLATE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::JSON};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_POSTMANREQUESTTEMPLATE_H
