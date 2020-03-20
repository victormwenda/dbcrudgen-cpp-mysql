//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_PHPPARSER_H
#define DBCRUDGEN_CPP_PHPPARSER_H

#include "../SyntaxParser.h"

namespace dbcrudgen {
    namespace orm {
        class PHPParser : public SyntaxParser {
        protected:
            static std::string toNamespace(const std::string pathName) {
                std::string nsName;

                int index = 0;
                while (index < pathName.length()) {

                    char c = pathName[index];

                    if (index == 0) {
                        c = toupper(c);
                    }

                    if (c == '/') {
                        nsName += "\\";
                    } else {
                        nsName += c;
                    }

                    index++;
                }

                return nsName;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_PHPPARSER_H
