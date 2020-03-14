//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_SOURCECODETEMPLATE_H
#define DBCRUDGEN_CPP_SOURCECODETEMPLATE_H

#include <string>

namespace dbcrudgen {
    namespace orm {

        class SourceCodeTemplate {
        public:
            SourceCodeTemplate() = default;

            /**
             * Returns the source code template
             * @return
             */
            virtual std::string getTemplate() = 0;

            /**
             * Get the language used to write the source code
             * @return
             */
            virtual std::string getLanguage() = 0;

        };
    }

}
#endif //DBCRUDGEN_CPP_SOURCECODETEMPLATE_H
