//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_CPPSTRUCTTABLECOLUMNMODELTEMPLATE_H
#define DBCRUDGEN_CPP_CPPSTRUCTTABLECOLUMNMODELTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "CppTemplateFiles.h"
#include "../../codegen/Languages.h"

namespace dbcrudgen {
    namespace orm {

        class CppStructTableColumnModelTemplate : public FileSourceCodeTemplate {

            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::CLASS_TABLE_MODEL_COLUMN_METADATA_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_CPPSTRUCTTABLECOLUMNMODELTEMPLATE_H
