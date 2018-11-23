//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/23/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLETABLECOLUMN_H
#define DBCRUDGEN_CPP_ORACLETABLECOLUMN_H


#include <string>

//
// OracleTableColumn
// //
class OracleTableColumn {
public:

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
    std::string histogram;

    OracleTableColumn(std::string table_name, std::string column_name, std::string data_type,
                      std::string data_type_mod, std::string data_type_owner, int data_length,
                      int data_precision, int data_scale, std::string nullable, int column_id,
                      std::string default_length, std::string data_default, int num_distinct,
                      std::string low_value, std::string high_value, int density, int num_nulls,
                      int num_buckets, std::string last_analyzed, int sample_size,
                      std::string character_set_name, std::string char_col_decl_length,
                      std::string global_stats, std::string user_stats, int avg_col_len, int char_length,
                      std::string char_used, std::string v80_fmt_image, std::string data_upgraded,
                      std::string histogram) : table_name(table_name), column_name(column_name),
                                               data_type(data_type), data_type_mod(data_type_mod),
                                               data_type_owner(data_type_owner), data_length(data_length),
                                               data_precision(data_precision), data_scale(data_scale),
                                               nullable(nullable), column_id(column_id),
                                               default_length(default_length), data_default(data_default),
                                               num_distinct(num_distinct), low_value(low_value),
                                               high_value(high_value), density(density), num_nulls(num_nulls),
                                               num_buckets(num_buckets), last_analyzed(last_analyzed),
                                               sample_size(sample_size), character_set_name(character_set_name),
                                               char_col_decl_length(char_col_decl_length),
                                               global_stats(global_stats), user_stats(user_stats),
                                               avg_col_len(avg_col_len), char_length(char_length),
                                               char_used(char_used), v80_fmt_image(v80_fmt_image),
                                               data_upgraded(data_upgraded), histogram(histogram) {}

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


#endif //DBCRUDGEN_CPP_ORACLETABLECOLUMN_H
