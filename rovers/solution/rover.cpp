#include "rover.h"

using namespace std;

rover::rover():ID(0), x(0), y(0), maxResults(100)
{
}

rover::rover(int ID, const int maxResults, queue& resultqueue) :ID(ID), x(0), y(0), maxResults(maxResults)
{
	results = &resultqueue;
}
	
rover::rover(const rover& aRover)// : ID(NULL), x(NULL)
{
	setID(aRover.getID());
	setX(aRover.getX());
	setY(aRover.getY());
	setMaxResults(aRover.maxResults);
	//setQueue(*(aRover.results));
}

const rover& rover::operator=(const rover& aRover)
{
	setID(aRover.ID);
	setX(aRover.x);
	setY(aRover.y);
	setMaxResults(aRover.maxResults);
	//setQueue(*(aRover.results));
	return *this;
}

rover::~rover()
{
	//delete results;
}

int rover::getID(void) const
{
	return ID;
}

int rover::getX(void) const
{
	return x;
}

int rover::getY(void) const
{
	return y;
}

void rover::setID(int ID)
{
	this->ID = ID;
}

void rover::setX(int x)
{
	this->x = x;
}

void rover::setY(int y)
{
	this->y = y;
}

void rover::setMaxResults(int max)
{
	this->maxResults = max;
}

void rover::setQueue(queue resultsqueue)
{
	this->results = &resultsqueue;
}

void rover::deploy()
{
	cout << "Rover (ID " << getID() << ") deploying..." << endl;
	cout << "Rover (ID " << getID() << ") ready." << endl;
}

void rover::move(int x, int y)
{
	setX(x);
	setY(y);
	location coordinates(x, y);
	route.push(coordinates);
	cout << "Rover (ID " << getID() << ") moving to location " << x << ", " << y << ".\n";
}

void rover::corescan()
{
	cout << "Rover (ID " << getID() << ") scanning.\n";
	resultdata entry(getID(), getX(), getY(), scandata::getScandata(getY(), getX()));
	results->enqueue(entry);
}

void rover::dock()
{
	cout << "Rover (ID " << getID() << ") returning to base.\n";
	location coordinates;
	route.pop(coordinates); // no need to move to current location
	while(!route.isEmpty())
	{
		route.pop(coordinates);
		cout << "Rover (ID " << getID() << ") moving to location " << coordinates.getX() << ", " << coordinates.getY() << ".\n";
	}
	coordinates.setX(0);
	coordinates.setY(0);
	cout << "Rover (ID " << getID() << ") moving to location " << coordinates.getX() << ", " << coordinates.getY() << ".\n";
	cout << "Rover (ID " << getID() << ") at base and docked.\n";
}




