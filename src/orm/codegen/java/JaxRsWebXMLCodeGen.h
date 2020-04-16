//
// Created by victor on 4/16/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSWEBXMLCODEGEN_H
#define DBCRUDGEN_CPP_JAXRSWEBXMLCODEGEN_H

#include "JavaProjectCodeGen.h"
#include "../../templates/java/jax-rs/JaxRsScriptWebXMLTemplate.h"
#include "../../parsers/java/JaxRsWebXMLParser.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * Generates the source code for Web XML in Jax rs. This is the file stored in WEB-INFO/ as web.xml
         */
        class JaxRsWebXMLCodeGen : public JavaProjectCodeGen {

        public:

            /**
             * Create Web XML Source Code
             * @param projectModel
             * @return
             */
            static std::string createWebXML(const JaxRsProjectModel &projectModel) {
                JaxRsScriptWebXMLTemplate webXmlTemplate;
                std::string webXmlSource = webXmlTemplate.getTemplate();


                //Set the project details
                JaxRsWebXMLParser::substituteProjectDetails(projectModel, webXmlSource);

                return webXmlSource;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_JAXRSWEBXMLCODEGEN_H
