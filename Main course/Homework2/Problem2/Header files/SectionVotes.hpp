#pragma once

#include <fstream>

enum Party
{
	PARTY1 = 0,
	PARTY2 = 1,
	PARTY3 = 2,
};

class SectionVotes
{
public:
	SectionVotes() = default;
	SectionVotes(int party1Votes, int party2Votes, int party3Votes);

	SectionVotes& operator=(const SectionVotes&);

	int votesForParty(Party) const;

	friend std::istream& operator>>(std::istream&, SectionVotes&);
	friend std::ostream& operator<<(std::ostream&, const SectionVotes&);

private:
	static const int PARTYS_COUNT = 3;

	int votes[PARTYS_COUNT];
};


