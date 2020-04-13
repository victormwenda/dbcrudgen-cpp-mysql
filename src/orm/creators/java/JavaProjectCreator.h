//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAVAPROJECTCREATOR_H
#define DBCRUDGEN_CPP_JAVAPROJECTCREATOR_H

#include "../ProjectCreator.h"
#include "../../codegen/Languages.h"
#include "../../codegen/Databases.h"
#include "../../../io/FilesWriter.h"
#include "../../projects/JavaProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class JavaProjectCreator : public ProjectCreator {
        private:
            JavaProjectModel projectModel;
        public:

            explicit JavaProjectCreator(JavaProjectModel &projectModel) : projectModel{projectModel} {}

            /**
             *
             * Get the programming language used to develop the project
             * @return
             */
            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }

            /**
             * Get the database used for generating the project
             * @return
             */
            std::string getDatabase() override {
                return std::string{Databases::SQLite};
            }

            const JavaProjectModel &getProjectModel() const {
                return projectModel;
            }

            /**
             * Create project Dirs
             */
            void createProjectDirs() override {

                FilesWriter::createDirs(projectModel.getAbsoluteProjectPath());
                FilesWriter::createDirs(projectModel.getAbsoluteJavaPath());
                FilesWriter::createDirs(projectModel.getAbsoluteLibsPath());
                FilesWriter::createDirs(projectModel.getAbsoluteResourcesPath());

            }

            /**
             * Create project source files
             */
            void createSourceFiles() override {

            }

            /**
             * Create a java project
             */
            void createProject() override {
                createProjectDirs();
                createSourceFiles();
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAVAPROJECTCREATOR_H
