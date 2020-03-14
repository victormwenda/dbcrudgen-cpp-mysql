//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_CPPTEMPLATEFILES_H
#define DBCRUDGEN_CPP_CPPTEMPLATEFILES_H

#include "../TemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class CppTemplateFiles : TemplateFiles {
        public:
            static constexpr const char *CLASS_TEMPLATE = "templates/cpp/class.mdl";
            static constexpr const char *CLASS_TABLE_TEMPLATE = "templates/cpp/class_table.mdl";
            static constexpr const char *CLASS_TABLE_MODEL_COLUMN_METADATA_TEMPLATE = "templates/cpp/class_table_model_column_metadata.mdl";
            static constexpr const char *METHOD_TEMPLATE = "templates/cpp/method.mdl";
            static constexpr const char *VARIABLE_TEMPLATE = "templates/cpp/variable.mdl";
        };

    }
}
#endif //DBCRUDGEN_CPP_CPPTEMPLATEFILES_H
