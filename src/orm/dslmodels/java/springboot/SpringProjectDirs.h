//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGPROJECTDIRS_H
#define DBCRUDGEN_CPP_SPRINGPROJECTDIRS_H

#include <string>

namespace dbcrudgen {
    namespace orm {
        class SpringProjectDirs {

            std::string srcDir;
            std::string moduleDir;
            std::string javaDir;
            std::string libsDir;
            std::string resourcesDir;
            std::string webDir;

        public:
            SpringProjectDirs(std::string &srcDir, std::string &moduleDir, std::string &javaDir,
                              std::string &libsDir, std::string &resourcesDir, std::string &webDir)
                    : srcDir(srcDir), moduleDir(moduleDir), javaDir(javaDir), libsDir(libsDir),
                      resourcesDir(resourcesDir), webDir(webDir) {}

            std::string &getSrcDir() {
                return srcDir;
            }

            std::string &getModuleDir() {
                return moduleDir;
            }

            std::string &getJavaDir() {
                return javaDir;
            }

            std::string &getLibsDir() {
                return libsDir;
            }

            std::string &getResourcesDir() {
                return resourcesDir;
            }

            const std::string &getWebDir() const {
                return webDir;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGPROJECTDIRS_H
