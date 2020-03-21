#Cmake version
cmake_minimum_required(VERSION 3.7)

#Project name
project(dbcrudgen_cpp)

#Compilers
SET(CMAKE_C_COMPILER /usr/bin/cc)
SET(CMAKE_CXX_COMPILER /usr/bin/c++)

#Linker flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

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

        src/databases/generic/Database.h
        src/databases/generic/Table.h
        src/databases/generic/Column.h
        src/databases/generic/User.h

        ##############################################################################################################
        # MSSQL DATABASE SOURCE FILES
        ##############################################################################################################

        src/databases/mssql/models/MSSQLDatabaseSchemas.h
        src/databases/mssql/connectors/MSSQLDatabaseConnectionParams.h
        src/databases/mssql/parsers/MSSQLDatabaseFlattener.h

        ##############################################################################################################
        # MySQL DATABASE SOURCE FILES
        ##############################################################################################################

        src/databases/mysql/core/MYSQLIdentifierLengthLimits.h
        src/databases/mysql/core/MYSQLObjects.h
        src/databases/mysql/core/MYSQLKeyWords.h
        src/databases/mysql/core/MYSQLReservedWords.h
        src/databases/mysql/core/RowFormats.h
        src/databases/mysql/core/MYSQLDataType.h


        src/databases/mysql/columns/MysqlKeyColumnUsageTableColumns.h
        src/databases/mysql/columns/MysqlTableColumnColumns.h
        src/databases/mysql/columns/MYSQLTableColumn.h
        src/databases/mysql/columns/MysqlUserColumn.h

        src/databases/mysql/connectors/MYSQLDatabaseConnectionParams.h
        src/databases/mysql/connectors/MYSQLDatabaseConnector.h
        src/databases/mysql/connectors/MYSQLQueryExecutor.h

        src/databases/mysql/decomposer/MYSQLDatabaseDecomposer.h

        src/databases/mysql/exceptions/MYSQLDatabaseException.h

        src/databases/mysql/models/DataType.h
        src/databases/mysql/models/MYSQLDatabaseModel.h

        src/databases/mysql/objects/constraints/ColumnConstraints.h
        src/databases/mysql/objects/MYSQLTable.h
        src/databases/mysql/objects/MYSQLDatabase.h
        src/databases/mysql/objects/stored/MYSQLProcedure.h
        src/databases/mysql/objects/stored/MYSQLFunction.h
        src/databases/mysql/objects/stored/MYSQLTrigger.h
        src/databases/mysql/objects/stored/MYSQLEvent.h
        src/databases/mysql/objects/stored/MYSQLView.h
        src/databases/mysql/objects/MysqlRelationTypes.h


        src/databases/mysql/queries/MysqlCreateTableColumns.h
        src/databases/mysql/queries/MysqlFullTablesColumns.h
        src/databases/mysql/scaffolding/queries/MysqlQueries.h
        src/databases/mysql/queries/MYSQLStatements.h

        src/databases/mysql/parsers/MYSQLLangParser.h
        src/databases/mysql/parsers/MYSQLDatabaseFlattener.h

        src/databases/mysql/scaffolding/entities/CharacterSets.h
        src/databases/mysql/scaffolding/entities/Collations.h
        src/databases/mysql/scaffolding/entities/CollationCharacterSetApplicability.h
        src/databases/mysql/scaffolding/entities/Columns.h
        src/databases/mysql/scaffolding/entities/ColumnPrivileges.h
        src/databases/mysql/scaffolding/entities/Engines.h
        src/databases/mysql/scaffolding/entities/Events.h
        src/databases/mysql/scaffolding/entities/Files.h
        src/databases/mysql/scaffolding/entities/GlobalStatus.h
        src/databases/mysql/scaffolding/entities/GlobalVariables.h
        src/databases/mysql/scaffolding/entities/KeyColumnUsage.h
        src/databases/mysql/scaffolding/entities/OptimizerTrace.h
        src/databases/mysql/scaffolding/entities/Parameters.h
        src/databases/mysql/scaffolding/entities/Partitions.h
        src/databases/mysql/scaffolding/entities/Plugins.h
        src/databases/mysql/scaffolding/entities/ProcessList.h src/databases/mysql/scaffolding/entities/Profiling.h
        src/databases/mysql/scaffolding/entities/ReferentialConstraints.h
        src/databases/mysql/scaffolding/entities/Routines.h
        src/databases/mysql/scaffolding/entities/Schemata.h src/databases/mysql/scaffolding/entities/SchemaPrivileges.h
        src/databases/mysql/scaffolding/entities/SessionStatus.h src/databases/mysql/scaffolding/entities/SessionVariables.h
        src/databases/mysql/scaffolding/entities/Statistics.h src/databases/mysql/scaffolding/entities/Tables.h
        src/databases/mysql/scaffolding/entities/TableSpaces.h src/databases/mysql/scaffolding/entities/TableConstraints.h
        src/databases/mysql/scaffolding/entities/TablePrivileges.h src/databases/mysql/scaffolding/entities/Triggers.h
        src/databases/mysql/scaffolding/entities/UserPrivileges.h src/databases/mysql/scaffolding/entities/Views.h
        src/databases/mysql/scaffolding/entities/InnoDbLocks.h src/databases/mysql/scaffolding/entities/InnoDbTrx.h
        src/databases/mysql/scaffolding/entities/InnoDbSysDataFiles.h src/databases/mysql/scaffolding/entities/InnoDbFtConfig.h
        src/databases/mysql/scaffolding/entities/InnoDbSysVirtual.h src/databases/mysql/scaffolding/entities/InnoDbCmp.h
        src/databases/mysql/scaffolding/entities/InnoDbFtBeingDeleted.h src/databases/mysql/scaffolding/entities/InnoDbCmpReset.h
        src/databases/mysql/scaffolding/entities/InnoDbCmpPerIndex.h src/databases/mysql/scaffolding/entities/InnoDbCmpMemReset.h
        src/databases/mysql/scaffolding/entities/InnoDbFtDeleted.h src/databases/mysql/scaffolding/entities/InnoDbBufferPageLRU.h
        src/databases/mysql/scaffolding/entities/InnoDbLockWaits.h src/databases/mysql/scaffolding/entities/InnoDbTempTableInfo.h
        src/databases/mysql/scaffolding/entities/InnoDbSysIndexes.h src/databases/mysql/scaffolding/entities/InnoDbSysTables.h
        src/databases/mysql/scaffolding/entities/InnoDbSysFields.h src/databases/mysql/scaffolding/entities/InnoDbCmpPerIndexReset.h
        src/databases/mysql/scaffolding/entities/InnoDbBufferPage.h src/databases/mysql/scaffolding/entities/InnoDbFtDefaultStopWord.h
        src/databases/mysql/scaffolding/entities/InnoDbFtIndexTable.h src/databases/mysql/scaffolding/entities/InnoDbFtIndexCache.h
        src/databases/mysql/scaffolding/entities/InnoDbSysTableSpaces.h src/databases/mysql/scaffolding/entities/InnoDbMetrics.h
        src/databases/mysql/scaffolding/entities/InnoDbSysForeignCols.h src/databases/mysql/scaffolding/entities/InnoDbCmpMem.h
        src/databases/mysql/scaffolding/entities/InnoDbBufferPoolStats.h src/databases/mysql/scaffolding/entities/InnoDbSysColumns.h
        src/databases/mysql/scaffolding/entities/InnoDbSysForeign.h src/databases/mysql/scaffolding/entities/InnoDbSysTableStats.h
        src/databases/mysql/scaffolding/entities/ColumnsPriv.h
        src/databases/mysql/scaffolding/entities/Db.h
        src/databases/mysql/scaffolding/entities/EngineCost.h
        src/databases/mysql/scaffolding/entities/Event.h
        src/databases/mysql/scaffolding/entities/Func.h
        src/databases/mysql/scaffolding/entities/GeneralLog.h
        src/databases/mysql/scaffolding/entities/GtidExecuted.h
        src/databases/mysql/scaffolding/entities/HelpCategory.h
        src/databases/mysql/scaffolding/entities/HelpKeyword.h
        src/databases/mysql/scaffolding/entities/HelpRelation.h
        src/databases/mysql/scaffolding/entities/HelpTopic.h
        src/databases/mysql/scaffolding/entities/InnoDbIndexStats.h
        src/databases/mysql/scaffolding/entities/InnoDbTableStats.h
        src/databases/mysql/scaffolding/entities/NdbBinlogIndex.h
        src/databases/mysql/scaffolding/entities/Plugin.h
        src/databases/mysql/scaffolding/entities/Proc.h
        src/databases/mysql/scaffolding/entities/ProcsPriv.h
        src/databases/mysql/scaffolding/entities/ProxiesPriv.h
        src/databases/mysql/scaffolding/entities/ServerCost.h
        src/databases/mysql/scaffolding/entities/Servers.h
        src/databases/mysql/scaffolding/entities/SlaveMasterInfo.h
        src/databases/mysql/scaffolding/entities/SlaveRelayLogInfo.h
        src/databases/mysql/scaffolding/entities/SlaveWorkerInfo.h
        src/databases/mysql/scaffolding/entities/SlowLog.h
        src/databases/mysql/scaffolding/entities/TablesPriv.h
        src/databases/mysql/scaffolding/entities/TimeZone.h
        src/databases/mysql/scaffolding/entities/TimeZoneLeapSecond.h
        src/databases/mysql/scaffolding/entities/TimeZoneName.h
        src/databases/mysql/scaffolding/entities/TimeZoneTransition.h
        src/databases/mysql/scaffolding/entities/TimeZoneTransitionType.h
        src/databases/mysql/scaffolding/entities/User.h

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
        src/databases/oracle/parsers/OracleDatabaseFlattener.h


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
        src/databases/sqlite/parsers/SQLiteDatabaseFlattener.h

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

        src/orm/codegen/Databases.h
        src/orm/codegen/Languages.h
        src/orm/codegen/Frameworks.h

        src/orm/codegen/ProjectCodeGen.h

        src/orm/codegen/android/AndroidProjectCodeGen.h

        src/orm/codegen/cpp/CppMYSQLDbConnectorCodeGen.h
        src/orm/codegen/cpp/CppMYSQLDbTableModelCodeGen.h
        src/orm/codegen/cpp/CppMYSQLProjectCodeGen.h
        src/orm/codegen/cpp/CppMYSQLSCRUDCodeGen.h
        src/orm/codegen/cpp/CppProjectCodeGen.h
        src/orm/codegen/cpp/CppSQLiteProjectCodeGen.h
        src/orm/codegen/cpp/CppOracleProjectCodeGen.h

        src/orm/codegen/java/JavaProjectCodeGen.h
        src/orm/codegen/java/JavaMYSQLProjectCodeGen.h
        src/orm/codegen/java/JavaSQLiteProjectCodeGen.h
        src/orm/codegen/java/JavaOracleProjectCodeGen.h

        src/orm/codegen/PostmanProjectCodeGen.h

        src/orm/codegen/php/PHPProjectCodeGen.h
        src/orm/codegen/php/PHPOracleProjectCodeGen.h
        src/orm/codegen/php/PHPMYSQLProjectCodeGen.h
        src/orm/codegen/php/PHPSQLiteProjectCodeGen.h

        src/orm/codegen/swift/SwiftProjectCodeGen.h

        src/orm/creators/ProjectCreator.h
        src/orm/creators/cpp/CppMYSQLProjectCreator.h
        src/orm/creators/cpp/CppOracleProjectCreator.h
        src/orm/creators/cpp/CppProjectCreator.h
        src/orm/creators/cpp/CppSQLiteProjectCreator.h
        src/orm/creators/java/JavaMYSQLProjectCreator.h
        src/orm/creators/java/JavaOracleProjectCreator.h
        src/orm/creators/java/JavaSQLiteProjectCreator.h
        src/orm/creators/swift/SwiftSQLiteProjectCreator.h
        src/orm/creators/swift/SwiftOracleProjectCreator.h
        src/orm/creators/swift/SwiftMYSQLProjectCreator.h
        src/orm/creators/php/LaravelPHPMYSQLProjectCreator.h
        src/orm/creators/php/PHPMYSQLProjectCreator.h

        src/orm/parsers/SyntaxParser.h
        src/orm/parsers/cpp/CppMYSQLParser.h
        src/orm/parsers/cpp/CppMYSQLSCRUDParser.h

        src/orm/parsers/php/PHPParser.h
        src/orm/parsers/php/PHPMYSQLParser.h
        src/orm/parsers/php/LaravelParser.h

        src/orm/projects/AndroidProjectModel.h
        src/orm/projects/CppMYSQLProjectModel.h
        src/orm/projects/CppOracleProjectModel.h
        src/orm/projects/CppSQLiteProjectModel.h
        src/orm/projects/CppProjectModel.h
        src/orm/projects/JavaMYSQLProjectModel.h
        src/orm/projects/JavaOracleProjectModel.h
        src/orm/projects/JavaProjectModel.h
        src/orm/projects/JavaSQLiteProjectModel.h
        src/orm/projects/LaravelPHPMYSQLProjectModel.h
        src/orm/projects/PHPMYSQLProjectModel.h
        src/orm/projects/PHPOracleProjectModel.h
        src/orm/projects/PHPProjectModel.h
        src/orm/projects/PHPSQLiteProjectModel.h
        src/orm/projects/PostmanProjectModel.h
        src/orm/projects/ProjectModel.h
        src/orm/projects/SwiftProjectModel.h

        src/orm/templates/FileSourceCodeTemplate.h
        src/orm/templates/SourceCodeTemplate.h
        src/orm/templates/StringSourceCodeTemplate.h
        src/orm/templates/TemplateFiles.h

        src/orm/templates/android/AndroidContentProviderTemplate.h
        src/orm/templates/android/AndroidSQLiteOpenHelperTemplate.h

        src/orm/templates/cpp/CppClassTableModelTemplate.h
        src/orm/templates/cpp/CppCtorInitializersTemplate.h
        src/orm/templates/cpp/CppClassTemplate.h
        src/orm/templates/cpp/CppMYSQLConnectorTemplate.h
        src/orm/templates/cpp/CppOracleConnectorTemplate.h
        src/orm/templates/cpp/CppPropertyGetterTemplate.h
        src/orm/templates/cpp/CppPropertySetterTemplate.h
        src/orm/templates/cpp/CppPropertyGetterSetterTemplate.h
        src/orm/templates/cpp/CppClassTableSCRUDTemplate.h
        src/orm/templates/cpp/CppSQLiteConnectorTemplate.h
        src/orm/templates/cpp/CppStructTableColumnModelTemplate.h
        src/orm/templates/cpp/CppMYSQLTableInsertWithModelTemplate.h
        src/orm/templates/cpp/CppMYSQLTableDeleteWithModelTemplate.h
        src/orm/templates/cpp/CppMYSQLTableUpdateWithIDTemplate.h
        src/orm/templates/cpp/CppMYSQLTableQueryRecordsNativeTemplate.h
        src/orm/templates/cpp/CppMYSQLTableQueryRecordNativeTemplate.h
        src/orm/templates/cpp/CppMYSQLTableQueryRecordWithIDTemplate.h
        src/orm/templates/cpp/CppMYSQLTableQueryRecordWithModelTemplate.h
        src/orm/templates/cpp/CppMYSQLTableDeleteWithIDTemplate.h
        src/orm/templates/cpp/CppMYSQLTableDeleteWithNativeTemplate.h
        src/orm/templates/cpp/CppMYSQLTableInsertNativeTemplate.h
        src/orm/templates/cpp/CppMYSQLTableUpdateWithModelTemplate.h
        src/orm/templates/cpp/CppMYSQLTableUpdateWithNativeTemplate.h
        src/orm/templates/cpp/CppMYSQLTableQueryRecordsAllTemplate.h
        src/orm/templates/cpp/CppVariableTemplate.h
        src/orm/templates/cpp/CppTemplateFiles.h

        src/orm/templates/java/JavaOracleConnectorTemplate.h
        src/orm/templates/java/JavaMYSQLConnectorTemplate.h
        src/orm/templates/java/JavaSQLiteConnectorTemplate.h

        src/orm/templates/postman/PostmanCollectionTemplate.h
        src/orm/templates/postman/PostmanRequestTemplate.h
        src/orm/templates/postman/PostmanTemplateFiles.h
        src/orm/creators/postman/PostmanProjectCreator.h

        src/orm/templates/php/laravel/LaravelControllerTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodCreateTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodEditTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodDestoryTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodIndexTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodStoreTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodShowTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodUpdateTemplate.h
        src/orm/templates/php/laravel/LaravelPHPTemplateFiles.h
        src/orm/templates/php/laravel/LaravelModelTemplate.h
        src/orm/templates/php/laravel/LaravelTableRoutesApiTemplate.h
        src/orm/templates/php/laravel/LaravelRouteApiGetTemplate.h
        src/orm/templates/php/laravel/LaravelRouteApiDeleteTemplate.h
        src/orm/templates/php/laravel/LaravelRouteApiPutTemplate.h
        src/orm/templates/php/laravel/LaravelRouteApiPostTemplate.h
        src/orm/templates/php/laravel/LaravelRouteWebDeleteTemplate.h
        src/orm/templates/php/laravel/LaravelRouteWebGetTemplate.h
        src/orm/templates/php/laravel/LaravelRouteWebPostTemplate.h
        src/orm/templates/php/laravel/LaravelRouteWebPutTemplate.h
        src/orm/templates/php/laravel/LaravelTableWebRoutesTemplate.h
        src/orm/templates/php/laravel/LaravelRoutesWebTemplate.h
        src/orm/templates/php/laravel/LaravelRoutesApiTemplate.h

        src/orm/templates/php/PHPOracleConnectorTemplate.h
        src/orm/templates/php/PHPMYSQLConnectorTemplate.h
        src/orm/templates/php/PHPSQLiteConnectorTemplate.h

        src/orm/utils/ConnectorUtils.h
        src/orm/utils/DbCrudgenError.h
        src/orm/utils/StringUtils.h
        )

#GoogleTest
add_subdirectory(lib/test/googletest)
include_directories(lib/test/googletest/googletest/include)
include_directories(lib/test/googletest/googlemock/include)

#GoogleBenchmark
add_subdirectory(lib/benchmark/)

#Create executable
add_executable(dbcrudgen_cpp ${SOURCE_FILES})

#Link with GoogleTest
target_link_libraries(dbcrudgen_cpp gtest gtest_main pthread)

#Link with GoogleMock
target_link_libraries(dbcrudgen_cpp gmock gmock_main pthread)

#Link with GoogleBenchmark
target_link_libraries(dbcrudgen_cpp benchmark)

#Link SQLite3 libs
target_link_libraries(dbcrudgen_cpp sqlite3)

#Link MysqlCpp libs
target_link_libraries(dbcrudgen_cpp mysqlcppconn)

#Link the Oracle libs
target_link_libraries(dbcrudgen_cpp ${OCCI_LIBS})

#Copy the template resources
file(COPY res/templates DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

