//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/21/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEDBATABLES_H
#define DBCRUDGEN_CPP_ORACLEDBATABLES_H


#include <string>

namespace dbcrudgen {
    namespace db {
        namespace oracle {

            //
            // OracleDBATables
            // //
            class OracleDBATables {

            public:
                std::string owner;
                std::string table_name;
                std::string tablespace_name;
                std::string cluster_name;
                std::string iot_name;
                std::string status;
                int pct_free;
                int pct_used;
                int ini_trans;
                int max_trans;
                int initial_extent;
                int next_extent;
                int min_extents;
                int max_extents;
                std::string pct_increase;
                int freelists;
                int freelist_groups;
                std::string logging;
                std::string backed_up;
                int num_rows;
                int blocks;
                int empty_blocks;
                int avg_space;
                int chain_cnt;
                int avg_row_len;
                int avg_space_freelist_blocks;
                int num_freelist_blocks;
                std::string degree;
                std::string instances;
                std::string cache;
                std::string table_lock;
                int sample_size;
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

                OracleDBATables(std::string owner, std::string table_name, std::string tablespace_name,
                                std::string cluster_name, std::string iot_name, std::string status,
                                int pct_free, int pct_used, int ini_trans, int max_trans, int initial_extent,
                                int next_extent,
                                int min_extents, int max_extents, std::string pct_increase, int freelists,
                                int freelist_groups, std::string logging, std::string backed_up, int num_rows,
                                int blocks, int empty_blocks, int avg_space, int chain_cnt, int avg_row_len,
                                int avg_space_freelist_blocks, int num_freelist_blocks, std::string degree,
                                std::string instances, std::string cache, std::string table_lock,
                                int sample_size, std::string last_analyzed, std::string partitioned,
                                std::string iot_type, std::string temporary, std::string secondary,
                                std::string nested, std::string buffer_pool, std::string flash_cache,
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
                    OracleDBATables::owner = owner;
                }

                std::string getTable_name() {
                    return table_name;
                }

                void setTable_name(std::string table_name) {
                    OracleDBATables::table_name = table_name;
                }

                std::string getTablespace_name() {
                    return tablespace_name;
                }

                void setTablespace_name(std::string tablespace_name) {
                    OracleDBATables::tablespace_name = tablespace_name;
                }

                std::string getCluster_name() {
                    return cluster_name;
                }

                void setCluster_name(std::string cluster_name) {
                    OracleDBATables::cluster_name = cluster_name;
                }

                std::string getIot_name() {
                    return iot_name;
                }

                void setIot_name(std::string iot_name) {
                    OracleDBATables::iot_name = iot_name;
                }

                std::string getStatus() {
                    return status;
                }

                void setStatus(std::string status) {
                    OracleDBATables::status = status;
                }

                int getPct_free() {
                    return pct_free;
                }

                void setPct_free(int pct_free) {
                    OracleDBATables::pct_free = pct_free;
                }

                int getPct_used() {
                    return pct_used;
                }

                void setPct_used(int pct_used) {
                    OracleDBATables::pct_used = pct_used;
                }

                int getIni_trans() {
                    return ini_trans;
                }

                void setIni_trans(int ini_trans) {
                    OracleDBATables::ini_trans = ini_trans;
                }

                int getMax_trans() {
                    return max_trans;
                }

                void setMax_trans(int max_trans) {
                    OracleDBATables::max_trans = max_trans;
                }

                int getInitial_extent() {
                    return initial_extent;
                }

                void setInitial_extent(int initial_extent) {
                    OracleDBATables::initial_extent = initial_extent;
                }

                int getNext_extent() {
                    return next_extent;
                }

                void setNext_extent(int next_extent) {
                    OracleDBATables::next_extent = next_extent;
                }

                int getMin_extents() {
                    return min_extents;
                }

                void setMin_extents(int min_extents) {
                    OracleDBATables::min_extents = min_extents;
                }

                int getMax_extents() {
                    return max_extents;
                }

                void setMax_extents(int max_extents) {
                    OracleDBATables::max_extents = max_extents;
                }

                std::string getPct_increase() {
                    return pct_increase;
                }

                void setPct_increase(std::string pct_increase) {
                    OracleDBATables::pct_increase = pct_increase;
                }

                int getFreelists() {
                    return freelists;
                }

                void setFreelists(int freelists) {
                    OracleDBATables::freelists = freelists;
                }

                int getFreelist_groups() {
                    return freelist_groups;
                }

                void setFreelist_groups(int freelist_groups) {
                    OracleDBATables::freelist_groups = freelist_groups;
                }

                std::string getLogging() {
                    return logging;
                }

                void setLogging(std::string logging) {
                    OracleDBATables::logging = logging;
                }

                std::string getBacked_up() {
                    return backed_up;
                }

                void setBacked_up(std::string backed_up) {
                    OracleDBATables::backed_up = backed_up;
                }

                int getNum_rows() {
                    return num_rows;
                }

                void setNum_rows(int num_rows) {
                    OracleDBATables::num_rows = num_rows;
                }

                int getBlocks() {
                    return blocks;
                }

                void setBlocks(int blocks) {
                    OracleDBATables::blocks = blocks;
                }

                int getEmpty_blocks() {
                    return empty_blocks;
                }

                void setEmpty_blocks(int empty_blocks) {
                    OracleDBATables::empty_blocks = empty_blocks;
                }

                int getAvg_space() {
                    return avg_space;
                }

                void setAvg_space(int avg_space) {
                    OracleDBATables::avg_space = avg_space;
                }

                int getChain_cnt() {
                    return chain_cnt;
                }

