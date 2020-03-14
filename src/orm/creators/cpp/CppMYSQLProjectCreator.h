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
#include "../../../databases/mysql/models/MYSQLDatabaseModel.h"
#include "../../../databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "../../../databases/mysql/models/MYSQLDatabaseTable.h"
#include "../../utils/TransactionUtils.h"
#include "../ProjectCreator.h"
#include "../../projects/CppMYSQLProjectModel.h"
#include "../../../io/FilesWriter.h"

namespace dbcrudgen {

    namespace orm {
        //
        // CppMYSQLDatabaseModelCreator
        // //
        class CppMYSQLProjectCreator : ProjectCreator {

        private:
            CppMYSQLProjectModel projectModel;


        public:

            explicit CppMYSQLProjectCreator(CppMYSQLProjectModel &projectModel) : projectModel{projectModel} {}

            const CppMYSQLProjectModel &getProjectModel() const {
                return projectModel;
            }

            void createProject() override {

                //Create source dirs
                createSourceDirs();

            }

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

        private:
            void createSourceDirs() {

                const std::string separator = "/";

                //Create project dir
                std::string projectDir = projectModel.getProjectDir();
                FilesWriter::createDir(const_cast<std::string &>(projectDir));

                //Create includes dir
                std::string includesDir = projectModel.getIncludesDir();
                std::string includesPath = {projectDir + separator + includesDir};
                FilesWriter::createDir(includesPath);

                //create libs dir
                std::string libsDir = projectModel.getLibsDir();
                std::string libsPath = projectDir + separator + libsDir;
                FilesWriter::createDir(libsPath);

                //create generated code dir
                std::string genCodeDir = projectModel.getGeneratedCodeDir();
                std::string codeGenPath = projectDir + separator + genCodeDir;
                FilesWriter::createDir(codeGenPath);

            }
        };
    }
}

#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H
