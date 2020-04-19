//
// Created by victor on 4/19/20.
//

#ifndef DBCRUDGEN_CPP_JAXBPARSER_H
#define DBCRUDGEN_CPP_JAXBPARSER_H

#include "JavaParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class JaxbParser : public JavaParser {

        public:

            /**
             * Substitute class details
             * @param model
             * @param className
             * @param beanSource
             */
            static std::string
            substituteClassDetails(const JaxRsProjectModel &model, const std::string &className,
                                   std::string &beanSource) {


                StringUtils::replace(beanSource, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(beanSource, "${BEANS_PACKAGE}", model.getBeansPkg());

                StringUtils::replace(beanSource, "${CLASS_NAME}", className);

                return beanSource;

            }

            /**
             * Replace Getter Setters for java bean elements and attributes
             * @param beanSource
             * @param getterSetters
             * @return
             */
            static std::string substituteGetterSetters(std::string &beanSource, const std::string &getterSetters) {
                StringUtils::replace(beanSource, "${GETTER_SETTERS}", getterSetters);
                return beanSource;
            }

            /**
             * Replace the instance variables in the java bean
             * @param beanSource
             * @param instanceVariables
             * @return
             */
            static std::string
            substituteInstanceVariables(std::string &beanSource, const std::string &instanceVariables) {
                StringUtils::replace(beanSource, "${INSTANCE_VARIABLES}", instanceVariables);
                return beanSource;
            }

            /**
             * Replace constructor variables in the java beans class
             * @param beanSource
             * @param constructorVariables
             * @return
             */
            static std::string
            substituteConstructorVariables(std::string &beanSource, const std::string &constructorVariables) {
                StringUtils::replace(beanSource, "${CONSTRUCTOR_VARIABLES}", constructorVariables);
                return beanSource;
            }

            /**
             * Replace the instance variables initialization on the non default bean class constructor
             * @param beanSource
             * @param instanceVariableInitializations
             * @return
             */
            static std::string
            substituteInstanceVariablesInitialization(std::string &beanSource,
                                                      const std::string &instanceVariableInitializations) {
                StringUtils::replace(beanSource, "${INSTANCE_VARIABLES_INITIALIZATION}",
                                     instanceVariableInitializations);
                return beanSource;
            }

            /**
             * Add default instance variables initialization on the default constructor of the bean class
             * @param beanSource
             * @param defaultInstanceVariablesInitialization
             * @return
             */
            static std::string
            substituteDefaultInstanceVariablesInitialization(std::string &beanSource,
                                                             const std::string &defaultInstanceVariablesInitialization) {
                StringUtils::replace(beanSource, "${DEFAULT_INSTANCE_VARIABLES_INITIALIZATION}",
                                     defaultInstanceVariablesInitialization);
                return beanSource;
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXBPARSER_H
