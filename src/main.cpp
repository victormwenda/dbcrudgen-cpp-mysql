#include <iostream>
#include <occi.h>
#include "databases/oracle/models/OracleDatabaseModel.h"

int main(int argc, char **argv) {


    const std::string userName = "victor";
    const std::string password = "root3358";

    const std::string connectionString = "//localhost:1521/XE";


    OracleDatabaseModel model{userName, password, connectionString};
    std::string ddl = model.getTableDDL("VICTOR", "BUG_LOGGER");
    std::cout << ddl << std::endl;

    return EXIT_SUCCESS;
}