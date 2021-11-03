#include "Repository.hpp"

Repository::Repository(const Repository& repository)
{
	this->copy(repository);
}

Repository& Repository::operator=(const Repository& repository)
{
	if (this != &repository)
	{
		this->deleteSubscribers();
		this->subscribers.clear();
		this->copy(repository);
	}

	return *this;
}

Repository::~Repository()
{
	this->deleteSubscribers();
}

void Repository::add(const Averager* averager)
{
	this->subscribers.push_back(averager->clone());
}

Averager* Repository::get(const std::string& id) const
{
	for (auto subscriber : this->subscribers)
	{
		if (subscriber->id == id)
		{
			return subscriber;
		}
	}

	return nullptr;
}

void Repository::copy(const Repository& repository)
{
	for (auto subscriber : repository.subscribers)
	{
		this->subscribers.push_back(subscriber->clone());
	}
}

void Repository::deleteSubscribers()
{
	for (auto subscriber : this->subscribers)
	{
		delete subscriber;
	}
}
