//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/22/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEOBJECTS_H
#define DBCRUDGEN_CPP_ORACLEOBJECTS_H


//
// OracleObject - https://docs.oracle.com/cd/B19306_01/server.102/b14220/schema.htm
// //
class OracleObject {
public:
    struct Contexts {
        constexpr static const char *NAME = "CONTEXT";
    };
    struct Directories {
        constexpr static const char *NAME = "DIRECTORY";
    };
    struct Profiles {
        constexpr static const char *NAME = "PROFILE";
    };
    struct Roles {
        constexpr static const char *NAME = "ROLE";
    };
    struct TableSpaces {
        constexpr static const char *NAME = "TABLE";
    };
    struct Users {
        constexpr static const char *NAME = "USER";
    };
};


#endif //DBCRUDGEN_CPP_ORACLEOBJECTS_H
