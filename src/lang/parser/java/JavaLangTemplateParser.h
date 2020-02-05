//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 6/25/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_JAVALANGTEMPLATEPARSER_H
#define DBCRUDGEN_CPP_JAVALANGTEMPLATEPARSER_H


#include "../LangTemplateParser.h"

//
// JavaLangTemplateParser
// //
class JavaLangTemplateParser : public LangTemplateParser {
private:
    std::string &langModel;
public:
    /**
     * Java Language model
     * Contains the java language model
     * @param langModel
     */
    JavaLangTemplateParser(std::string &langModel) : langModel(langModel) {}

    /**
         * Replace the tag with the value in the language model
         * @param tag
         * @param value
         * @return
         */
    JavaLangTemplateParser parse(std::string &tag, std::string &value) {
        parseTag(tag, value);
        return *this;
    }

    /**
     * Replaces the tag with the value
     * @param tag
     * @param value
     * @return
     */
    std::string parseTag(std::string &tag, std::string &value) {
        return parseTemplate(langModel, tag, value);
    }

    /**
     * Returns the language template
     * @return
     */
    std::string getTemplate() {
        return langModel;
    }
};


#endif //DBCRUDGEN_CPP_JAVALANGTEMPLATEPARSER_H
