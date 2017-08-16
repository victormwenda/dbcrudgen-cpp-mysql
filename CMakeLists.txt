cmake_minimum_required(VERSION 3.7)

project(dbcrudgen_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Include the Mysql Dirs
include_directories(/usr/local/include/mysql-connector-cpp/include)

#Include the Oracle OCI dir
include_directories(/usr/local/include/oracle/instant-client)
include_directories(/usr/local/include/oracle/instant-client/include)

set(SOURCE_FILES

        main.cpp

        #creators/DatabaseModelCreator.h
        #creators/MYSQLDatabaseModelCreator.h
        #creators/OracleDatabaseModelCreator.h
        #creators/SQLiteDatabaseModelCreator.h


        core/database/schemas/OracleDatabaseSchemas.h
        core/database/schemas/SQLDatabaseSchemas.h
        core/database/schemas/MYSQLDatabaseSchemas.h
        core/database/schemas/MSSQLDatabaseSchemas.h
        core/database/schemas/DatabaseSchemas.h

        core/database/connectors/DatabaseConnector.h
        core/database/connectors/MYSQLDatabaseConnector.h
        core/database/connectors/OracleDatabaseConnector.h
        core/database/connectors/SQLiteDatabaseConnector.h

        core/database/connectors/credentials/DatabaseConnection.h
        core/database/connectors/credentials/SQLDatabaseConnectionParams.h
        core/database/connectors/credentials/MSSQLDatabaseConnectionParams.h
        core/database/connectors/credentials/MYSQLDatabaseConnectionParams.h
        core/database/connectors/credentials/OracleDatabaseConnectionParams.h
        core/database/connectors/credentials/SQLiteDatabaseConnectionParams.h

        core/database/columns/TableColumn.h
        core/database/constraints/ColumnConstraints.h

        core/database/datatypes/DataType.h

        core/database/error/DatabaseError.h
        core/database/executors/MYSQLQueryExecutor.h
        core/database/executors/SQLiteQueryExecutor.h

        core/database/relations/DatabaseTable.h
        core/database/relations/MYSQLDatabaseTable.h
        core/database/formats/RowFormats.h

        core/cli/CliParser.h

        core/crud/actions/DatabaseCrudActions.h

        core/io/FilesReader.h
        core/io/FilesWriter.h
        core/io/FilesManager.h

        lang/dsl/LanguageDSL.h
        lang/dsl/LanguageFilesProperties.h
        lang/dsl/JavaLangDSL.h
        lang/dsl/PHPLangDSL.h
        lang/dsl/CPPLangDSL.h

        lang/parser/LangTemplateParser.h
        lang/parser/java/JavaLangTemplateParser.h

        utils/StringUtils.h)

add_executable(dbcrudgen_cpp ${SOURCE_FILES})

#Link SQLite3 libs
target_link_libraries(dbcrudgen_cpp sqlite3)

#Link MysqlCpp libs
target_link_libraries(dbcrudgen_cpp mysqlcppconn)

#Link the Oracle libs
target_link_libraries(dbcrudgen_cpp /usr/local/include/oracle/instant-client/libocci.so)
target_link_libraries(dbcrudgen_cpp /usr/local/include/oracle/instant-client/libclntsh.so)


