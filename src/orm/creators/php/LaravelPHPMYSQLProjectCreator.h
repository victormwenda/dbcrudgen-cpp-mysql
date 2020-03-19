//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H
#define DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H

#include "PHPMYSQLProjectCreator.h"
#include "../../projects/LaravelPHPMYSQLProjectModel.h"
#include "../../parsers/php/LaravelParser.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelPHPMYSQLProjectCreator : public PHPMYSQLProjectCreator {

        private:
            LaravelPHPMYSQLProjectModel projectModel;
            LaravelParser parser;

        public:
            explicit LaravelPHPMYSQLProjectCreator(LaravelPHPMYSQLProjectModel &projectModel,
                                                   dbcrudgen::mysql::MYSQLDatabaseModel databaseModel)
                    : PHPMYSQLProjectCreator{projectModel, databaseModel}, projectModel{projectModel} {}


            void createProject() override {
                PHPMYSQLProjectCreator::createProject();
                createProjectDirs();
                createSourceFiles();
            }

            void createProjectDirs() override {
                PHPMYSQLProjectCreator::createProjectDirs();

                FilesWriter::createDirs(projectModel.getControllersFullDir());
                FilesWriter::createDirs(projectModel.getModelsFullDir());
                FilesWriter::createDirs(projectModel.getViewsFullDir());
                FilesWriter::createDirs(projectModel.getRoutesFullDir());
            }

            void createSourceFiles() override {
                PHPMYSQLProjectCreator::createSourceFiles();

                //Create web routes
                const std::string webRouteFilePath = projectModel.getWebRouteFilePath();
                FilesWriter::writeFile(webRouteFilePath, "");

                //Create api routes
                const std::string apiRouteFilePath = projectModel.getApiRouteFilePath();
                FilesWriter::writeFile(apiRouteFilePath, "");

                auto databaseModel = getDatabaseModel();
                auto tables = databaseModel.getTables();

                for (const auto table : tables) {
                    const std::string tableName = table.getTableName();

                    //Create model file
                    const std::string modelFilename = parser.toPHPClassName(tableName);
                    const std::string modelFilePath = projectModel.getModelsFullDir() + "/" + modelFilename + ".php";
                    FilesWriter::writeFile(modelFilePath, "");

                    //create controller file
                    const std::string controllerFilename = parser.toPHPClassName(tableName);
                    const std::string controllerFilePath =
                            projectModel.getControllersFullDir() + "/" + controllerFilename + "Controller.php";
                    FilesWriter::writeFile(controllerFilePath, "");
                }

            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H
