cmake_minimum_required(VERSION 3.7)

project(dbcrudgen_cpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/include/mysql-connector-cpp/include)

set(SOURCE_FILES main.cpp core/cli/CliParser.h core/crud/actions/DatabaseCrudActions.h core/io/FilesReader.h core/io/FilesWriter.h core/io/FilesManager.h core/database/schemas/OracleDatabaseSchemas.h core/database/schemas/SQLDatabaseSchemas.h core/database/schemas/MYSQLDatabaseSchemas.h core/database/schemas/MSSQLDatabaseSchemas.h core/database/schemas/DatabaseSchemas.h core/database/connection/DatabaseConnection.h core/database/connection/SQLDatabaseConnection.h core/database/connection/MSSQLDatabaseConnection.h core/database/connection/MYSQLDatabaseConnection.h core/database/connection/OracleDatabaseConnection.h core/database/columns/TableColumn.h core/database/datatypes/DataType.h core/database/constraints/ColumnConstraints.h core/database/relations/DatabaseTable.h core/database/relations/MYSQLDatabaseTable.h core/database/formats/RowFormats.h lang/dsl/LanguageDSL.h lang/dsl/LanguageFilesProperties.h lang/dsl/JavaLangDSL.h lang/dsl/PHPLangDSL.h lang/dsl/CPPLangDSL.h core/database/connection/Connector.cpp)

add_executable(dbcrudgen_cpp ${SOURCE_FILES})

target_link_libraries(dbcrudgen_cpp mysqlcppconn)

