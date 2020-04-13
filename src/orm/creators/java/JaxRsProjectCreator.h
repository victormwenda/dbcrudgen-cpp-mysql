//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSPROJECTCREATOR_H
#define DBCRUDGEN_CPP_JAXRSPROJECTCREATOR_H

#include "JavaProjectCreator.h"
#include "../../projects/JaxRsProjectModel.h"
#include "../../../databases/generic/Database.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * JAX-RS Project Creator
         */
        class JaxRsProjectCreator : public JavaProjectCreator {

        private:
            JaxRsProjectModel projectModel;
            dbcrudgen::db::generic::Database database;
        public:

            JaxRsProjectCreator(JaxRsProjectModel &projectModel, dbcrudgen::db::generic::Database &database)
                    : projectModel{projectModel}, database{database}, JavaProjectCreator{projectModel} {}

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }

            std::string getDatabase() override {
                return std::string{Databases::GENERIC};
            }

            /**
              * Create project Dirs
              */
            void createProjectDirs() override {
                JavaProjectCreator::createProjectDirs();

                FilesWriter::createDirs(projectModel.getEntitiesAbsolutePath());
                FilesWriter::createDirs(projectModel.getApisAbsolutePath());
            }

            /**
             * Create project source files
             */
            void createSourceFiles() override {
                JavaProjectCreator::createSourceFiles();
            }

            /**
             * Create a java jax-rs project
             */
            void createProject() override {
                JavaProjectCreator::createProject();
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSPROJECTCREATOR_H
