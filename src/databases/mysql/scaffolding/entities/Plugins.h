//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_PLUGINS_H
#define DBCRUDGEN_CPP_PLUGINS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class Plugins {

            private:
                std::string pluginName;
                std::string pluginVersion;
                std::string pluginStatus;
                std::string pluginType;
                std::string pluginTypeVersion;
                std::string pluginLibrary;
                std::string pluginLibraryVersion;
                std::string pluginAuthor;
                std::string pluginDescription;
                std::string pluginLicense;
                std::string loadOption;

            public:

                static constexpr const char *TABLE_NAME = "PLUGINS";

                struct COLUMNS {
                    struct PLUGIN_NAME {
                        static constexpr const char *NAME = "PLUGIN_NAME";
                        static const int INDEX = 1;
                    };
                    struct PLUGIN_VERSION {
                        static constexpr const char *NAME = "PLUGIN_VERSION";
                        static const int INDEX = 2;
                    };
                    struct PLUGIN_STATUS {
                        static constexpr const char *NAME = "PLUGIN_STATUS";
                        static const int INDEX = 3;
                    };
                    struct PLUGIN_TYPE {
                        static constexpr const char *NAME = "PLUGIN_TYPE";
                        static const int INDEX = 4;
                    };
                    struct PLUGIN_TYPE_VERSION {
                        static constexpr const char *NAME = "PLUGIN_TYPE_VERSION";
                        static const int INDEX = 5;
                    };
                    struct PLUGIN_LIBRARY {
                        static constexpr const char *NAME = "PLUGIN_LIBRARY";
                        static const int INDEX = 6;
                    };
                    struct PLUGIN_LIBRARY_VERSION {
                        static constexpr const char *NAME = "PLUGIN_LIBRARY_VERSION";
                        static const int INDEX = 7;
                    };
                    struct PLUGIN_AUTHOR {
                        static constexpr const char *NAME = "PLUGIN_AUTHOR";
                        static const int INDEX = 8;
                    };
                    struct PLUGIN_DESCRIPTION {
                        static constexpr const char *NAME = "PLUGIN_DESCRIPTION";
                        static const int INDEX = 9;
                    };
                    struct PLUGIN_LICENSE {
                        static constexpr const char *NAME = "PLUGIN_LICENSE";
                        static const int INDEX = 10;
                    };
                    struct LOAD_OPTION {
                        static constexpr const char *NAME = "LOAD_OPTION";
                        static const int INDEX = 11;
                    };
                };

                Plugins(std::string &pluginName, std::string &pluginVersion, std::string &pluginStatus,
                        std::string &pluginType, std::string &pluginTypeVersion, std::string &pluginLibrary,
                        std::string &pluginLibraryVersion, std::string &pluginAuthor, std::string &pluginDescription,
                        std::string &pluginLicense, std::string &loadOption) : pluginName{pluginName},
                                                                               pluginVersion{pluginVersion},
                                                                               pluginStatus{pluginStatus},
                                                                               pluginType{pluginType},
                                                                               pluginTypeVersion{pluginTypeVersion},
                                                                               pluginLibrary{pluginLibrary},
                                                                               pluginLibraryVersion{
                                                                                       pluginLibraryVersion},
                                                                               pluginAuthor{pluginAuthor},
                                                                               pluginDescription{pluginDescription},
                                                                               pluginLicense{pluginLicense},
                                                                               loadOption{loadOption} {}

                // Get the value of pluginName
                const std::string &getPluginName() const {
                    return pluginName;
                }

                // Get the value of pluginVersion
                const std::string &getPluginVersion() const {
                    return pluginVersion;
                }

                // Get the value of pluginStatus
                const std::string &getPluginStatus() const {
                    return pluginStatus;
                }

                // Get the value of pluginType
                const std::string &getPluginType() const {
                    return pluginType;
                }

                // Get the value of pluginTypeVersion
                const std::string &getPluginTypeVersion() const {
                    return pluginTypeVersion;
                }

                // Get the value of pluginLibrary
                const std::string &getPluginLibrary() const {
                    return pluginLibrary;
                }

                // Get the value of pluginLibraryVersion
                const std::string &getPluginLibraryVersion() const {
                    return pluginLibraryVersion;
                }

                // Get the value of pluginAuthor
                const std::string &getPluginAuthor() const {
                    return pluginAuthor;
                }

                // Get the value of pluginDescription
                const std::string &getPluginDescription() const {
                    return pluginDescription;
                }

                // Get the value of pluginLicense
                const std::string &getPluginLicense() const {
                    return pluginLicense;
                }

                // Get the value of loadOption
                const std::string &getLoadOption() const {
                    return loadOption;
                }

                /**
                * Returns the table name 'PLUGINS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_PLUGINS_H
