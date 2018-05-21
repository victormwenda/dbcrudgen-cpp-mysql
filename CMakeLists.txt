#Cmake version
cmake_minimum_required(VERSION 3.7)

#Project name
project(dbcrudgen_cpp)

#Compilers
#SET(CMAKE_C_COMPILER /usr/bin/gcc-4.8)
#SET(CMAKE_CXX_COMPILER /usr/bin/g++-4.8)

#Linker flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#MYSQL connector dir
set(MYSQL_HOME /usr/local/include/mysql-connector-cpp/include)

#Oracle Instant client dir
set(ORACLE_INSTANT_CLIENT_HOME

        oracle/instant-client
        oracle/instant-client/include)

#Instant client libs
set(OCCI_LIBS
        oracle/instant-client/libocci.so
        oracle/instant-client/libclntsh.so)

#Include the Mysql Dirs
include_directories(${MYSQL_HOME})

#Include the Oracle OCI dir
include_directories(${ORACLE_INSTANT_CLIENT_HOME})

set(SOURCE_FILES

        src/main.cpp

        src/creators/DatabaseModelCreator.h
        src/creators/MYSQLDatabaseModelCreator.h
        src/creators/OracleDatabaseModelCreator.h
        src/creators/SQLiteDatabaseModelCreator.h


        src/core/database/schemas/OracleDatabaseSchemas.h
        src/core/database/schemas/SQLDatabaseSchemas.h
        src/core/database/schemas/MYSQLDatabaseSchemas.h
        src/core/database/schemas/MSSQLDatabaseSchemas.h
        src/core/database/schemas/DatabaseSchemas.h

        src/core/database/connectors/DatabaseConnector.h
        src/core/database/connectors/MYSQLDatabaseConnector.h
        src/core/database/connectors/OracleDatabaseConnector.h
        src/core/database/connectors/SQLiteDatabaseConnector.h

        src/core/database/connectors/credentials/DatabaseConnection.h
        src/core/database/connectors/credentials/SQLDatabaseConnectionParams.h
        src/core/database/connectors/credentials/MSSQLDatabaseConnectionParams.h
        src/core/database/connectors/credentials/MYSQLDatabaseConnectionParams.h
        src/core/database/connectors/credentials/OracleDatabaseConnectionParams.h
        src/core/database/connectors/credentials/SQLiteDatabaseConnectionParams.h

        src/core/database/columns/TableColumn.h
        src/core/database/columns/MYSQLTableColumn.h

        src/core/database/constraints/ColumnConstraints.h

        src/core/database/datatypes/DataType.h

        src/core/database/error/DatabaseError.h
        src/core/database/executors/MYSQLQueryExecutor.h
        src/core/database/executors/SQLiteQueryExecutor.h

        src/core/database/exceptions/MYSQLDatabaseException.h

        src/core/database/formats/RowFormats.h

        src/core/database/prepared/MYSQLStatements.h

        src/core/database/relations/DatabaseTable.h
        src/core/database/relations/MYSQLDatabaseTable.h
        src/core/database/relations/MysqlKeyColumnUsage.h
        src/core/database/relations/MysqlUser.h

        src/core/database/reserved/MysqlKeyColumnUsageTableColumns.h
        src/core/database/reserved/MysqlUserColumn.h

        src/core/database/tables/MysqlRelationTypes.h


        src/core/cli/CliParser.h

        src/core/crud/actions/DatabaseCrudActions.h

        src/core/io/FilesReader.h
        src/core/io/FilesWriter.h
        src/core/io/FilesManager.h

        src/lang/dsl/LanguageDSL.h
        src/lang/dsl/LanguageFilesProperties.h
        src/lang/dsl/JavaLangDSL.h
        src/lang/dsl/PHPLangDSL.h
        src/lang/dsl/CPPLangDSL.h

        src/lang/parser/LangTemplateParser.h
        src/lang/parser/java/JavaLangTemplateParser.h
        src/lang/parser/mysql/MYSQLLangParser.h


        src/models/MYSQLDatabaseModel.h
        src/models/OracleDatabaseModel.h
        src/models/SQLiteDatabaseModel.h

        src/utils/ConnectorUtils.h
        src/utils/DbCrudgenError.h
        src/utils/StringUtils.h
        src/utils/TransactionUtils.h
        src/utils/Tags.h
        src/utils/MysqlTags.h
        )

add_executable(dbcrudgen_cpp ${SOURCE_FILES})

#Link SQLite3 libs
target_link_libraries(dbcrudgen_cpp sqlite3)

#Link MysqlCpp libs
target_link_libraries(dbcrudgen_cpp mysqlcppconn)

#Link the Oracle libs
target_link_libraries(dbcrudgen_cpp ${OCCI_LIBS})


