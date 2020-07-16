#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_CLI_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_CLI_H

#include <iostream>
#include "command_factory.h"


class CLI{
private:
    CommandFactpry commandFactpry;
public:
    void executeCmd(std::string fullCommand);
    void executeProgram();
};

inline void CLI::executeProgram() {
    std::string  command;
    while (true){
        std::cout << "> cmd >>>";
        getline(std::cin, command);
        if (command == "quit")
            break;
        executeCmd(command);
    }
}

inline void CLI::executeCmd(std::string fullCommand) {
    std::string command , args;
    size_t posSpace = fullCommand.find(" ");
    if(posSpace == std::string::npos){
        command = fullCommand;
    }
    else {
        command = fullCommand.substr(0, posSpace);
        args = fullCommand.substr(posSpace);
    }
    ICommand* cmd = commandFactpry.getCommand(command);
    cmd->execute(args);
}


#endif //DNA_ANALYZER_PROJECT_P_S_MBY_CLI_H
