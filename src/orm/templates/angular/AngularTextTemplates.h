//
// Created by victor on 6/5/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARTEXTTEMPLATES_H
#define DBCRUDGEN_CPP_ANGULARTEXTTEMPLATES_H

#include "../FileSourceCodeTemplate.h"
#include "../TemplateFiles.h"
#include "AngularTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {

        class AngularTextTemplates {
        public:
            static constexpr const char *FORM_CONTROL_DECLARATION = "${FORM_CONTROL}Fc : FormControl;";
            static constexpr const char *FORM_CONTROL_INIT = "this.${FORM_CONTROL}Fc = new FormControl(${DEFAULT_VALUE}, []);";

            static constexpr const char *FORM_GROUP_DECLARATION = "${FORM_GROUP}Fg : FormGroup;";
            static constexpr const char *FORM_GROUP_INIT = "this.${FORM_GROUP}Fg = new FormGroup({});";
        };
    }
}


#endif //DBCRUDGEN_CPP_ANGULARTEXTTEMPLATES_H
