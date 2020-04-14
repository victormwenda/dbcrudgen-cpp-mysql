//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_JAVATEMPLATEFILES_H
#define DBCRUDGEN_CPP_JAVATEMPLATEFILES_H
namespace dbcrudgen {
    namespace orm {
        class JavaTemplateFiles {

        public:

            static constexpr const char *DEFAULT_CLASS_TEMPLATE = "templates/java/default_class_template.mdl";
            static constexpr const char *DEFAULT_METHOD_TEMPLATE = "templates/java/default_method_template.mdl";

            static constexpr const char *DEFAULT_VARIABLE_INSTANCE_TEMPLATE = "templates/java/default_variable_instance_template.mdl";
            static constexpr const char *DEFAULT_VARIABLE_LOCAL_TEMPLATE = "templates/java/default_variable_local_template.mdl";
            static constexpr const char *DEFAULT_VARIABLE_STATIC_TEMPLATE = "templates/java/default_variable_static_template.mdl";

            struct Hibernate {
                static constexpr const char *CLASS_CONFIGURATION_TEMPLATE = "templates/java/hibernate/class_configuration_template.mdl";
                static constexpr const char *CLASS_ENTITY_TEMPLATE = "templates/java/hibernate/class_entity_template.mdl";
                static constexpr const char *CLASS_TRANSACTIONS_TEMPLATE = "templates/java/hibernate/class_transactions_template.mdl";
            };
            struct JaxRs {
                static constexpr const char *CLASS_RESOURCES_TEMPLATE = "templates/java/jax-rs/class_resources_template.mdl";
                static constexpr const char *METHOD_RESOURCES_DELETE_TEMPLATE = "templates/java/jax-rs/method_resources_delete_template.mdl";
                static constexpr const char *METHOD_RESOURCES_GET_TEMPLATE = "templates/java/jax-rs/method_resources_get_template.mdl";
                static constexpr const char *METHOD_RESOURCES_POST_TEMPLATE = "templates/java/jax-rs/method_resources_post_template.mdl";
                static constexpr const char *METHOD_RESOURCES_PUT_TEMPLATE = "templates/java/jax-rs/method_resources_put_template.mdl";
            };
            struct JaxWs {
                static constexpr const char *CLASS_RESOURCES_TEMPLATE = "templates/java/jax-ws/class_resources_template.mdl";
            };

        };
    }
}
#endif //DBCRUDGEN_CPP_JAVATEMPLATEFILES_H
