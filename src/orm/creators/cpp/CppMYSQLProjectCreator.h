//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H
#define DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H


#include <vector>
#include "CppProjectCreator.h"
#include "../../projects/CppMYSQLProjectModel.h"
#include "../../codegen/cpp/CppMYSQLProjectCodeGen.h"
#include "../../codegen/cpp/CppMYSQLDbTableModelCodeGen.h"
#include "../../codegen/cpp/CppMYSQLDbConnectorCodeGen.h"

namespace dbcrudgen {

    namespace orm {

        //
        // CppMYSQLDatabaseModelCreator
        // //
        class CppMYSQLProjectCreator : public CppProjectCreator {

        private:
            CppMYSQLProjectModel projectModel;
            mysql::MYSQLDatabaseModel databaseModel;

            CppMYSQLDbTableModelCodeGen tableModelCodeGen;
            CppMYSQLDbConnectorCodeGen connectorCodeGen;


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
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H
