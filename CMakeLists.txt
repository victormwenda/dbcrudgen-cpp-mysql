#Cmake version
cmake_minimum_required(VERSION 3.24.2)

#Project name
project(dbcrudgen_cpp_mysql)

#Project path
set(PROJECT_DIR ${PROJECT_SOURCE_DIR}) #Replace with the path to your project

set(SYS_ARCH ${CMAKE_SYSTEM_PROCESSOR})

#Set build type
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MESSAGE_LOG_LEVEL Debug)

#-----------------------------------------------------------------------------------------------------------------------
# LINKER FLAGS
#-----------------------------------------------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 11)


# MYSQL CONFIGURATIONS -------------------------------------------------------------------------------------------------
set(MYSQL_HEADERS "")

# OTHER LIBS  ----------------------------------------------------------------------------------------------------------
set(OTHER_LIBS_PATH "")

#-----------------------------------------------------------------------------------------------------------------------
# WINDOWS BUILD ENVIRONMENT
#-----------------------------------------------------------------------------------------------------------------------

if (WIN32)

    # ------------------------------------ MYSQL ----------------------------------------------------------------------#

    set(MYSQL_HEADERS ${PROJECT_DIR}/include/db-conn/windows/mysql/c++-8.0.31-winx64/include/jdbc)
    set(MYSQL_LIBS_DIR ${PROJECT_DIR}/include/db-conn/windows/mysql/c++-8.0.31-winx64/lib64)
    set(MYSQL_LIBS ${MYSQL_LIBS_DIR}/mysqlcppconn8-2-vs14.dll ${MYSQL_LIBS_DIR}/libssl-1_1-x64.dll ${MYSQL_LIBS_DIR}/libcrypto-1_1-x64.dll)

endif (WIN32)

#-----------------------------------------------------------------------------------------------------------------------
# LINUX BUILD ENVIRONMENT
#-----------------------------------------------------------------------------------------------------------------------


if (UNIX)

    set(OTHER_LIBS_PATH ${PROJECT_DIR}/lib/linux/others/)


    # ------------------------------------ MYSQL ----------------------------------------------------------------------#

    set(MYSQL_HEADERS)
    set(MYSQL_LIBS_DIR)
    set(MYSQL_LIBS)

    if (${SYS_ARCH} STREQUAL "x86_64")
        set(MYSQL_HEADERS ${PROJECT_DIR}/include/db-conn/linux/mysql/mysql-connector-c++-8.0.32-linux-glibc2.28-x86-64bit/include/jdbc)
        #set(MYSQL_LIBS_DIR ${PROJECT_DIR}/lib/linux/mysql/mysql-connector-c++-8.0.32-linux-glibc2.28-x86-64bit/lib64)
        #set(MYSQL_LIBS ${OTHER_LIBS_PATH}/x86-64/libmysqlclient.so.21.2.32 ${OTHER_LIBS_PATH}/x86-64/libcrypto.so.1.1 ${MYSQL_LIBS_DIR}/libmysqlcppconn8-static.a)
        set(MYSQL_LIBS mysqlcppconn)
    endif ()
    if (${SYS_ARCH} STREQUAL "aarch64")
        set(MYSQL_HEADERS ${PROJECT_DIR}/include/db-conn/linux/mysql/mysql-connector-c++-8.0.32-linux-glibc2.28-aarch64/include/jdbc)
        set(MYSQL_LIBS_DIR ${PROJECT_DIR}/lib/linux/mysql/mysql-connector-c++-8.0.32-linux-glibc2.28-aarch64/lib64)
        set(MYSQL_LIBS ${MYSQL_LIBS_DIR}/libmysqlcppconn8-static.a)
    endif ()

endif (UNIX)

#-----------------------------------------------------------------------------------------------------------------------
# MACOS BUILD ENVIRONMENT
#-----------------------------------------------------------------------------------------------------------------------

