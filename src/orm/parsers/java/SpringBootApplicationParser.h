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
            *
            * @param model
            * @param sbAppClassSrc
            */
            static void substituteProjectDetails(const SpringBootProjectModel &model, std::string &sbAppClassSrc) {

                StringUtils::replace(sbAppClassSrc, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sbAppClassSrc, "${SB_APPLICATION_PACKAGE}", model.getSBAppClassPkg());
                StringUtils::replace(sbAppClassSrc, "${CLASS_NAME}", model.getSBAppClassName());

            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
