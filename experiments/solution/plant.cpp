#include "plant.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

plant::plant(const char* ID, int growth, int nutrition, int water) : ID(NULL), growth(growth), nutrition(nutrition), water(water)
{
	setID(ID);
}

plant::plant(const plant& aPlant):ID(NULL)
{
	setID(aPlant.ID);
	setGrowth(aPlant.growth);
	setNutrition(aPlant.nutrition);
	setWater(aPlant.water);
	//cout << "copy constructor";
}

plant::~plant()
{
	if(ID){
		//cout << "trying to delete plant: " << ID << "... ";
		delete [] ID;
	}
	/*
	else
		cout << "no plant ID to delete" << endl;
	cout << "deleted " << ID << endl;
*/
}

int plant::getGrowth(void) const
{
	return growth;
}

int	plant::getNutrition(void) const
{
	return nutrition;
}

int	plant::getWater(void) const
{
	return water;
}

void plant::setID(const char * ID)
{
	if(this->ID)
		delete [] this->ID;

	this->ID = new char[15];
	strcpy(this->ID, ID);
}

void plant::setGrowth(int growth)
{
	this->growth = growth;
}

void plant::setNutrition(int nutrition)
{
	this->nutrition = nutrition;
}

void plant::setWater(int water)
{
	this->water = water;
}
/*
bool operator<(const plant& d1, const plant& d2)
{
	return d1.ch < d2.ch;
}
*/
bool operator==(const plant& d1, const plant& d2)
{
	if(strcmp(d1.ID, d2.ID) == 0)
		return true;
	return false;
}

ostream& operator<<(ostream& out, const plant& d)
{
	out << "Plant ID: " << d.ID
		<< " (G: " 		<< d.growth
		<< " N: "		<< d.nutrition
		<< " W: "		<< d.water
		<< ")";
	return out;
}