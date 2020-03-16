//
// Created by victor on 3/16/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H
#define DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H

#include "CppProjectCreator.h"
#include "../../projects/CppMYSQLProjectModel.h"
#include "../../codegen/cpp/CppMYSQLDbTableModelCodeGen.h"
#include "../../codegen/cpp/CppMYSQLDbConnectorCodeGen.h"
#include "../../codegen/cpp/CppMYSQLSCRUDCodeGen.h"

namespace dbcrudgen {
    namespace orm {
        class CppMYSQLProjectCreator : CppProjectCreator {
        private:

            CppMYSQLProjectModel projectModel;
            mysql::MYSQLDatabaseModel databaseModel;

            CppMYSQLDbTableModelCodeGen tableModelCodeGen;
            CppMYSQLDbConnectorCodeGen connectorCodeGen;
            CppMYSQLSCRUDCodeGen scrudCodeGen;


        public:

            explicit CppMYSQLProjectCreator(CppMYSQLProjectModel &projectModel) :
                    CppProjectCreator{projectModel},
                    projectModel{projectModel} {}

            /**
            *
            * Get the programming language used to develop the project
            * @return
            */
            std::string getLanguage() override {
                return std::string{"cpp"};
            }

            /**
             * Get the database used for generating the project
             * @return
             */
            std::string getDatabase() override {
                return std::string{"mysql"};
            }

            const CppMYSQLProjectModel &getProjectModel() const {
                return projectModel;
            }

            void setDatabaseModel(mysql::MYSQLDatabaseModel &databaseModel) {
                CppMYSQLProjectCreator::databaseModel = databaseModel;
            }

            const CppMYSQLProjectCodeGen &getCodeGen() const {
                return tableModelCodeGen;
            }

            void createProject() override {

                //Create source dirs
                createProjectDirs();

                //create source files
                createSourceFiles();
            }


            void createSourceFiles() override {

                // Create database connector file
                std::string connectorScriptDir = projectModel.getProjectDir().append("/").append(
                        projectModel.getGeneratedCodeDir());
                connectorCodeGen.createDatabaseConnector(projectModel, connectorScriptDir);

                //Create database table model files
                std::string tableModelDir = projectModel.getProjectDir().append("/").append(
                        projectModel.getGeneratedCodeDir());
                tableModelCodeGen.createDatabaseTableModel(projectModel, databaseModel, tableModelDir);

                //Create SCRUD files
                std::string scrudDir = projectModel.getProjectDir().append("/").append(
                        projectModel.getGeneratedCodeDir());
                scrudCodeGen.createDatabaseSCRUD(projectModel, databaseModel, scrudDir);
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H
