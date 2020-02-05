//
// Created by victor on 5/26/17.
//

#ifndef DBCRUDGEN_CPP_CLIPARSER_H
#define DBCRUDGEN_CPP_CLIPARSER_H

#include <iostream>
#include "../../io/FilesManager.h"

class CliParser {
private:
    FilesManager filesManager;
protected:
    FilesManager *getFilesManger(){
        return (&filesManager);
    }
public:

    /**
     * Parse a command line value, return the action
     *
     * @param value
     * @return
     */
    int parse(std::string value) {
        if (value == "-h" || value == "--help") {
            return 0;
        }
        if (value == "--database-crud") {
            return 1;
        }
        return -1;
    }

    /**
     * Log invalid command line arguments
     * @param numberOfArguments
     * @param command
     * @param leastArguments
     * @param errorMessage
     */
    void logInvalidArguments(int numberOfArguments, std::string command, int leastArguments, std::string errorMessage) {
        std::cerr << "Cannot execute command : " << command << std::endl;
        std::cerr << "Number of arguments passed : " << numberOfArguments << std::endl;
        std::cerr << "Least expected arguments passed : " << leastArguments << std::endl;
        std::cerr << "Extra error error message : " << errorMessage << std::endl;
    }

    /**
     * Log a command line action
     *
     * @param actionId
     * @param action
     */
    void log(int actionId, std::string action) {
        std::cout << "Action ID :" << actionId << std::endl;
        std::cout << "Action Name : " << action << std::endl;
    }

    /**
     * Log an invalid action
     * @param action
     */
    void logInvalidAction(std::string action) {
        std::cout << " Invalid action :" << action << std::endl;
    }

    /**
     * Show all the available actions
     * Reads from a file
     */
    void showAvailableActions() {
        std::string availableActions = getFilesManger()->readFile("/home/victor/Documents/workspace/c++/dbcrudgen-cpp/res/core/support/help");
        std::cout<<availableActions<<std::endl;
    }
};


#endif //DBCRUDGEN_CPP_CLIPARSER_H
