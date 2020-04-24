//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/22/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEOBJECTS_H
#define DBCRUDGEN_CPP_ORACLEOBJECTS_H

namespace dbcrudgen {
    namespace db {
        namespace oracle {

            //
            // OracleObject - https://docs.oracle.com/cd/B19306_01/server.102/b14220/schema.htm
            // //
            class OracleObject {
            public:

                struct CLUSTER {
                    constexpr static const char *NAME = "CLUSTER";
                };
                struct CONSUMER_GROUP {
                    constexpr static const char *NAME = "CONSUMER GROUP";
                };
                struct CONTEXT {
                    constexpr static const char *NAME = "CONTEXT";
                };
                struct DESTINATION {
                    constexpr static const char *NAME = "DESTINATION";
                };
                struct DIRECTORY {
                    constexpr static const char *NAME = "DIRECTORY";
                };
                struct EDITION {
                    constexpr static const char *NAME = "EDITION";
                };
                struct EVALUATION_CONTEXT {
                    constexpr static const char *NAME = "EVALUATION CONTEXT";
                };
                struct FUNCTION {
                    constexpr static const char *NAME = "FUNCTION";
                };
                struct INDEX_PARTITION {
                    constexpr static const char *NAME = "INDEX PARTITION";
                };
                struct INDEX {
                    constexpr static const char *NAME = "INDEX";
                };
                struct INDEXTYPE {
                    constexpr static const char *NAME = "INDEXTYPE";
                };
                struct JOB {
                    constexpr static const char *NAME = "JOB";
                };
                struct JOB_CLASS {
                    constexpr static const char *NAME = "JOB CLASS";
                };
                struct LIBRARY {
                    constexpr static const char *NAME = "LIBRARY";
                };
                struct OPERATOR {
                    constexpr static const char *NAME = "OPERATOR";
                };
                struct PACKAGE {
                    constexpr static const char *NAME = "PACKAGE";
                };
                struct PACKAGE_BODY {
                    constexpr static const char *NAME = "PACKAGE BODY";
                };
                struct PROCEDURE {
                    constexpr static const char *NAME = "PROCEDURE";
                };
                struct PROGRAM {
                    constexpr static const char *NAME = "PROGRAM";
                };
                struct RULE {
                    constexpr static const char *NAME = "RULE";
                };
                struct RULE_SET {
                    constexpr static const char *NAME = "RULE SET";
                };
                struct SCHEDULE {
                    constexpr static const char *NAME = "SCHEDULE";
                };
                struct SCHEDULER_GROUP {
                    constexpr static const char *NAME = "SCHEDULER GROUP";
                };
                struct SEQUENCE {
                    constexpr static const char *NAME = "SEQUENCE";
                };
                struct SYNONYM {
                    constexpr static const char *NAME = "SYNONYM";
                };
                struct TABLE {
                    constexpr static const char *NAME = "TABLE";
                };
                struct TABLE_PARTITION {
                    constexpr static const char *NAME = "TABLE PARTITION";
                };
                struct TABLE_SUBPARTITION {
                    constexpr static const char *NAME = "TABLE SUBPARTITION";
                };
                struct TRIGGER {
                    constexpr static const char *NAME = "TRIGGER";
                };
                struct TYPE {
                    constexpr static const char *NAME = "TYPE";
                };
                struct TYPE_BODY {
                    constexpr static const char *NAME = "TYPE BODY";
                };
                struct VIEW {
                    constexpr static const char *NAME = "VIEW";
                };
                struct WINDOW {
                    constexpr static const char *NAME = "WINDOW";
                };
                struct XML_SCHEMA {
                    constexpr static const char *NAME = "XML SCHEMA";
                };

            };
        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLEOBJECTS_H
