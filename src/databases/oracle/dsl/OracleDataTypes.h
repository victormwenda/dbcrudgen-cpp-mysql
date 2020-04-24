//
// Created by vrwanda on 10/30/19.
//

#ifndef DBCRUDGEN_CPP_ORACLEDATATYPES_H
#define DBCRUDGEN_CPP_ORACLEDATATYPES_H

namespace dbcrudgen {
    namespace db {
        namespace oracle {
            class OracleDataTypes {
            public:
                enum DataType {
                    INTERNAL, EXTERNAL
                };
                struct BFILE {
                    const char *NAME = "BFILE";
                    const int CODE = 114;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };

                struct NCHAR {
                    const char *NAME = "NCHAR";
                    const int CODE = 96;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };

                struct INTERVAL_DAY_TO_SECOND_REF {
                    const char *NAME = "INTERVAL DAY TO SECOND REF";
                    const int CODE = 183;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };
                struct INTERVAL_YEAR_TO_MONTH_REF {
                    const char *NAME = "INTERVAL YEAR TO MONTH REF";
                    const int CODE = 182;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };


                struct REF_BLOB {
                    const char *NAME = "REF BLOB";
                    const int CODE = 113;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };
                struct REF_CLOB {
                    const char *NAME = "REF CLOB";
                    const int CODE = 112;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };
                struct REF_NCLOB {
                    const char *NAME = "REF NCLOB";
                    const int CODE = 112;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };

                struct UROWID {
                    const char *NAME = "UROWID";
                    const int CODE = 208;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };
                struct VARRAY {
                    const char *NAME = "VARRAY";
                    const int CODE = 108;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };

                struct NVARCHAR2 {
                    const char *NAME = "NVARCHAR2";
                    const int CODE = 1;
                    const char *CPP_DATA_TYPE = "";
                    const char *OCCI_TYPE = "";
                    const DataType TYPE = INTERNAL;
                };
                struct Binary_FILE {
                    const char *NAME = "Binary FILE";
                    const int CODE = 114;
                    const char *CPP_DATA_TYPE = "LNOCILobLocator";
                    const char *OCCI_TYPE = "OCCI_SQLT_FILE";
                    const DataType TYPE = EXTERNAL;
                };
                struct Binary_LOB {
                    const char *NAME = "Binary LOB";
                    const int CODE = 113;
                    const char *CPP_DATA_TYPE = "LNOCILobLocator";
                    const char *OCCI_TYPE = "OCCI_SQLT_BLOB";
                    const DataType TYPE = EXTERNAL;
                };
                struct CHAR {
                    const char *NAME = "CHAR";
                    const int CODE = 96;
                    const char *CPP_DATA_TYPE = "char[n]";
                    const char *OCCI_TYPE = "OCCI_SQLT_AFC";
                    const DataType TYPE = EXTERNAL;
                };

                struct Character_LOB {
                    const char *NAME = "Character LOB";
                    const int CODE = 112;
                    const char *CPP_DATA_TYPE = "LNOCILobLocator";
                    const char *OCCI_TYPE = "OCCI_SQLT_CLOB";
                    const DataType TYPE = EXTERNAL;
                };
                struct CHARZ {
                    const char *NAME = "CHARZ";
                    const int CODE = 97;
                    const char *CPP_DATA_TYPE = "char[n+1]";
                    const char *OCCI_TYPE = "OCCI_SQLT_RDD";
                    const DataType TYPE = EXTERNAL;
                };
                struct DATE {
                    const char *NAME = "DATE";
                    const int CODE = 12;
                    const char *CPP_DATA_TYPE = "char[7]";
                    const char *OCCI_TYPE = "OCCI_SQLT_DAT";
                    const DataType TYPE = EXTERNAL;
                };

                struct FLOAT {
                    const char *NAME = "FLOAT";
                    const int CODE = 4;
                    const char *CPP_DATA_TYPE = "float, double";
                    const char *OCCI_TYPE = "OCCIFLOAT";
                    const DataType TYPE = EXTERNAL;
                };

