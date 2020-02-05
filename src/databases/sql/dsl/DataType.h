/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/14/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_DATATYPES_H
#define DBCRUDGEN_CPP_DATATYPES_H

#include <iostream>

using namespace std;

/**
* DataTypes
* */
class DataType {
private:
    std::string type;
public:
    /**
     * Initialize the data type
     * @param type
     */
    DataType(const std::string type) : type{type} {}

    /**
     * Get the data type
     * @return type
     */
    std::string getType() const { return type; }
};


#endif //DBCRUDGEN_CPP_DATATYPES_H
