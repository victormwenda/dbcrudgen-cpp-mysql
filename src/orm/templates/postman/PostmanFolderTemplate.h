//
// Created by victor on 12/23/20.
//

#ifndef DBCRUDGEN_CPP_POSTMANFOLDERTEMPLATE_H
#define DBCRUDGEN_CPP_POSTMANFOLDERTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "PostmanTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Postman Request Template
         */
        class PostmanFolderTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{PostmanTemplateFiles::FOLDER_TEMPLATE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::JSON};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_POSTMANFOLDERTEMPLATE_H
