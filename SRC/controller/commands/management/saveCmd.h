#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_SAVECMD_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_SAVECMD_H

#include <iostream>
#include "../icommand.h"

class Save: public ICommand{
public:
    void execute(std::string args);
};

inline void Save::execute(std::string args) {
    std::cout << "save" << std::endl;
}
#endif //DNA_ANALYZER_PROJECT_P_S_MBY_SAVECMD_H
