#ifndef INFORMATION_SCHEMA_CPP_HELP_KEYWORD_H
#define INFORMATION_SCHEMA_CPP_HELP_KEYWORD_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class HelpKeyword {

        private:
            int helpKeywordId;
            std::string name;

        public:

            static constexpr const char *TABLE_NAME = "help_keyword";

            struct COLUMNS {
                struct HELP_KEYWORD_ID {
                    static constexpr const char *NAME = "help_keyword_id";
                    static const int INDEX = 1;
                };
                struct NAME {
                    static constexpr const char *_NAME = "name";
                    static const int INDEX = 2;
                };
            };

            HelpKeyword(int helpKeywordId, std::string &name) : helpKeywordId{helpKeywordId}, name{name} {}

            // Get the value of helpKeywordId
            int getHelpKeywordId() const {
                return helpKeywordId;
            }

            // Get the value of name
            const std::string &getName() const {
                return name;
            }


            /**
            * Returns the table name 'help_keyword';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_HELP_KEYWORD_H