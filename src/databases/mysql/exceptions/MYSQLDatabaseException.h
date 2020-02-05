//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/25/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLDATABASEEXCEPTION_H
#define DBCRUDGEN_CPP_MYSQLDATABASEEXCEPTION_H


//
// MYSQLDatabaseException
// //
class MYSQLDatabaseException {
public:
    static int INVALID_DATABASE; //Should be initialized in the cpp file not the header file (int MYSQLDatabaseException::INVALID_DATABASE = 0x001;)
};


#endif //DBCRUDGEN_CPP_MYSQLDATABASEEXCEPTION_H
