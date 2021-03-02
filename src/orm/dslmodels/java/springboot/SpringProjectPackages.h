//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGPROJECTPACKAGES_H
#define DBCRUDGEN_CPP_SPRINGPROJECTPACKAGES_H

#include <string>

namespace dbcrudgen {
    namespace orm {
        class SpringProjectPackages {

            std::string beansPkg;
            std::string bzLogicPkg;
            std::string ctlsPkg;
            std::string dbConnPkg;
            std::string entitiesPkg;
            std::string httpReqPkg;
            std::string httpResPkg;
            std::string modelsPkg;
            std::string reposPkg;
            std::string transactionsPkg;
            std::string webAppPkg;

        public:
            SpringProjectPackages( std::string &beansPkg, std::string &bzLogicPkg,
                                  std::string &ctlsPkg, std::string &dbConnPkg, std::string &entitiesPkg,
                                  std::string &httpReqPkg, std::string &httpResPkg, std::string &modelsPkg,
                                  std::string &reposPkg, std::string &transactionsPkg, std::string &webAppPkg)
                    : beansPkg(beansPkg), bzLogicPkg(bzLogicPkg), ctlsPkg(ctlsPkg),
                      dbConnPkg(dbConnPkg), entitiesPkg(entitiesPkg), httpReqPkg(httpReqPkg), httpResPkg(httpResPkg),
                      modelsPkg(modelsPkg), reposPkg(reposPkg), transactionsPkg(transactionsPkg),
                      webAppPkg(webAppPkg) {}

            const std::string &getBeansPkg() const {
                return beansPkg;
            }

            const std::string &getBzLogicPkg() const {
                return bzLogicPkg;
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

            const std::string &getModelsPkg() const {
                return modelsPkg;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_SPRINGPROJECTPACKAGES_H
