//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H
#define DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H

#include "PHPMYSQLProjectCreator.h"
#include "../../projects/LaravelPHPMYSQLProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelPHPMYSQLProjectCreator : public PHPMYSQLProjectCreator {

        private:
            LaravelPHPMYSQLProjectModel projectModel;

        public:
            explicit LaravelPHPMYSQLProjectCreator(LaravelPHPMYSQLProjectModel &projectModel,
                                                   dbcrudgen::mysql::MYSQLDatabaseModel databaseModel)
                    : PHPMYSQLProjectCreator{projectModel, databaseModel}, projectModel{projectModel} {}


            void createProject() override {
                PHPMYSQLProjectCreator::createProject();
            }

            void createProjectDirs() override {
                PHPMYSQLProjectCreator::createProjectDirs();

                FilesWriter::createDirs(projectModel.getControllersFullDir());
                FilesWriter::createDirs(projectModel.getModelsFullDir());
                FilesWriter::createDirs(projectModel.getViewsFullDir());
                FilesWriter::createDirs(projectModel.getAPIsFullDir());
            }

            void createSourceFiles() override {
                PHPMYSQLProjectCreator::createSourceFiles();
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H
