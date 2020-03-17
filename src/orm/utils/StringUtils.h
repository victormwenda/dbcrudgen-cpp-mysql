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
#include <cstring>

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
    static std::string replace(std::string &subject, const std::string &search, const std::string &value) {

        std::size_t firstPosition = subject.find(search);

        if (firstPosition != std::string::npos) {

            subject.replace(firstPosition, search.length(), value);

            return replace(subject, search, value);
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
            std::string text = subject.substr(lastPosition, currentPosition - lastPosition);
            parts.push_back(text);
            lastPosition = ++currentPosition;
        }

        if (subject.find(delimiter) != std::string::npos && (lastPosition != subject.length())) {
            parts.push_back(subject.substr(lastPosition));
        }

        return parts;
    }

    /**
     * Create an all caps header name
     * @param name
     * @return
     */
    static std::string createCapsHeaderName(std::string name) {

        int index = 0;
        while (index < name.length()) {

            if (!isalpha(name[index])) {
                name[index] = '_';
            } else {
                name[index] = toupper(name[index]);
            }

            index++;
        }

        return name;
    }

    /**
     * Create a camel case class name
     * @param name
     * @return
     */
    static std::string createClassNameCamelCase(std::string name) {

        std::string class_name;
        std::vector<std::string> parts = split(name.c_str(), "_");

        if (parts.size() == 0) {
            return name;
        }

        for (std::string &part : parts) {

            char firstChar = part[0];

            if (isalpha(firstChar) && islower(firstChar)) {
                part[0] = toupper(firstChar);
            }

            class_name += part;
        }

        name = class_name;

        return name;
    }

    /**
     * Create a camel case method name
     * @param name
     * @return
     */
    static std::string createMethodNameCamelCase(std::string name) {

        //convert all letters to small letters
        int index = 0;
        while (index < name.length()) {
            name[index] = tolower(name[index]);
            index++;
        }

        std::string method_name;
        std::vector<std::string> parts = split(name.c_str(), "_");

        if (parts.size() == 0) {
            return name;
        }

        int partsIndex = 0;

        for (std::string &part : parts) {

            if (partsIndex == 0) {
                method_name += part;
                partsIndex++;
                continue;
            }

            char partsFirstChar = part[0];

            if (isalpha(partsFirstChar) && islower(partsFirstChar)) {
                part[0] = toupper(partsFirstChar);
            }

            partsIndex++;
            method_name += part;
        }

        name = method_name;
        return name;
    }

    /**
     * Create a camel case variable name
     * @param name
     * @return
     */
    static std::string createVariableNameCamelCase(std::string name) {

        //convert all letters to small letters
        int index = 0;
        while (index < name.length()) {
            name[index] = tolower(name[index]);
            index++;
        }

        std::string variable_name;
        std::vector<std::string> parts = split(name.c_str(), "_");

        if (parts.size() == 0) {
            return name;
        }

        int partsIndex = 0;

        for (std::string &part : parts) {

            if (partsIndex == 0) {
                variable_name += part;
                partsIndex++;
                continue;
            }

            char partsFirstChar = part[0];

            if (isalpha(partsFirstChar) && islower(partsFirstChar)) {
                part[0] = toupper(partsFirstChar);
            }

            partsIndex++;
            variable_name += part;
        }

        name = variable_name;
        return name;
    }

    /**
     * Convert text to upper
     * @param text
     * @return
     */
    static std::string to_upper(std::string text) {

        int index = 0;

        while (index < text.size()) {
            text[index] = toupper(text[index]);
            index++;
        }

        return text;
    }

    /**
     * Convert text to lower
     * @param text
     * @return
     */
    static std::string to_lower(std::string text) {

        int index = 0;

        while (index < text.size()) {
            text[index] = toupper(text[index]);
            index++;
        }

        return text;
    }
};


#endif //DBCRUDGEN_CPP_STRINGUTILS_H
