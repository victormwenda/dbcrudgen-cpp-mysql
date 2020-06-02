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
            struct Component {
                static constexpr const char *COMPONENT_CSS = "templates/angular/component_css.mdl";
                static constexpr const char *COMPONENT_HTML = "templates/angular/component_html.mdl";
                static constexpr const char *COMPONENT_SPEC = "templates/angular/component_spec.mdl";
                static constexpr const char *COMPONENT_TS = "templates/angular/component_ts.mdl";
            };
            struct Enums {
                static constexpr const char *ANGULAR_ENUM_DEFAULT = "templates/angular/enum_template.mdl";
            };
        };
    }
}

#endif //DBCRUDGEN_CPP_ANGULARTEMPLATEFILES_H
