/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/24/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_LANGUAGEDSL_H
#define DBCRUDGEN_CPP_LANGUAGEDSL_H

#include <iostream>
#include <vector>
#include "LanguageFilesProperties.h"

/**
* LanguageDSL
* */
class LanguageDSL {
public:
    /**
     * Returns list of the language file properties
     * @return
     */
    virtual std::vector<LanguageFilesProperties> getLanguageFileProperties() = 0;
};


#endif //DBCRUDGEN_CPP_LANGUAGEDSL_H
