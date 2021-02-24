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

            std::string getAbsoluteProjectPath() const {
                return getWorkspaceDir() + "/" + getProjectName();
            }

            std::string getAbsoluteSrcPath() const {
                return getAbsoluteProjectPath() + "/" + getSrcDir();
            }

            std::string getAbsoluteModulePath() const {
                return getAbsoluteSrcPath() + "/" + getModuleDir();
            }

            /**
            * Get the absolute path to the project java files
            * @return
            */
            const std::string getAbsoluteJavaPath() const {
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

            /**
             * Get the absolute path to the application.properties file
             * @param filename
             * @return
             */
            std::string getApplicationPropertiesFilePath(const std::string& filename = "application.properties") {
                return getAbsoluteResourcesPath() + "/" + filename;
            }

            /**
            * Get the absolute path to the project java files
            * @return
            */
            const std::string getAbsoluteBaseCodePath() const {
                std::string pkgName = getPackageName();
                std::string baseCode = StringUtils::replace(pkgName, ".", "/");
                const std::string &javaPath = getAbsoluteJavaPath();
                return javaPath + "/" + baseCode;
            }
        };

    }
}

#endif //DBCRUDGEN_CPP_JAVAPROJECTMODEL_H