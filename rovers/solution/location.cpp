#include "location.h"
using namespace std;

location::location():x(0), y(0)
{
}

location::location(int x, int y) :x(x), y(y)
{
}
	
location::location(const location& pair)// : ID(NULL), x(NULL)
{
	setX(pair.x);
	setY(pair.y);
}

const location& location::operator=(const location& pair)
{
	//if it is a self copy, don't do anything
	if(this == &pair)
		return *this;
	//make current object *this a copy of the passed in location
	else
	{
		setX(pair.x);
		setY(pair.y);
		return *this;
	}
}

location::~location()
{
}

int location::getX(void) const
{
	return x;
}

int location::getY(void) const
{
	return y;
}

void location::setX(int x)
{
	this->x = x;
}

void location::setY(int y)
{
	this->y = y;
}
