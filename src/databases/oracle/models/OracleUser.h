//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/18/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEUSER_H
#define DBCRUDGEN_CPP_ORACLEUSER_H


#include <string>

//
// OracleUser
// //
class OracleUser {

public:
    int userid;
    std::string username;
    std::string created;

    OracleUser(int userid, const std::string &username, const std::string &created)
            : userid(userid), username(username), created(created) {}

    int getUserid() const {
        return userid;
    }

    void setUserid(int userid) {
        OracleUser::userid = userid;
    }

    const std::string &getUsername() const {
        return username;
    }

    void setUsername(const std::string &username) {
        OracleUser::username = username;
    }

    const std::string &getCreated() const {
        return created;
    }

    void setCreated(const std::string &created) {
        OracleUser::created = created;
    }

    enum Columns {
        USERNAME = 1, USER_ID = 2, CREATED = 3
    };

};


#endif //DBCRUDGEN_CPP_ORACLEUSER_H
