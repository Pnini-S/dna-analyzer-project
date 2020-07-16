
#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_NEWCMD_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_NEWCMD_H

#include <string>
#include "../icommand.h"
#include "../../../model-dnaStruture/dna_data_base.h"

class New: public ICommand{
public:
    void execute(std::string args);

private:
    static size_t s_numOfNew;
};

inline void New::execute(std::string args) {
    std::cout<<"new"<<std::endl;

    if(args.find(" ") == std::string::npos){
        std::string name = "str" + std::to_string(s_numOfNew);
        DnaData newDna = DnaDataBase::addDna(name, args);
        newDna.printDna();
    }



}

#endif //DNA_ANALYZER_PROJECT_P_S_MBY_NEWCMD_H
