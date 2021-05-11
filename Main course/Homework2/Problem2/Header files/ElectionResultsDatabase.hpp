#pragma once

#include "SectionVotes.hpp"

#include <vector>

class ElectionResultsDatabase
{
public:
    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;

    friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
    friend std::ostream& operator<<(std::ostream&, const ElectionResultsDatabase&);

private:
    static const int PARTYS_COUNT = 3;

    std::vector<SectionVotes> sections;
};
