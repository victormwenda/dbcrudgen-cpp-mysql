//
// Created by victor on 3/23/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELPROJECTCREATOR_H
#define DBCRUDGEN_CPP_LARAVELPROJECTCREATOR_H

#include "../../parsers/php/LaravelParser.h"
#include "../../templates/php/laravel/LaravelControllerTemplate.h"
#include "../../templates/php/laravel/LaravelModelTemplate.h"
#include "../../templates/php/laravel/LaravelTableWebRoutesTemplate.h"
#include "../../templates/php/laravel/LaravelTableRoutesApiTemplate.h"
#include "../../templates/php/laravel/LaravelRoutesApiTemplate.h"
#include "../../templates/php/laravel/LaravelRoutesWebTemplate.h"
#include "../../projects/LaravelProjectModel.h"
#include "PHPProjectCreator.h"
#include "../../templates/php/laravel/LaravelViewTemplate.h"
#include "../../templates/php/laravel/LaravelTableScrudJSTemplate.h"
#include "../../templates/php/laravel/LaravelDataTableTemplate.h"

namespace dbcrudgen {
    namespace orm {

        class LaravelProjectCreator : public PHPProjectCreator {

        private:
            LaravelProjectModel projectModel;

        public:
            explicit LaravelProjectCreator(LaravelProjectModel &projectModel,
                                           dbcrudgen::db::generic::Database databaseModel)
                    : PHPProjectCreator{projectModel, databaseModel}, projectModel{projectModel} {}


            void createProject() override {
                PHPProjectCreator::createProject();
                createProjectDirs();
                createSourceFiles();
            }

            void createProjectDirs() override {
                PHPProjectCreator::createProjectDirs();

                FilesWriter::createDirs(projectModel.getControllersFullDir());
                FilesWriter::createDirs(projectModel.getModelsFullDir());
                FilesWriter::createDirs(projectModel.getViewsFullDir());
                FilesWriter::createDirs(projectModel.getRoutesFullDir());
            }

