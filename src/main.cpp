#include <iostream>
#include <string>
#include <sql.h>
#include <sqlext.h>


int main(int argc, char **argv) {
    SQLHENV hEnv = nullptr;
    SQLHDBC hDbc = nullptr;
    SQLHSTMT hStmt = NULL;

    /**
     * Allocate environment handle
     */
    SQLRETURN allocReturn = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);

    //Set environment
    SQLRETURN setEnvReturn = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0);

    //Allocate connection handle

    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
    SQLCHAR *connection_string = (SQLCHAR *)
            "DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost,1433;DATABASE=dbcrudgen;UID=sa;PWD=Root@3358";

    //Connect to database
    SQLRETURN connReturn = SQLDriverConnect(hDbc, NULL, connection_string, SQL_NTS, NULL, 0, NULL,
                                            SQL_DRIVER_COMPLETE);

    //Allocate Statement Handle
    SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

    //Create statement
    SQLCHAR *query = (SQLCHAR *) "SELECT * FROM TEST;";
    SQLRETURN sqlPrepareResponse = SQLPrepare(hStmt, query, SQL_NTS); //strlen(reinterpret_cast<const char *>(query))

    //Bind columns
    SQLCHAR personName[20];
    SQLLEN personNameIndex;
    SQLRETURN bindNameResponse = SQLBindCol(hStmt, 2, SQL_C_CHAR, personName, sizeof(personName),
                                            &personNameIndex);


    SQLINTEGER personId;
    SQLLEN personIdIndex;
    SQLRETURN personIdBindResponse = SQLBindCol(hStmt, 1, SQL_INTEGER, &personId, 0, &personIdIndex);

    SQLRETURN execResponse = SQLExecute(hStmt);

    SQLRETURN fetchResponse;

    while ((fetchResponse = SQLFetch(hStmt)) != SQL_NO_DATA) {
        std::cout << "ID: [" << personId << "] :" << personName << std::endl;
    }


    /* Free the statement handle. */
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);

    /* Disconnect from the database. */
    SQLDisconnect(hDbc);

    /* Free the connection handle. */
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);

    /* Free the environment handle. */
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

    return EXIT_SUCCESS;
}

