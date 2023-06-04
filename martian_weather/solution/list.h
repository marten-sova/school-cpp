#ifndef LIST_H
#define LIST_H

#include <cstring>
#include <ostream>
#include "weatherdata.h"

class list
{
public:
	list();
	~list();


	bool 	insert(const weatherdata& aData);
	bool 	remove(int timestamp);
	bool 	retrieve(int query, weatherdata& foundEntry) const;
	int 	getSize(void) const;

	void 	traverseTime (int& startTime, int& endTime, int& rangeSize);
	void 	traverseTemperature (int rangeSize, int averageTemperature[10], int& minTemperatureCount, int& maxTemperatureCount, int& commonTemperature);
	void 	traverseWindspeed (int rangeSize, int averageWindspeed[10], int& minWindspeedCount, int& maxWindspeedCount, int& commonWindspeed);

private:
	list(const list& aList); // no copying allowed
	struct node
	{
		weatherdata entry;
		node * 		nextTime;
		node * 		nextTemperature;
		node * 		nextWindspeed;
	};

		node*		headTime;
		node*		headTemperature;
		node*		headWindspeed;
		int			size;
};

#endif
