#include "resultdata.h"
#include <iostream>
//#include <iomanip>
using namespace std;

resultdata::resultdata():ID(0), x(0), y(0), reading(0)
{
}

resultdata::resultdata(int ID, int x, int y, int reading) :ID(ID), x(x), y(y), reading(reading)
{
}
	
resultdata::resultdata(const resultdata& entry)// : ID(NULL), x(NULL)
{
	setID(entry.getID());
	setX(entry.getX());
	setY(entry.getY());
	setReading(entry.getReading());
}

const resultdata& resultdata::operator=(const resultdata& entry)
{
	setID(entry.getID());
	setX(entry.getX());
	setY(entry.getY());
	setReading(entry.getReading());
	return *this;
}

resultdata::~resultdata()
{
}

int resultdata::getID(void) const
{
	return ID;
}

int resultdata::getX(void) const
{
	return x;
}

int resultdata::getY(void) const
{
	return y;
}

int resultdata::getReading(void) const
{
	return reading;
}

void resultdata::setID(int ID)
{
	this->ID = ID;
}

void resultdata::setX(int x)
{
	this->x = x;
}

void resultdata::setY(int y)
{
	this->y = y;
}

void resultdata::setReading(int reading)
{
	this->reading = reading;
}

void resultdata::print()
{
	cout << "Reading from rover #" << getID() << " at " << getX() << ", " << getY() << " is " << getReading() << endl;
}
