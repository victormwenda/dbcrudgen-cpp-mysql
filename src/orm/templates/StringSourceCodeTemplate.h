//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_STRINGSOURCECODETEMPLATE_H
#define DBCRUDGEN_CPP_STRINGSOURCECODETEMPLATE_H

#include <string>
#include "SourceCodeTemplate.h"

namespace dbcrudgen {
    namespace orm {

        class StringSourceCodeTemplate : SourceCodeTemplate {

        public:

            StringSourceCodeTemplate() = default;

            /**
            * Get the source code template string
            * @return
            */
            virtual std::string getSourceString() = 0;
        };

    }
}
#endif //DBCRUDGEN_CPP_STRINGSOURCECODETEMPLATE_H
