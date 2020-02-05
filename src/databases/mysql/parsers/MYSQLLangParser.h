//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/25/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLLANGPARSER_H
#define DBCRUDGEN_CPP_MYSQLLANGPARSER_H


#include <sstream>
#include "../../../lang/parser/LangTemplateParser.h"

//
// MYSQLLangParser
// //
class MYSQLLangParser : public LangTemplateParser {

public:
    static std::string toAbsolutePath(const std::string &schemas, const std::string tableName) {
        std::stringstream stream;
        stream << schemas << "." << tableName;
        return std::string{stream.str()};
    }
};


#endif //DBCRUDGEN_CPP_MYSQLLANGPARSER_H
