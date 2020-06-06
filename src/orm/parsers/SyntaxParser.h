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
                return SyntaxParser::createClassNameCamelCase(name);
            }

            /**
             * Create C++ method name
             * @param name
             * @return
             */
            static std::string toCppMethodName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return SyntaxParser::createMethodNameCamelCase(name);
            }

            /**
            * Create C++ Variable name
            * @param name
            * @return
            */
            static std::string toCppVariableName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return SyntaxParser::createVariableNameCamelCase(name);
            }

            /**
             * Create C++ Class name
             * @param name
             * @return
             */
            static std::string toPHPClassName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return SyntaxParser::createClassNameCamelCase(name);
            }

            /**
             * Create C++ method name
             * @param name
             * @return
             */
            static std::string toPHPMethodName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return SyntaxParser::createMethodNameCamelCase(name);
            }

            /**
            * Create C++ Variable name
            * @param name
            * @return
            */
            static std::string toPHPVariableName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return SyntaxParser::createVariableNameCamelCase(name);
            }

            /**
            * Convert text to snake case
            * @param name
            * @return
            */
            static std::string toSnakeCase(std::string name) {
                std::string snake_case;
                int index = 0;

                while (index < name.size()) {

                    if (isupper(name[index])) {

                        if (snake_case.empty()) {
                            snake_case.append(1, tolower(name[index]));
                        } else {
                            snake_case.append("_").append(1, tolower(name[index]));
                        }
                    } else {
                        snake_case.append(1, name[index]);
                    }

                    index++;
                }

                return snake_case;
            }

            /**
             * Convert text to kebab case
             * Kebab case contains lower case words separated with hyphens.
             * Also called caterpillar case
             * @param name
             * @return
             */
            static std::string toKebabCase(std::string name) {
                std::string snake_case;
                int index = 0;

                while (index < name.size()) {

                    if (name[index] == '_') {
                        snake_case.append("-");
                        index++;
                        continue;
                    }

                    if (isupper(name[index])) {

                        if (snake_case.empty()) {
                            snake_case.append(1, tolower(name[index]));
                        } else {
                            snake_case.append("-").append(1, tolower(name[index]));
                        }
                    } else {
                        snake_case.append(1, name[index]);
                    }


                    index++;
                }

                return snake_case;
            }

            /**
             * Create a camel case name
             * @param name
             * @return
             */
            static std::string toCamelCase(std::string name) {

                //convert all letters to small letters
                int index = 0;
                while (index < name.length()) {
                    name[index] = tolower(name[index]);
                    index++;
                }

                std::string variable_name;
                std::vector<std::string> parts = StringUtils::split(name.c_str(), "_");

                if (parts.size() == 0) {
                    return name;
                }

                int partsIndex = 0;

                for (std::string &part : parts) {

                    if (partsIndex == 0) {
                        variable_name += part;
                        partsIndex++;
                        continue;
                    }

                    char partsFirstChar = part[0];

                    if (isalpha(partsFirstChar) && islower(partsFirstChar)) {
                        part[0] = toupper(partsFirstChar);
                    }

                    partsIndex++;
                    variable_name += part;
                }

                name = variable_name;
                return name;
            }

            /**
             * Create a pascal case name
             * @param name
             * @return
             */
            static std::string toPascalCase(std::string name) {

                name = StringUtils::to_lower(name);
                name[0] = toupper(name[0]);

                std::string class_name;
                std::vector<std::string> parts = StringUtils::split(name.c_str(), "_");

                if (parts.size() == 0) {
                    name = StringUtils::to_lower(name);
                    name[0] = toupper(name[0]);
                    return name;
                }

                for (std::string &part : parts) {

                    part = StringUtils::to_lower(part);

                    char firstChar = part[0];

                    if (isalpha(firstChar) && islower(firstChar)) {
                        part[0] = toupper(firstChar);
                    }

                    class_name += part;
                }

                name = class_name;

                return name;
            }

            /**
             * Convert text to space separated title case
             * @param name
             * @return
             */
            static std::string toTitle(std::string name) {
                std::string title;
                int index = 0;

                while (index < name.size()) {

                    if (index == 0) {
                        title.append(1, toupper(name[index]));
                    } else {
                        if (name[index] == '_' || name[index] == '-') {
                            title.append(1, toupper(' '));

                            if (index - name.length() - 1) {
                                title.append(1, toupper(name[++index]));
                            }
                        } else {
                            title.append(1, name[index]);
                        }
                    }
                    index++;
                }

                return title;
            }

            /**
             * Create an all caps header name
             * @param name
             * @return
             */
            static std::string createCapsHeaderName(std::string name) {

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
             * Create a camel case class name
             * @param name
             * @return
             */
            static std::string createClassNameCamelCase(std::string name) {

                name = StringUtils::to_lower(name);
                name[0] = toupper(name[0]);

                std::string class_name;
                std::vector<std::string> parts = StringUtils::split(name.c_str(), "_");

                if (parts.size() == 0) {
                    name = StringUtils::to_lower(name);
                    name[0] = toupper(name[0]);
                    return name;
                }

                for (std::string &part : parts) {

                    part = StringUtils::to_lower(part);

                    char firstChar = part[0];

                    if (isalpha(firstChar) && islower(firstChar)) {
                        part[0] = toupper(firstChar);
                    }

                    class_name += part;
                }

                name = class_name;

                return name;
            }

            /**
             * Create a camel case method name
             * @param name
             * @return
             */
            static std::string createMethodNameCamelCase(std::string name) {

                //Make the first letter upper case
                name[0] = toupper(name[0]);

                //convert all letters after first letter to small letters
                int index = 1;
                while (index < name.length()) {
                    name[index] = tolower(name[index]);
                    index++;
                }

                std::string method_name;
                std::vector<std::string> parts = StringUtils::split(name.c_str(), "_");

                if (parts.size() == 0) {
                    return name;
                }


                int partsIndex = 0;

                for (std::string &part : parts) {

                    if (partsIndex == 0) {
                        method_name += part;
                        partsIndex++;
                        continue;
                    }

                    char partsFirstChar = part[0];

                    if (isalpha(partsFirstChar) && islower(partsFirstChar)) {
                        part[0] = toupper(partsFirstChar);
                    }

                    partsIndex++;
                    method_name += part;
                }

                name = method_name;

                return name;
            }

            /**
             * Create a camel case variable name
             * @param name
             * @return
             */
            static std::string createVariableNameCamelCase(std::string name) {
                return toCamelCase(name);
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_SYNTAXPARSER_H
