//
// Created by victor on 4/20/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATECLASSABSTRACTABLETRANSACTIONSTEMPLATE_H
#define DBCRUDGEN_CPP_HIBERNATECLASSABSTRACTABLETRANSACTIONSTEMPLATE_H

#include "../../../FileSourceCodeTemplate.h"
#include "../../JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateClassAbstractableTransactionsTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::Hibernate::CLASS_ABSTRACTABLE_TRANSACTIONS_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATECLASSABSTRACTABLETRANSACTIONSTEMPLATE_H
