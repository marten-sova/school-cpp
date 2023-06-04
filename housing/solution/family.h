#ifndef FAMILY_H
#define FAMILY_H
#include <iostream>
using namespace std;
class family
{
public:
	family();
	family(char* ID, char* name, int size);
	family(const family& aFamily);		//copy constructor: make current object a copy of "student"
	~family();						//destructor: release the dynamically allocated memory

	void getName(char* name) const;
	int getSize(void) const;
	void getID(char* ID) const;

	void setName(char* name);
	void setSize(int size);
	void setID(char* ID);
	bool addFriend(char* aFriend);

	const family& operator=(const family& aFamily);	 //overloading assignment operator
	friend ostream& operator<<(ostream& out, const family& aFamily);

private:
	int		size;
	char*	ID;
	char*	name;
	char*	friend1;
	char*	friend2;
	char*	friend3;
};

bool operator< (const family& d1, const family& d2);
bool operator== (const family& d1, const family& d2);

#endif