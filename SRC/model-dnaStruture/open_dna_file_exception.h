#ifndef CPP_DNA_SEQUENCE_P_S_MBY_2_OPEN_DNA_FILE_EXCEPTION_H
#define CPP_DNA_SEQUENCE_P_S_MBY_2_OPEN_DNA_FILE_EXCEPTION_H

#include <exception>
#include <iostream>

class ErrorOpenningDnaFile: public std::runtime_error{
public:
    ErrorOpenningDnaFile(const std::string &badDNA);
};

inline ErrorOpenningDnaFile::ErrorOpenningDnaFile( const std::string &badDNA) : runtime_error("open file error"){}

#endif //CPP_DNA_SEQUENCE_P_S_MBY_2_OPEN_DNA_FILE_EXCEPTION_H
