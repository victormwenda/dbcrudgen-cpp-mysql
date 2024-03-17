//
// Created by victor on 3/17/24.
//

#ifndef DBCRUDGEN_CPP_MYSQL_RESOURCEGROUPS_H
#define DBCRUDGEN_CPP_MYSQL_RESOURCEGROUPS_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class ResourceGroups {

            private:
                std::string resourceGroupName;
                std::string resourceGroupType;
                int resourceGroupEnabled;
                std::string vcpu_ids;
                int thread_priority;

            public:

                static constexpr const char *TABLE_NAME = "RESOURCE_GROUPS";

                struct COLUMNS {
                    struct RESOURCE_GROUP_NAME {
                        static constexpr const char *NAME = "RESOURCE_GROUP_NAME";
                        static const int INDEX = 1;
                    };
                    struct RESOURCE_GROUP_TYPE {
                        static constexpr const char *NAME = "RESOURCE_GROUP_TYPE";
                        static const int INDEX = 2;
                    };
                    struct RESOURCE_GROUP_ENABLED {
                        static constexpr const char *NAME = "RESOURCE_GROUP_ENABLED";
                        static const int INDEX = 3;
                    };
                    struct VCPU_IDS {
                        static constexpr const char *NAME = "VCPU_IDS";
                        static const int INDEX = 4;
                    };
                    struct THREAD_PRIORITY {
                        static constexpr const char *NAME = "THREAD_PRIORITY";
                        static const int INDEX = 5;
                    };
                };

                ResourceGroups(std::string &resourceGroupName, std::string &resourceGroupType,
                               int resourceGroupEnabled, std::string &vcpuIds, int threadPriority)
                        : resourceGroupName(resourceGroupName), resourceGroupType(resourceGroupType),
                          resourceGroupEnabled(resourceGroupEnabled), vcpu_ids(vcpuIds),
                          thread_priority(threadPriority) {}

                const std::string &getResourceGroupName() const {
                    return resourceGroupName;
                }

                const std::string &getResourceGroupType() const {
                    return resourceGroupType;
                }

                int getResourceGroupEnabled() const {
                    return resourceGroupEnabled;
                }

                const std::string &getVcpuIds() const {
                    return vcpu_ids;
                }

                int getThreadPriority() const {
                    return thread_priority;
                }

                /**
                * Returns the table name 'RESOURCE_GROUPS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_MYSQL_RESOURCEGROUPS_H