                struct INTEGER_16 {
                    const char *NAME = "16 bit signed INTEGER";
                    const int CODE = 3;
                    const char *CPP_DATA_TYPE = "signed short, signed int";
                    const char *OCCI_TYPE = "OCCIINT";
                    const DataType TYPE = EXTERNAL;
                };
                struct INTEGER_32 {
                    const char *NAME = "32 bit signed INTEGER";
                    const int CODE = 3;
                    const char *CPP_DATA_TYPE = "signed int, signed long";
                    const char *OCCI_TYPE = "OCCIINT";
                    const DataType TYPE = EXTERNAL;
                };
                struct INTEGER_8 {
                    const char *NAME = "signed char";
                    const int CODE = 3;
                    const char *CPP_DATA_TYPE = "signed char";
                    const char *OCCI_TYPE = "OCCIINT";
                    const DataType TYPE = EXTERNAL;
                };
                struct INTERVAL_DAY_TO_SECOND {
                    const char *NAME = "INTERVAL DAY TO SECOND";
                    const int CODE = 190;
                    const char *CPP_DATA_TYPE = "char[11]";
                    const char *OCCI_TYPE = "OCCI_SQLT_INTERVAL_DS";
                    const DataType TYPE = EXTERNAL;
                };
                struct INTERVAL_YEAR_TO_MONTH {
                    const char *NAME = "INTERVAL YEAR TO MONTH";
                    const int CODE = 189;
                    const char *CPP_DATA_TYPE = "char[5]";
                    const char *OCCI_TYPE = "OCCI_SQLT_INTERVAL_YM";
                    const DataType TYPE = EXTERNAL;
                };
                struct LONG {
                    const char *NAME = "LONG";
                    const int CODE = 8;
                    const char *CPP_DATA_TYPE = "char[n]";
                    const char *OCCI_TYPE = "OCCI_SQLT_LNG";
                    const DataType TYPE = EXTERNAL;
                };
                struct LONG_RAW {
                    const char *NAME = "LONG RAW";
                    const int CODE = 24;
                    const char *CPP_DATA_TYPE = "unsigned char[n]";
                    const char *OCCI_TYPE = "OCCI_SQLT_LBI";
                    const DataType TYPE = EXTERNAL;
                };
                struct LONG_VARCHAR {
                    const char *NAME = "LONG VARCHAR";
                    const int CODE = 94;
                    const char *CPP_DATA_TYPE = "char[n+sizeof(integer)]";
                    const char *OCCI_TYPE = "OCCI_SQLT_LVC";
                    const DataType TYPE = EXTERNAL;
                };
                struct LONG_VARRAW {
                    const char *NAME = "LONG VARRAW";
                    const int CODE = 95;
                    const char *CPP_DATA_TYPE = "unsigned char[n+sizeof(integer)]";
                    const char *OCCI_TYPE = "OCCI_SQLT_LVB";
                    const DataType TYPE = EXTERNAL;
                };
                struct NAMED_DATA_TYPE {
                    const char *NAME = "NAMED DATA TYPE";
                    const int CODE = 108;
                    const char *CPP_DATA_TYPE = "struct";
                    const char *OCCI_TYPE = "OCCI_SQLT_NTY";
                    const DataType TYPE = EXTERNAL;
                };

