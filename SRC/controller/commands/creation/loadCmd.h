#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_LOADCMD_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_LOADCMD_H

#include <iostream>
#include "../icommand.h"

class Load: public ICommand{
public:
    void execute(std::string args);
};

inline void Load::execute(std::string args) {
    std::cout<<"load"<<std::endl;
}



#endif //DNA_ANALYZER_PROJECT_P_S_MBY_LOADCMD_H
