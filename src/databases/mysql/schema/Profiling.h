//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_PROFILING_H
#define DBCRUDGEN_CPP_PROFILING_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class Profiling {

        private:
            int queryId;
            int seq;
            std::string state;
            long duration;
            long cpuUser;
            long cpuSystem;
            int contextVoluntary;
            int contextInvoluntary;
            int blockOpsIn;
            int blockOpsOut;
            int messagesSent;
            int messagesReceived;
            int pageFaultsMajor;
            int pageFaultsMinor;
            int swaps;
            std::string sourceFunction;
            std::string sourceFile;
            int sourceLine;

        public:

            static constexpr const char *TABLE_NAME = "PROFILING";

            struct COLUMNS {
                struct QUERY_ID {
                    static constexpr const char *NAME = "QUERY_ID";
                    static const int INDEX = 1;
                };
                struct SEQ {
                    static constexpr const char *NAME = "SEQ";
                    static const int INDEX = 2;
                };
                struct STATE {
                    static constexpr const char *NAME = "STATE";
                    static const int INDEX = 3;
                };
                struct DURATION {
                    static constexpr const char *NAME = "DURATION";
                    static const int INDEX = 4;
                };
                struct CPU_USER {
                    static constexpr const char *NAME = "CPU_USER";
                    static const int INDEX = 5;
                };
                struct CPU_SYSTEM {
                    static constexpr const char *NAME = "CPU_SYSTEM";
                    static const int INDEX = 6;
                };
                struct CONTEXT_VOLUNTARY {
                    static constexpr const char *NAME = "CONTEXT_VOLUNTARY";
                    static const int INDEX = 7;
                };
                struct CONTEXT_INVOLUNTARY {
                    static constexpr const char *NAME = "CONTEXT_INVOLUNTARY";
                    static const int INDEX = 8;
                };
                struct BLOCK_OPS_IN {
                    static constexpr const char *NAME = "BLOCK_OPS_IN";
                    static const int INDEX = 9;
                };
                struct BLOCK_OPS_OUT {
                    static constexpr const char *NAME = "BLOCK_OPS_OUT";
                    static const int INDEX = 10;
                };
                struct MESSAGES_SENT {
                    static constexpr const char *NAME = "MESSAGES_SENT";
                    static const int INDEX = 11;
                };
                struct MESSAGES_RECEIVED {
                    static constexpr const char *NAME = "MESSAGES_RECEIVED";
                    static const int INDEX = 12;
                };
                struct PAGE_FAULTS_MAJOR {
                    static constexpr const char *NAME = "PAGE_FAULTS_MAJOR";
                    static const int INDEX = 13;
                };
                struct PAGE_FAULTS_MINOR {
                    static constexpr const char *NAME = "PAGE_FAULTS_MINOR";
                    static const int INDEX = 14;
                };
                struct SWAPS {
                    static constexpr const char *NAME = "SWAPS";
                    static const int INDEX = 15;
                };
                struct SOURCE_FUNCTION {
                    static constexpr const char *NAME = "SOURCE_FUNCTION";
                    static const int INDEX = 16;
                };
                struct SOURCE_FILE {
                    static constexpr const char *NAME = "SOURCE_FILE";
                    static const int INDEX = 17;
                };
                struct SOURCE_LINE {
                    static constexpr const char *NAME = "SOURCE_LINE";
                    static const int INDEX = 18;
                };
            };

            Profiling(int queryId, int seq, std::string &state, long duration, long cpuUser, long cpuSystem,
                      int contextVoluntary, int contextInvoluntary, int blockOpsIn, int blockOpsOut, int messagesSent,
                      int messagesReceived, int pageFaultsMajor, int pageFaultsMinor, int swaps,
                      std::string &sourceFunction, std::string &sourceFile, int sourceLine)
                    : queryId{queryId}, seq{seq}, state{state}, duration{duration}, cpuUser{cpuUser},
                      cpuSystem{cpuSystem}, contextVoluntary{contextVoluntary}, contextInvoluntary{contextInvoluntary},
                      blockOpsIn{blockOpsIn}, blockOpsOut{blockOpsOut}, messagesSent{messagesSent},
                      messagesReceived{messagesReceived}, pageFaultsMajor{pageFaultsMajor},
                      pageFaultsMinor{pageFaultsMinor}, swaps{swaps}, sourceFunction{sourceFunction},
                      sourceFile{sourceFile}, sourceLine{sourceLine} {}

            // Get the value of queryId
            int getQueryId() const {
                return queryId;
            }

            // Get the value of seq
            int getSeq() const {
                return seq;
            }

            // Get the value of state
            const std::string &getState() const {
                return state;
            }

            // Get the value of duration
            long getDuration() const {
                return duration;
            }

            // Get the value of cpuUser
            long getCpuUser() const {
                return cpuUser;
            }

            // Get the value of cpuSystem
            long getCpuSystem() const {
                return cpuSystem;
            }

            // Get the value of contextVoluntary
            int getContextVoluntary() const {
                return contextVoluntary;
            }

            // Get the value of contextInvoluntary
            int getContextInvoluntary() const {
                return contextInvoluntary;
            }

            // Get the value of blockOpsIn
            int getBlockOpsIn() const {
                return blockOpsIn;
            }

            // Get the value of blockOpsOut
            int getBlockOpsOut() const {
                return blockOpsOut;
            }

            // Get the value of messagesSent
            int getMessagesSent() const {
                return messagesSent;
            }

            // Get the value of messagesReceived
            int getMessagesReceived() const {
                return messagesReceived;
            }

            // Get the value of pageFaultsMajor
            int getPageFaultsMajor() const {
                return pageFaultsMajor;
            }

            // Get the value of pageFaultsMinor
            int getPageFaultsMinor() const {
                return pageFaultsMinor;
            }

            // Get the value of swaps
            int getSwaps() const {
                return swaps;
            }

            // Get the value of sourceFunction
            const std::string &getSourceFunction() const {
                return sourceFunction;
            }

            // Get the value of sourceFile
            const std::string &getSourceFile() const {
                return sourceFile;
            }

            // Get the value of sourceLine
            int getSourceLine() const {
                return sourceLine;
            }

            /**
            * Returns the table name 'PROFILING';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_PROFILING_H
