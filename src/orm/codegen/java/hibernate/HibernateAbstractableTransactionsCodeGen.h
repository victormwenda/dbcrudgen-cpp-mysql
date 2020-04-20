//
// Created by victor on 4/20/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATEABSTRACTABLETRANSACTIONSCODEGEN_H
#define DBCRUDGEN_CPP_HIBERNATEABSTRACTABLETRANSACTIONSCODEGEN_H

#include "../JavaProjectCodeGen.h"
#include "../../../templates/java/jax-rs/JaxRsScriptWebXMLTemplate.h"
#include "../../../parsers/java/JaxRsWebXMLParser.h"
#include "../../../templates/java/jax-rs/JaxRsClassWebApplicationTemplate.h"
#include "../../../parsers/java/JaxRsWebApplicationParser.h"
#include "../../../templates/java/crud/hibernate/HibernateClassAbstractableTransactionsTemplate.h"
#include "../../../parsers/java/HibernateAbstractableTransactionsParser.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Generates the source code for the class that extends Application in Jax-RS
         */
        class HibernateAbstractableTransactionsCodeGen : public JavaProjectCodeGen {

        public:

            /**
             * Get abstractable transactions source
             * @return
             */
            static std::string getAbstractableTransactionsSource(const JaxRsProjectModel &model) {
                HibernateClassAbstractableTransactionsTemplate abstractableTransactionsTemplate;
                std::string absTrxTemplate = abstractableTransactionsTemplate.getTemplate();

                HibernateAbstractableTransactionsParser parser;
                parser.parseClassDetails(model, absTrxTemplate);

                return absTrxTemplate;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_HIBERNATEABSTRACTABLETRANSACTIONSCODEGEN_H
