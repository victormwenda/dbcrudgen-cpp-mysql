//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_CPPPROJECTCREATOR_H
#define DBCRUDGEN_CPP_CPPPROJECTCREATOR_H

#include "../ProjectCreator.h"
#include "../../projects/CppProjectModel.h"
#include "../../../io/FilesWriter.h"

namespace dbcrudgen {
    namespace orm {
        class CppProjectCreator : ProjectCreator {

        private:
            CppProjectModel projectModel;

        public:
            explicit CppProjectCreator(CppProjectModel &projectModel) : projectModel{projectModel} {}

            /**
             *
             * Get the programming language used to develop the project
             * @return
             */
            std::string getLanguage() override {
                return std::string{"cpp"};
            }

            void createProjectDirs() override {
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

#endif //DBCRUDGEN_CPP_CPPPROJECTCREATOR_H
