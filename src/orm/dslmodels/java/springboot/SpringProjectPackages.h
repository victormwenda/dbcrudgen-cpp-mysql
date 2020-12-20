//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGPROJECTPACKAGES_H
#define DBCRUDGEN_CPP_SPRINGPROJECTPACKAGES_H

#include <string>

namespace dbcrudgen {
    namespace orm {
        class SpringProjectPackages {

            std::string apisPkg;
            std::string beansPkg;
            std::string ctlsPkg;
            std::string dbConnPkg;
            std::string entitiesPkg;
            std::string httpReqPkg;
            std::string httpResPkg;
            std::string reposPkg;
            std::string transactionsPkg;
            std::string webAppPkg;

        public:
            SpringProjectPackages(std::string &apisPkg, std::string &beansPkg, std::string &ctlsPkg,
                                  std::string &dbConnPkg, std::string &entitiesPkg, std::string &httpReqPkg,
                                  std::string &httpResPkg, std::string &reposPkg, std::string &transactionsPkg,
                                  std::string &webAppPkg)
                    : apisPkg(apisPkg), beansPkg(beansPkg), ctlsPkg(ctlsPkg), dbConnPkg(dbConnPkg),
                      entitiesPkg(entitiesPkg),
                      httpReqPkg(httpReqPkg), httpResPkg(httpResPkg), reposPkg(reposPkg),
                      transactionsPkg(transactionsPkg), webAppPkg(webAppPkg) {}

            const std::string &getApisPkg() const {
                return apisPkg;
            }

            const std::string &getBeansPkg() const {
                return beansPkg;
            }

            const std::string &getCtlsPkg() const {
                return ctlsPkg;
            }

            const std::string &getDbConnPkg() const {
                return dbConnPkg;
            }

            const std::string &getEntitiesPkg() const {
                return entitiesPkg;
            }

            const std::string &getHttpReqPkg() const {
                return httpReqPkg;
            }

            const std::string &getHttpResPkg() const {
                return httpResPkg;
            }

            const std::string &getReposPkg() const {
                return reposPkg;
            }

            const std::string &getTransactionsPkg() const {
                return transactionsPkg;
            }

            const std::string &getWebAppPkg() const {
                return webAppPkg;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_SPRINGPROJECTPACKAGES_H
