#ifndef LOCATION_H
#define LOCATION_H
using namespace std;

class location
{
public:
	location();
	location(int x, int y);
	location(const location& pair);		//copy constructor: make current object a copy of "entry"
	~location();						//destructor: release the dynamically allocated memory

	int getX(void) const;
	int getY(void) const;

	void setX(int x);
	void setY(int y);

	const location& operator=(const location& pair);	 //overloading assignment operator

private:
	int x;
	int y;
};

#endif