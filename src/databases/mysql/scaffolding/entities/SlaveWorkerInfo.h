#ifndef INFORMATION_SCHEMA_CPP_SLAVE_WORKER_INFO_H
#define INFORMATION_SCHEMA_CPP_SLAVE_WORKER_INFO_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class SlaveWorkerInfo {

        private:
            int id;
            std::string relayLogName;
            long relayLogPos;
            std::string masterLogName;
            long masterLogPos;
            std::string checkpointRelayLogName;
            long checkpointRelayLogPos;
            std::string checkpointMasterLogName;
            long checkpointMasterLogPos;
            int checkpointSeqno;
            int checkpointGroupSize;
            std::string checkpointGroupBitmap;
            std::string channelName;

        public:

            static constexpr const char *TABLE_NAME = "slave_worker_info";

            struct COLUMNS {
                struct ID {
                    static constexpr const char *NAME = "Id";
                    static const int INDEX = 1;
                };
                struct RELAY_LOG_NAME {
                    static constexpr const char *NAME = "Relay_log_name";
                    static const int INDEX = 2;
                };
                struct RELAY_LOG_POS {
                    static constexpr const char *NAME = "Relay_log_pos";
                    static const int INDEX = 3;
                };
                struct MASTER_LOG_NAME {
                    static constexpr const char *NAME = "Master_log_name";
                    static const int INDEX = 4;
                };
                struct MASTER_LOG_POS {
                    static constexpr const char *NAME = "Master_log_pos";
                    static const int INDEX = 5;
                };
                struct CHECKPOINT_RELAY_LOG_NAME {
                    static constexpr const char *NAME = "Checkpoint_relay_log_name";
                    static const int INDEX = 6;
                };
                struct CHECKPOINT_RELAY_LOG_POS {
                    static constexpr const char *NAME = "Checkpoint_relay_log_pos";
                    static const int INDEX = 7;
                };
                struct CHECKPOINT_MASTER_LOG_NAME {
                    static constexpr const char *NAME = "Checkpoint_master_log_name";
                    static const int INDEX = 8;
                };
                struct CHECKPOINT_MASTER_LOG_POS {
                    static constexpr const char *NAME = "Checkpoint_master_log_pos";
                    static const int INDEX = 9;
                };
                struct CHECKPOINT_SEQNO {
                    static constexpr const char *NAME = "Checkpoint_seqno";
                    static const int INDEX = 10;
                };
                struct CHECKPOINT_GROUP_SIZE {
                    static constexpr const char *NAME = "Checkpoint_group_size";
                    static const int INDEX = 11;
                };
                struct CHECKPOINT_GROUP_BITMAP {
                    static constexpr const char *NAME = "Checkpoint_group_bitmap";
                    static const int INDEX = 12;
                };
                struct CHANNEL_NAME {
                    static constexpr const char *NAME = "Channel_name";
                    static const int INDEX = 13;
                };
            };

            SlaveWorkerInfo(int id, std::string &relayLogName, long relayLogPos, std::string &masterLogName,
                            long masterLogPos, std::string &checkpointRelayLogName, long checkpointRelayLogPos,
                            std::string &checkpointMasterLogName, long checkpointMasterLogPos, int checkpointSeqno,
                            int checkpointGroupSize, std::string &checkpointGroupBitmap, std::string &channelName)
                    : id{id}, relayLogName{relayLogName}, relayLogPos{relayLogPos}, masterLogName{masterLogName},
                      masterLogPos{masterLogPos}, checkpointRelayLogName{checkpointRelayLogName},
                      checkpointRelayLogPos{checkpointRelayLogPos}, checkpointMasterLogName{checkpointMasterLogName},
                      checkpointMasterLogPos{checkpointMasterLogPos}, checkpointSeqno{checkpointSeqno},
                      checkpointGroupSize{checkpointGroupSize}, checkpointGroupBitmap{checkpointGroupBitmap},
                      channelName{channelName} {}

            // Get the value of id
            int getId() const {
                return id;
            }

            // Get the value of relayLogName
            const std::string &getRelayLogName() const {
                return relayLogName;
            }

            // Get the value of relayLogPos
            long getRelayLogPos() const {
                return relayLogPos;
            }

            // Get the value of masterLogName
            const std::string &getMasterLogName() const {
                return masterLogName;
            }

            // Get the value of masterLogPos
            long getMasterLogPos() const {
                return masterLogPos;
            }

            // Get the value of checkpointRelayLogName
            const std::string &getCheckpointRelayLogName() const {
                return checkpointRelayLogName;
            }

            // Get the value of checkpointRelayLogPos
            long getCheckpointRelayLogPos() const {
                return checkpointRelayLogPos;
            }

            // Get the value of checkpointMasterLogName
            const std::string &getCheckpointMasterLogName() const {
                return checkpointMasterLogName;
            }

            // Get the value of checkpointMasterLogPos
            long getCheckpointMasterLogPos() const {
                return checkpointMasterLogPos;
            }

            // Get the value of checkpointSeqno
            int getCheckpointSeqno() const {
                return checkpointSeqno;
            }

            // Get the value of checkpointGroupSize
            int getCheckpointGroupSize() const {
                return checkpointGroupSize;
            }

            // Get the value of checkpointGroupBitmap
            const std::string &getCheckpointGroupBitmap() const {
                return checkpointGroupBitmap;
            }

            // Get the value of channelName
            const std::string &getChannelName() const {
                return channelName;
            }


            /**
            * Returns the table name 'slave_worker_info';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_SLAVE_WORKER_INFO_H