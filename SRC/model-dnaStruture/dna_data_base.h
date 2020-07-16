#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_DNA_DATA_BASE_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_DNA_DATA_BASE_H

#include <map>
#include "dna_data.h"

class DnaDataBase {
private:
    static size_t s_currentId;
    static std::map <size_t, std::string> s_idToName;
    static std::map <std::string, DnaData*> s_nameToDna;
public:
    static const DnaData& getDnaByName(const std::string &name);
    static const DnaData& getDnaById(size_t id);
    static DnaData &addDna(std::string &name, std::string &dna);
};

inline const DnaData &DnaDataBase::getDnaByName(const std::string &name) {

    return *s_nameToDna[name];
}

inline const DnaData &DnaDataBase::getDnaById(size_t id) {
    return *s_nameToDna[s_idToName[id]];
}

inline DnaData &DnaDataBase::addDna(std::string &name, std::string &dna) {
    s_currentId++;
    DnaData *newDna =new DnaData(name, s_currentId, dna);
    s_idToName[s_currentId] = name;
    s_nameToDna[name] = newDna;
    return *newDna;
}


#endif //DNA_ANALYZER_PROJECT_P_S_MBY_DNA_DATA_BASE_H
