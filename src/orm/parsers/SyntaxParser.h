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
             * Create C++ Variable name
             * @param name
             * @return
             */
            static std::string toCppVariableName(std::string &name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createVariableNameCamelCase(name);
            }

            /**
             * Create C++ method name
             * @param name
             * @return
             */
            static std::string toCppMethodName(std::string &name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createMethodNameCamelCase(name);
            }

            /**
                 * Create C++ Class name
                 * @param name
                 * @return
                 */
            static std::string toCppClassName(std::string &name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createClassNameCamelCase(name);
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_SYNTAXPARSER_H
