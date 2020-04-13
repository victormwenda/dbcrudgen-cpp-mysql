//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAVAPARSER_H
#define DBCRUDGEN_CPP_JAVAPARSER_H

#include "../SyntaxParser.h"

namespace dbcrudgen {
    namespace orm {
        class JavaParser : public SyntaxParser {

        public:
            /**
             * Create Java Class name
             * @param name
             * @return
             */
            static std::string toJavaClassName(std::string &name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createClassNameCamelCase(name);
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_JAVAPARSER_H
