//
// Created by victor on 6/2/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARTEMPLATEFILES_H
#define DBCRUDGEN_CPP_ANGULARTEMPLATEFILES_H

namespace dbcrudgen {
    namespace orm {
        class AngularTemplateFiles {
        public:
            struct Classes {
                static constexpr const char *ANGULAR_CLASS_TABLE_MODEL = "templates/angular/class_table_model_template.mdl";
                static constexpr const char *ANGULAR_CLASS_DEFAULT = "templates/angular/class_default_template.mdl";
            };
            struct Enums {
                static constexpr const char *ANGULAR_ENUM_DEFAULT = "templates/angular/enum_template.mdl";
            };
        };
    }
}

#endif //DBCRUDGEN_CPP_ANGULARTEMPLATEFILES_H
