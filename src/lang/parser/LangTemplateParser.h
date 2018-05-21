/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/25/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_LANGTEMPLATEPARSER_H
#define DBCRUDGEN_CPP_LANGTEMPLATEPARSER_H

#include <iostream>

/**
* LangTemplateParser
* */
class LangTemplateParser {
public:
    /**
     * Recursively Replaces the tag in the model with the value
     * @param model
     * @param tag
     * @param value
     * @return
     */
    std::string parseTemplate(std::string &model, const std::string &tag, const std::string &value) {

        std::size_t firstPosition = model.find(tag.c_str());

        if (firstPosition != std::string::npos) {

            model.replace(firstPosition, tag.length(), value);

            bool hasMultipleTags = model.find(tag.c_str(), firstPosition + tag.length()) != std::string::npos;

            return hasMultipleTags ? parseTemplate(model, tag, value) : model;
        }

        return model;
    }
};


#endif //DBCRUDGEN_CPP_LANGTEMPLATEPARSER_H
