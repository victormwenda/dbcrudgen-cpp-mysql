/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/24/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_CPPLANGDSL_H
#define DBCRUDGEN_CPP_CPPLANGDSL_H


#include "LanguageDSL.h"

/**
* CPPLangDSL
* */
class CPPLangDSL : public LanguageDSL {
public:
    /**
    * Returns list of the language file properties
    * @return
    */
    std::vector<LanguageFilesProperties> getLanguageFileProperties() override {
        auto languageFileProperties = {
                LanguageFilesProperties {"${CPP_SRC_DIR}/", "CLASS", {".h"}},
                LanguageFilesProperties {"${CPP_SRC_DIR}/", "CLASS", {".hpp"}},
                LanguageFilesProperties {"${CPP_SRC_DIR}/", "CLASS", {".cpp"}},
        };
        return languageFileProperties;
    }
};


#endif //DBCRUDGEN_CPP_CPPLANGDSL_H