if (APPLE)

    # MYSQL
    set(MYSQL_HEADERS ${PROJECT_DIR}/include/macos/mysql-connector-c++-8.0.30-macos12-arm64/include/jdbc)
    set(MYSQL_LIBS_DIR ${PROJECT_DIR}/include/macos/mysql-connector-c++-8.0.30-macos12-arm64/lib64)
    set(MYSQL_LIBS ${MYSQL_LIBS_DIR}/libmysqlcppconn.dylib)

endif (APPLE)

#-----------------------------------------------------------------------------------------------------------------------
# ALL CONFIGURATIONS
#-----------------------------------------------------------------------------------------------------------------------

# MYSQL CONFIGURATIONS
include_directories(${MYSQL_HEADERS})

#-----------------------------------------------------------------------------------------------------------------------
# SOURCE FILES
#-----------------------------------------------------------------------------------------------------------------------

set(SOURCE_FILES

        src/main.cpp

        src/databases/generic/Column.h
        src/databases/generic/Connection.h
        src/databases/generic/Database.h
        src/databases/generic/Flavor.h
        src/databases/generic/Table.h
        src/databases/generic/User.h


        ##############################################################################################################
        # MySQL DATABASE SOURCE FILES
        ##############################################################################################################
        src/databases/mysql/builder/MYSQLDatabaseModelBuilder.h

        src/databases/mysql/core/MYSQLIdentifierLengthLimits.h
        src/databases/mysql/core/MYSQLObjects.h
        src/databases/mysql/core/MYSQLKeyWords.h
        src/databases/mysql/core/MYSQLReservedWords.h
        src/databases/mysql/core/RowFormats.h
        src/databases/mysql/core/MYSQLDataType.h


        src/databases/mysql/connectors/MYSQLDatabaseConnectionParams.h
        src/databases/mysql/connectors/MYSQLDatabaseConnector.h
        src/databases/mysql/connectors/MYSQLQueryExecutor.h

        src/databases/mysql/decomposer/MYSQLDatabasePreparedDecomposer.h
        src/databases/mysql/decomposer/MYSQLDatabaseDecomposer.h

        src/databases/mysql/exceptions/MYSQLDatabaseException.h

        src/databases/mysql/models/DataType.h
        src/databases/mysql/models/MYSQLDatabaseModel.h
        src/databases/mysql/models/MYSQLDatabaseConnectionModel.h

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


        ##############################################################################################################
        # SQL GENERIC SOURCE FILES
        ##############################################################################################################
        src/databases/sql/columns/TableColumn.h

        src/databases/sql/connectors/DatabaseConnector.h
        src/databases/sql/connectors/DatabaseConnection.h

        src/databases/sql/dsl/DataType.h

        src/databases/sql/exceptions/DatabaseError.h

        src/databases/sql/models/SQLDatabaseSchemas.h
        src/databases/sql/models/DatabaseSchemas.h
        src/databases/sql/models/DatabaseTable.h

        src/databases/sql/parsers/Tags.h

        src/databases/utils/DatabaseUtils.h

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

        src/orm/codegen/java/JavaProjectCodeGen.h
        src/orm/codegen/java/JavaMYSQLProjectCodeGen.h
        src/orm/codegen/java/JaxbCodeGen.h
        src/orm/codegen/java/jax-rs/JaxRsWebXMLCodeGen.h
        src/orm/codegen/java/jax-rs/JaxRSWebApplicationCodeGen.h
        src/orm/codegen/java/jax-rs/JaxRsAPIResourcesCodeGen.h
        src/orm/codegen/java/hibernate/HibernateAbstractableTransactionsCodeGen.h
        src/orm/codegen/java/hibernate/HibernateTransactionsCodeGen.h
        src/orm/codegen/java/hibernate/HibernateEntitiyCodeGen.h
        src/orm/codegen/java/hibernate/HibernateConfigCodeGen.h
        src/orm/codegen/java/spring-boot/SpringBootApplicationCodeGen.h
        src/orm/codegen/java/spring-boot/SpringBootControllerCodeGen.h
        src/orm/codegen/java/spring-boot/SpringBootHttpErrorCodeGen.h
        src/orm/codegen/java/spring-boot/SpringBootHttpCodeGen.h
        src/orm/codegen/java/spring-boot/SpringBootRepoCodeGen.h
        src/orm/codegen/java/spring-boot/SpringBootServiceDbCodeGen.h
        src/orm/codegen/java/spring-boot/SpringBootServiceBzLogicCodeGen.h

        src/orm/codegen/postman/PostmanProjectCodeGen.h

        src/orm/codegen/php/PHPProjectCodeGen.h
        src/orm/codegen/php/PHPMYSQLProjectCodeGen.h

        src/orm/codegen/swift/SwiftProjectCodeGen.h

        src/orm/creators/ProjectCreator.h

        src/orm/creators/angular/AngularProjectCreator.h

        src/orm/creators/cpp/CppMYSQLProjectCreator.h
        src/orm/creators/cpp/CppProjectCreator.h

        src/orm/creators/java/JavaMYSQLProjectCreator.h
        src/orm/creators/java/JavaProjectCreator.h

        src/orm/creators/java/JaxRsProjectCreator.h
        src/orm/creators/java/JaxWsProjectCreator.h
        src/orm/creators/java/SpringBootProjectCreator.h

        src/orm/creators/php/LaravelProjectCreator.h
        src/orm/creators/php/PHPProjectCreator.h
        src/orm/creators/php/PHPMYSQLProjectCreator.h
        src/orm/creators/postman/PostmanProjectCreator.h

        src/orm/creators/swift/SwiftMYSQLProjectCreator.h

        src/orm/dslmodels/java/springboot/SpringProjectDirs.h
        src/orm/dslmodels/java/springboot/SpringProjectPackages.h
        src/orm/dslmodels/java/springboot/SpringProjectClasses.h
        src/orm/dslmodels/java/springboot/SpringProjectSuffixes.h

        src/orm/parsers/SyntaxParser.h
        src/orm/parsers/cpp/CppMYSQLParser.h

        src/orm/parsers/angular/AngularParser.h

        src/orm/parsers/cpp/CppMYSQLSCRUDParser.h

        src/orm/parsers/java/HibernateAbstractableTransactionsParser.h
        src/orm/parsers/java/HibernateConfigurationParser.h
        src/orm/parsers/java/HibernateEntitiesParser.h
        src/orm/parsers/java/HibernateTransactionsParser.h
        src/orm/parsers/java/HibernateParser.h
        src/orm/parsers/java/JavaParser.h
        src/orm/parsers/java/JaxbParser.h
        src/orm/parsers/java/JaxRsResourcesParser.h
        src/orm/parsers/java/JaxRsWebXMLParser.h
        src/orm/parsers/java/JaxRsWebApplicationParser.h
        src/orm/parsers/java/SpringBootApplicationParser.h
        src/orm/parsers/java/SpringBootControllerParser.h

        src/orm/parsers/php/PHPParser.h
        src/orm/parsers/php/PHPMYSQLParser.h
        src/orm/parsers/php/LaravelParser.h

        src/orm/projects/AndroidProjectModel.h

        src/orm/projects/AngularProjectModel.h

        src/orm/projects/CppMYSQLProjectModel.h
        src/orm/projects/CppProjectModel.h

        src/orm/projects/JavaMYSQLProjectModel.h
        src/orm/projects/JavaProjectModel.h

        src/orm/projects/JaxRsProjectModel.h
        src/orm/projects/JaxWsProjectModel.h

        src/orm/projects/LaravelProjectModel.h

        src/orm/projects/PHPMYSQLProjectModel.h
        src/orm/projects/PHPProjectModel.h
        src/orm/projects/PostmanProjectModel.h
        src/orm/projects/ProjectModel.h
        src/orm/projects/SwiftProjectModel.h

        src/orm/projects/SpringBootProjectModel.h

        src/orm/templates/FileSourceCodeTemplate.h
        src/orm/templates/SourceCodeTemplate.h
        src/orm/templates/StringSourceCodeTemplate.h
        src/orm/templates/TemplateFiles.h

        src/orm/templates/android/AndroidContentProviderTemplate.h

        src/orm/templates/angular/AngularClassTemplate.h
        src/orm/templates/angular/AngularClassTableModelTemplate.h
        src/orm/templates/angular/AngularComponentCssTemplate.h
        src/orm/templates/angular/AngularComponentHtmlTemplate.h
        src/orm/templates/angular/AngularComponentTemplate.h
        src/orm/templates/angular/AngularComponentSpecTemplate.h
        src/orm/templates/angular/AngularEnumTemplate.h
        src/orm/templates/angular/AngularHtmlFormInputTemplate.h
        src/orm/templates/angular/AngularHtmlFormTemplate.h
        src/orm/templates/angular/AngularHtmlTableBodyTemplate.h
        src/orm/templates/angular/AngularHtmlTableHeadTemplate.h
        src/orm/templates/angular/AngularHtmlTableTemplate.h
        src/orm/templates/angular/AngularModuleTemplate.h
        src/orm/templates/angular/AngularServiceTemplate.h
        src/orm/templates/angular/AngularServiceSpecTemplate.h
        src/orm/templates/angular/AngularTemplateFiles.h
        src/orm/templates/angular/AngularTextTemplates.h
        src/orm/templates/angular/AngularTsFormControlInitBindTemplate.h
        src/orm/templates/angular/AngularTsFormGroupInitBindTemplate.h

        src/orm/templates/cpp/CppClassTableModelTemplate.h
        src/orm/templates/cpp/CppCtorInitializersTemplate.h
        src/orm/templates/cpp/CppClassTemplate.h
        src/orm/templates/cpp/CppMYSQLConnectorTemplate.h
        src/orm/templates/cpp/CppPropertyGetterTemplate.h
        src/orm/templates/cpp/CppPropertySetterTemplate.h
        src/orm/templates/cpp/CppPropertyGetterSetterTemplate.h
        src/orm/templates/cpp/CppClassTableSCRUDTemplate.h
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

        src/orm/templates/java/JavaTemplateFiles.h
        src/orm/templates/java/JavaClassTemplate.h
        src/orm/templates/java/JavaMethodTemplate.h
        src/orm/templates/java/JavaVariableInstanceTemplate.h
        src/orm/templates/java/JavaVariableLocalTemplate.h
        src/orm/templates/java/JavaVariableStaticTemplate.h

        src/orm/templates/java/jax-b/JaxbClassTemplate.h
        src/orm/templates/java/jax-b/JaxbAttributeTemplate.h
        src/orm/templates/java/jax-b/JaxbElementTemplate.h

        src/orm/templates/java/jax-rs/JaxRsScriptWebXMLTemplate.h
        src/orm/templates/java/jax-rs/JaxRsClassWebApplicationTemplate.h

        src/orm/templates/java/crud/classic/JavaMYSQLConnectorTemplate.h

        src/orm/templates/java/crud/connections/JavaMYSQLConnectionStringTemplate.h

        src/orm/templates/java/crud/drivers/JavaMYSQLConnectionDriverTemplate.h

        src/orm/templates/java/crud/hibernate/HibernateClassConfigurationTemplate.h
        src/orm/templates/java/crud/hibernate/HibernateClassEntityTemplate.h
        src/orm/templates/java/crud/hibernate/HibernateClassTransactionsTemplate.h
        src/orm/templates/java/crud/hibernate/HibernateScriptConfigurationTemplate.h
        src/orm/templates/java/crud/hibernate/HibernateParameterEntityMappingTemplate.h

        src/orm/templates/java/JavaTemplateFiles.h
        src/orm/templates/java/JavaClassTemplate.h
        src/orm/templates/java/JavaGetterTemplate.h
        src/orm/templates/java/JavaGetterSetterTemplate.h
        src/orm/templates/java/JavaMethodTemplate.h
        src/orm/templates/java/JavaSetterTemplate.h
        src/orm/templates/java/JavaVariableInstanceTemplate.h
        src/orm/templates/java/JavaVariableLocalTemplate.h
        src/orm/templates/java/JavaVariableStaticTemplate.h

        src/orm/templates/java/crud/hibernate/HibernateClassAbstractableTransactionsTemplate.h
        src/orm/templates/java/jax-rs/JaxRsClassResourcesTemplate.h
        src/orm/templates/java/jax-rs/JaxRsMethodGetTemplate.h
        src/orm/templates/java/jax-rs/JaxRsMethodDeleteTemplate.h
        src/orm/templates/java/jax-rs/JaxRsMethodPostTemplate.h
        src/orm/templates/java/jax-rs/JaxRsMethodPutTemplate.h
        src/orm/templates/java/jax-ws/JaxWsClassResourcesTemplate.h

        src/orm/templates/java/spring-boot/SpringBootClassApplicationTemplate.h
        src/orm/templates/java/spring-boot/SpringBootClassControllerTemplate.h
        src/orm/templates/java/spring-boot/SpringBootClassHttpReqTemplate.h
        src/orm/templates/java/spring-boot/SpringBootClassHttpResTemplate.h
        src/orm/templates/java/spring-boot/SpringBootClassHttpResWithListTemplate.h
        src/orm/templates/java/spring-boot/SpringBootClassModelTemplate.h
        src/orm/templates/java/spring-boot/SpringBootClassRepoTemplate.h
        src/orm/templates/java/spring-boot/SpringBootClassServiceBusinessTemplate.h
        src/orm/templates/java/spring-boot/SpringBootClassServiceDaoTemplate.h
        src/orm/templates/java/spring-boot/SpringBootFileApplicationPropertiesTemplate.h
        src/orm/templates/java/spring-boot/SpringBootHttpErrorTemplate.h
        src/orm/templates/java/spring-boot/SpringBootWebErrorFileTemplate.h
        src/orm/templates/java/spring-boot/SpringBootWebFileIndexTemplate.h

        src/orm/templates/php/laravel/LaravelControllerTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodCreateTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodEditTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodDestoryTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodIndexTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodStoreTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodShowTemplate.h
        src/orm/templates/php/laravel/LaravelControllerMethodUpdateTemplate.h
        src/orm/templates/php/laravel/LaravelDataTableTemplate.h
        src/orm/templates/php/laravel/LaravelTemplateFiles.h
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
        src/orm/templates/php/laravel/LaravelRoutesWebTemplate.h
        src/orm/templates/php/laravel/LaravelRoutesApiTemplate.h
        src/orm/templates/php/laravel/LaravelTableCrudJSTemplate.h
        src/orm/templates/php/laravel/LaravelTableWebRoutesTemplate.h
        src/orm/templates/php/laravel/LaravelViewTemplate.h

        src/orm/templates/php/PHPMYSQLConnectorTemplate.h


        src/orm/templates/postman/PostmanCollectionTemplate.h
        src/orm/templates/postman/PostmanFolderTemplate.h
        src/orm/templates/postman/PostmanRequestBodyTemplate.h
        src/orm/templates/postman/PostmanRequestTemplate.h
        src/orm/templates/postman/PostmanTemplateFiles.h

        src/orm/utils/StringUtils.h)

#GoogleTest
#add_subdirectory(include/google/googletest)

#GoogleBenchmark
#add_subdirectory(include/google/benchmark)

#Create executable
add_executable(dbcrudgen_cpp_mysql ${SOURCE_FILES})

#-----------------------------------------------------------------------------------------------------------------------
# LIBRARY LINKING
#-----------------------------------------------------------------------------------------------------------------------

#Link with GoogleTest
#target_link_libraries(dbcrudgen_cpp_mysql gtest gtest_main pthread)

#Link with GoogleMock
#target_link_libraries(dbcrudgen_cpp_mysql gmock gmock_main pthread) - Disable Google Mock

#Link with GoogleBenchmark
#target_link_libraries(dbcrudgen_cpp_mysql benchmark) - Disable Google Benchmark

#Link MysqlCpp libs
target_link_libraries(dbcrudgen_cpp_mysql ${MYSQL_LIBS})

#Copy the template resources
file(COPY res/templates DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