                struct NUMBER {
                    const char *NAME = "NUMBER";
                    const int CODE = 2;
                    const char *CPP_DATA_TYPE = "unsigned char[21]";
                    const char *OCCI_TYPE = "OCCI_SQLT_NUM";
                    const DataType TYPE = EXTERNAL;
                };
                struct RAW {
                    const char *NAME = "RAW";
                    const int CODE = 23;
                    const char *CPP_DATA_TYPE = "unsigned char[n]";
                    const char *OCCI_TYPE = "OCCI_SQLT_BIN";
                    const DataType TYPE = EXTERNAL;
                };
                struct REF {
                    const char *NAME = "REF";
                    const int CODE = 110;
                    const char *CPP_DATA_TYPE = "LNOCIRef";
                    const char *OCCI_TYPE = "OCCI_SQLT_REF";
                    const DataType TYPE = EXTERNAL;
                };
                struct ROWID {
                    const char *NAME = "ROWID";
                    const int CODE = 11;
                    const char *CPP_DATA_TYPE = "LNOCIRowid";
                    const char *OCCI_TYPE = "OCCI_SQLT_RID";
                    const DataType TYPE = EXTERNAL;
                };
                struct ROWID_descriptor {
                    const char *NAME = "ROWID descriptor";
                    const int CODE = 104;
                    const char *CPP_DATA_TYPE = "LNOCIRowid";
                    const char *OCCI_TYPE = "OCCI_SQLT_RDD";
                    const DataType TYPE = EXTERNAL;
                };

                struct STRING {
                    const char *NAME = "null-terminated STRING";
                    const int CODE = 5;
                    const char *CPP_DATA_TYPE = "char[n+1]";
                    const char *OCCI_TYPE = "OCCI_SQLT_STR";
                    const DataType TYPE = EXTERNAL;
                };
                struct TIMESTAMP {
                    const char *NAME = "TIMESTAMP";
                    const int CODE = 187;
                    const char *CPP_DATA_TYPE = "char[11]";
                    const char *OCCI_TYPE = "OCCI_SQLT_TIMESTAMP";
                    const DataType TYPE = EXTERNAL;
                };
                struct TIMESTAMP_WITH_LOCAL_TIME_ZONE {
                    const char *NAME = "TIMESTAMP WITH LOCAL TIME ZONE";
                    const int CODE = 232;
                    const char *CPP_DATA_TYPE = "char[7]";
                    const char *OCCI_TYPE = "OCCI_SQLT_TIMESTAMP_LTZ";
                    const DataType TYPE = EXTERNAL;
                };
                struct TIMESTAMP_WITH_TIME_ZONE {
                    const char *NAME = "TIMESTAMP WITH TIME ZONE";
                    const int CODE = 188;
                    const char *CPP_DATA_TYPE = "char[13]";
                    const char *OCCI_TYPE = "OCCI_SQLT_TIMESTAMP_TZ";
                    const DataType TYPE = EXTERNAL;
                };
                struct UNSIGNED_INT {
                    const char *NAME = "UNSIGNED INT";
                    const int CODE = 68;
                    const char *CPP_DATA_TYPE = "unsigned";
                    const char *OCCI_TYPE = "OCCIUNSIGNED_INT";
                    const DataType TYPE = EXTERNAL;
                };
                struct VARCHAR {
                    const char *NAME = "VARCHAR";
                    const int CODE = 9;
                    const char *CPP_DATA_TYPE = "char[n+sizeof(short integer)]";
                    const char *OCCI_TYPE = "OCCI_SQLT_VCS";
                    const DataType TYPE = EXTERNAL;
                };
                struct VARCHAR2 {
                    const char *NAME = "VARCHAR2";
                    const int CODE = 1;
                    const char *CPP_DATA_TYPE = "char[n]";
                    const char *OCCI_TYPE = "OCCI_SQLT_CHR";
                    const DataType TYPE = EXTERNAL;
                };
                struct VARNUM {
                    const char *NAME = "VARNUM";
                    const int CODE = 6;
                    const char *CPP_DATA_TYPE = "char[22]";
                    const char *OCCI_TYPE = "OCCI_SQLT_VNU";
                    const DataType TYPE = EXTERNAL;
                };
                struct VARRAW {
                    const char *NAME = "VARRAW";
                    const int CODE = 15;
                    const char *CPP_DATA_TYPE = "unsigned char[n+sizeof(short integer)]";
                    const char *OCCI_TYPE = "OCCI_SQLT_VBI";
                    const DataType TYPE = EXTERNAL;
                };
            };

        }
    }
}
#endif //DBCRUDGEN_CPP_ORACLEDATATYPES_H

