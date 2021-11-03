#include "Averager.hpp"

Averager::Averager(const std::string& id) 
	: id(id)
{
}

void Averager::signal(const Message& message)
{
	this->messages.push_back(message);
}

int Averager::read() const
{
	if (this->messages.size() == 0)
	{
		return 0;
	}

	int sum = 0;
	for (int i = 0; i < this->messages.size(); i++)
	{
		sum += this->messages[i].data;
	}
	return sum / this->messages.size();
}

Averager* Averager::clone() const
{
	return new Averager(*this);
}
