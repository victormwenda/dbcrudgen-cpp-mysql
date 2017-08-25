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
#include "../core/database/relations/MYSQLDatabaseTable.h"
#include "../lang/parser/mysql/MYSQLLangParser.h"
#include "../core/database/columns/MYSQLTableColumn.h"
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
    static std::vector<std::string>
    getMYSQLDatabaseTables(MYSQLDatabaseConnector &connector, const std::string &schemas) {
        std::vector<std::string> tablesNames;
        std::string query = "SHOW TABLES IN " + schemas;
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            tablesNames.push_back(resultSet->getString(1));
        }
        resultSet->close();
        statement->close();
        return tablesNames;
    }

    static std::vector<MYSQLTableColumn>
    getMYSQLTableColumns(MYSQLDatabaseConnector &connector, const std::string &schemas, std::string tableName) {

       std::vector<MYSQLTableColumn> tableColumns;

        std::string query = "DESC " +MYSQLLangParser::toAbsolutePath(schemas,tableName);
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            std::string field = resultSet->getString("Field");
            std::string type = resultSet->getString("Type");
            std::string allowNull = resultSet->getString("Null");
            std::string defaultValue = resultSet->getString("Default");
            std::string extra = resultSet->getString("Extra");
            MYSQLTableColumn mysqlTable {field, type,allowNull, defaultValue,extra};
            tableColumns.push_back(mysqlTable);
        }
        resultSet->close();
        statement->close();

        return tableColumns;
    }
};


#endif //DBCRUDGEN_CPP_TRANSACTIONUTILS_H
