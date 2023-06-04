#include "family.h"
#include <iostream>
#include <iomanip>
using namespace std;
#pragma warning(disable:4996)		// allow call to strcpy
/*************************
private:
	int		size;
	char*	ID;
	char*	name;
	char*	friend1;
	char*	friend2;
	char*	friend3;
*************************/
family::family():ID(NULL), name(NULL), size(0), friend1(NULL), friend2(NULL), friend3(NULL)
{
}

family::family(char* ID, char* name, int size) :
	name(NULL),
	ID(NULL),
	size(size),
	friend1(NULL),
	friend2(NULL),
	friend3(NULL)
{
	setName(name);
	setID(ID);
}
	
family::family(const data& aFamily) : name(NULL), ID(NULL)
{
	setName(aFamily.name);
	setSize(aFamily.size);
	setID(aFamily.ID);
}

const family& family::operator=(const family& aFamily)
{
	//if it is a self copy, don't do anything
	if(this == &aFamily)
		return *this;
	//make current object *this a copy of the passed in family
	else
	{
		setName(aFamily.name);
		setSize(aFamily.size);
		setID(aFamily.ID);
		return *this;
	}
}

family::~family()
{
	if(name)
		delete[] name;
	if(ID)
		delete[] ID;
	if(friend1)
		delete[] friend1;
	if(friend2)
		delete[] friend2;
	if(friend2)
		delete[] friend2;
}

void family::getName(char * name) const
{
	strcpy(name, this->name);
}

void family::getID(char * ID) const
{
	strcpy(ID, this->ID);
}

float family::getSize(void) const
{
	return size;
}

void family::setName(char * name)
{
	//release the existing memory if there is any
	if(this->name)
		delete [] this->name;

	//set new name
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

void family::setID(char * ID)
{
	//release the existing memory if there is any
	if(this->ID)
		delete [] this->ID;

	//set new Id
	this->ID = new char[strlen(ID)+1];
	strcpy(this->ID, ID);
}

void family::setSize(int size)
{
	this->size = size;
}

bool addFriend(char* aFriend)
{
	if(this->friend1){
		if(this->friend2){
			if(this->friend3)
				return false;
			else {
				this->friend3 = new char[strlen(aFriend)+1];
				strcpy(this->friend3, aFriend);
			}
		}
		else {
			this->friend2 = new char[strlen(aFriend)+1];
			strcpy(this->friend2, aFriend);
		}
	}
	else {
		this->friend1 = new char[strlen(aFriend)+1];
		strcpy(this->friend1, aFriend);
	}
	return true;
}

bool operator<(const family& d1, const family& d2)
{
	char name1[100];
	char name2[100];

	d1.getName(name1);
	d2.getName(name2);

	if(strcmp(name1, name2) < 0)
		return true;
	else
		return false;
}

bool operator==(const family& d1, const family& d2)
{
	char id1[100];
	char id2[100];

	d1.getID(id1);
	d2.getID(id2);

	if(strcmp(id1, id2) == 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const family& aFamily)
{
	out << setw(20) << family.name
		<< setw(15) << family.ID
		<< setw(8) << fixed << setprecision(2) << family.size;
	return out;
}