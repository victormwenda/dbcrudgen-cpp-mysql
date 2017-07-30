//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/4/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_DATABASECONNECTOR_H
#define DBCRUDGEN_CPP_DATABASECONNECTOR_H

#include <iostream>

//
// DatabaseConnector
// //
class DatabaseConnector {

public:
    /**
     * Open a database connection
     * @return returns true if the connection was established
     */
    virtual bool open() = 0;

    /**
     * Returns if this database is open
     * @return
     */
    virtual bool isOpen() = 0;

    /**
     * Closes the database
     * @return true if the connection was closed
     */
    virtual bool close() = 0;

    /**
     * Called when an error occurs
     * @param errorLevel
     * @param errorMessage
     */
    virtual void onError(const std::string &errorLevel, const std::string &errorMessage, bool logError) {
        if (logError) {
            std::cerr << errorLevel << ":" << errorMessage;
        }
    }
};


#endif //DBCRUDGEN_CPP_DATABASECONNECTOR_H
