//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/19/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEUSERTABLES_H
#define DBCRUDGEN_CPP_ORACLEUSERTABLES_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace oracle {
            //
            // OracleUserTables
            // //
            class OracleUserTables {

            public:
                std::string owner;
                std::string table_name;
                std::string tablespace_name;
                std::string cluster_name;
                std::string iot_name;
                std::string status;
                std::string pct_free;
                std::string pct_used;
                std::string ini_trans;
                std::string max_trans;
                std::string initial_extent;
                std::string next_extent;
                std::string min_extents;
                std::string max_extents;
                std::string pct_increase;
                std::string freelists;
                std::string freelist_groups;
                std::string logging;
                std::string backed_up;
                std::string num_rows;
                std::string blocks;
                std::string empty_blocks;
                std::string avg_space;
                std::string chain_cnt;
                std::string avg_row_len;
                std::string avg_space_freelist_blocks;
                std::string num_freelist_blocks;
                std::string degree;
                std::string instances;
                std::string cache;
                std::string table_lock;
                std::string sample_size;
                std::string last_analyzed;
                std::string partitioned;
                std::string iot_type;
                std::string temporary;
                std::string secondary;
                std::string nested;
                std::string buffer_pool;
                std::string flash_cache;
                std::string cell_flash_cache;
                std::string row_movement;
                std::string global_stats;
                std::string user_stats;
                std::string duration;
                std::string skip_corrupt;
                std::string monitoring;
                std::string cluster_owner;
                std::string dependencies;
                std::string compression;
                std::string compress_for;
                std::string dropped;
                std::string read_only;
                std::string segment_created;
                std::string result_cache;

                OracleUserTables(std::string owner, std::string table_name, std::string tablespace_name,
                                 std::string cluster_name, std::string iot_name, std::string status,
                                 std::string pct_free, std::string pct_used, std::string ini_trans,
                                 std::string max_trans, std::string initial_extent, std::string next_extent,
                                 std::string min_extents, std::string max_extents, std::string pct_increase,
                                 std::string freelists, std::string freelist_groups, std::string logging,
                                 std::string backed_up, std::string num_rows, std::string blocks,
                                 std::string empty_blocks, std::string avg_space, std::string chain_cnt,
                                 std::string avg_row_len, std::string avg_space_freelist_blocks,
                                 std::string num_freelist_blocks, std::string degree, std::string instances,
                                 std::string cache, std::string table_lock, std::string sample_size,
                                 std::string last_analyzed, std::string partitioned, std::string iot_type,
                                 std::string temporary, std::string secondary, std::string nested,
                                 std::string buffer_pool, std::string flash_cache,
                                 std::string cell_flash_cache, std::string row_movement,
                                 std::string global_stats, std::string user_stats, std::string duration,
                                 std::string skip_corrupt, std::string monitoring, std::string cluster_owner,
                                 std::string dependencies, std::string compression, std::string compress_for,
                                 std::string dropped, std::string read_only, std::string segment_created,
                                 std::string result_cache) : owner(owner), table_name(table_name),
                                                             tablespace_name(tablespace_name),
                                                             cluster_name(cluster_name),
                                                             iot_name(iot_name), status(status), pct_free(pct_free),
                                                             pct_used(pct_used), ini_trans(ini_trans),
                                                             max_trans(max_trans),
                                                             initial_extent(initial_extent), next_extent(next_extent),
                                                             min_extents(min_extents), max_extents(max_extents),
                                                             pct_increase(pct_increase), freelists(freelists),
                                                             freelist_groups(freelist_groups), logging(logging),
                                                             backed_up(backed_up), num_rows(num_rows), blocks(blocks),
                                                             empty_blocks(empty_blocks), avg_space(avg_space),
                                                             chain_cnt(chain_cnt), avg_row_len(avg_row_len),
                                                             avg_space_freelist_blocks(avg_space_freelist_blocks),
                                                             num_freelist_blocks(num_freelist_blocks), degree(degree),
                                                             instances(instances), cache(cache), table_lock(table_lock),
                                                             sample_size(sample_size), last_analyzed(last_analyzed),
                                                             partitioned(partitioned), iot_type(iot_type),
                                                             temporary(temporary), secondary(secondary), nested(nested),
                                                             buffer_pool(buffer_pool), flash_cache(flash_cache),
                                                             cell_flash_cache(cell_flash_cache),
                                                             row_movement(row_movement),
                                                             global_stats(global_stats), user_stats(user_stats),
                                                             duration(duration), skip_corrupt(skip_corrupt),
                                                             monitoring(monitoring), cluster_owner(cluster_owner),
                                                             dependencies(dependencies), compression(compression),
                                                             compress_for(compress_for), dropped(dropped),
                                                             read_only(read_only), segment_created(segment_created),
                                                             result_cache(result_cache) {}

                std::string getOwner() {
                    return owner;
                }

                void setOwner(std::string owner) {
                    OracleUserTables::owner = owner;
                }

                std::string getTable_name() {
                    return table_name;
                }

                void setTable_name(std::string table_name) {
                    OracleUserTables::table_name = table_name;
                }

                std::string getTablespace_name() {
                    return tablespace_name;
                }

                void setTablespace_name(std::string tablespace_name) {
                    OracleUserTables::tablespace_name = tablespace_name;
                }

                std::string getCluster_name() {
                    return cluster_name;
                }

                void setCluster_name(std::string cluster_name) {
                    OracleUserTables::cluster_name = cluster_name;
                }

                std::string getIot_name() {
                    return iot_name;
                }

                void setIot_name(std::string iot_name) {
                    OracleUserTables::iot_name = iot_name;
                }

                std::string getStatus() {
                    return status;
                }

                void setStatus(std::string status) {
                    OracleUserTables::status = status;
                }

                std::string getPct_free() {
                    return pct_free;
                }

                void setPct_free(std::string pct_free) {
                    OracleUserTables::pct_free = pct_free;
                }

                std::string getPct_used() {
                    return pct_used;
                }

                void setPct_used(std::string pct_used) {
                    OracleUserTables::pct_used = pct_used;
                }

                std::string getIni_trans() {
                    return ini_trans;
                }

                void setIni_trans(std::string ini_trans) {
                    OracleUserTables::ini_trans = ini_trans;
                }

                std::string getMax_trans() {
                    return max_trans;
                }

                void setMax_trans(std::string max_trans) {
                    OracleUserTables::max_trans = max_trans;
                }

                std::string getInitial_extent() {
                    return initial_extent;
                }

                void setInitial_extent(std::string initial_extent) {
                    OracleUserTables::initial_extent = initial_extent;
                }

                std::string getNext_extent() {
                    return next_extent;
                }

                void setNext_extent(std::string next_extent) {
                    OracleUserTables::next_extent = next_extent;
                }

                std::string getMin_extents() {
                    return min_extents;
                }

                void setMin_extents(std::string min_extents) {
                    OracleUserTables::min_extents = min_extents;
                }

                std::string getMax_extents() {
                    return max_extents;
                }

                void setMax_extents(std::string max_extents) {
                    OracleUserTables::max_extents = max_extents;
                }

                std::string getPct_increase() {
                    return pct_increase;
                }

                void setPct_increase(std::string pct_increase) {
                    OracleUserTables::pct_increase = pct_increase;
                }

                std::string getFreelists() {
                    return freelists;
                }

                void setFreelists(std::string freelists) {
                    OracleUserTables::freelists = freelists;
                }

                std::string getFreelist_groups() {
                    return freelist_groups;
                }

                void setFreelist_groups(std::string freelist_groups) {
                    OracleUserTables::freelist_groups = freelist_groups;
                }

                std::string getLogging() {
                    return logging;
                }

                void setLogging(std::string logging) {
                    OracleUserTables::logging = logging;
                }

                std::string getBacked_up() {
                    return backed_up;
                }

                void setBacked_up(std::string backed_up) {
                    OracleUserTables::backed_up = backed_up;
                }

                std::string getNum_rows() {
                    return num_rows;
                }

                void setNum_rows(std::string num_rows) {
                    OracleUserTables::num_rows = num_rows;
                }

                std::string getBlocks() {
                    return blocks;
                }

                void setBlocks(std::string blocks) {
                    OracleUserTables::blocks = blocks;
                }

                std::string getEmpty_blocks() {
                    return empty_blocks;
                }

                void setEmpty_blocks(std::string empty_blocks) {
                    OracleUserTables::empty_blocks = empty_blocks;
                }

                std::string getAvg_space() {
                    return avg_space;
                }

                void setAvg_space(std::string avg_space) {
                    OracleUserTables::avg_space = avg_space;
                }

                std::string getChain_cnt() {
                    return chain_cnt;
                }

                void setChain_cnt(std::string chain_cnt) {
                    OracleUserTables::chain_cnt = chain_cnt;
                }

                std::string getAvg_row_len() {
                    return avg_row_len;
                }

                void setAvg_row_len(std::string avg_row_len) {
                    OracleUserTables::avg_row_len = avg_row_len;
                }

                std::string getAvg_space_freelist_blocks() {
                    return avg_space_freelist_blocks;
                }

                void setAvg_space_freelist_blocks(std::string avg_space_freelist_blocks) {
                    OracleUserTables::avg_space_freelist_blocks = avg_space_freelist_blocks;
                }

                std::string getNum_freelist_blocks() {
                    return num_freelist_blocks;
                }

                void setNum_freelist_blocks(std::string num_freelist_blocks) {
                    OracleUserTables::num_freelist_blocks = num_freelist_blocks;
                }

                std::string getDegree() {
                    return degree;
                }

                void setDegree(std::string degree) {
                    OracleUserTables::degree = degree;
                }

                std::string getInstances() {
                    return instances;
                }

                void setInstances(std::string instances) {
                    OracleUserTables::instances = instances;
                }

                std::string getCache() {
                    return cache;
                }

                void setCache(std::string cache) {
                    OracleUserTables::cache = cache;
                }

                std::string getTable_lock() {
                    return table_lock;
                }

                void setTable_lock(std::string table_lock) {
                    OracleUserTables::table_lock = table_lock;
                }

                std::string getSample_size() {
                    return sample_size;
                }

                void setSample_size(std::string sample_size) {
                    OracleUserTables::sample_size = sample_size;
                }

                std::string getLast_analyzed() {
                    return last_analyzed;
                }

                void setLast_analyzed(std::string last_analyzed) {
                    OracleUserTables::last_analyzed = last_analyzed;
                }

                std::string getPartitioned() {
                    return partitioned;
                }

                void setPartitioned(std::string partitioned) {
                    OracleUserTables::partitioned = partitioned;
                }

                std::string getIot_type() {
                    return iot_type;
                }

                void setIot_type(std::string iot_type) {
                    OracleUserTables::iot_type = iot_type;
                }

                std::string getTemporary() {
                    return temporary;
                }

                void setTemporary(std::string temporary) {
                    OracleUserTables::temporary = temporary;
                }

                std::string getSecondary() {
                    return secondary;
                }

                void setSecondary(std::string secondary) {
                    OracleUserTables::secondary = secondary;
                }

                std::string getNested() {
                    return nested;
                }

                void setNested(std::string nested) {
                    OracleUserTables::nested = nested;
                }

                std::string getBuffer_pool() {
                    return buffer_pool;
                }

                void setBuffer_pool(std::string buffer_pool) {
                    OracleUserTables::buffer_pool = buffer_pool;
                }

                std::string getFlash_cache() {
                    return flash_cache;
                }

                void setFlash_cache(std::string flash_cache) {
                    OracleUserTables::flash_cache = flash_cache;
                }

                std::string getCell_flash_cache() {
                    return cell_flash_cache;
                }

                void setCell_flash_cache(std::string cell_flash_cache) {
                    OracleUserTables::cell_flash_cache = cell_flash_cache;
                }

                std::string getRow_movement() {
                    return row_movement;
                }

                void setRow_movement(std::string row_movement) {
                    OracleUserTables::row_movement = row_movement;
                }

                std::string getGlobal_stats() {
                    return global_stats;
                }

                void setGlobal_stats(std::string global_stats) {
                    OracleUserTables::global_stats = global_stats;
                }

                std::string getUser_stats() {
                    return user_stats;
                }

                void setUser_stats(std::string user_stats) {
                    OracleUserTables::user_stats = user_stats;
                }

                std::string getDuration() {
                    return duration;
                }

                void setDuration(std::string duration) {
                    OracleUserTables::duration = duration;
                }

                std::string getSkip_corrupt() {
                    return skip_corrupt;
                }

                void setSkip_corrupt(std::string skip_corrupt) {
                    OracleUserTables::skip_corrupt = skip_corrupt;
                }

                std::string getMonitoring() {
                    return monitoring;
                }

                void setMonitoring(std::string monitoring) {
                    OracleUserTables::monitoring = monitoring;
                }

                std::string getCluster_owner() {
                    return cluster_owner;
                }

                void setCluster_owner(std::string cluster_owner) {
                    OracleUserTables::cluster_owner = cluster_owner;
                }

                std::string getDependencies() {
                    return dependencies;
                }

                void setDependencies(std::string dependencies) {
                    OracleUserTables::dependencies = dependencies;
                }

                std::string getCompression() {
                    return compression;
                }

                void setCompression(std::string compression) {
                    OracleUserTables::compression = compression;
                }

                std::string getCompress_for() {
                    return compress_for;
                }

                void setCompress_for(std::string compress_for) {
                    OracleUserTables::compress_for = compress_for;
                }

                std::string getDropped() {
                    return dropped;
                }

                void setDropped(std::string dropped) {
                    OracleUserTables::dropped = dropped;
                }

                std::string getRead_only() {
                    return read_only;
                }

                void setRead_only(std::string read_only) {
                    OracleUserTables::read_only = read_only;
                }

                std::string getSegment_created() {
                    return segment_created;
                }

                void setSegment_created(std::string segment_created) {
                    OracleUserTables::segment_created = segment_created;
                }

                std::string getResult_cache() {
                    return result_cache;
                }

                void setResult_cache(std::string result_cache) {
                    OracleUserTables::result_cache = result_cache;
                }
            };

        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLEUSERTABLES_H
