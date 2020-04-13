//
// Created by vrwanda on 3/5/20.
//

/**
 * Java Project Model
 */


#ifndef DBCRUDGEN_CPP_JAVAPROJECTMODEL_H
#define DBCRUDGEN_CPP_JAVAPROJECTMODEL_H

#include <string>

namespace dbcrudgen {
    namespace orm {
        class JavaProjectModel {

            std::string projectName;
            std::string workspaceDir;

            std::string srcDir;
            std::string moduleDir;


            std::string javaDir;
            std::string libsDir;
            std::string resourcesDir;

            std::string packageName;

        public:

            JavaProjectModel(std::string &projectName, std::string &workspaceDir, std::string &srcDir,
                             std::string &moduleDir, std::string &javaDir, std::string &libsDir,
                             std::string &resourcesDir, std::string &packageName)
                    : projectName(projectName), workspaceDir(workspaceDir), srcDir(srcDir), moduleDir(moduleDir),
                      javaDir(javaDir), libsDir(libsDir), resourcesDir(resourcesDir), packageName(packageName) {}

            const std::string &getProjectName() const {
                return projectName;
            }

            const std::string &getWorkspaceDir() const {
                return workspaceDir;
            }

            const std::string &getSrcDir() const {
                return srcDir;
            }

            const std::string &getModuleDir() const {
                return moduleDir;
            }

            const std::string &getJavaDir() const {
                return javaDir;
            }

            const std::string &getLibsDir() const {
                return libsDir;
            }

            const std::string &getResourcesDir() const {
                return resourcesDir;
            }

            const std::string &getPackageName() const {
                return packageName;
            }

            std::string getAbsoluteProjectPath() {
                return getWorkspaceDir() + "/" + getProjectName();
            }

            std::string getAbsoluteSrcPath() {
                return getAbsoluteProjectPath() + "/" + getSrcDir();
            }

            std::string getAbsoluteModulePath() {
                return getAbsoluteSrcPath() + "/" + getModuleDir();
            }

            /**
            * Get the absolute path to the project java files
            * @return
            */
            std::string getAbsoluteJavaPath() {
                return getAbsoluteModulePath() + "/" + getJavaDir();
            }

            /**
            * Get the absolute path to the project libs files
            * @return
            */
            std::string getAbsoluteLibsPath() {
                return getAbsoluteModulePath() + "/" + getLibsDir();
            }

            /**
            * Get the absolute path to the project resource files
            * @return
            */
            std::string getAbsoluteResourcesPath() {
                return getAbsoluteModulePath() + "/" + getResourcesDir();
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_JAVAPROJECTMODEL_H