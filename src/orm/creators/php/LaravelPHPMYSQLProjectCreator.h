//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H
#define DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H

#include "PHPMYSQLProjectCreator.h"
#include "../../projects/LaravelPHPMYSQLProjectModel.h"
#include "../../parsers/php/LaravelParser.h"
#include "../../templates/php/laravel/LaravelControllerTemplate.h"
#include "../../templates/php/laravel/LaravelModelTemplate.h"

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

                auto databaseTableColumns = databaseModel.getTableColumns();

                for (const auto &table : tables) {

                    const std::string &tableName = table.getTableName();

                    std::string controllerSource = createControllerSource(table);
                    std::string modelSource = createModelSource(table);

                    auto tableColumnsIterator = databaseTableColumns.find(tableName);
                    auto columns = tableColumnsIterator->second;


                    std::string modelFillables;
                    std::string deserializedFormData;
                    std::string formDataValidationCandidates;
                    std::string packInsertTableAttribs;
                    std::string insertValidationRules;
                    std::string updateValidationRules;

                    int index = 0;
                    for (const auto &column : columns) {
                        bool isBeforeLast = index < columns.size() - 1;

                        //Create model fillables
                        modelFillables += LaravelParser::createModelFillableColumns(column, isBeforeLast);

                        //unpack form data
                        deserializedFormData += LaravelParser::deserializeSubmittedFormData(column);
                        formDataValidationCandidates += LaravelParser::createValidationCandidates(column, isBeforeLast);
                        packInsertTableAttribs += LaravelParser::packTableAttributesForInsert(column, isBeforeLast);

                        insertValidationRules += LaravelParser::createInsertValidationRules(column, isBeforeLast);
                        updateValidationRules += LaravelParser::createUpdateValidationRules(column, isBeforeLast);

                        index++;
                    }

                    //Replace model items
                    LaravelParser::replace(modelSource, "${FILLABLE_COLUMN_NAMES}", modelFillables);

                    //Replace controller items
                    LaravelParser::replace(controllerSource, "${DESERIALIZE_FORM_DATA}", deserializedFormData);
                    LaravelParser::replace(controllerSource, "${UNPACK_FORM_DATA}", formDataValidationCandidates);
                    LaravelParser::replace(controllerSource, "${PACK_TABLE_ATTRIBUTES}", packInsertTableAttribs);
                    LaravelParser::replace(controllerSource, "${INSERT_VALIDATION_RULES}", insertValidationRules);
                    LaravelParser::replace(controllerSource, "${UPDATE_VALIDATION_RULES}", updateValidationRules);


                    //Create model file
                    const std::string modelFilename = LaravelParser::toPHPClassName(tableName);
                    const std::string modelFilePath = projectModel.getModelsFullDir() + "/" + modelFilename + ".php";
                    FilesWriter::writeFile(modelFilePath, modelSource);

                    //create controller file
                    const std::string controllerFilename = LaravelParser::toPHPClassName(tableName);
                    const std::string controllerFilePath =
                            projectModel.getControllersFullDir() + "/" + controllerFilename + "Controller.php";
                    FilesWriter::writeFile(controllerFilePath, controllerSource);
                }

            }

            std::string createControllerSource(const mysql::Tables &table) {

                const std::string &tableName = table.getTableName();

                LaravelControllerTemplate controllerTemplate;
                std::string controllerSource = controllerTemplate.getTemplate();

                //create namespaces
                std::string controllerNamespace = LaravelParser::toNamespace(projectModel.getControllersDir());
                std::string modelNamespace = LaravelParser::toNamespace(projectModel.getModelsDir());

                //Add namespaces
                LaravelParser::replace(controllerSource, "${CONTROLLER_NAMESPACE}", controllerNamespace);
                LaravelParser::replace(controllerSource, "${MODEL_NAMESPACE}", modelNamespace);

                //Add class names
                std::string className = LaravelParser::toPHPClassName(tableName);
                std::string classNameVariable = LaravelParser::toPHPVariableName(tableName);


                LaravelParser::replace(controllerSource, "${CLASS_NAME}", className);
                LaravelParser::replace(controllerSource, "${MODEL_CLASS}", className);

                //Controller
                LaravelParser::replace(controllerSource, "${MODEL_VARIABLE}", classNameVariable);

                return controllerSource;
            }

            std::string createModelSource(const mysql::Tables &table) {

                const std::string &tableName = table.getTableName();

                LaravelModelTemplate modelTemplate;

                std::string modelSource = modelTemplate.getTemplate();

                //create namespaces
                std::string modelNamespace = LaravelParser::toNamespace(projectModel.getModelsDir());
                LaravelParser::replace(modelSource, "${MODEL_NAMESPACE}", modelNamespace);

                //Add class name
                std::string className = LaravelParser::toPHPClassName(tableName);
                LaravelParser::replace(modelSource, "${CLASS_NAME}", className);

                //Add table name
                LaravelParser::replace(modelSource, "${TABLE_NAME}", tableName);

                //Add model relation ships
                LaravelParser::replace(modelSource, "${MODEL_RELATIONSHIPS}", "");
                LaravelParser::replace(modelSource, "${MODEL_RELATIONSHIPS_INCLUDES}", "");

                return modelSource;
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTCREATOR_H
