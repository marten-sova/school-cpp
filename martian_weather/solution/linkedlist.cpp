#include "list.h"
#include "datalogger.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

list::list() : headTime(NULL), headTemperature(NULL), headWindspeed(NULL), size(0)
{
}

list::~list()
{
    node * curr = headTime;
    while(headTime)
    {
	curr = headTime->nextTime;
	delete headTime;
	headTime = curr;
    } 
}

bool list::insert (const weatherdata& newEntry)
{
    node * prev = NULL;
    node * curr = headTime;
    
    while (curr!=NULL && curr->entry.getTimestamp() < newEntry.getTimestamp())
    {
		prev = curr;
		curr = curr->nextTime;
    }
    
	node * newNode = new node;
	newNode->entry = newEntry;
	newNode->nextTime = NULL;
	newNode->nextTemperature = NULL;
	newNode->nextWindspeed = NULL;

	newNode->nextTime = curr;
	if(prev == NULL)
	    headTime = newNode;
	else
	    prev->nextTime = newNode;

	prev = NULL;
	curr = headTemperature;

	while (curr!=NULL && curr->entry.getTemperature() < newEntry.getTemperature())
    {
		prev = curr;
		curr = curr->nextTemperature;
    }
	newNode->nextTemperature = curr;
	if(prev == NULL){
	    headTemperature = newNode;
	}
	else{
	    prev->nextTemperature = newNode;
	}

	prev = NULL;
	curr = headWindspeed;

	while (curr!=NULL && curr->entry.getWindspeed() < newEntry.getWindspeed())
    {
		prev = curr;
		curr = curr->nextWindspeed;
    }
	newNode->nextWindspeed = curr;
	if(prev == NULL)
	    headWindspeed = newNode;
	else
	    prev->nextWindspeed = newNode;


	size++;
	return true;
    
}

bool list::remove (int timestamp)
{
    int 	suspect;
    node * 	identified;

    node * prev = NULL;
    node * curr = headTime;
    while (curr)
    {
		suspect = curr->entry.getTimestamp();
		if(suspect == timestamp)
		{
			identified = curr;
		    if(!prev)
				headTime = curr->nextTime;
		    else{
				prev->nextTime = curr->nextTime;
			}

			prev = NULL;
			curr = headTemperature;
			while(curr){
				suspect = curr->entry.getTimestamp();
				if(suspect == timestamp){
					if(!prev)
						headTemperature = curr->nextTemperature;
					else
						prev->nextTemperature = curr->nextTemperature;

					prev = NULL;
					curr = headWindspeed;
					while(curr){
						suspect = curr->entry.getTimestamp();
						if(suspect == timestamp){
							if(!prev)
								headWindspeed = curr->nextWindspeed;
							else
								prev->nextWindspeed = curr->nextWindspeed;

							delete identified;
							size--;
							return true;
						}
						prev = curr;
						curr = curr->nextWindspeed;
					}
				}
				prev = curr;
				curr = curr->nextTemperature;
			}
		}

		prev = curr;
		curr = curr->nextTime;
    }
    return false;
}

bool list::retrieve (int query, weatherdata & foundEntry) const
{
    node * curr;
    int entryTime;
    for(curr=headTime; curr; curr=curr->nextTime)
    {
		entryTime = curr->entry.getTimestamp();
		if(query == entryTime)
		{
	    	foundEntry = curr->entry;
	    	return true;
		}
    }
    return false;
}

void list::traverseTime (int& startTime, int& endTime, int& rangeSize)
{
    node * curr;
    startTime = headTime->entry.getTimestamp();
    rangeSize = size/10;
    for(curr=headTime; curr; curr=curr->nextTime)
    {
		if(!curr->nextTime){ // if end of list
			endTime = curr->entry.getTimestamp();
			return;
		}
    }
}

void list::traverseTemperature (int rangeSize, int averageTemperature[10], int& minTemperatureCount, int& maxTemperatureCount, int& commonTemperature)
{
    node * 	curr;
    int 	currentRange = 0;
    int 	count = 0;
    int 	currentTotal = 0;
    int 	currentStreak = 0;
    int 	previousTemperature;
    int 	commonTemperatureCount = 0;

    for(curr=headTemperature; curr; curr=curr->nextTemperature)
    {
    	count++;
    	currentTotal+=curr->entry.getTemperature();

    	if(count == rangeSize){
    		averageTemperature[currentRange] = currentTotal/count;
    		currentRange++;
    		count = 0;
    		currentTotal = 0;
    	}

    	if(curr->entry.getTemperature() < MIN_TEMP){
    		minTemperatureCount++;
    	}
    	else if(curr->entry.getTemperature() > MAX_TEMP){
    		maxTemperatureCount++;
    	}

    	if(curr->entry.getTemperature() == previousTemperature){
    		currentStreak++;
    		if(currentStreak > commonTemperatureCount){
    			commonTemperatureCount = currentStreak;
    			commonTemperature = curr->entry.getTemperature();
    		}
    	}
    	else{
    		currentStreak = 1;
    		previousTemperature = curr->entry.getTemperature();
    	}
    }
    return;
}

void list::traverseWindspeed (int rangeSize, int averageWindspeed[10], int& minWindspeedCount, int& maxWindspeedCount, int& commonWindspeed)
{
    node * 	curr;
    int 	currentRange = 0;
    int 	count = 0;
    int 	currentTotal = 0;
    int 	currentStreak = 0;
    int 	previousWindspeed;
    int 	commonWindspeedCount = 0;

    for(curr=headWindspeed; curr; curr=curr->nextWindspeed)
    {
    	count++;
    	currentTotal+=curr->entry.getWindspeed();

    	if(count == rangeSize){
    		averageWindspeed[currentRange] = currentTotal/count;
    		currentRange++;
    		count = 0;
    		currentTotal = 0;
    	}

    	if(curr->entry.getWindspeed() <= MIN_WIND){
    		minWindspeedCount++;
    	}
    	else if(curr->entry.getWindspeed() > MAX_WIND){
    		maxWindspeedCount++;
    	}

    	if(curr->entry.getWindspeed() == previousWindspeed){
    		currentStreak++;
    		if(currentStreak > commonWindspeedCount){
    			commonWindspeedCount = currentStreak;
    			commonWindspeed = curr->entry.getWindspeed();
    		}
    	}
    	else{
    		currentStreak = 1;
    		previousWindspeed = curr->entry.getWindspeed();
    	}
    }
    return;
}

int list::getSize () const
{
    return size;
}


