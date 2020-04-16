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

            struct Connections {
                static constexpr const char *MSSQL_CONNECTION_TEMPLATE = "templates/java/databases/connections/mssql_connection_string.mdl";
                static constexpr const char *MYSQL_CONNECTION_TEMPLATE = "templates/java/databases/connections/mysql_connection_string.mdl";
                static constexpr const char *ORACLE_SID_CONNECTION_TEMPLATE = "templates/java/databases/connections/oracle_connection_string_sid.mdl";
                static constexpr const char *ORACLE_SNAME_CONNECTION_TEMPLATE = "templates/java/databases/connections/oracle_connection_string_sname.mdl";
                static constexpr const char *SQLITE_TEMPLATE = "templates/java/databases/connections/sqlite_connection_string.mdl";
            };

            struct DriverManagers {
                static constexpr const char *MSSQL_DRIVER_TEMPLATE = "templates/java/databases/drivers/mssql_connection_driver.mdl";
                static constexpr const char *MYSQL_DRIVER_TEMPLATE = "templates/java/databases/drivers/mysql_connection_driver.mdl";
                static constexpr const char *ORACLE_DRIVER_TEMPLATE = "templates/java/databases/drivers/oracle_connection_driver.mdl";
                static constexpr const char *SQLITE_DRIVER_TEMPLATE = "templates/java/databases/drivers/sqlite_connection_driver.mdl";
            };

            struct Hibernate {
                static constexpr const char *CLASS_CONFIGURATION_TEMPLATE = "templates/java/hibernate/class_configuration_template.mdl";
                static constexpr const char *CLASS_ENTITY_TEMPLATE = "templates/java/hibernate/class_entity_template.mdl";
                static constexpr const char *CLASS_TRANSACTIONS_TEMPLATE = "templates/java/hibernate/class_transactions_template.mdl";

                static constexpr const char *PARAMETER_ENTITY_MAPPING = "templates/java/hibernate/parameter_entity_mapping_template.mdl";

                static constexpr const char *SCRIPT_HIBERNATE_MAPPING = "templates/java/hibernate/script_hibernate_config_template.mdl";
            };
            struct JaxRs {
                static constexpr const char *CLASS_RESOURCES_TEMPLATE = "templates/java/jax-rs/class_resources_template.mdl";
                static constexpr const char *CLASS_WEB_APPLICATION_TEMPLATE = "templates/java/jax-rs/class_web_application_template.mdl";
                static constexpr const char *METHOD_RESOURCES_DELETE_TEMPLATE = "templates/java/jax-rs/method_resources_delete_template.mdl";
                static constexpr const char *METHOD_RESOURCES_GET_TEMPLATE = "templates/java/jax-rs/method_resources_get_template.mdl";
                static constexpr const char *METHOD_RESOURCES_POST_TEMPLATE = "templates/java/jax-rs/method_resources_post_template.mdl";
                static constexpr const char *METHOD_RESOURCES_PUT_TEMPLATE = "templates/java/jax-rs/method_resources_put_template.mdl";
                static constexpr const char *SCRIPT_WEB_XML_TEMPLATE = "templates/java/jax-rs/script_web_xml_template.mdl";
            };
            struct JaxWs {
                static constexpr const char *CLASS_RESOURCES_TEMPLATE = "templates/java/jax-ws/class_resources_template.mdl";
            };

        };
    }
}
#endif //DBCRUDGEN_CPP_JAVATEMPLATEFILES_H
