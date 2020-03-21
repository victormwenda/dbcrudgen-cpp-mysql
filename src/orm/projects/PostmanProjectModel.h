//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_POSTMANPROJECTMODEL_H
#define DBCRUDGEN_CPP_POSTMANPROJECTMODEL_H

#include "ProjectModel.h"
#include "../codegen/Languages.h"


namespace dbcrudgen {
    namespace orm {

        /**
         * Postman project model
         */
        class PostmanProjectModel : public ProjectModel {

        private:

            std::string projectName;
            std::string workspaceDir;
            std::string protocol;
            std::string host;
            int port;
            std::string pathSegments;
            std::map<std::string, std::string> headers;
            std::string databaseType;

        public:
            PostmanProjectModel(std::string &projectName, std::string &workspaceDir, std::string &protocol,
                                std::string &host, int port, std::string &pathSegments,
                                std::map<std::string, std::string> &headers, std::string &databaseType) : projectName(
                    projectName), workspaceDir(workspaceDir), protocol(protocol), host(host), port(port), pathSegments(
                    pathSegments), headers(headers), databaseType(databaseType) {}

            const std::string &getProjectName() override {
                return projectName;
            }

            const std::string &getWorkspaceDir() override {
                return workspaceDir;
            }

            const std::string &getGeneratedCodeDir() override {
                return workspaceDir;
            }

            std::string getSourceLang() override {
                return std::string{Languages::JSON};
            }

            const std::string &getHost() const {
                return host;
            }

            int getPort() const {
                return port;
            }

            const std::string &getPathSegments() const {
                return pathSegments;
            }

            const std::map<std::string, std::string> &getHeaders() const {
                return headers;
            }

            const std::string &getDatabaseType() const {
                return databaseType;
            }

            const std::string &getProtocol() const {
                return protocol;
            }

            /**
             * Build a base URL for the API access
             * @return
             */
            const std::string getBaseURL() {
                return std::string{protocol + "://" + host + ":" + std::to_string(port) + "/" + pathSegments};
            }

        };
    }
}
#endif //DBCRUDGEN_CPP_POSTMANPROJECTMODEL_H
