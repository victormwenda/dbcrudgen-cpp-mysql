//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/22/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLESCHEMAOBJECTS_H
#define DBCRUDGEN_CPP_ORACLESCHEMAOBJECTS_H


#include "OracleObject.h"

namespace dbcrudgen {
    namespace db {
        namespace oracle {

            //
            // OracleSchemaObject
            // //
            class OracleSchemaObject : public OracleObject {
            public:
                struct Clusters {
                    constexpr static const char *NAME = "Clusters";
                };
                struct DatabaseLinks {
                    constexpr static const char *NAME = "DatabaseLinks";
                };
                struct DatabaseTriggers {
                    constexpr static const char *NAME = "DatabaseTriggers";
                };
                struct Dimensions {
                    constexpr static const char *NAME = "Dimensions";
                };
                struct ExternalProcedureLibraries {
                    constexpr static const char *NAME = "ExternalProcedureLibraries";
                };
                struct Indexes {
                    constexpr static const char *NAME = "Indexes";
                };
                struct IndexTypes {
                    constexpr static const char *NAME = "IndexTypes";
                };
                struct Java {
                    constexpr static const char *NAME = "Java";
                };
                struct JavaClasses {
                    constexpr static const char *NAME = "JavaClasses";
                };
                struct JavaResources {
                    constexpr static const char *NAME = "JavaResources";
                };
                struct JavaSources {
                    constexpr static const char *NAME = "JavaSources";
                };
                struct MaterializedViews {
                    constexpr static const char *NAME = "MaterializedViews";
                };
                struct MaterializedViewLogs {
                    constexpr static const char *NAME = "MaterializedViewLogs";
                };
                struct ObjectTables {
                    constexpr static const char *NAME = "ObjectTables";
                };
                struct ObjectTypes {
                    constexpr static const char *NAME = "ObjectTypes";
                };
                struct ObjectViews {
                    constexpr static const char *NAME = "ObjectViews";
                };
                struct Operators {
                    constexpr static const char *NAME = "Operators";
                };
                struct Sequences {
                    constexpr static const char *NAME = "Sequences";
                };
                struct StoredFunctions {
                    constexpr static const char *NAME = "StoredFunctions";
                };
                struct StoredProcedures {
                    constexpr static const char *NAME = "StoredProcedures";
                };
                struct StoredPackages {
                    constexpr static const char *NAME = "StoredPackages";
                };
                struct Synonyms {
                    constexpr static const char *NAME = "Synonyms";
                };
                struct IndexTables {
                    constexpr static const char *NAME = "IndexTables";
                };
                struct OrganizedIndexTables {
                    constexpr static const char *NAME = "OrganizedIndexTables";
                };
                struct Views {
                    constexpr static const char *NAME = "Views";
                };
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLESCHEMAOBJECTS_H
