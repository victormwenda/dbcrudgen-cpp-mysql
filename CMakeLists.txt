#Cmake version
cmake_minimum_required(VERSION 3.7)

#Project name
project(dbcrudgen_cpp)

#Compilers
SET(CMAKE_C_COMPILER /usr/bin/gcc-4.8)
SET(CMAKE_CXX_COMPILER /usr/bin/g++-4.8)

#Linker flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Project path
set(PROJECT_DIR ${PROJECT_SOURCE_DIR}) #Replace with the path to your project

#MYSQL connector dir
set(MYSQL_HOME ${PROJECT_DIR}/include/mysql-connector-cpp/include)

#Oracle Instant client dir
set(ORACLE_INSTANT_CLIENT_HOME ${PROJECT_DIR}/include/oracle/instant-client)

#Oracle OCCI Headers
set(ORACLE_HEADERS ${ORACLE_INSTANT_CLIENT_HOME}/headers)

#Oracle Libs
set(ORACLE_LIBS ${ORACLE_INSTANT_CLIENT_HOME}/libs)


#Oracle Instant client dir
set(ORACLE_OCCI_HEADERS ${PROJECT_DIR}/include/oracle/instant-client/include)

#Instant client libs
set(OCCI_LIBS
        ${ORACLE_LIBS}/libclntsh.so.11.1
        ${ORACLE_LIBS}/libocci.so.11.1
        ${ORACLE_LIBS}/libociei.so
        )

#Include the Mysql Dirs
include_directories(${MYSQL_HOME})

#Include the Oracle instant client directory
include_directories(${ORACLE_HEADERS})

#Include the Oracle OCCI headers
include_directories(${ORACLE_OCCI_HEADERS})

set(SOURCE_FILES

        src/main.cpp

        ##############################################################################################################
        # MYSQL DATABASE SOURCE FILES
        ##############################################################################################################
        src/databases/mssql/connectors/MSSQLDatabaseConnectionParams.h
        src/databases/mssql/models/MSSQLDatabaseSchemas.h

        src/databases/mysql/columns/MYSQLTableColumn.h
        src/databases/mysql/connectors/MYSQLDatabaseConnectionParams.h
        src/databases/mysql/connectors/MYSQLDatabaseConnector.h
        src/databases/mysql/connectors/MYSQLQueryExecutor.h

        src/databases/mysql/exceptions/MYSQLDatabaseException.h

        src/databases/mysql/models/MYSQLDatabaseSchemas.h
        src/databases/mysql/models/MYSQLDatabaseModel.h
        src/databases/mysql/models/MYSQLDatabaseTable.h
        src/databases/mysql/models/MysqlKeyColumnUsage.h
        src/databases/mysql/models/MysqlUser.h

        src/databases/mysql/objects/constraints/ColumnConstraints.h
        src/databases/mysql/objects/tables/RowFormats.h
        src/databases/mysql/objects/tables/MysqlTableColumnColumns.h
        src/databases/mysql/objects/tables/MysqlKeyColumnUsageTableColumns.h
        src/databases/mysql/objects/tables/MysqlUserColumn.h
        src/databases/mysql/objects/MysqlRelationTypes.h

        src/databases/mysql/queries/MYSQLStatements.h
        src/databases/mysql/queries/MysqlCreateTableColumns.h
        src/databases/mysql/queries/MysqlFullTablesColumns.h

        src/databases/mysql/parsers/MYSQLLangParser.h

        src/databases/mysql/symbols/MysqlTable.h

        ##############################################################################################################
        # ORACLE DATABASE SOURCE FILES
        ##############################################################################################################
        src/databases/oracle/connectors/OracleDatabaseConnector.h
        src/databases/oracle/connectors/OracleDatabaseConnectionParams.h

        src/databases/oracle/dsl/OracleDataTypes.h

        src/databases/oracle/indices/OracleAllTablesColumns.h
        src/databases/oracle/indices/OracleColsColumns.h
        src/databases/oracle/indices/OracleDBATablesColumns.h
        src/databases/oracle/indices/OracleDBAUsersColumns.h
        src/databases/oracle/indices/OracleDbaColsColumns.h
        src/databases/oracle/dsl/OracleObject.h
        src/databases/oracle/dsl/OracleObjectTypes.h
        src/databases/oracle/dsl/OracleSchemaObject.h
        src/databases/oracle/indices/OracleUsersColumns.h
        src/databases/oracle/indices/OracleUserTablesColumns.h

        src/databases/oracle/models/OracleDatabaseSchemas.h
        src/databases/oracle/models/OracleDatabaseModel.h

        src/databases/oracle/parsers/MysqlTags.h
        src/databases/oracle/parsers/OracleTags.h

        src/databases/oracle/queries/OracleStatements.h

        src/databases/oracle/objects/OracleDBATables.h
        src/databases/oracle/objects/OracleDBAUser.h
        src/databases/oracle/objects/OracleTableColumn.h
        src/databases/oracle/objects/OracleTableColsDba.h
        src/databases/oracle/models/OracleTableDDL.h
        src/databases/oracle/models/OracleUser.h

        src/databases/oracle/objects/OracleUserTables.h

        ##############################################################################################################
        # SQL GENERIC SOURCE FILES
        ##############################################################################################################
        src/databases/sql/columns/TableColumn.h

        src/databases/sql/connectors/DatabaseConnector.h
        src/databases/sql/connectors/DatabaseConnection.h
        src/databases/sql/connectors/SQLiteDatabaseConnectionParams.h

        src/databases/sql/dsl/DataType.h

        src/databases/sql/exceptions/DatabaseError.h

        src/databases/sql/models/SQLDatabaseSchemas.h
        src/databases/sql/models/DatabaseSchemas.h
        src/databases/sql/models/DatabaseTable.h

        src/databases/sql/parsers/Tags.h

        ##############################################################################################################
        # SQLITE SOURCE FILES
        ##############################################################################################################
        src/databases/sqlite/connectors/SQLiteDatabaseConnector.h
        src/databases/sqlite/connectors/SQLiteQueryExecutor.h
        src/databases/sqlite/models/SQLiteDatabaseModel.h

        ##############################################################################################################
        # IO
        ##############################################################################################################

        src/io/FilesReader.h
        src/io/FilesWriter.h
        src/io/FilesManager.h

        ##############################################################################################################
        # LANGUAGE CORE
        ##############################################################################################################
        src/lang/dsl/LanguageDSL.h
        src/lang/dsl/LanguageFilesProperties.h
        src/lang/dsl/JavaLangDSL.h
        src/lang/dsl/PHPLangDSL.h
        src/lang/dsl/CPPLangDSL.h
        src/lang/parser/LangTemplateParser.h
        src/lang/parser/java/JavaLangTemplateParser.h

        ##############################################################################################################
        # ORM
        ##############################################################################################################
        src/orm/cli/CliParser.h
        src/orm/cli/DatabaseCrudActions.h

        src/orm/creators/DatabaseModelCreator.h
        src/orm/creators/MYSQLDatabaseModelCreator.h
        src/orm/creators/OracleDatabaseModelCreator.h
        src/orm/creators/SQLiteDatabaseModelCreator.h

        src/orm/utils/ConnectorUtils.h
        src/orm/utils/DbCrudgenError.h
        src/orm/utils/StringUtils.h
        src/orm/utils/TransactionUtils.h

        )

#GoogleTest
add_subdirectory(lib/test/googletest)
include_directories(lib/test/googletest/googletest/include)
include_directories(lib/test/googletest/googlemock/include)

#Create executable
add_executable(dbcrudgen_cpp ${SOURCE_FILES})

#Link with GoogleTest
target_link_libraries(dbcrudgen_cpp gtest gtest_main pthread)

#Link with GoogleMock
target_link_libraries(dbcrudgen_cpp gmock gmock_main pthread)

#Link SQLite3 libs
target_link_libraries(dbcrudgen_cpp sqlite3)

#Link MysqlCpp libs
target_link_libraries(dbcrudgen_cpp mysqlcppconn)

#Link the Oracle libs
target_link_libraries(dbcrudgen_cpp ${OCCI_LIBS})

