#ifndef CPP_DNA_SEQUENCE_P_S_MBY_2_BAD_DNA_NUCLEOTIDE_H
#define CPP_DNA_SEQUENCE_P_S_MBY_2_BAD_DNA_NUCLEOTIDE_H

#include <exception>
#include <iostream>

class BadNucleotidexception: public std::runtime_error{
public:
    BadNucleotidexception(const std::string &badDNA);
};

inline BadNucleotidexception::BadNucleotidexception( const std::string &badDNA) : runtime_error(badDNA){}

#endif //CPP_DNA_SEQUENCE_P_S_MBY_2_BAD_DNA_NUCLEOTIDE_H
