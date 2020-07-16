#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_ICOMMAND_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_ICOMMAND_H

class ICommand{
public:
    virtual ~ICommand() {}
    virtual void execute(std::string args) = 0;
};



#endif //DNA_ANALYZER_PROJECT_P_S_MBY_ICOMMAND_H
