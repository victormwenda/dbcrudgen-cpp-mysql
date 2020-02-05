#include <iostream>
#include <occi.h>
#include "models/OracleDatabaseModel.h"

int main(int argc, char **argv) {


    const std::string userName = "victor";
    const std::string password = "root3358";

    const std::string connectionString = "//localhost:1521/XE";


    OracleDatabaseModel model{userName, password, connectionString};
    std::string ddl = model.getTableDDL("VICTOR", "BUG_LOGGER");
    std::cout << ddl << std::endl;

    /**
     * Objects:
     * EDITION
INDEX PARTITION
TABLE SUBPARTITION
CONSUMER GROUP
SEQUENCE
TABLE PARTITION
SCHEDULE
RULE
PROCEDURE
OPERATOR
DESTINATION
WINDOW
SCHEDULER GROUP
PACKAGE
PACKAGE BODY
LIBRARY
PROGRAM
RULE SET
CONTEXT
TYPE BODY
XML SCHEMA
TRIGGER
JOB CLASS
DIRECTORY
TABLE
INDEX
SYNONYM
VIEW
FUNCTION
INDEXTYPE
CLUSTER
TYPE
JOB
EVALUATION CONTEXT
     */
    return EXIT_SUCCESS;
}