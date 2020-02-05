//
// Created by vrwanda on 11/22/19.
//

#ifndef DBCRUDGEN_CPP_ORACLETABLECOLSDBA_H
#define DBCRUDGEN_CPP_ORACLETABLECOLSDBA_H

#endif //DBCRUDGEN_CPP_ORACLETABLECOLSDBA_H

class OracleTAbleColsDba {
public:
    std::string owner;
    std::string table_name;
    std::string column_name;
    std::string data_type;
    std::string data_type_mod;
    std::string data_type_owner;
    int data_length;
    int data_precision;
    int data_scale;
    std::string nullable;
    int column_id;
    std::string default_length;
    std::string data_default;
    int num_distinct;
    std::string low_value;
    std::string high_value;
    int density;
    int num_nulls;
    int num_buckets;
    std::string last_analyzed;
    int sample_size;
    std::string character_set_name;
    std::string char_col_decl_length;
    std::string global_stats;
    std::string user_stats;
    int avg_col_len;
    int char_length;
    std::string char_used;
    std::string v80_fmt_image;
    std::string data_upgraded;
    std::string hidden_column;
    std::string virtual_column;
    int segment_column_id;
    int internal_column_id;
    std::string histogram;
    std::string qualified_col_name;

    OracleTAbleColsDba(const std::string &owner, const std::string &tableName, const std::string &columnName,
                       const std::string &dataType, const std::string &dataTypeMod, const std::string &dataTypeOwner,
                       int dataLength, int dataPrecision, int dataScale, const std::string &nullable, int columnId,
                       const std::string &defaultLength, const std::string &dataDefault, int numDistinct,
                       const std::string &lowValue, const std::string &highValue, int density, int numNulls,
                       int numBuckets, const std::string &lastAnalyzed, int sampleSize,
                       const std::string &characterSetName, const std::string &charColDeclLength,
                       const std::string &globalStats, const std::string &userStats, int avgColLen, int charLength,
                       const std::string &charUsed, const std::string &v80FmtImage, const std::string &dataUpgraded,
                       const std::string &hiddenColumn, const std::string &virtualColumn, int segmentColumnId,
                       int internalColumnId, const std::string &histogram, const std::string &qualifiedColName)
            : owner(owner), table_name(tableName), column_name(columnName), data_type(dataType),
              data_type_mod(dataTypeMod), data_type_owner(dataTypeOwner), data_length(dataLength),
              data_precision(dataPrecision), data_scale(dataScale), nullable(nullable), column_id(columnId),
              default_length(defaultLength), data_default(dataDefault), num_distinct(numDistinct), low_value(lowValue),
              high_value(highValue), density(density), num_nulls(numNulls), num_buckets(numBuckets),
              last_analyzed(lastAnalyzed), sample_size(sampleSize), character_set_name(characterSetName),
              char_col_decl_length(charColDeclLength), global_stats(globalStats), user_stats(userStats),
              avg_col_len(avgColLen), char_length(charLength), char_used(charUsed), v80_fmt_image(v80FmtImage),
              data_upgraded(dataUpgraded), hidden_column(hiddenColumn), virtual_column(virtualColumn),
              segment_column_id(segmentColumnId), internal_column_id(internalColumnId),
              histogram(histogram), qualified_col_name(qualifiedColName) {}

    std::string getOwner()   {
        return owner;
    }

    std::string getTable_name() {
        return table_name;
    }

    std::string getColumn_name() {
        return column_name;
    }

    std::string getData_type() {
        return data_type;
    }

    std::string getData_type_mod() {
        return data_type_mod;
    }

    std::string getData_type_owner() {
        return data_type_owner;
    }

    int getData_length() {
        return data_length;
    }

    int getData_precision() {
        return data_precision;
    }

    int getData_scale() {
        return data_scale;
    }

    std::string getNullable() {
        return nullable;
    }

    int getColumn_id() {
        return column_id;
    }

    std::string getDefault_length() {
        return default_length;
    }

    std::string getData_default() {
        return data_default;
    }

    int getNum_distinct() {
        return num_distinct;
    }

    std::string getLow_value() {
        return low_value;
    }

    std::string getHigh_value() {
        return high_value;
    }

    int getDensity() {
        return density;
    }

    int getNum_nulls() {
        return num_nulls;
    }

    int getNum_buckets() {
        return num_buckets;
    }

    std::string getLast_analyzed() {
        return last_analyzed;
    }

    int getSample_size() {
        return sample_size;
    }

    std::string getCharacter_set_name() {
        return character_set_name;
    }

    std::string getChar_col_decl_length() {
        return char_col_decl_length;
    }

    std::string getGlobal_stats() {
        return global_stats;
    }

    std::string getUser_stats() {
        return user_stats;
    }

    int getAvg_col_len() {
        return avg_col_len;
    }

    int getChar_length() {
        return char_length;
    }

    std::string getChar_used() {
        return char_used;
    }

    std::string getV80_fmt_image() {
        return v80_fmt_image;
    }

    std::string getData_upgraded() {
        return data_upgraded;
    }

    std::string getHistogram() {
        return histogram;
    }
};