#ifndef INFORMATION_SCHEMA_CPP_HELP_TOPIC_H
#define INFORMATION_SCHEMA_CPP_HELP_TOPIC_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class HelpTopic {

        private:
            int helpTopicId;
            std::string name;
            int helpCategoryId;
            std::string description;
            std::string example;
            std::string url;

        public:

            static constexpr const char *TABLE_NAME = "help_topic";

            struct COLUMNS {
                struct HELP_TOPIC_ID {
                    static constexpr const char *NAME = "help_topic_id";
                    static const int INDEX = 1;
                };
                struct NAME {
                    static constexpr const char *_NAME = "name";
                    static const int INDEX = 2;
                };
                struct HELP_CATEGORY_ID {
                    static constexpr const char *NAME = "help_category_id";
                    static const int INDEX = 3;
                };
                struct DESCRIPTION {
                    static constexpr const char *NAME = "description";
                    static const int INDEX = 4;
                };
                struct EXAMPLE {
                    static constexpr const char *NAME = "example";
                    static const int INDEX = 5;
                };
                struct URL {
                    static constexpr const char *NAME = "url";
                    static const int INDEX = 6;
                };
            };

            HelpTopic(int helpTopicId, std::string &name, int helpCategoryId, std::string &description,
                      std::string &example, std::string &url)
                    : helpTopicId{helpTopicId}, name{name}, helpCategoryId{helpCategoryId}, description{description},
                      example{example}, url{url} {}

            // Get the value of helpTopicId
            int getHelpTopicId() const {
                return helpTopicId;
            }

            // Get the value of name
            const std::string &getName() const {
                return name;
            }

            // Get the value of helpCategoryId
            int getHelpCategoryId() const {
                return helpCategoryId;
            }

            // Get the value of description
            const std::string &getDescription() const {
                return description;
            }

            // Get the value of example
            const std::string &getExample() const {
                return example;
            }

            // Get the value of url
            const std::string &getUrl() const {
                return url;
            }


            /**
            * Returns the table name 'help_topic';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_HELP_TOPIC_H