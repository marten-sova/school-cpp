#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include <iostream>


class weatherdata
{
public:
	weatherdata();
	weatherdata(int timestamp, int temperature, int windspeed);
	weatherdata(const weatherdata& entry);
	~weatherdata();

	int getTimestamp(void) const;
	int getTemperature(void) const;
	int getWindspeed(void) const;

	void setTimestamp(int timestamp);
	void setTemperature(int temperature);
	void setWindspeed(int windspeed);

	const weatherdata& operator=(const weatherdata& entry);



private:
	int		timestamp;
	int		temperature;
	int		windspeed;
};

#endif
