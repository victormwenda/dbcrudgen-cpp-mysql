//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_SYNTAXPARSER_H
#define DBCRUDGEN_CPP_SYNTAXPARSER_H

#include <string>
#include "../utils/StringUtils.h"

namespace dbcrudgen {
    namespace orm {
        class SyntaxParser {
        public:

            /**
            * Recursively Replaces the tag in the model with the value
            * @param subject string being manipulated
            * @param search string to search
            * @param value string to replace with
            * @return
            */
            static std::string
            replace(std::string &subject, const std::string &search, const std::string &value) {
                return StringUtils::replace(subject, search, value);
            }

            /**
            * Create C++ header name
            * @param name
            * @return
            */
            static std::string parseProjectNameToHeaderName(std::string name) {

                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity

                int index = 0;
                while (index < name.length()) {

                    if (!isalpha(name[index])) {
                        name[index] = '_';
                    } else {
                        name[index] = toupper(name[index]);
                    }

                    index++;
                }

                return name;
            }

            /**
            * Create C++ header name
            * @param name
            * @return
            */
            static std::string parseClassNameToHeaderName(std::string name) {

                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity

                int index = 0;
                while (index < name.length()) {

                    if (!isalpha(name[index])) {
                        name[index] = '_';
                    } else {
                        name[index] = toupper(name[index]);
                    }

                    index++;
                }

                return name;
            }

            /**
             * Create C++ Class name
             * @param name
             * @return
             */
            static std::string toCppClassName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createClassNameCamelCase(name);
            }

            /**
             * Create C++ method name
             * @param name
             * @return
             */
            static std::string toCppMethodName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createMethodNameCamelCase(name);
            }

            /**
            * Create C++ Variable name
            * @param name
            * @return
            */
            static std::string toCppVariableName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createVariableNameCamelCase(name);
            }

            /**
             * Create C++ Class name
             * @param name
             * @return
             */
            static std::string toPHPClassName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createClassNameCamelCase(name);
            }

            /**
             * Create C++ method name
             * @param name
             * @return
             */
            static std::string toPHPMethodName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createMethodNameCamelCase(name);
            }

            /**
            * Create C++ Variable name
            * @param name
            * @return
            */
            static std::string toPHPVariableName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createVariableNameCamelCase(name);
            }

            /**
             * Convert name to snake case
             * @param name
             * @return
             */
            static std::string toSnakeCase(std::string name) {
                return StringUtils::toSnakeCase(name);
            }

            /**
             * Convert name to kebab case
             * @param name
             * @return
             */
            static std::string toKebabCase(std::string name) {
                return StringUtils::toKebabCase(name);
            }

            /**
             * Convert name to camel case
             * @param name
             * @return
             */
            static std::string toCamelCase(std::string name) {
                return StringUtils::toCamelCase(name);
            }

            /**
             * Convert name to pascal case
             * @param name
             * @return
             */
            static std::string toPascalCase(std::string name) {
                return StringUtils::toPascalCase(name);
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_SYNTAXPARSER_H
