//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/19/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEALLTABLESCOLUMNS_H
#define DBCRUDGEN_CPP_ORACLEALLTABLESCOLUMNS_H

namespace dbcrudgen {
    namespace db {
        namespace oracle {
            //
            // OracleAllTablesColumns
            //
            // SELECT * FROM ALL_TABLES;
            //
            class OracleAllTablesColumns {
            public:
                struct OWNER {
                    static const unsigned int INDEX = 1;
                };
                struct TABLE_NAME {
                    static const unsigned int INDEX = 2;
                };
                struct TABLESPACE_NAME {
                    static const unsigned int INDEX = 3;
                };
                struct CLUSTER_NAME {
                    static const unsigned int INDEX = 4;
                };
                struct IOT_NAME {
                    static const unsigned int INDEX = 5;
                };
                struct STATUS {
                    static const unsigned int INDEX = 6;
                };
                struct PCT_FREE {
                    static const unsigned int INDEX = 7;
                };
                struct PCT_USED {
                    static const unsigned int INDEX = 8;
                };
                struct INI_TRANS {
                    static const unsigned int INDEX = 9;
                };
                struct MAX_TRANS {
                    static const unsigned int INDEX = 10;
                };
                struct INITIAL_EXTENT {
                    static const unsigned int INDEX = 11;
                };
                struct NEXT_EXTENT {
                    static const unsigned int INDEX = 12;
                };
                struct MIN_EXTENTS {
                    static const unsigned int INDEX = 13;
                };
                struct MAX_EXTENTS {
                    static const unsigned int INDEX = 16;
                };
                struct PCT_INCREASE {
                    static const unsigned int INDEX = 15;
                };
                struct FREELISTS {
                    static const unsigned int INDEX = 16;
                };
                struct FREELIST_GROUPS {
                    static const unsigned int INDEX = 17;
                };
                struct LOGGING {
                    static const unsigned int INDEX = 18;
                };
                struct BACKED_UP {
                    static const unsigned int INDEX = 19;
                };
                struct NUM_ROWS {
                    static const unsigned int INDEX = 20;
                };
                struct BLOCKS {
                    static const unsigned int INDEX = 21;
                };
                struct EMPTY_BLOCKS {
                    static const unsigned int INDEX = 22;
                };
                struct AVG_SPACE {
                    static const unsigned int INDEX = 23;
                };
                struct CHAIN_CNT {
                    static const unsigned int INDEX = 24;
                };
                struct AVG_ROW_LEN {
                    static const unsigned int INDEX = 25;
                };
                struct AVG_SPACE_FREELIST_BLOCKS {
                    static const unsigned int INDEX = 26;
                };
                struct NUM_FREELIST_BLOCKS {
                    static const unsigned int INDEX = 27;
                };
                struct DEGREE {
                    static const unsigned int INDEX = 28;
                };
                struct INSTANCES {
                    static const unsigned int INDEX = 29;
                };
                struct CACHE {
                    static const unsigned int INDEX = 30;
                };
                struct TABLE_LOCK {
                    static const unsigned int INDEX = 31;
                };
                struct SAMPLE_SIZE {
                    static const unsigned int INDEX = 32;
                };
                struct LAST_ANALYZED {
                    static const unsigned int INDEX = 33;
                };
                struct PARTITIONED {
                    static const unsigned int INDEX = 34;
                };
                struct IOT_TYPE {
                    static const unsigned int INDEX = 35;
                };
                struct TEMPORARY {
                    static const unsigned int INDEX = 36;
                };
                struct SECONDARY {
                    static const unsigned int INDEX = 37;
                };
                struct NESTED {
                    static const unsigned int INDEX = 38;
                };
                struct BUFFER_POOL {
                    static const unsigned int INDEX = 39;
                };
                struct FLASH_CACHE {
                    static const unsigned int INDEX = 40;
                };
                struct CELL_FLASH_CACHE {
                    static const unsigned int INDEX = 41;
                };
                struct ROW_MOVEMENT {
                    static const unsigned int INDEX = 42;
                };
                struct GLOBAL_STATS {
                    static const unsigned int INDEX = 43;
                };
                struct USER_STATS {
                    static const unsigned int INDEX = 44;
                };
                struct DURATION {
                    static const unsigned int INDEX = 45;
                };
                struct SKIP_CORRUPT {
                    static const unsigned int INDEX = 46;
                };
                struct MONITORING {
                    static const unsigned int INDEX = 47;
                };
                struct CLUSTER_OWNER {
                    static const unsigned int INDEX = 48;
                };
                struct DEPENDENCIES {
                    static const unsigned int INDEX = 49;
                };
                struct COMPRESSION {
                    static const unsigned int INDEX = 50;
                };
                struct COMPRESS_FOR {
                    static const unsigned int INDEX = 51;
                };
                struct DROPPED {
                    static const unsigned int INDEX = 52;
                };
                struct READ_ONLY {
                    static const unsigned int INDEX = 53;
                };
                struct SEGMENT_CREATED {
                    static const unsigned int INDEX = 54;
                };
                struct RESULT_CACHE {
                    static const unsigned int INDEX = 55;
                };
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLEALLTABLESCOLUMNS_H
