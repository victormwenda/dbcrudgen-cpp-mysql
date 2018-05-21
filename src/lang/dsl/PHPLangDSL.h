/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/24/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_PHPLANGDSL_H
#define DBCRUDGEN_CPP_PHPLANGDSL_H

#include <iostream>
#include "LanguageDSL.h"

/**
* PHPLangDSL
* */
class PHPLangDSL : public LanguageDSL {
public:
    /**
    * Returns list of the language file properties
    * @return
    */
    std::vector<LanguageFilesProperties> getLanguageFileProperties() override {
        auto languageFileProperties = {
                LanguageFilesProperties {"${DOCUMENT_ROOT}/", "PHP", {".php"}},
        };
        return languageFileProperties;
    }
};

#endif //DBCRUDGEN_CPP_PHPLANGDSL_H
