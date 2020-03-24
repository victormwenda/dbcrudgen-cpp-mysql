//
// Created by victor on 3/24/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELDATATABLETEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELDATATABLETEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelDataTableTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::SCRIPT_DATA_TABLE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELDATATABLETEMPLATE_H
