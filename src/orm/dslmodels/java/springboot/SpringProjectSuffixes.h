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
            std::string apiClassSuffix;
            std::string beansClassSuffix;
            std::string entityClassSuffix;
            std::string httpReqClassSuffix;
            std::string httpResClassSuffix;
            std::string repoClassSuffix;
            std::string trxClassSuffix;
            std::string modelClassSuffix;

        public:
            SpringProjectSuffixes(std::string &apiClassSuffix, std::string &beansClassSuffix,
                                  std::string &entityClassSuffix, std::string &httpReqClassSuffix,
                                  std::string &httpResClassSuffix, std::string &repoClassSuffix,
                                  std::string &trxClassSuffix, std::string &modelClassSuffix)
                    : apiClassSuffix(apiClassSuffix), beansClassSuffix(beansClassSuffix),
                      entityClassSuffix(entityClassSuffix), httpReqClassSuffix(httpReqClassSuffix),
                      httpResClassSuffix(httpResClassSuffix), repoClassSuffix(repoClassSuffix),
                      trxClassSuffix(trxClassSuffix), modelClassSuffix(modelClassSuffix) {}

            const std::string &getApiClassSuffix() const {
                return apiClassSuffix;
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

            const std::string &getTrxClassSuffix() const {
                return trxClassSuffix;
            }

            const std::string &getModelClassSuffix() const {
                return modelClassSuffix;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGPROJECTSUFFIXES_H
