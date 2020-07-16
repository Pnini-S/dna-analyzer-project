#ifndef CPP_DNA_SEQUENCE_P_S_MBY_2_DNA_SEQUENCE_H
#define CPP_DNA_SEQUENCE_P_S_MBY_2_DNA_SEQUENCE_H

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "open_dna_file_exception.h"

class DnaSequence {
    friend std::ostream & operator <<(std::ostream &os, const DnaSequence& dna);
    friend DnaSequence operator+(const DnaSequence &dna1,const DnaSequence &dna2);

public:
    DnaSequence(const std::string &dna);
    DnaSequence(const DnaSequence &otherDna);
    DnaSequence & operator=(const DnaSequence& otherDna);
    ~DnaSequence();

    bool operator==(const DnaSequence& otherDna) const;
    bool operator!=(const DnaSequence& otherDna) const;

    size_t length() const;
    DnaSequence slice (size_t begin, size_t end) const;
    DnaSequence pair() const;
    size_t find(const DnaSequence &sub_seq) const;
    size_t count (const DnaSequence &sub_seq) const;
    std::vector<size_t> findAll(const DnaSequence &sub_seq) const;
    std::vector<DnaSequence> findConsensusSequences() const;

private:
    class Nucleotide {
    public:
        
        Nucleotide();
        Nucleotide(char c);
        const Nucleotide &operator=(const Nucleotide &nucleotide);
        operator char() const ;
        
    private:
        char m_nucleotide;
    };

    Nucleotide *m_dna;
    size_t m_len;

    void copy (const DnaSequence &otherDna);
    Nucleotide *convert_to_nucleotides(const char *dna);
    std::string convert_to_string() const;

public:
    const DnaSequence::Nucleotide &operator[](size_t i) const;
    DnaSequence::Nucleotide &operator[](size_t i);
};


inline DnaSequence::DnaSequence(const std::string &dna):m_dna(NULL),m_len(dna.length())
{
    const char *tmp=dna.c_str();
    m_dna=convert_to_nucleotides(tmp);
}

inline DnaSequence::DnaSequence(const DnaSequence &otherDna):m_dna(NULL),m_len(otherDna.m_len)
{
    m_dna=new Nucleotide[otherDna.m_len];
    copy(otherDna);
}

inline DnaSequence& DnaSequence::operator=(const DnaSequence &otherDna)
{
    Nucleotide *tmp=m_dna;
    m_len=otherDna.m_len;
    m_dna= new Nucleotide[otherDna.m_len];
    copy(otherDna);
    delete[]tmp;
    return *this;
}

inline DnaSequence::~DnaSequence()
{
    delete [] m_dna;
}

inline std::ostream &operator<<(std::ostream &os,const DnaSequence& dna)
{
    os<<dna.convert_to_string();
    return os;
}

inline bool DnaSequence::operator==(const DnaSequence &otherDna) const
{
    return convert_to_string() == otherDna.convert_to_string();
}

inline bool DnaSequence::operator!=(const DnaSequence &otherDna) const
{
    return !(convert_to_string() == otherDna.convert_to_string());
}

inline DnaSequence operator+(const DnaSequence &dna1,const DnaSequence &dna2)
{
    std::string str=dna1.convert_to_string();
    str+=dna2.convert_to_string();
    return DnaSequence(str);
}

inline const DnaSequence::Nucleotide &DnaSequence::operator[](size_t i) const
{
    return m_dna[i];
}

inline DnaSequence::Nucleotide &DnaSequence::operator[](size_t i)
{
    return m_dna[i];
}

inline size_t DnaSequence::length() const
{
    return m_len;
}

inline DnaSequence::Nucleotide::operator char() const
{
    return m_nucleotide;
}

inline DnaSequence DnaSequence::slice (size_t begin, size_t end) const
{
    std::string str;
    for (size_t i=begin;i<end;i++)
    {
        str.push_back(m_dna[i]);
    }
    DnaSequence res(str);
    return res;
}

inline DnaSequence DnaSequence::pair() const
{
    std::string str=convert_to_string();
    std::reverse(str.begin(),str.end());
    DnaSequence res(str);
    for (size_t i=0;i<res.m_len;i++)
    {
        switch (res[i])
        {
            case 'A':res[i]='T';
                break;
            case 'C':res[i]='G';
                break;
            case 'T':res[i]='A';
                break;
            case 'G':res[i]='C';
                break;
        }
    }
    return res;
}

inline size_t DnaSequence::find(const DnaSequence &sub_seq) const
{
    size_t index,j,tmp;
    bool found=false;
    for(size_t i=0; i<m_len; i++)
    {
        j=0;
        tmp=i;
        for(;j<sub_seq.m_len && m_dna[i]==sub_seq.m_dna[j];j++,i++){}
        if (j==sub_seq.m_len) {
       	found = true;
       	index=tmp;
        	break;
        }
        i=tmp;
    }
    if (found)
        return index;
    return std::string::npos;
}

inline size_t DnaSequence::count (const DnaSequence &sub_seq) const
{
    size_t pos;
    size_t counter=0;
    DnaSequence tmp= *this;
    pos=tmp.find(sub_seq);
    while(pos!=std::string::npos){

        counter++;
        tmp = tmp.slice(pos + 1, m_len);
        pos = tmp.find(sub_seq);
    }
    return counter;
}

inline std::vector<size_t> DnaSequence::findAll(const DnaSequence &sub_seq) const
{
    size_t counter=0,pos=0;
    std::vector<size_t> findings;

    DnaSequence tmp= *this;
    pos=tmp.find(sub_seq);

    while(pos!=std::string::npos){
    
	findings.push_back(pos + counter);
        counter += pos+1;
        tmp = tmp.slice(pos + 1, m_len);
        pos = tmp.find(sub_seq);
        
    }

    return findings;
}

inline std::vector<DnaSequence> DnaSequence::findConsensusSequences() const
{
    std::vector<DnaSequence> res;
    std::string start_codon = "ATG";
    std::vector<std::string> end_codons;
    end_codons.push_back("TAG");
    end_codons.push_back("TAA");
    end_codons.push_back("TGA");
    std::vector<std::string>::iterator it_cod;
    std::vector<size_t> pos_start_cod=findAll(start_codon),pos_end_cod;
    std::vector<size_t>::iterator it_start,it_end;
    for(it_start=pos_start_cod.begin();it_start!=pos_start_cod.end();it_start++)
    {
    	std::cout << *it_start<<std::endl;
        for (it_cod = end_codons.begin(); it_cod != end_codons.end(); it_cod++)
        {
            DnaSequence tmp(slice(*it_start + 3, m_len));
            pos_end_cod = tmp.findAll(*it_cod);
            for (it_end = pos_end_cod.begin(); it_end != pos_end_cod.end(); it_end++)
            {
                if ((*it_end) % 3 == 0)
                    res.push_back(slice(*it_start, *it_start + *it_end + 6));
            }
        }
    }
    return res;
}

#endif //CPP_DNA_SEQUENCE_P_S_MBY_2_DNA_SEQUENCE_H
