#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		return;
	}

	inputFile >> *this;

	inputFile.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
	return this->sections.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
	int votes = 0;
	for (int i = 0; i < this->sections.size(); i++)
	{
		votes += this->sections[i].votesForParty(party);
	}

	return votes;
}

Party ElectionResultsDatabase::winningParty() const
{
	Party winningParty = (Party)0;
	int winningPartyVotes = this->votesForParty(winningParty);

	for (int i = 1; i < this->PARTYS_COUNT; i++)
	{
		int currentPartyVotes = this->votesForParty((Party)i);
		if (currentPartyVotes > winningPartyVotes)
		{
			winningParty = (Party)i;
			winningPartyVotes = currentPartyVotes;
		}
	}

	return winningParty;
}

std::istream& operator>>(std::istream& input, ElectionResultsDatabase& electionResultDatabase)
{
	SectionVotes section;
	while (input >> section)
	{
		electionResultDatabase.sections.push_back(section);
	}

	return input;
}

std::ostream& operator<<(std::ostream& output, const ElectionResultsDatabase& electionResultDatabase)
{
	for (int i = 0; i < electionResultDatabase.sections.size(); i++)
	{
		output << electionResultDatabase.sections[i] << '\n';
	}

	return output;
}