                void setChain_cnt(int chain_cnt) {
                    OracleDBATables::chain_cnt = chain_cnt;
                }

                int getAvg_row_len() {
                    return avg_row_len;
                }

                void setAvg_row_len(int avg_row_len) {
                    OracleDBATables::avg_row_len = avg_row_len;
                }

                int getAvg_space_freelist_blocks() {
                    return avg_space_freelist_blocks;
                }

                void setAvg_space_freelist_blocks(int avg_space_freelist_blocks) {
                    OracleDBATables::avg_space_freelist_blocks = avg_space_freelist_blocks;
                }

                int getNum_freelist_blocks() {
                    return num_freelist_blocks;
                }

                void setNum_freelist_blocks(int num_freelist_blocks) {
                    OracleDBATables::num_freelist_blocks = num_freelist_blocks;
                }

                std::string getDegree() {
                    return degree;
                }

                void setDegree(std::string degree) {
                    OracleDBATables::degree = degree;
                }

                std::string getInstances() {
                    return instances;
                }

                void setInstances(std::string instances) {
                    OracleDBATables::instances = instances;
                }

                std::string getCache() {
                    return cache;
                }

                void setCache(std::string cache) {
                    OracleDBATables::cache = cache;
                }

                std::string getTable_lock() {
                    return table_lock;
                }

                void setTable_lock(std::string table_lock) {
                    OracleDBATables::table_lock = table_lock;
                }

                int getSample_size() {
                    return sample_size;
                }

                void setSample_size(int sample_size) {
                    OracleDBATables::sample_size = sample_size;
                }

                std::string getLast_analyzed() {
                    return last_analyzed;
                }

                void setLast_analyzed(std::string last_analyzed) {
                    OracleDBATables::last_analyzed = last_analyzed;
                }

                std::string getPartitioned() {
                    return partitioned;
                }

                void setPartitioned(std::string partitioned) {
                    OracleDBATables::partitioned = partitioned;
                }

                std::string getIot_type() {
                    return iot_type;
                }

                void setIot_type(std::string iot_type) {
                    OracleDBATables::iot_type = iot_type;
                }

                std::string getTemporary() {
                    return temporary;
                }

                void setTemporary(std::string temporary) {
                    OracleDBATables::temporary = temporary;
                }

                std::string getSecondary() {
                    return secondary;
                }

                void setSecondary(std::string secondary) {
                    OracleDBATables::secondary = secondary;
                }

                std::string getNested() {
                    return nested;
                }

                void setNested(std::string nested) {
                    OracleDBATables::nested = nested;
                }

                std::string getBuffer_pool() {
                    return buffer_pool;
                }

                void setBuffer_pool(std::string buffer_pool) {
                    OracleDBATables::buffer_pool = buffer_pool;
                }

                std::string getFlash_cache() {
                    return flash_cache;
                }

                void setFlash_cache(std::string flash_cache) {
                    OracleDBATables::flash_cache = flash_cache;
                }

                std::string getCell_flash_cache() {
                    return cell_flash_cache;
                }

                void setCell_flash_cache(std::string cell_flash_cache) {
                    OracleDBATables::cell_flash_cache = cell_flash_cache;
                }

                std::string getRow_movement() {
                    return row_movement;
                }

                void setRow_movement(std::string row_movement) {
                    OracleDBATables::row_movement = row_movement;
                }

                std::string getGlobal_stats() {
                    return global_stats;
                }

                void setGlobal_stats(std::string global_stats) {
                    OracleDBATables::global_stats = global_stats;
                }

                std::string getUser_stats() {
                    return user_stats;
                }

                void setUser_stats(std::string user_stats) {
                    OracleDBATables::user_stats = user_stats;
                }

                std::string getDuration() {
                    return duration;
                }

                void setDuration(std::string duration) {
                    OracleDBATables::duration = duration;
                }

                std::string getSkip_corrupt() {
                    return skip_corrupt;
                }

                void setSkip_corrupt(std::string skip_corrupt) {
                    OracleDBATables::skip_corrupt = skip_corrupt;
                }

                std::string getMonitoring() {
                    return monitoring;
                }

                void setMonitoring(std::string monitoring) {
                    OracleDBATables::monitoring = monitoring;
                }

                std::string getCluster_owner() {
                    return cluster_owner;
                }

                void setCluster_owner(std::string cluster_owner) {
                    OracleDBATables::cluster_owner = cluster_owner;
                }

                std::string getDependencies() {
                    return dependencies;
                }

                void setDependencies(std::string dependencies) {
                    OracleDBATables::dependencies = dependencies;
                }

                std::string getCompression() {
                    return compression;
                }

                void setCompression(std::string compression) {
                    OracleDBATables::compression = compression;
                }

                std::string getCompress_for() {
                    return compress_for;
                }

                void setCompress_for(std::string compress_for) {
                    OracleDBATables::compress_for = compress_for;
                }

                std::string getDropped() {
                    return dropped;
                }

                void setDropped(std::string dropped) {
                    OracleDBATables::dropped = dropped;
                }

                std::string getRead_only() {
                    return read_only;
                }

                void setRead_only(std::string read_only) {
                    OracleDBATables::read_only = read_only;
                }

                std::string getSegment_created() {
                    return segment_created;
                }

                void setSegment_created(std::string segment_created) {
                    OracleDBATables::segment_created = segment_created;
                }

                std::string getResult_cache() {
                    return result_cache;
                }

                void setResult_cache(std::string result_cache) {
                    OracleDBATables::result_cache = result_cache;
                }


            };
        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLEDBATABLES_H
