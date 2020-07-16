#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_MANAGER_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_MANAGER_H
#include "cli.h"

class Manager {
public:
    Manager();
    void init();
    void run();
    void exit();
};

inline void Manager::run() {
    CLI cli;
    cli.executeProgram();
}

inline void Manager::init() {

}

inline void Manager::exit() {

}

inline Manager::Manager() {
    init();
    run();
    exit();
}

#endif //DNA_ANALYZER_PROJECT_P_S_MBY_MANAGER_H
