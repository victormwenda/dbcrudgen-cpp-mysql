//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
#define DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H


#include "JavaParser.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootApplicationParser : public JavaParser {
        public:
            /**
            * substitute project details
            * @param model
            * @param sbAppClassSrc
            */
            static void substituteProjectDetails(const SpringBootProjectModel &model, std::string &sbAppClassSrc) {

                StringUtils::replace(sbAppClassSrc, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sbAppClassSrc, "${SB_APPLICATION_PACKAGE}", model.getSBAppClassPkg());
                StringUtils::replace(sbAppClassSrc, "${CONTROLLERS_PACKAGE}", model.getControllersPkg());
                StringUtils::replace(sbAppClassSrc, "${CLASS_NAME}", model.getSBAppClassName());

            }

            static std::string
            substituteControllerDetails(const SpringBootProjectModel &model, std::string ctrlSource,
                                        const std::string &ctrlClass,
                                        const std::string &entityClass,
                                        const std::string &trxClass, const std::string &apiResName) {
                StringUtils::replace(ctrlSource, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(ctrlSource, "${CONTROLLER_PACKAGE}", model.getControllersPkg());
                StringUtils::replace(ctrlSource, "${CONTROLLER_CLASS}", ctrlClass);
                StringUtils::replace(ctrlSource, "${RESOURCE-NAME}", apiResName);
                return ctrlSource;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
