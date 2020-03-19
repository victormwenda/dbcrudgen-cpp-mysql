//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELPHPTEMPLATEFILES_H
#define DBCRUDGEN_CPP_LARAVELPHPTEMPLATEFILES_H

#include "../../TemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelPHPTemplateFiles : TemplateFiles {
        public:
            static constexpr const char *CLASS_CONTROLLER_TEMPLATE = "templates/php/laravel/class_controller.php.mdl";
            static constexpr const char *CLASS_MODEL_TEMPLATE = "templates/php/laravel/class_model.php.mdl";

            static constexpr const char *METHOD_CONTROLLER_CREATE = "templates/php/laravel/method_controller_create.mdl";
            static constexpr const char *METHOD_CONTROLLER_DESTROY = "templates/php/laravel/method_controller_destroy.mdl";
            static constexpr const char *METHOD_CONTROLLER_EDIT = "templates/php/laravel/method_controller_edit.mdl";
            static constexpr const char *METHOD_CONTROLLER_SHOW = "templates/php/laravel/method_controller_show.mdl";
            static constexpr const char *METHOD_CONTROLLER_STORE = "templates/php/laravel/method_controller_store.mdl";
            static constexpr const char *METHOD_CONTROLLER_UPDATE = "templates/php/laravel/method_controller_update.mdl";

            static constexpr const char *METHOD_ROUTE_API_DELETE = "templates/php/laravel/method_route_api_delete.mdl";
            static constexpr const char *METHOD_ROUTE_API_GET = "templates/php/laravel/method_route_api_get.mdl";
            static constexpr const char *METHOD_ROUTE_API_POST = "templates/php/laravel/method_route_api_post.mdl";
            static constexpr const char *METHOD_ROUTE_API_PUT = "templates/php/laravel/method_route_api_put.mdl";

            static constexpr const char *METHOD_ROUTE_WEB_DELETE = "templates/php/laravel/method_route_web_delete.mdl";
            static constexpr const char *METHOD_ROUTE_WEB_GET = "templates/php/laravel/method_route_web_get.mdl";
            static constexpr const char *METHOD_ROUTE_WEB_POST = "templates/php/laravel/method_route_web_post.mdl";
            static constexpr const char *METHOD_ROUTE_WEB_PUT = "templates/php/laravel/method_route_web_put.mdl";

            static constexpr const char *SCRIPT_ROUTE_WEB = "templates/php/laravel/";
            static constexpr const char *SCRIPT_ROUTE_API = "templates/php/laravel/";
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELPHPTEMPLATEFILES_H
