// Victor Mwenda
// E: vmwenda.vm@gmail.com
// P: +254718034449
//
//C++ Dev Computer
// Created by victor on 6/16/18.
//

#ifndef DBCRUDGEN_CPP_MYSQLTABLE_H
#define DBCRUDGEN_CPP_MYSQLTABLE_H


#include <string>
#include <utility>

class MysqlTable {

private:
    std::string name;
    std::string type;

public:
    explicit MysqlTable(std::string name, std::string type) : name(std::move(name)), type(std::move(type)) {}

    std::string getName() const {
        return name;
    }

    std::string getType() const {
        return type;
    }

};


#endif //DBCRUDGEN_CPP_MYSQLTABLE_H
