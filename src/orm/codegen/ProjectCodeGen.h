//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_PROJECTCODEGEN_H
#define DBCRUDGEN_CPP_PROJECTCODEGEN_H

#include "../../io/FilesWriter.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Code generator
         */
        class ProjectCodeGen {

        protected:
            FilesWriter filesWriter;

        public:
            const FilesWriter &getFilesWriter() const {
                return filesWriter;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_PROJECTCODEGEN_H
