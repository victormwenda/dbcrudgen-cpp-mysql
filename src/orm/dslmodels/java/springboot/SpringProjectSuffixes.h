//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGPROJECTSUFFIXES_H
#define DBCRUDGEN_CPP_SPRINGPROJECTSUFFIXES_H

#include <string>

namespace dbcrudgen {
    namespace orm {
        class SpringProjectSuffixes {
        private:
            std::string beansClassSuffix;
            std::string bzLogicClassSuffix;
            std::string ctlClassSuffix;
            std::string entityClassSuffix;
            std::string httpReqClassSuffix;
            std::string httpResClassSuffix;
            std::string modelClassSuffix;
            std::string repoClassSuffix;
            std::string trxClassSuffix;

        public:
            SpringProjectSuffixes(std::string &beansClassSuffix, std::string &bzLogicClassSuffix,
                                  std::string &ctlClassSuffix, std::string &entityClassSuffix,
                                  std::string &httpReqClassSuffix, std::string &httpResClassSuffix,
                                  std::string &modelClassSuffix, std::string &repoClassSuffix,
                                  std::string &trxClassSuffix)
                    : beansClassSuffix(beansClassSuffix),
                      bzLogicClassSuffix(bzLogicClassSuffix),
                      ctlClassSuffix(ctlClassSuffix),
                      entityClassSuffix(entityClassSuffix),
                      httpReqClassSuffix(httpReqClassSuffix),
                      httpResClassSuffix(httpResClassSuffix),
                      modelClassSuffix(modelClassSuffix),
                      repoClassSuffix(repoClassSuffix),
                      trxClassSuffix(trxClassSuffix) {}

            const std::string &getCtlClassSuffix() const {
                return ctlClassSuffix;
            }

            const std::string &getBeansClassSuffix() const {
                return beansClassSuffix;
            }

            const std::string &getEntityClassSuffix() const {
                return entityClassSuffix;
            }

            const std::string &getHttpReqClassSuffix() const {
                return httpReqClassSuffix;
            }

            const std::string &getHttpResClassSuffix() const {
                return httpResClassSuffix;
            }

            const std::string &getRepoClassSuffix() const {
                return repoClassSuffix;
            }

            /**
             * Get DAO class suffix
             * @return
             */
            const std::string &getTrxClassSuffix() const {
                return trxClassSuffix;
            }

            /**
             * Get DAO class suffix
             * @return
             */
            const std::string &getDaoClassSuffix() const {
                return getTrxClassSuffix();
            }

            const std::string &getModelClassSuffix() const {
                return modelClassSuffix;
            }

            const std::string &getBzLogicClassSuffix() const {
                return bzLogicClassSuffix;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGPROJECTSUFFIXES_H
