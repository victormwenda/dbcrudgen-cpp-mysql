#ifndef INFORMATION_SCHEMA_CPP_HELP_RELATION_H
#define INFORMATION_SCHEMA_CPP_HELP_RELATION_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class HelpRelation {

            private:
                int helpTopicId;
                int helpKeywordId;

            public:

                static constexpr const char *TABLE_NAME = "help_relation";

                struct COLUMNS {
                    struct HELP_TOPIC_ID {
                        static constexpr const char *NAME = "help_topic_id";
                        static const int INDEX = 1;
                    };
                    struct HELP_KEYWORD_ID {
                        static constexpr const char *NAME = "help_keyword_id";
                        static const int INDEX = 2;
                    };
                };

                HelpRelation(int helpTopicId, int helpKeywordId) : helpTopicId{helpTopicId},
                                                                   helpKeywordId{helpKeywordId} {}

                // Get the value of helpTopicId
                int getHelpTopicId() const {
                    return helpTopicId;
                }

                // Get the value of helpKeywordId
                int getHelpKeywordId() const {
                    return helpKeywordId;
                }


                /**
                * Returns the table name 'help_relation';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_HELP_RELATION_H