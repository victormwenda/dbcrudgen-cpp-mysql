//
// Created by victor on 6/1/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARPROJECTCREATOR_H
#define DBCRUDGEN_CPP_ANGULARPROJECTCREATOR_H

#include "../../projects/AngularProjectModel.h"
#include "../../../databases/generic/Database.h"
#include "../ProjectCreator.h"
#include "../../codegen/Databases.h"
#include "../../../io/FilesWriter.h"
#include "../../parsers/angular/AngularParser.h"

namespace dbcrudgen {
    namespace orm {
        class AngularProjectCreator : public ProjectCreator {

        private:
            dbcrudgen::orm::AngularProjectModel projectModel;
            dbcrudgen::db::generic::Database databaseModel;

        public:
            AngularProjectCreator(dbcrudgen::orm::AngularProjectModel &projectModel,
                                  dbcrudgen::db::generic::Database &databaseModel)
                    : projectModel{projectModel},
                      databaseModel{databaseModel} {}

            const AngularProjectModel &getProjectModel() {
                return projectModel;
            }

            const db::generic::Database &getDatabaseModel() const {
                return databaseModel;
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }

            std::string getDatabase() override {
                return std::string{dbcrudgen::orm::Databases::GENERIC};
            }

            void createProjectDirs() override {

                //Create Project Dir
                const std::string projectDirFullPath = projectModel.getProjectDirFullPath();
                FilesWriter::createDirs(projectDirFullPath);

                //Create e2e Dir
                const std::string &e2EDirFullPath = projectModel.getE2EDirFullPath();
                FilesWriter::createDirs(e2EDirFullPath);

                //Create node module Dir
                const std::string &nodeModulesDirFullPath = projectModel.getNodeModulesDirFullPath();
                FilesWriter::createDirs(nodeModulesDirFullPath);

                //Create src dir
                const std::string &srcDirFullPath = projectModel.getSrcDirFullPath();
                FilesWriter::createDirs(srcDirFullPath);

                //Create app dir
                const std::string &appDirFullPath = projectModel.getAppDirFullPath();
                FilesWriter::createDirs(appDirFullPath);

                //Create assets dir
                const std::string &assetsDirFullPath = projectModel.getAssetsDirFullPath();
                FilesWriter::createDirs(assetsDirFullPath);

                //Create environments dir
                const std::string &environmentDirFullPath = projectModel.getEnvironmentDirFullPath();
                FilesWriter::createDirs(environmentDirFullPath);

                //Create module dir
                const std::string &moduleDirFullPath = projectModel.getModuleDirFullPath();
                FilesWriter::createDirs(moduleDirFullPath);

                const std::string &modelsDir = projectModel.getModelsDirFullPath();
                FilesWriter::createDirs(modelsDir);
            }


