#include <iostream>
#include "core/cli/CliParser.h"
#include "core/crud/actions/DatabaseCrudActions.h"
#include "core/io/FilesManager.h"

using namespace std;

int main(int argc, char *argv[]) {

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

    return 0;
}