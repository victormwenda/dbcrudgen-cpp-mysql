//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAXWSPROJECTCREATOR_H
#define DBCRUDGEN_CPP_JAXWSPROJECTCREATOR_H


#include "JavaProjectCreator.h"
#include "../../projects/JaxWsProjectModel.h"
#include "../../../databases/generic/Database.h"

namespace dbcrudgen {
    namespace orm {

        class JaxWsProjectCreator : public JavaProjectCreator {

        private:
            JaxWsProjectModel &projectModel;
            dbcrudgen::db::generic::Database database;
        public:

            /**
             * JAX-WS Project Creator
             * @param projectModel
             */
            explicit JaxWsProjectCreator(JaxWsProjectModel &projectModel, dbcrudgen::db::generic::Database &database)
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

                FilesWriter::createDirs(projectModel.getAbsoluteWebDirPath());
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
             * Create a java jax-ws project
             */
            void createProject() override {
                JavaProjectCreator::createProject();
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXWSPROJECTCREATOR_H
