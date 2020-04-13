#ifndef INFORMATION_SCHEMA_CPP_HELP_CATEGORY_H
#define INFORMATION_SCHEMA_CPP_HELP_CATEGORY_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class HelpCategory {

            private:
                int helpCategoryId;
                std::string name;
                int parentCategoryId;
                std::string url;

            public:

                static constexpr const char *TABLE_NAME = "help_category";

                struct COLUMNS {
                    struct HELP_CATEGORY_ID {
                        static constexpr const char *NAME = "help_category_id";
                        static const int INDEX = 1;
                    };
                    struct NAME {
                        static constexpr const char *_NAME = "name";
                        static const int INDEX = 2;
                    };
                    struct PARENT_CATEGORY_ID {
                        static constexpr const char *NAME = "parent_category_id";
                        static const int INDEX = 3;
                    };
                    struct URL {
                        static constexpr const char *NAME = "url";
                        static const int INDEX = 4;
                    };
                };

                HelpCategory(int helpCategoryId, std::string &name, int parentCategoryId, std::string &url)
                        : helpCategoryId{helpCategoryId}, name{name}, parentCategoryId{parentCategoryId}, url{url} {}

                // Get the value of helpCategoryId
                int getHelpCategoryId() const {
                    return helpCategoryId;
                }

                // Get the value of name
                const std::string &getName() const {
                    return name;
                }

                // Get the value of parentCategoryId
                int getParentCategoryId() const {
                    return parentCategoryId;
                }

                // Get the value of url
                const std::string &getUrl() const {
                    return url;
                }


                /**
                * Returns the table name 'help_category';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_HELP_CATEGORY_H