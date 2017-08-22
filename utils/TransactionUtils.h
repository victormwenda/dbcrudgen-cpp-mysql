//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/22/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_TRANSACTIONUTILS_H
#define DBCRUDGEN_CPP_TRANSACTIONUTILS_H


#include "../core/database/connectors/OracleDatabaseConnector.h"

//
// TransactionUtils
// //
class TransactionUtils {

public:
    static OracleDatabaseConnector openOracleDatabase(OracleDatabaseConnectionParams connectionParams){
        OracleDatabaseConnector oracleDatabaseConnector{connectionParams, true};
        return oracleDatabaseConnector;
    }
};


#endif //DBCRUDGEN_CPP_TRANSACTIONUTILS_H
