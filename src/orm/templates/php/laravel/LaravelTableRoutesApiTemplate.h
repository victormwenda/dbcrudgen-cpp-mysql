//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELTABLEROUTESAPITEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELTABLEROUTESAPITEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelTableRoutesApiTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::METHODS_ROUTES_API_TABLE};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELTABLEROUTESAPITEMPLATE_H
