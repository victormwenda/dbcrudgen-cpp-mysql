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
                static constexpr const char *COMPONENT_CLASS = "templates/angular/component_ts.mdl";
            };
            struct Enums {
                static constexpr const char *ANGULAR_ENUM_DEFAULT = "templates/angular/enum_template.mdl";
            };
            struct Forms {
                static constexpr const char * HTML_FORM = "templates/angular/angular_html_form.mdl";
                static constexpr const char * HTML_FORM_INPUT = "templates/angular/angular_html_form_input.mdl";
                static constexpr const char * TS_FORM_CONTROL_INIT_BIND = "templates/angular/angular_form_control_init_bind_ts.mdl";
                static constexpr const char * TS_FORM_GROUP_INIT_BIND = "templates/angular/angular_form_group_bind_ts.mdl";
            };
            struct Html {
                static constexpr const char *HTML_TABLE = "templates/angular/html_table.mdl";
                static constexpr const char *HTML_TABLE_HEADER = "templates/angular/html_table_head.mdl";
                static constexpr const char *HTML_TABLE_BODY = "templates/angular/html_table_body.mdl";
            };
            struct Module {
                static constexpr const char *MODULE_CLASS = "templates/angular/module_class.mdl";
            };
            struct Service {
                static constexpr const char *SERVICE_CLASS = "templates/angular/service_class.mdl";
                static constexpr const char *SERVICE_CLASS_SPEC = "templates/angular/service_class_spec.mdl";
            };
        };
    }
}

#endif //DBCRUDGEN_CPP_ANGULARTEMPLATEFILES_H
