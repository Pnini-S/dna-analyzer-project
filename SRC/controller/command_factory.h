#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_COMMAND_FACTORY_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_COMMAND_FACTORY_H

#include <map>
#include <string>
#include "commands/icommand.h"
#include "commands/creation/newCmd.h"
#include "commands/creation/loadCmd.h"
#include "commands/management/saveCmd.h"

class CommandFactpry{
private:
    std::map <std::string, ICommand*> saveCommand;
public:
    ICommand* getCommand(std::string nameCommand);
    bool findCommand(std::string nameCommand);
    void createCommand(std::string nameCommand);
};

inline ICommand *CommandFactpry::getCommand(std::string nameCommand) {
    if (!findCommand(nameCommand)){
        createCommand(nameCommand);
    }
    return saveCommand[nameCommand];

}

inline bool CommandFactpry::findCommand(std::string nameCommand) {

    return saveCommand.find(nameCommand) != saveCommand.end();
}

inline void CommandFactpry::createCommand(std::string nameCommand) {
    if (nameCommand == "new"){
        saveCommand.insert(std::pair<std::string, ICommand*> (nameCommand, new New));
    }
    else if (nameCommand == "load"){
        saveCommand.insert(std::pair<std::string, ICommand*>(nameCommand, new Load));
    }
    else if (nameCommand == "save"){
        saveCommand.insert(std::pair<std::string, ICommand*>(nameCommand, new Save));
    }
}


#endif //DNA_ANALYZER_PROJECT_P_S_MBY_COMMAND_FACTORY_H
