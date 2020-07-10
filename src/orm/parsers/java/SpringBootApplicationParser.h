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

            /**
             * Substitute controller details
             * @param model
             * @param ctrlSource
             * @param ctrlClass
             * @param entityClass
             * @param trxClass
             * @param apiResName
             * @return
             */
            static std::string
            substituteControllerDetails(const SpringBootProjectModel &model, const db::generic::Column &column,
                                        std::string ctrlSource,
                                        const std::string &ctrlClass,
                                        const std::string &entityClass,
                                        const std::string &trxClass, const std::string &apiResName) {
                StringUtils::replace(ctrlSource, "${PROJECT_PACKAGE}", model.getPackageName());

                StringUtils::replace(ctrlSource, "${CONTROLLER_PACKAGE}", model.getControllersPkg());
                StringUtils::replace(ctrlSource, "${CONTROLLER_CLASS}", ctrlClass);

                StringUtils::replace(ctrlSource, "${TRX_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(ctrlSource, "${TRX_CLASS}", trxClass);
                std::string trxObject = toJavaVariableLocal(trxClass);
                StringUtils::replace(ctrlSource, "${TRX_OBJECT}", trxObject);

                StringUtils::replace(ctrlSource, "${ENTITY_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(ctrlSource, "${ENTITY_CLASS}", entityClass);
                std::string entityObject = toJavaVariableLocal(entityClass);
                StringUtils::replace(ctrlSource, "${ENTITY_OBJECT}", entityObject);

                StringUtils::replace(ctrlSource, "${PK_COLUMN_NAME}", column.getColumnName());
                StringUtils::replace(ctrlSource, "${PK_COLUMN_DATATYPE}", toJavaDataType(column.getDataType()));

                std::string methodGetter = "get";
                methodGetter = methodGetter.append(toJavaClassName(column.getColumnName()));
                StringUtils::replace(ctrlSource, "${PK_METHOD_GETTER}", methodGetter);

                StringUtils::replace(ctrlSource, "${RESOURCE-NAME}", apiResName);
                return ctrlSource;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
