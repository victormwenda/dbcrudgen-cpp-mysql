#include <iostream>
#include "core/cli/CliParser.h"
#include "core/crud/actions/DatabaseCrudActions.h"
#include "core/database/schemas/DatabaseSchemas.h"
#include <algorithm>

using namespace std;

int handleCliLaunch(int argc, char *argv[]) {

    FilesManager filesManager;

    CliParser cliParser;

    if (argc < 2) {
        string command(argv[0]);
        (&cliParser)->logInvalidArguments(1, command, 2, "No argument provided");
        return 0;
    } else {
        string action = std::string(argv[1]);
        int actionId = (&cliParser)->parse(action);
        switch (actionId) {
            case DatabaseCrudActions::INVALID_ACTION:
                (&cliParser)->logInvalidAction(action);
                break;
            case DatabaseCrudActions::HELP:
                (&cliParser)->showAvailableActions();
                break;
            case DatabaseCrudActions::ENABLE_DATABASE_CRUD:

                break;
            default:
                std::cerr << "Found undefined action : " << actionId << endl;
        }

    }

}

int main(int argc, char *argv[]) {

    std::string databaseName{"test_database"};

    std::vector<TableColumn> tableColumns{
            TableColumn{"username", "varchar(128) not null", "NO", "PRI", "NULL", ""},
            TableColumn{"password", "varchar(128) not null", "NO", "", "NULL", ""}
    };

    DatabaseConnection connection{"127.0.0.1", "root", "rootPass"};

    DatabaseSchemas<TableColumn> databaseSchemas{databaseName, tableColumns, connection};
    cout << databaseSchemas.getDatabaseName() << std::endl;

    auto container = databaseSchemas.getTableColumns();
    auto printValue = [](TableColumn tableColumn) { cout << "Column : " << tableColumn.getField() << endl; };

    for_each(begin(container), end(container), printValue);


    return 0;
}