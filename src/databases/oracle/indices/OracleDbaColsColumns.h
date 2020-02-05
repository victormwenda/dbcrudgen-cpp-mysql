//
// Created by vrwanda on 11/22/19.
//

#ifndef DBCRUDGEN_CPP_ORACLEDBACOLSCOLUMNS_H
#define DBCRUDGEN_CPP_ORACLEDBACOLSCOLUMNS_H

class OracleDbaColsColumns {
public:
    struct OWNER {
        static constexpr const int INDEX = 1;
    };
    struct TABLE_NAME {
        static constexpr const int INDEX = 2;
    };
    struct COLUMN_NAME {
        static constexpr const int INDEX = 3;
    };
    struct DATA_TYPE {
        static constexpr const int INDEX = 4;
    };
    struct DATA_TYPE_MOD {
        static constexpr const int INDEX = 5;
    };
    struct DATA_TYPE_OWNER {
        static constexpr const int INDEX = 6;
    };
    struct DATA_LENGTH {
        static constexpr const int INDEX = 7;
    };
    struct DATA_PRECISION {
        static constexpr const int INDEX = 8;
    };
    struct DATA_SCALE {
        static constexpr const int INDEX = 9;
    };
    struct NULLABLE {
        static constexpr const int INDEX = 10;
    };
    struct COLUMN_ID {
        static constexpr const int INDEX = 11;
    };
    struct DEFAULT_LENGTH {
        static constexpr const int INDEX = 12;
    };
    struct DATA_DEFAULT {
        static constexpr const int INDEX = 13;
    };
    struct NUM_DISTINCT {
        static constexpr const int INDEX = 14;
    };
    struct LOW_VALUE {
        static constexpr const int INDEX = 15;
    };
    struct HIGH_VALUE {
        static constexpr const int INDEX = 16;
    };
    struct DENSITY {
        static constexpr const int INDEX = 17;
    };
    struct NUM_NULLS {
        static constexpr const int INDEX = 18;
    };
    struct NUM_BUCKETS {
        static constexpr const int INDEX = 19;
    };
    struct LAST_ANALYZED {
        static constexpr const int INDEX = 20;
    };
    struct SAMPLE_SIZE {
        static constexpr const int INDEX = 21;
    };
    struct CHARACTER_SET_NAME {
        static constexpr const int INDEX = 22;
    };
    struct CHAR_COL_DECL_LENGTH {
        static constexpr const int INDEX = 23;
    };
    struct GLOBAL_STATS {
        static constexpr const int INDEX = 24;
    };
    struct USER_STATS {
        static constexpr const int INDEX = 25;
    };
    struct AVG_COL_LEN {
        static constexpr const int INDEX = 26;
    };
    struct CHAR_LENGTH {
        static constexpr const int INDEX = 27;
    };
    struct CHAR_USED {
        static constexpr const int INDEX = 28;
    };
    struct V80_FMT_IMAGE {
        static constexpr const int INDEX = 29;
    };
    struct DATA_UPGRADED {
        static constexpr const int INDEX = 30;
    };
    struct HIDDEN_COLUMN {
        static constexpr const int INDEX = 31;
    };
    struct VIRTUAL_COLUMN {
        static constexpr const int INDEX = 32;
    };
    struct SEGMENT_COLUMN_ID {
        static constexpr const int INDEX = 33;
    };
    struct INTERNAL_COLUMN_ID {
        static constexpr const int INDEX = 34;
    };
    struct HISTOGRAM {
        static constexpr const int INDEX = 35;
    };
    struct QUALIFIED_COL_NAME {
        static constexpr const int INDEX = 36;
    };
};

#endif //DBCRUDGEN_CPP_ORACLEDBACOLSCOLUMNS_H

