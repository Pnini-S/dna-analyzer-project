#ifndef DNA_ANALYZER_PROJECT_P_S_MBY_DNA_DATA_H
#define DNA_ANALYZER_PROJECT_P_S_MBY_DNA_DATA_H

#include "dna_sequence.h"

class DnaData{
public:
    DnaData(std::string name, size_t id, std::string dna);
    void printDna();

private:
    DnaSequence m_dnaSequence;
    std::string m_dnaName;
    size_t m_dnaId;
};

inline void DnaData::printDna() {
    std::cout << "[" << m_dnaId << "]" << m_dnaName << ": " << m_dnaSequence << std::endl;
}

DnaData::DnaData(std::string name, size_t id, std::string dna):m_dnaName(name), m_dnaId(id), m_dnaSequence(dna) {}


#endif //DNA_ANALYZER_PROJECT_P_S_MBY_DNA_DATA_H
