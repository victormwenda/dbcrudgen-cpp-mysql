#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include "core/database/connectors/MYSQLDatabaseConnector.h"


int main(int argc, char **argv) {


    sql::Driver *driver = get_driver_instance();
    sql::Connection *connection = driver->connect("tcp://127.0.0.1","root","root3358");
    connection->setSchema("dbcrudgen");
    sql::Statement *statement = connection->createStatement();
    sql::ResultSet *resultSet = statement->executeQuery("show tables;");
    while(resultSet->next()){
        std::cout << resultSet->getString(1);
    }
    return EXIT_SUCCESS;
}
