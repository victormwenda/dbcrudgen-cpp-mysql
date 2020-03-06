/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/13/17.
* C/C++ Laptop
*/

#ifndef DBCRUDGEN_CPP_MYSQLDATABASE_H
#define DBCRUDGEN_CPP_MYSQLDATABASE_H


#include <c++/4.8/vector>
#include "../connectors/MYSQLDatabaseConnector.h"
#include "../schema/Schemata.h"

class MYSQLDatabaseSchemas {

private:
    MYSQLDatabaseConnector &connector;


public:
    explicit MYSQLDatabaseSchemas(MYSQLDatabaseConnector &connector) : connector(connector) {}

    std::vector<Schemata> getSchemas() {
        std::vector<Schemata> schematas;

        std::string query = "SELECT * FROM SCHEMATA";

        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

        while (resultSet->next()) {
            std::string catalogName = resultSet->getString(Schemata::Columns::CATALOG_NAME::INDEX);
            std::string schemaName = resultSet->getString(Schemata::Columns::SCHEMA_NAME::INDEX);
            std::string defaultCharacterSetName = resultSet->getString(
                    Schemata::Columns::DEFAULT_CHARACTER_SET_NAME::INDEX);
            std::string defaultCollationName = resultSet->getString(Schemata::Columns::DEFAULT_COLLATION_NAME::INDEX);
            std::string sqlPath = resultSet->getString(Schemata::Columns::SQL_PATH::INDEX);

            const Schemata &schemata = Schemata{catalogName, schemaName, defaultCharacterSetName, defaultCollationName,
                                                sqlPath};
            schematas.emplace_back(schemata);
        }

        resultSet->close();
        statement->close();

        return schematas;
    };


};


#endif //DBCRUDGEN_CPP_MYSQLDATABASE_H
