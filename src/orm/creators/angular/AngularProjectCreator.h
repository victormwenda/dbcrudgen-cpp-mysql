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

                for (const auto &table : tables) {

                    std::string tableName = table.getTableName();

                    //Model source files
                    std::string modelClassName = SyntaxParser::toPascalCase(tableName);
                    std::string modelInstanceVars = "";

                    //Component files
                    std::string componentName = SyntaxParser::toKebabCase(tableName);
                    std::string componentClass = SyntaxParser::toCamelCase(tableName);
                    std::cout << "class name " << componentClass << std::endl;

                    std::string componentCssSrc = dbcrudgen::orm::AngularParser::createComponentCssSrc(componentName);
                    std::string componentHtmlSrc = dbcrudgen::orm::AngularParser::createComponentHtmlSrc(componentName);
                    std::string componentTestsSrc = dbcrudgen::orm::AngularParser::createComponentSpecSrc(
                            componentName, componentClass);
                    std::string componentTsSrc = dbcrudgen::orm::AngularParser::createComponentTsSrc(moduleName,
                                                                                                     componentName,
                                                                                                     componentClass);

                    for (const auto &column : table.getTableColumns()) {
                        //Model instance vars
                        modelInstanceVars += dbcrudgen::orm::AngularParser::createModelInstanceVariable(column);

                    }

                    std::string modelSrc = dbcrudgen::orm::AngularParser::createModelSource(modelClassName,
                                                                                            modelInstanceVars);
                    writeModelSrc(modelClassName, modelSrc);
                    writeComponentSrc(componentName, componentCssSrc, componentHtmlSrc, componentTestsSrc,
                                      componentTsSrc);

                    break;
                }

            }

            //Write the model source file
            void writeModelSrc(std::string className, std::string modelSrc) {
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
        };
    }
}
#endif //DBCRUDGEN_CPP_ANGULARPROJECTCREATOR_H
