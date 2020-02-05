//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/22/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLETABLEDDL_H
#define DBCRUDGEN_CPP_ORACLETABLEDDL_H


#include <string>
#include <utility>

//
// OracleTableDDL
// //
class OracleTableDDL {

    std::string ddl;

public:
    explicit OracleTableDDL(std::string ddl) : ddl{std::move(ddl)} {}

    const std::string &getDdl() const {
        return ddl;
    }
};


#endif //DBCRUDGEN_CPP_ORACLETABLEDDL_H