            void createSourceFiles() override {
                PHPProjectCreator::createSourceFiles();

                //Create web routes source
                std::string webRoutesSource;

                //Create api routes source
                std::string apiRoutesSource;

                //Create models includes for routes
                std::string modelsIncludes;

                auto databaseModel = getDatabaseModel();
                auto tables = databaseModel.getTables();


                for (const auto &table : tables) {

                    const std::string &tableName = table.getTableName();

                    std::string controllerSource = createControllerSource(table);
                    std::string modelSource = createModelSource(table);
                    std::string viewSource = createViewSource(table);
                    std::string dataTableSource = createDataTableSource(table);
                    std::string jsSource = createJSource(table);


                    //Create routes source
                    std::string webRoutes = createWebRouteSource(table);
                    std::string apiRoutes = createApiRouteSource(table);

                    //Append models include for routes
                    modelsIncludes += createModelsInclude(table);

                    auto columns = table.getTableColumns();

                    //Controller items
                    std::string modelFillables;
                    std::string deserializedFormData;
                    std::string formDataValidationCandidates;
                    std::string packInsertTableAttribs;
                    std::string insertValidationRules;
                    std::string updateValidationRules;

                    //Views items
                    std::string htmlTableHeaderCols;
                    std::string htmlTableRowsCols;
                    std::string formItems;

                    //Views items
                    std::string jsPackFormItems;
                    std::string jsRequestParams;
                    std::string jsUnPackItemData;
                    std::string jsBindItemDataDOM;

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

                        //Unpack table cols
                        htmlTableHeaderCols += LaravelParser::createTableHeaderColumns(table, column);
                        htmlTableRowsCols += LaravelParser::createTableRowsColumns(table, column);
                        formItems += LaravelParser::createFormItems(column);

                        //Pack form items
                        jsPackFormItems += LaravelParser::packJSFormItems(column);
                        jsRequestParams += LaravelParser::packRequestParams(column, isBeforeLast);
                        jsUnPackItemData += LaravelParser::unpackItemData(column);
                        jsBindItemDataDOM += LaravelParser::bindItemDataToDocument(column);

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

                    //Replace on routes files
                    LaravelParser::replace(apiRoutes, "${DESERIALIZE_FORM_DATA}", deserializedFormData);
                    LaravelParser::replace(apiRoutes, "${UNPACK_FORM_DATA}", formDataValidationCandidates);
                    LaravelParser::replace(apiRoutes, "${INSERT_VALIDATION_RULES}", insertValidationRules);
                    LaravelParser::replace(apiRoutes, "${UPDATE_VALIDATION_RULES}", updateValidationRules);
                    LaravelParser::replace(apiRoutes, "${PACK_TABLE_ATTRIBUTES}", packInsertTableAttribs);

                    webRoutesSource += webRoutes;
                    apiRoutesSource += apiRoutes;

                    //Add views data items
                    LaravelParser::replace(dataTableSource, "${TABLE_HEADERS}", htmlTableHeaderCols);
                    LaravelParser::replace(dataTableSource, "${TABLE_ROW_DATA}", htmlTableRowsCols);

                    LaravelParser::replace(viewSource, "${FORM_ITEMS}", formItems);

                    std::string tableViewDir = StringUtils::toKebabCase(tableName);
                    LaravelParser::replace(viewSource, "${VIEW_DIR}", tableViewDir);



                    //Add JS data
                    LaravelParser::replace(jsSource, "${PACK_FORM_ITEMS}", jsPackFormItems);
                    LaravelParser::replace(jsSource, "${PACK_REQUEST_PARAMS}", jsRequestParams);
                    LaravelParser::replace(jsSource, "${UNPACK_ITEM_DATA}", jsUnPackItemData);
                    LaravelParser::replace(jsSource, "${BIND_DATA_TO_DOCUMENT}", jsBindItemDataDOM);

                    //Create model file
                    const std::string modelFilename = LaravelParser::toPHPClassName(tableName);
                    const std::string modelFilePath = projectModel.getModelsFullDir() + "/" + modelFilename + ".php";
                    FilesWriter::writeFile(modelFilePath, modelSource);

                    //create controller file
                    const std::string controllerFilename = LaravelParser::toPHPClassName(tableName);
                    const std::string controllerFilePath =
                            projectModel.getControllersFullDir() + "/" + controllerFilename + "Controller.php";
                    FilesWriter::writeFile(controllerFilePath, controllerSource);

                    //create view file
                    const std::string viewFilename = LaravelParser::toSnakeCase(tableName);
                    LaravelParser::replace(controllerSource, "${VIEW_NAME}", "index");

                    const std::string controllerViewsDir = LaravelParser::toKebabCase(tableName);
                    const std::string controllerViewsDirPath = projectModel.getViewsFullDir().append("/")
                            .append(controllerViewsDir);
                    FilesWriter::createDirs(controllerViewsDirPath);

                    std::string viewsFilePath = controllerViewsDirPath + "/index.blade.php";
                    FilesWriter::writeFile(viewsFilePath, viewSource);

                    std::string dataTableFilePath = controllerViewsDirPath + "/table.blade.php";
                    FilesWriter::writeFile(dataTableFilePath, dataTableSource);

                    std::string jsFile = LaravelParser::toKebabCase(tableName);
                    std::string jsFilePath = projectModel.getJSFullDir() + "/" + jsFile + ".js";
                    FilesWriter::writeFile(jsFilePath, jsSource);
                }

                //Create web routes
                const std::string webRouteFilePath = projectModel.getWebRouteFilePath();
                LaravelRoutesWebTemplate webTemplate;
                std::string webFullSource = webTemplate.getTemplate();
                LaravelParser::replace(webFullSource, "${WEB_ROUTES}", webRoutesSource);
                LaravelParser::replace(webFullSource, "${MODELS_INCLUDES}", modelsIncludes); //Add models includes
                FilesWriter::writeFile(webRouteFilePath, webFullSource);

                //Create api routes
                const std::string apiRouteFilePath = projectModel.getApiRouteFilePath();
                LaravelRoutesApiTemplate apiTemplate;
                std::string apiFullSource = apiTemplate.getTemplate();
                LaravelParser::replace(apiFullSource, "${API_ROUTES}", apiRoutesSource);
                LaravelParser::replace(apiFullSource, "${MODELS_INCLUDES}", modelsIncludes); //Add models includes
                FilesWriter::writeFile(apiRouteFilePath, apiFullSource);
            }

