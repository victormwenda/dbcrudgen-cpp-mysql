//
// Created by vrwanda on 3/5/20.
//



#ifndef DBCRUDGEN_CPP_PROJECTMODEL_H
#define DBCRUDGEN_CPP_PROJECTMODEL_H

#include<string>

namespace dbcrudgen {
    namespace orm {
        /**
         * A project Model
         */
        class ProjectModel {

        public:
            /**
             * The project name
             * @return
             */
            virtual const std::string &getProjectName() = 0;


            /**
             * The workspace directory where the project should be stored
             * @return
             */
            virtual const std::string &getWorkspaceDir() = 0;

            /**
             * The directory to store the generated source code
             * @return
             */
            virtual const std::string &getGeneratedCodeDir() = 0;


            /**
             * Programming language used to develop the source code
             * @return
             */
            virtual std::string getSourceLang() = 0;

            /**
             * Get Project Directory
             * @return
             */
            std::string getProjectDir() {
                return std::string{getWorkspaceDir() + "/" + getProjectName()};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_PROJECTMODEL_H
