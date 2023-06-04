#ifndef PLANTTREE_H
#define PLANTTREE_H

#include <ostream>
#include "plant.h"

class planttree
{
public:
	planttree();
	planttree(const planttree& aTable);
	~planttree();

	const planttree& operator= (const planttree& aTable);

	void setRoot(const plant& aPlant);
	void addChildren(const plant& parentPlant, const plant& leftPlant, const plant& rightPlant);
	void display(void) const;

	plant* findBestGrowth(void) const;
	plant* findBestNutrition(void) const;
	plant* findBestWater(void) const;

private:
	struct treenode
	{
		plant item;
		treenode * left, * right;
		treenode(const plant& aPlant) :
			item(aPlant), left(0), right(0)
		{
		}
	};
	treenode * root;	

	void display(treenode * root, int level) const;
	void destroyTree(treenode*& root);
	void copyTree(treenode*& newRoot, treenode * root);
	bool addChildrenInternal(treenode * curr, const plant& parentPlant, const plant& leftPlant, const plant& rightPlant);
	plant* findBestGrowthInternal(treenode* curr, plant* best) const;
	plant* findBestNutritionInternal(treenode* curr, plant* best) const;
	plant* findBestWaterInternal(treenode* curr, plant* best) const;
};
#endif