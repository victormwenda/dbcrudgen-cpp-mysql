//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_PROJECTCREATOR_H
#define DBCRUDGEN_CPP_PROJECTCREATOR_H

#include <string>

namespace dbcrudgen {

    namespace orm {
        //
        // ProjectCreator
        // //
        class ProjectCreator {

        public:
            /**
             * Get the programming language used for generating the project
             * @return
             */
            virtual std::string getLanguage() = 0;

            /**
             * Get the database used for generating the project
             * @return
             */
            virtual std::string getDatabase() = 0;

            /**
             * Creates a project
             */
            virtual void createProject() = 0;

            /**
             * Create project dirs
             */
            virtual void createProjectDirs() = 0;

            /**
             * Create the source files for the project
             */
            virtual void createSourceFiles() = 0;
        };
    }
}

#endif //DBCRUDGEN_CPP_PROJECTCREATOR_H
