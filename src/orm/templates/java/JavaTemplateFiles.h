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

            static constexpr const char *GETTER_TEMPLATE = "templates/java/getter_template.mdl";
            static constexpr const char *SETTER_TEMPLATE = "templates/java/setter_template.mdl";
            static constexpr const char *GETTER_SETTER_TEMPLATE = "templates/java/getter_setter_template.mdl";

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
                static constexpr const char *CLASS_ABSTRACTABLE_TRANSACTIONS_TEMPLATE = "templates/java/hibernate/class_abstractable_transactions_executor_template.mdl";

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

            struct JaxB {
                static constexpr const char *CLASS_BEAN_TEMPLATE = "templates/java/jax-b/class_bean_template.mdl";
                static constexpr const char *VARIABLE_BEAN_ATTRIBUTE_TEMPLATE = "templates/java/jax-b/bean_attribute_template.mdl";
                static constexpr const char *VARIABLE_BEAN_ELEMENT_TEMPLATE = "templates/java/jax-b/bean_element_template.mdl";
            };

            struct SpringBoot {
                static constexpr const char *CLASS_CONTROLLER_TEMPLATE = "templates/java/spring-boot/class_controller_template.mdl";
                static constexpr const char *CLASS_APPLICATION_TEMPLATE = "templates/java/spring-boot/class_application_template.mdl";

                static constexpr const char *CLASS_HTTP_REQ_TEMPLATE = "templates/java/spring-boot/class_table_http_req_action_template.mdl";
                static constexpr const char *CLASS_HTTP_RES_TEMPLATE = "templates/java/spring-boot/class_table_http_res_action_template.mdl";
                static constexpr const char *CLASS_HTTP_RES_LIST_TEMPLATE = "templates/java/spring-boot/class_table_http_res_list_action_template.mdl";
                static constexpr const char *CLASS_TABLE_MODEL_TEMPLATE = "templates/java/spring-boot/class_table_model_template.mdl";
                static constexpr const char *CLASS_REPO_TEMPLATE = "templates/java/spring-boot/class_repository_template.mdl";
                static constexpr const char *CLASS_SERVICE_DAO_TEMPLATE = "templates/java/spring-boot/class_service_dao_template.mdl";
                static constexpr const char *CLASS_SERVICE_BUSINESS_TEMPLATE = "templates/java/spring-boot/class_service_business_template.mdl";

                static constexpr const char *FILE_APPLICATION_PROPERTIES_TEMPLATE = "templates/java/spring-boot/application_properties.mdl";

                static constexpr const char *HTML_INDEX_TEMPLATE = "templates/java/spring-boot/html_index_template.mdl";
                static constexpr const char *HTTP_ERROR_TEMPLATE = "templates/java/spring-boot/http_error_template.mdl";
            };
        };
    }
}
#endif //DBCRUDGEN_CPP_JAVATEMPLATEFILES_H
