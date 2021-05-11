#include "SectionVotes.hpp"

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
	this->votes[0] = party1Votes;
	this->votes[1] = party2Votes;
	this->votes[2] = party3Votes;
}

SectionVotes& SectionVotes::operator=(const SectionVotes& toCopy)
{
	for (int i = 0; i < this->PARTYS_COUNT; i++)
	{
		this->votes[i] = toCopy.votes[i];
	}

	return *this;
}

int SectionVotes::votesForParty(Party party) const
{
	return this->votes[party];
}

std::istream& operator>>(std::istream& input, SectionVotes& sectionVotes)
{
	int party1Votes, party2Votes, party3Votes;
	input >> party1Votes >> party2Votes >> party3Votes;

	sectionVotes = SectionVotes(party1Votes, party2Votes, party3Votes);

	return input;
}

std::ostream& operator<<(std::ostream& output, const SectionVotes& sectionVotes)
{
	output << sectionVotes.votes[0] << ' ' << sectionVotes.votes[1] << ' ' << sectionVotes.votes[2];

	return output;
}