            void createSourceFiles() override {

                auto tables = databaseModel.getTables();

                std::string moduleName = SyntaxParser::toKebabCase(projectModel.getEvalModuleName());


                std::string componentsClasses;
                std::string componentsClassImports;

                int index = 0;

                for (const auto &table : tables) {

                    bool isLastTable = index < (tables.size() - 1);

                    const std::string &tableName = table.getTableName();

                    //Model source files
                    std::string modelClassName = AngularParser::toClassName(tableName);
                    std::string modelObjectName = AngularParser::toVariableName(modelClassName);
                    std::string modelLocation = AngularParser::prepareModelLocation(projectModel.getModelsDir(),
                                                                                    modelClassName);

                    std::string modelInstanceVars;

                    //Component files
                    std::string componentName = SyntaxParser::toKebabCase(tableName);
                    std::string componentClass = SyntaxParser::toCamelCase(tableName);


                    componentsClasses +=
                            dbcrudgen::orm::AngularParser::addComponentClassDeclaration(componentClass, isLastTable);
                    componentsClassImports +=
                            dbcrudgen::orm::AngularParser::addComponentClassImport(componentName, componentClass);

                    std::string serviceSrc =
                            dbcrudgen::orm::AngularParser::createServiceSrc(componentName, componentClass,
                                                                            modelLocation, modelClassName,
                                                                            modelObjectName);
                    std::string serviceSpecSrc =
                            dbcrudgen::orm::AngularParser::createServiceSpecSrc(componentName, componentClass);


                    std::string tblHeadingTitles;
                    std::string tblColsDataItems;

                    std::string formInputsHtml;
                    std::string formControlsBindTs;
                    std::string formControlsDeclarationTs;
                    std::string formGroupDeclaration = dbcrudgen::orm::AngularParser::prepareFormGroupDeclaration(
                            modelObjectName);
                    std::string formGroupInit = dbcrudgen::orm::AngularParser::prepareFormGroupInt(modelObjectName);

                    for (const auto &column : table.getTableColumns()) {

                        std::string jsDataType = AngularParser::getJSDataType(column.getDataType());
                        std::string html5DataType = AngularParser::getHtml5DataType(column.getDataType());

                        std::string columnTitleName = AngularParser::toTitle(column.getColumnName());
                        std::string columnObjectName = AngularParser::toVariableName(column.getColumnName());

                        const std::string &defaultValue = column.getDefaultValue();

                        //Model instance vars
                        modelInstanceVars += dbcrudgen::orm::AngularParser::createModelInstanceVariable(jsDataType,
                                                                                                        columnObjectName);

                        tblHeadingTitles += dbcrudgen::orm::AngularParser::prepareTableHeadTD(columnTitleName);
                        tblColsDataItems += dbcrudgen::orm::AngularParser::prepareTableRowTD(modelObjectName,
                                                                                             columnObjectName);

                        formInputsHtml
                                += dbcrudgen::orm::AngularParser::prepareHtmlFormInputs(columnTitleName, html5DataType,
                                                                                        columnObjectName);

                        formControlsBindTs += dbcrudgen::orm::AngularParser::prepareTsFormInputs(modelObjectName,
                                                                                                 columnObjectName,
                                                                                                 defaultValue);

                        formControlsDeclarationTs += dbcrudgen::orm::AngularParser::prepareFormControlDeclaration(
                                columnObjectName);

                    }

                    std::string htmlForm = dbcrudgen::orm::AngularParser::generateHtmlForm(modelClassName,
                                                                                           modelObjectName,
                                                                                           formInputsHtml);

                    std::string tableHeadings = dbcrudgen::orm::AngularParser::createTableHeading(tblHeadingTitles);
                    std::string tableBody
                            = dbcrudgen::orm::AngularParser::createTableBody(modelObjectName, tblColsDataItems);

                    std::string htmlTable = dbcrudgen::orm::AngularParser::createTable(tableHeadings, tableBody);


                    //Write model
                    std::string modelSrc
                            = dbcrudgen::orm::AngularParser::createModelSource(modelClassName, modelInstanceVars);
                    writeModelSrc(modelClassName, modelSrc);

                    //Write components
                    std::string componentCssSrc = dbcrudgen::orm::AngularParser::createComponentCssSrc(componentName);
                    std::string componentHtmlSrc = dbcrudgen::orm::AngularParser::createComponentHtmlSrc(componentName,
                                                                                                         htmlForm,
                                                                                                         htmlTable);
                    std::string componentTestsSrc =
                            dbcrudgen::orm::AngularParser::createComponentSpecSrc(componentName, componentClass);
                    std::string componentTsSrc
                            = dbcrudgen::orm::AngularParser::createComponentTsSrc(moduleName,
                                                                                  componentName, componentClass,
                                                                                  modelLocation, modelClassName,
                                                                                  modelObjectName,
                                                                                  formGroupDeclaration,
                                                                                  formControlsDeclarationTs,
                                                                                  formGroupInit, formControlsBindTs);

                    writeComponentSrc(componentName, componentCssSrc, componentHtmlSrc, componentTestsSrc,
                                      componentTsSrc);

                    //Write services
                    writeServiceSrc(componentName, serviceSrc);
                    writeServiceSpecSrc(componentName, serviceSpecSrc);

                    break;

                }

                std::string moduleClassName = SyntaxParser::toKebabCase(projectModel.getEvalModuleName());
                std::string moduleSrc =
                        dbcrudgen::orm::AngularParser::createModuleSrc(moduleClassName, componentsClassImports,
                                                                       componentsClasses);
                writeModuleSrc(moduleName, moduleSrc);

            }

            void writeModuleSrc(const std::string &moduleName, const std::string &moduleSrc) {
                std::string filePath = {projectModel.getModuleDirFullPath() + "/" + moduleName + ".module.ts"};
                FilesWriter::writeFile(filePath, moduleSrc);
            }


            //Write the model source file
            void writeModelSrc(const std::string &className, const std::string &modelSrc) {
                std::string filePath = {projectModel.getModelsDirFullPath() + "/" + className + ".ts"};
                FilesWriter::writeFile(filePath, modelSrc);
            }

            //Write the component source files
            void
            writeComponentSrc(const std::string &componentName, const std::string &componentCssSrc,
                              const std::string &componentHtmlSrc, const std::string &componentSpecSrc,
                              const std::string &componentTsSrc) {

                std::string componentDir = projectModel.getModuleDirFullPath() + "/" + componentName;
                FilesWriter::createDirs(componentDir);

                //File names
                std::string cssFile = componentDir + "/" + componentName + ".component.css";
                std::string htmlFile = componentDir + "/" + componentName + ".component.html";
                std::string tsSpecsFile = componentDir + "/" + componentName + ".component.spec.ts";
                std::string typeScriptFile = componentDir + "/" + componentName + ".component.ts";

                //Write css file
                FilesWriter::writeFile(cssFile, componentCssSrc);

                //Write html file
                FilesWriter::writeFile(htmlFile, componentHtmlSrc);

                //Write ts test cases
                FilesWriter::writeFile(tsSpecsFile, componentSpecSrc);

                //write typescript file
                FilesWriter::writeFile(typeScriptFile, componentTsSrc);

            }

            void writeServiceSrc(const std::string &componentName, const std::string &serviceSrc) {
                std::string componentDir = projectModel.getModuleDirFullPath() + "/" + componentName;
                std::string filePath = {componentDir + "/" + componentName + ".service.ts"};
                FilesWriter::writeFile(filePath, serviceSrc);
            }

            void writeServiceSpecSrc(const std::string &componentName, const std::string &serviceSpecSrc) {
                std::string componentDir = projectModel.getModuleDirFullPath() + "/" + componentName;
                std::string filePath = {componentDir + "/" + componentName + ".service.spec.ts"};
                FilesWriter::writeFile(filePath, serviceSpecSrc);
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_ANGULARPROJECTCREATOR_H
