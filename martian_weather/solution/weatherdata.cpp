#include "weatherdata.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

weatherdata::weatherdata():timestamp(0), temperature(0), windspeed(0)
{
}

weatherdata::weatherdata(int timestamp, int temperature, int windspeed) :
    timestamp(timestamp),
    temperature(temperature),
    windspeed(windspeed)
{
}
	
weatherdata::weatherdata(const weatherdata& entry)
{
    setTimestamp(entry.timestamp);
    setTemperature(entry.temperature);
    setWindspeed(entry.windspeed);
}

const weatherdata& weatherdata::operator=(const weatherdata& entry)
{
    if(this == &entry)
	return *this;
    else
    {
	setTimestamp(entry.timestamp);
    setTemperature(entry.temperature);
    setWindspeed(entry.windspeed);
	return *this;
    }
}

weatherdata::~weatherdata()
{
}

int weatherdata::getTimestamp() const
{
    return timestamp;
}

int weatherdata::getTemperature() const
{
    return temperature;
}

int weatherdata::getWindspeed() const
{
    return windspeed;
}

void weatherdata::setTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

void weatherdata::setTemperature(int temperature)
{
    this->temperature = temperature;
}

void weatherdata::setWindspeed(int windspeed)
{
    this->windspeed = windspeed;
}