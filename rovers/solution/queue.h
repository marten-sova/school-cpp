#ifndef QUEUE_H
#define QUEUE_H

#include "resultdata.h"
using namespace std;
class queue 
{
public:
	queue(); 
	queue(const int maxCapacity);
	queue(const queue& aQueue);
	~queue();

	const queue& operator= (const queue& aQueue);

	bool enqueue(const resultdata&);//const;
	resultdata dequeue(void);

	bool isEmpty(void)const;
	void debugInfo(void)const;


private:
	resultdata* arr;
	int 		capacity;
	int			front;
	int			rear;
};
#endif