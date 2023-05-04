#pragma once
#include "SectionVotes.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class ElectionResultsDatabase
{
private:
    std::vector<SectionVotes> vec;
public:

    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;

    friend std::istream& operator>>(std::istream& in, ElectionResultsDatabase& res);
    friend std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& res);
};

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& res);
std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& res);


