/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/14/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_COLUMNCONSTRAINTS_H
#define DBCRUDGEN_CPP_COLUMNCONSTRAINTS_H

#include <iostream>

using namespace std;

/**
* ColumnConstraints
* */
class ColumnConstraints {
private:
    std::string nullValue;
    std::string keyType;
    std::string defaultValue;
    std::string extra;
public:
    ColumnConstraints(const string &nullValue, const string &keyType, const string &defaultValue, const string &extra)
            : nullValue(nullValue), keyType(keyType), defaultValue(defaultValue), extra(extra) {}

    const string &getNullValue() const {
        return nullValue;
    }

    const string &getKeyType() const {
        return keyType;
    }

    const string &getDefaultValue() const {
        return defaultValue;
    }

    const string &getExtra() const {
        return extra;
    }
};


#endif //DBCRUDGEN_CPP_COLUMNCONSTRAINTS_H
