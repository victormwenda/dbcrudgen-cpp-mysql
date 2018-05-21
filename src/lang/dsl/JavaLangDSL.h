/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/24/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_JAVALANGDSL_H
#define DBCRUDGEN_CPP_JAVALANGDSL_H


#include "LanguageDSL.h"

/**
* JavaLangDSL
* */
class JavaLangDSL : public LanguageDSL {
public:
    /**
    * Returns list of the language file properties
    * @return
    */
    std::vector<LanguageFilesProperties> getLanguageFileProperties() override {
        auto languageFileProperties = {
                LanguageFilesProperties {"src/main/java", "JAVA", {".java"}},
                LanguageFilesProperties {"src/main/java", "CLASS", {".java"}},
                LanguageFilesProperties {"src/main/java", "INTERFACE", {".java"}},
                LanguageFilesProperties {"src/main/java", "ENUM", {".java"}}
        };
        return languageFileProperties;
    }
};


#endif //DBCRUDGEN_CPP_JAVALANGDSL_H
