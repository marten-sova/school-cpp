#include "datalogger.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

datalogger::datalogger() : minTemperatureCount(0), maxTemperatureCount(0), minWindspeedCount(0), maxWindspeedCount(0)
{
    linkedList = new list();
}

datalogger::datalogger(const datalogger& datalog)
{
    this->linkedList = datalog.linkedList;
}

datalogger::~datalogger()
{
    if(linkedList)
	delete linkedList;
}


void datalogger::addData(int timestamp, int temperature, int windspeed)
{
    linkedList->insert(weatherdata(timestamp, temperature, windspeed));
}

void datalogger::removeData(int timestamp)
{
    linkedList->remove(timestamp);
}

bool datalogger::containsTimestamp(int timestamp)
{
    weatherdata match;
    if(linkedList->retrieve(timestamp, match)){
        return true;
    }
    return false;
}

void datalogger::printReport(const char* label)
{
    linkedList->traverseTime(startTime, endTime, rangeSize);
    linkedList->traverseTemperature(rangeSize, averageTemperature, minTemperatureCount, maxTemperatureCount, commonTemperature);
    linkedList->traverseWindspeed(rangeSize, averageWindspeed, minWindspeedCount, maxWindspeedCount, commonWindspeed);

    
    cout << "                                  -- Data report (" << label << ") --" << endl;
    cout << "Time range:\t        " << startTime << " - " << endTime << endl;
    cout << "Number of entries:                                      " << linkedList->getSize() << endl;
    cout << "Number of entries with < " << MIN_TEMP << "C temperature               " << minTemperatureCount << endl;
    cout << "Number of entries with > " << MAX_TEMP << "C temperature                  " << maxTemperatureCount << endl;
    cout << "Most common temperature                                " << commonTemperature << endl << endl;

    cout << "Number of entries with " << MIN_WIND << " windspeed                       " << minWindspeedCount << endl;
    cout << "Number of entries with > " << MAX_WIND << "m/s windspeed                " << maxWindspeedCount << endl;
    cout << "Most common windspeed                                      " << commonWindspeed << endl << endl;

    cout << "Average temperature over ranges" << endl;
    for(int i = 0; i < 10; i++){
        cout << i*rangeSize << " through " << (i+1)*rangeSize-1 << "      " << averageTemperature[i] << endl;
    }

    cout << endl << "Average windspeed over ranges" << endl;
    for(int i = 0; i < 10; i++){
        cout << i*rangeSize << " through " << (i+1)*rangeSize-1 << "       " << averageWindspeed[i] << endl;
    }

}




