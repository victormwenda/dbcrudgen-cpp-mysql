#include <iostream>
#include "core/database/connectors/credentials/OracleDatabaseConnectionParams.h"
#include "core/database/connectors/OracleDatabaseConnector.h"

using namespace std;


int main(int argc, char **argv) {
    OracleDatabaseConnectionParams connectionParams {"victor",1521,"victor","root3358","victor"};
    OracleDatabaseConnector databaseConnector{connectionParams, true};
     return EXIT_SUCCESS;
}