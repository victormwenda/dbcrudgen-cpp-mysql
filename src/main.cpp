#include <iostream>
#include <occi.h>
#include "models/OracleDatabaseModel.h"

int main(int argc, char **argv) {


    const std::string userName = "victor";
    const std::string password = "root3358";

    const std::string connectionString = "//localhost:1521/XE";


    OracleDatabaseModel model{userName, password, connectionString};
    model.executeQuery();

    return EXIT_SUCCESS;
}