            /**
             * Creates the controller source code
             * @param table
             * @return
             */
            std::string createControllerSource(const dbcrudgen::db::generic::Table &table) {

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
                std::string viewName = StringUtils::toKebabCase(tableName);


                LaravelParser::replace(controllerSource, "${CLASS_NAME}", className);
                LaravelParser::replace(controllerSource, "${MODEL_CLASS}", className);

                //Controller
                LaravelParser::replace(controllerSource, "${MODEL_VARIABLE}", classNameVariable);
                LaravelParser::replace(controllerSource, "${VIEW_DIR}", viewName);

                std::string viewFilename = LaravelParser::toKebabCase(tableName);
                LaravelParser::replace(controllerSource, "${INDEX_VIEW_NAME}", "index");
                LaravelParser::replace(controllerSource, "${REFRESH_VIEW_NAME}", "table");

                return controllerSource;
            }

            /**
             * Creates the model source code
             * @param table
             * @return
             */
            std::string createModelSource(const dbcrudgen::db::generic::Table &table) {

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

            /**
             * Creates the model source code
             * @param table
             * @return
             */
            std::string createViewSource(const dbcrudgen::db::generic::Table &table) {

                const std::string &tableName = table.getTableName();

                LaravelViewTemplate viewTemplate;

                std::string viewSource = viewTemplate.getTemplate();

                std::string tableTitle = StringUtils::toTitle(tableName);
                std::string projectTitle = StringUtils::toTitle(projectModel.getProjectName());
                std::string className = LaravelParser::toPHPClassName(tableName);
                std::string classVariable = LaravelParser::toPHPVariableName(tableName);
                std::string classId = LaravelParser::toSnakeCase(tableName);

                //create namespaces
                std::string modelNamespace = LaravelParser::toNamespace(projectModel.getModelsDir());
                LaravelParser::replace(viewSource, "${MODEL_NAMESPACE}", modelNamespace);

                //Add class name
                LaravelParser::replace(viewSource, "${CLASS_NAME}", className);

                //Add table name
                LaravelParser::replace(viewSource, "${TABLE_NAME}", tableName);

                //Add model relation ships
                LaravelParser::replace(viewSource, "${MODEL_RELATIONSHIPS}", "");
                LaravelParser::replace(viewSource, "${MODEL_RELATIONSHIPS_INCLUDES}", "");

                //Add basic project info
                LaravelParser::replace(viewSource, "${PAGE_TITLE}", projectTitle + " | " + tableTitle);
                LaravelParser::replace(viewSource, "${ITEMS_HANDLE}", classVariable);
                LaravelParser::replace(viewSource, "${MODAL_ID}", classId);
                LaravelParser::replace(viewSource, "${MODAL_TITLE}", tableTitle);

                //Add JS details
                LaravelParser::replace(viewSource, "${JS-ASSET-DIR}", projectModel.getJsDir());
                LaravelParser::replace(viewSource, "${VIEW-JS-FILE}", StringUtils::toKebabCase(tableName));

                return viewSource;
            }

            /**
            * Creates the data table source code
            * @param table
            * @return
            */
            static std::string createDataTableSource(const dbcrudgen::db::generic::Table &table) {

                const std::string &tableName = table.getTableName();

                LaravelDataTableTemplate dataTableTemplate;

                std::string tableSource = dataTableTemplate.getTemplate();

                std::string classVariable = LaravelParser::toPHPVariableName(tableName);
                LaravelParser::replace(tableSource, "${ITEMS_HANDLE}", classVariable);

                return tableSource;
            }

            /**
             * Creates the java script source code
             * @param table
             * @return
             */
            std::string createJSource(const dbcrudgen::db::generic::Table &table) {

                const std::string &tableName = table.getTableName();

                LaravelTableScrudJSTemplate jsTemplate;

                std::string viewSource = jsTemplate.getTemplate();

                std::string tableTitle = StringUtils::toTitle(tableName);
                std::string projectTitle = StringUtils::toTitle(projectModel.getProjectName());
                std::string className = LaravelParser::toPHPClassName(tableName);
                std::string classVariable = LaravelParser::toPHPVariableName(tableName);
                std::string classId = LaravelParser::toSnakeCase(tableName);

                //create namespaces
                std::string modelNamespace = LaravelParser::toNamespace(projectModel.getModelsDir());
                LaravelParser::replace(viewSource, "${MODEL_NAMESPACE}", modelNamespace);

                //Add class name
                LaravelParser::replace(viewSource, "${CLASS_NAME}", className);

                //Add table name
                LaravelParser::replace(viewSource, "${TABLE_NAME}", tableName);

                //Add model relation ships
                LaravelParser::replace(viewSource, "${MODEL_RELATIONSHIPS}", "");
                LaravelParser::replace(viewSource, "${MODEL_RELATIONSHIPS_INCLUDES}", "");

                //Add basic project info
                LaravelParser::replace(viewSource, "${PAGE_TITLE}", projectTitle + " | " + tableTitle);
                LaravelParser::replace(viewSource, "${ITEMS_HANDLE}", classVariable);
                LaravelParser::replace(viewSource, "${MODAL_ID}", classId);
                LaravelParser::replace(viewSource, "${MODAL_TITLE}", tableTitle);
                LaravelParser::replace(viewSource, "${API_NAME}", StringUtils::toKebabCase(tableName));

                return viewSource;
            }

            /**
             * Create Table Web Routes source code
             * @param table
             * @return
             */
            static std::string createWebRouteSource(const dbcrudgen::db::generic::Table &table) {
                LaravelTableWebRoutesTemplate routeWebTemplate;
                std::string source = routeWebTemplate.getTemplate();

                std::string className = LaravelParser::toPHPClassName(table.getTableName());
                std::string apiName = StringUtils::toKebabCase(className);

                LaravelParser::replace(source, "${CONTROLLER_CLASS}", className.append("Controller"));
                LaravelParser::replace(source, "${API_NAME}", apiName);
                LaravelParser::replace(source, "${TABLE NAME}", table.getTableName());

                return source;
            }

            /**
             * Create Table API Routes Source code
             * @param table
             * @return
             */
            std::string createApiRouteSource(const dbcrudgen::db::generic::Table &table) {
                LaravelTableRoutesApiTemplate routeApiTemplate;
                std::string source = routeApiTemplate.getTemplate();

                std::string className = LaravelParser::toPHPClassName(table.getTableName());
                std::string classVariable = LaravelParser::toPHPVariableName(table.getTableName());
                std::string apiName = StringUtils::toKebabCase(className);

                LaravelParser::replace(source, "${API_VERSION}", projectModel.getApiVersion());
                LaravelParser::replace(source, "${API_NAME}", apiName);
                LaravelParser::replace(source, "${TABLE NAME}", table.getTableName());
                LaravelParser::replace(source, "${MODEL_CLASS}", className);
                LaravelParser::replace(source, "${MODEL_VARIABLE}", classVariable);
                return source;
            }

            std::string createModelsInclude(const dbcrudgen::db::generic::Table &table) {

                std::string modelNamespace = LaravelParser::toNamespace(projectModel.getModelsDir());
                std::string modelClassName = LaravelParser::toPHPClassName(table.getTableName());

                return std::string{"use " + modelNamespace + "\\" + modelClassName + ";\n"};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELPROJECTCREATOR_H
