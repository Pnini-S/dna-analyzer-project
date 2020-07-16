#include "dna_sequence.h"
#include "bad_dna_nucleotide.h"

bool is_valid_nucleotide(const char nucleotide)
{
    return nucleotide =='A' || nucleotide =='C' || nucleotide =='T' || nucleotide =='G';
}

std::string DnaSequence::convert_to_string() const
{
    std::string str;
    for (size_t i=0;i<m_len;i++)
    {
        str.push_back(m_dna[i]);
    }
    return str;
}

void DnaSequence::copy (const DnaSequence &otherDna)
{
    for (size_t i=0;i<m_len;i++)
    {
        m_dna[i]=otherDna.m_dna[i];
    }
}

DnaSequence::Nucleotide *DnaSequence::convert_to_nucleotides(const char *dna)
{
    size_t len = strlen(dna);
    Nucleotide *newNucleotide=new Nucleotide[len];
    try {
        for (size_t i=0;i<len;i++)
        {
            newNucleotide[i]=dna[i];
        }
    }
    catch (BadNucleotidexception &e)
    {
       delete[] newNucleotide;
       throw;
    }
    return newNucleotide;
}

DnaSequence::Nucleotide::Nucleotide(char c):m_nucleotide(c)
{
    if(!is_valid_nucleotide(c))
        throw BadNucleotidexception("bad nucleotide");
}

DnaSequence::Nucleotide::Nucleotide(){}

const DnaSequence::Nucleotide &DnaSequence::Nucleotide::operator=(const Nucleotide &nucleotide)
{
    m_nucleotide=nucleotide.m_nucleotide;
    return *this;
}


