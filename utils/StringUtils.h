//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/1/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_STRINGUTILS_H
#define DBCRUDGEN_CPP_STRINGUTILS_H


#include <iostream>

//
// StringUtils
// //
class StringUtils {
    /**
     * Recursively Replaces the tag in the model with the value
     * @param subject string being manipulated
     * @param search string to search
     * @param value string to replace with
     * @return
     */
    std::string parseTemplate(std::string &subject, const std::string &search, const std::string &value) {

        std::size_t firstPosition = subject.find(search.c_str());

        if (firstPosition != std::string::npos) {

            subject.replace(firstPosition, search.length(), value);

            bool hasMultipleTags = contains(subject, search, firstPosition + search.length());

            return hasMultipleTags ? parseTemplate(subject, search, value) : subject;
        }

        return subject;
    }

    /**
     * Returns if a string contains another string
     * @param subject string to be searched
     * @param search value to be searched
     * @param position position to start from
     * @return
     */
    bool contains(const std::string &subject, const std::string &search, size_t position = 0) const {
        return subject.find(search.c_str(), position) != std::string::npos;
    }

    //TODO Add implementation
    std::string *split(const std::string subject, const std::string delimiter) {
        if (StringUtils::contains(subject, delimiter, 0)) {
            return nullptr;
        }
        return nullptr;
    }
};


#endif //DBCRUDGEN_CPP_STRINGUTILS_H
