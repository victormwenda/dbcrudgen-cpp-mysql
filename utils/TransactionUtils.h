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
#include "../core/database/connectors/MYSQLDatabaseConnector.h"
#include "../core/database/connectors/credentials/MYSQLDatabaseConnectionParams.h"
#include "ConnectorUtils.h"
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

//
// TransactionUtils
// //
class TransactionUtils {

public:
    /**
     * Get the list of all tables in a MYSQL Database
     *
     * @param connectionParams
     * @return
     */
    static std::vector<std::string> getMYSQLDatabaseTables(MYSQLDatabaseConnectionParams connectionParams) {
        std::vector<std::string> tablesNames;
        std::string query = "SHOW TABLES IN " + connectionParams.getSchemas();
        MYSQLDatabaseConnector connector = ConnectorUtils::openMYSQLDatabase(connectionParams);
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            tablesNames.push_back(resultSet->getString(1));
        }
        resultSet->close();
        statement->close();
        return tablesNames;
    }
};


#endif //DBCRUDGEN_CPP_TRANSACTIONUTILS_H
