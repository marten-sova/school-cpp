#ifndef PLANT_H
#define PLANT_H
#include <iostream>

using namespace std;

class plant
{
public:
	plant(const char* ID, int growth, int nutrition, int water);
	plant(const plant& aPlant);
	~plant();

	int 	getGrowth(void) const;
	int		getNutrition(void) const;
	int		getWater(void) const;

	void	setID(const char* ID);
	void 	setGrowth(int growth);
	void 	setNutrition(int nutrition);
	void	setWater(int water);

	friend bool operator== (const plant& d1, const plant& d2);
	friend ostream& operator<<(ostream& out, const plant& d);

	friend class planttree;

private:
	char* 	ID;
	int 	growth, nutrition, water;
};

#endif