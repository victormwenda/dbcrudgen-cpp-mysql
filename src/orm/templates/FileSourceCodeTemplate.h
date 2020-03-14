//
// Created by vrwanda on 3/5/20.
//


#ifndef DBCRUDGEN_CPP_FILESOURCECODETEMPLATE_H
#define DBCRUDGEN_CPP_FILESOURCECODETEMPLATE_H

#include <string>
#include "../../io/FilesReader.h"
#include "SourceCodeTemplate.h"

namespace dbcrudgen {
    namespace orm {

        class FileSourceCodeTemplate : SourceCodeTemplate {

        protected:

            /**
            * Get the source code template file
            * @return
            */
            virtual std::string getSourceFile() = 0;

        public:
            FileSourceCodeTemplate() = default;

            /**
             * Returns the source code template
             * @return
             */
            std::string getTemplate() override {
                std::string sourceFile = getSourceFile();
                return FilesReader::readFile(sourceFile);
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_FILESOURCECODETEMPLATE_H