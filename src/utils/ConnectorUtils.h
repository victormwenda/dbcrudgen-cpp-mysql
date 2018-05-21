//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/24/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_CONNECTORUTILS_H
#define DBCRUDGEN_CPP_CONNECTORUTILS_H


#include "../core/database/connectors/OracleDatabaseConnector.h"
#include "../core/database/connectors/MYSQLDatabaseConnector.h"

//
// ConnectorUtils
// Creates Database connections
// //
class ConnectorUtils {
public:
/**
     * Open Oracle database connection
     * @param connectionParams
     * @return
     */
    static OracleDatabaseConnector openOracleDatabase(OracleDatabaseConnectionParams connectionParams) {
        OracleDatabaseConnector oracleDatabaseConnector{connectionParams, true};
        return oracleDatabaseConnector;
    }

    /**
     * Open MYSQL database connection
     * @param connectionParams
     * @return
     */
    static MYSQLDatabaseConnector openMYSQLDatabase(MYSQLDatabaseConnectionParams connectionParams) {
        MYSQLDatabaseConnector mysqlDatabaseConnector{connectionParams, true};
        return mysqlDatabaseConnector;
    }
};


#endif //DBCRUDGEN_CPP_CONNECTORUTILS_H
