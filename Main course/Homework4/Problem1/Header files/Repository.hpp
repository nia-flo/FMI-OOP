#pragma once

#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

// Repository is the single place where Subscribers will
// be stored. A Repository has ownership of the Subscribers
// stored inside it.
// The only way to access the available Subscribers in the
// repository is via the Subscriber's unique id.
// id's are guaranteed to be unique
class Repository {
public:
	Repository() = default;
	Repository(const Repository&);
	Repository& operator=(const Repository&);
	~Repository();

	// add registers a new Subscriber in the Repository
	void add(const Averager*);

	// get returns a Subscriber in the Repository if a
	// Subscriber with the given id exists.
	// Returns nullptr otherwise
	Averager* get(const std::string& id) const;

private:
	std::vector<Averager*> subscribers;

	void copy(const Repository&);
	void deleteSubscribers();
};
