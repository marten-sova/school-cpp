#ifndef ROVER_H
#define ROVER_H
#include <iostream>
#include "location.h"
#include "stack.h"
#include "queue.h"
#include "scandata.h"

using namespace std;

class rover 
{
public:
	rover();
	rover(int ID, const int maxResults, queue& resultqueue);
	rover(const rover& aRover);
	~rover();

	const rover& operator=(const rover& aRover);

	void deploy();
	void move(int x, int y);
	void corescan();
	void dock();
	//void printID();

	void setID(int ID);
	void setX(int x);
	void setY(int y);
	void setMaxResults(int max);
	void setQueue(queue resultsqueue);

	int getID() const;
	int getX() const;
	int getY() const;


private:	
	int 	ID;
	int		x;
	int		y;
	int		maxResults;
	stack 	route;
	queue * results;
};
#endif