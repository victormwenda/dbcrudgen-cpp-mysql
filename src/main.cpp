#include <iostream>
#include <occi.h>
#include <algorithm>
#include "databases/oracle/models/OracleDatabaseModel.h"

int main(int argc, char **argv) {


    const std::string userName = "victor";
    const std::string password = "root3358";

    const std::string connectionString = "//localhost:1521/XE";


    OracleDatabaseModel model{userName, password, connectionString};
    auto users = model.getAllUsers();

    std::for_each(std::begin(users), std::end(users),[] (OracleUser &user) {
        std::cout << user.getUsername() << std::endl;
    });

    return EXIT_SUCCESS;
}