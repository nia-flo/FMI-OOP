#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "BacklogPublisher.hpp"
#include "SimplePublisher.hpp"
#include "PeriodicSampler.hpp"
#include "Repository.hpp"
#include <assert.h>

#include<iostream>

// Here's some sample usage of the Subscribers,
// Publishers and the Repository

void testSimplePublisher() {
	Repository repo;

	Averager avg1("avg1");
	repo.add(&avg1);

	Averager avg2("avg2");
	repo.add(&avg2);

	SimplePublisher sp;
	sp.subscribe(static_cast<Averager*>(repo.get("avg1")));
	sp.signal({ 10 });
	sp.subscribe((Averager*)repo.get("avg2"));
	sp.signal({ 0 });

	assert(static_cast<Averager*>(repo.get("avg1"))->read() == 5);
	assert(static_cast<Averager*>(repo.get("avg2"))->read() == 0);
	assert(avg1.read() == 0);

	Repository repoCopy = repo;
}

void testBacklogPublisher() {
	Repository repo;
	Averager avg1("avg1");
	repo.add(&avg1);

	BacklogPublisher bp;
	bp.signal({ 10 });
	bp.signal({ 0 });

	bp.subscribe(static_cast<Averager*>(repo.get("avg1")));
	assert(static_cast<Averager*>(repo.get("avg1"))->read() == 5);
}

void testMovingAverager() {
	Repository repo;
	MovingAverager mavg1("mavg1", 2);
	repo.add(&mavg1);

	SimplePublisher sp;
	sp.subscribe(static_cast<MovingAverager*>(repo.get("mavg1")));
	sp.signal({ 10 });
	sp.signal({ 0 });
	assert(static_cast<MovingAverager*>(repo.get("mavg1"))->read() == 5);

	sp.signal({ 4 });
	Averager* returnedAv = repo.get("mavg1");
	assert(static_cast<MovingAverager*>(repo.get("mavg1"))->read() == 2);
}

void testPeriodicSampler() {
	Repository repo;
	PeriodicSampler ps2("ps2", 2);
	repo.add(&ps2);

	SimplePublisher sp;
	sp.subscribe(static_cast<PeriodicSampler*>(repo.get("ps2")));
	sp.signal({ 10 });
	assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 10);

	sp.signal({ 0 });
	assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 10);

	sp.signal({ 4 });
	assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 4);
}

void testAveragers()
{
	Averager avg("id1");
	MovingAverager movAvg("id2", 5);
	PeriodicSampler perSam("id3", 3);

	avg.signal(Message(1));
	avg.signal(Message(2));
	avg.signal(Message(3));
	avg.signal(Message(4));
	avg.signal(Message(5));
	avg.signal(Message(6));
	avg.signal(Message(7));
	avg.signal(Message(8));
	avg.signal(Message(9));

	assert(avg.read() == 5);

	movAvg.signal(Message(1));
	movAvg.signal(Message(2));
	movAvg.signal(Message(3));
	movAvg.signal(Message(4));
	movAvg.signal(Message(5));
	movAvg.signal(Message(6));
	movAvg.signal(Message(7));
	movAvg.signal(Message(8));
	movAvg.signal(Message(9));

	assert(movAvg.read() == 7);

	perSam.signal(Message(1));
	perSam.signal(Message(2));
	perSam.signal(Message(3));
	perSam.signal(Message(4));
	perSam.signal(Message(5));
	perSam.signal(Message(6));
	perSam.signal(Message(7));
	perSam.signal(Message(8));
	perSam.signal(Message(9));

	assert(perSam.read() == 7); 

}

int main() {

	testSimplePublisher();
	testBacklogPublisher();
	testMovingAverager();
	testPeriodicSampler();

	testAveragers();
}
