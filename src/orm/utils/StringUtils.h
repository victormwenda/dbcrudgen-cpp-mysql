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
#include <vector>

//
// StringUtils
// //
class StringUtils {
public:
    /**
     * Recursively Replaces the tag in the model with the value
     * @param subject string being manipulated
     * @param search string to search
     * @param value string to replace with
     * @return
     */
    static std::string parseTemplate(std::string &subject, const std::string &search, const std::string &value) {

        std::size_t firstPosition = subject.find(search);

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
    static bool contains(const std::string &subject, const std::string &search, size_t position = 0) {
        return subject.find(search, position) != std::string::npos;
    }

    /**
     * Splits the provided strings into a string vector
     * @param subject
     * @param delimiter
     * @return
     */
    static std::vector<std::string> split(const std::string &subject, const std::string &delimiter) {
        std::vector<std::string> parts;

        size_t lastPosition = 0;
        size_t currentPosition = 0;

        while ((currentPosition = subject.find(delimiter, lastPosition)) != std::string::npos) {
            parts.push_back(subject.substr(lastPosition, currentPosition - lastPosition));
            lastPosition = ++currentPosition;
        }

        if (subject.find(delimiter) != std::string::npos && (lastPosition != subject.length() - 1)) {
            parts.push_back(subject.substr(lastPosition));
        }

        return parts;
    }
};


#endif //DBCRUDGEN_CPP_STRINGUTILS_H
