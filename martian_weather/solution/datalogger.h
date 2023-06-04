#ifndef DATALOGGER_H
#define DATALOGGER_H
#include <iostream>
#include "list.h"

const int MIN_TEMP = -50;
const int MAX_TEMP = 0;
const int MIN_WIND = 0;
const int MAX_WIND = 25;


class datalogger
{
public:
	datalogger();
	datalogger(const datalogger& datalog);
	~datalogger();

	void addData(int timestamp, int temperature, int windspeed);
	void removeData(int timestamp);
	bool containsTimestamp(int timestamp);
	void printReport(const char* label);

	int 	count;
	int		startTime;
	int		endTime;
	int		minTemperatureCount;
	int		maxTemperatureCount;
	int		minWindspeedCount;
	int		maxWindspeedCount;
	int		averageTemperature[10];
	int		averageWindspeed[10];
	int		rangeSize;
	int		commonWindspeed;
	int 	commonTemperature;


private:
	list* 		linkedList;
};

#endif
