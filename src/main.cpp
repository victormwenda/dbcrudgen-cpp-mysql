#include <iostream>
#include <string>
#include <sql.h>
#include <sqlext.h>
#include <cstring>

#define SQL_QUERY_SIZE 1000
#define ROWSET_SIZE 3

void printSQLResponse(SQLRETURN connReturn);

using namespace std;

void printSQLResponse(const std::string &method, SQLRETURN sqlReturn) {

    if (sqlReturn == SQL_SUCCESS) { cout << method << " :: SQL_SUCCESS" << endl; }
    if (sqlReturn == SQL_SUCCESS_WITH_INFO) { cout << method << " :: SQL_SUCCESS_WITH_INFO" << endl; }
    if (sqlReturn == SQL_INVALID_HANDLE) { cout << method << " :: SQL_INVALID_HANDLE" << endl; }
    if (sqlReturn == SQL_ERROR) { cout << method << " :: SQL_ERROR" << endl; }
}

void test() {
    SQLHENV hEnv = NULL;
    SQLHDBC hDbc = NULL;
    SQLHSTMT hStmt = NULL;
    WCHAR *pswszConnStr;
    WCHAR wszInput[SQL_QUERY_SIZE];

    /**
     * Allocate environment handle
     */
    SQLRETURN allocReturn = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    printSQLResponse("SQLAllocHandle", allocReturn);

    //Set environment
    SQLRETURN setEnvReturn = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0);
    printSQLResponse("SQLSetEnvAttr", setEnvReturn);

    /**
     * Allocate connection handle
     */
    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
    SQLCHAR *connection_string = (SQLCHAR *) "DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost,1433;DATABASE=dbcrudgen;UID=sa;PWD=Root@3358";

    //Connect to database
    SQLRETURN connReturn = SQLDriverConnect(hDbc, NULL, connection_string, SQL_NTS, NULL, 0, NULL,
                                            SQL_DRIVER_COMPLETE);

    printSQLResponse("SQLDriverConnect", connReturn);


    /**
     * Allocate Statement Handle
     */
    SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

    //Create statement
    SQLCHAR *query = (SQLCHAR *) "SELECT * FROM TEST;";
    SQLRETURN sqlPrepareResponse = SQLPrepare(hStmt, query, SQL_NTS); //strlen(reinterpret_cast<const char *>(query))
    printSQLResponse("SQLPrepare", sqlPrepareResponse);

    //Bind columns
    SQLCHAR personName [20];
    SQLLEN personNameIndex;
    SQLRETURN bindNameResponse = SQLBindCol(hStmt, 2, SQL_C_CHAR, personName, sizeof(personName),
                                            &personNameIndex);
    printSQLResponse("SQLBindCol", bindNameResponse);


    SQLINTEGER personId;
    SQLLEN personIdIndex;
    SQLRETURN personIdBindResponse = SQLBindCol(hStmt, 1, SQL_INTEGER, &personId, 0, &personIdIndex);
    printSQLResponse("SQLBindCol", personIdBindResponse);

    SQLRETURN execResponse = SQLExecute(hStmt);
    printSQLResponse("SQLExec", execResponse);

    SQLRETURN fetchResponse;

    while ((fetchResponse = SQLFetch(hStmt)) != SQL_NO_DATA) {
        printSQLResponse("SQLFetch", fetchResponse);
        std::cout << "Person id : " << personId << std::endl;
        std::cout << " Person name : " <<  personName << std::endl;
    }


    /* Free the statement handle. */
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);

    /* Disconnect from the database. */
    SQLDisconnect(hDbc);

    /* Free the connection handle. */
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);

    /* Free the environment handle. */
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

}

void sampleInsert(SQLHSTMT hStmt) {
    //Create statement
    SQLCHAR *query = (SQLCHAR *) "INSERT INTO test (id, name) values (3, 'Victor Rwanda');";
    SQLRETURN sqlPrepareResponse = SQLPrepare(hStmt, query, SQL_NTS); //strlen(reinterpret_cast<const char *>(query))
    printSQLResponse("SQLPrepare", sqlPrepareResponse);

    SQLRETURN execResponse = SQLExecDirect(hStmt, query, SQL_NTS);
    printSQLResponse("SQLExecDirect", execResponse);
}

void test2() {
    SQLHANDLE hEnv;

    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);

    SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);

    SQLHANDLE hConn;

    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hConn);


    SQLCHAR *dsnName = (SQLCHAR *) "dsn01";  // MUST BE THE SAME
    SQLCHAR *userid = (SQLCHAR *) "nodata\0";
    SQLCHAR *password = (SQLCHAR *) "nodata\0";

    SQLConnect(hConn, dsnName, 5, userid, SQL_NTS, password, SQL_NTS);

}

int main(int argc, char **argv) {
    test();
    return EXIT_SUCCESS;
}

