#ifndef RESULTDATA_H
#define RESULTDATA_H
#include <iostream>
using namespace std;

class resultdata
{
public:
	resultdata();
	resultdata(int ID, int x, int y, int reading);
	resultdata(const resultdata& entry);		//copy constructor: make current object a copy of "entry"
	~resultdata();						//destructor: release the dynamically allocated memory

	int getID(void) const;
	int getX(void) const;
	int getY(void) const;
	int getReading(void) const;

	void setID(int ID);
	void setX(int x);
	void setY(int y);
	void setReading(int reading);

	void print();

	const resultdata& operator=(const resultdata& entry);	 //overloading assignment operator

private:
	int ID;
	int x;
	int y;
	int reading;
};

#endif