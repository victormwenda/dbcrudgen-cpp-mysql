#include <iostream>
#include <occi.h>
#include "models/OracleDatabaseModel.h"

int main(int argc, char **argv) {


    const std::string userName = "victor";
    const std::string password = "root3358";

    const std::string connectionString = "//localhost:1521/XE";


    oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
    oracle::occi::Connection *conn = env->createConnection(userName, password, connectionString);


    oracle::occi::MetaData metaData = conn->getMetaData("BUG_LOGGER", oracle::occi::MetaData::PTYPE_TABLE);

    std::vector<oracle::occi::MetaData> columns = metaData.getVector(oracle::occi::MetaData::ATTR_LIST_COLUMNS);

    for(auto& column : columns) {
        std::cout << column.getString(oracle::occi::MetaData::ATTR_NAME) << " : ";
        std::cout << column.getInt(oracle::occi::MetaData::ATTR_DATA_TYPE) << "\n";
    }


    //env->terminateConnection(conn);
    //oracle::occi::Environment::terminateEnvironment(env);

    return EXIT_SUCCESS;
}