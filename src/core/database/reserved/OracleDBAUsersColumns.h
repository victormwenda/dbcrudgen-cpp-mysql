//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/18/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEDBAUSERSCOLUMNS_H
#define DBCRUDGEN_CPP_ORACLEDBAUSERSCOLUMNS_H


//
// OracleDBAUsersColumns
// //
class OracleDBAUsersColumns {

public:

    //Name of the user
    struct USERNAME {
        static const unsigned int INDEX = 1;
    };
    //Numeric ID assigned to the user
    struct USER_ID {
        static const unsigned int INDEX = 2;
    };

    //Deprecated
    struct PASSWORD {
        static const unsigned int INDEX = 3;
    };

    //Status of the user such as:
    struct ACCOUNT_STATUS {
        static const unsigned int INDEX = 4;
    };


    //Date that User was locked (if applicable)
    struct LOCK_DATE {
        static const unsigned int INDEX = 5;
    };

    //Date that User was expired
    struct EXPIRY_DATE {
        static const unsigned int INDEX = 6;
    };

    //Default tablespace for the user
    struct DEFAULT_TABLESPACE {
        static const unsigned int INDEX = 7;
    };


    //Temporary tablespace for the user
    struct TEMPORARY_TABLESPACE {
        static const unsigned int INDEX = 8;
    };


    //Date that user was created
    struct CREATED {
        static const unsigned int INDEX = 9;
    };


    //User resource profile name
    struct PROFILE {
        static const unsigned int INDEX = 10;
    };


    //Initial resource consumer group for the user
    struct INITIAL_RSRC_CONSUMER_GROUP {
        static const unsigned int INDEX = 11;
    };


    //External name for the user
    struct EXTERNAL_NAME {
        static const unsigned int INDEX = 12;
    };


    //List of versions of the password hashes
    struct PASSWORD_VERSIONS {
        static const unsigned int INDEX = 13;
    };


    //  Y/N indicating whether editions have been enabled for the user
    struct EDITIONS_ENABLED {
        static const unsigned int INDEX = 14;
    };


    //Authentication method for the user
    struct AUTHENTICATION_TYPE {
        static const unsigned int INDEX = 15;
    };
};


#endif //DBCRUDGEN_CPP_ORACLEDBAUSERSCOLUMNS_H
