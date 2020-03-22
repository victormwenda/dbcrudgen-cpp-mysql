//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_POSTMANTEMPLATEFILES_H
#define DBCRUDGEN_CPP_POSTMANTEMPLATEFILES_H

#include "../TemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Postman Template Files
         */
        class PostmanTemplateFiles : public TemplateFiles {

        public:
            static constexpr const char *COLLECTION_TEMPLATE = "templates/postman/postman_collection.mdl";
            static constexpr const char *REQUEST_TEMPLATE = "templates/postman/postman_request.mdl";
            static constexpr const char *REQUEST_BODY_TEMPLATE = "templates/postman/postman_request_body.mdl";
        };
    }
}

#endif //DBCRUDGEN_CPP_POSTMANTEMPLATEFILES_H
