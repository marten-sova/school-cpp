#include "planttree.h"
#include <ostream>
using namespace std;

planttree::planttree() : root(NULL)
{
}

planttree::planttree(const planttree& aTable):root(NULL)
{
	*this = aTable;
}

const planttree& planttree::operator= (const planttree& aTable)
{
	if(this == &aTable)
		return *this;
	else
	{
		destroyTree(root); 
		copyTree(root, aTable.root);
		return *this;
	}
}

void planttree::copyTree (treenode*& newRoot, treenode * root)
{
	if(root)
	{
		newRoot = new treenode(root->item);
		copyTree(newRoot->left, root->left);
		copyTree(newRoot->right, root->right);
	}
	else
	{
		newRoot = NULL;
	}
}

planttree::~planttree()
{
	destroyTree(root); 
}

void planttree::destroyTree (treenode *& root)
{
	if(root)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = NULL;
	}
}

void planttree::setRoot(const plant& aPlant)
{
	root = new treenode(aPlant);
}

void planttree::addChildren(const plant& parentPlant, const plant& leftPlant, const plant& rightPlant)
{
	addChildrenInternal(root, parentPlant, leftPlant, rightPlant);
}

bool planttree::addChildrenInternal(treenode * curr, const plant& parentPlant, const plant& leftPlant, const plant& rightPlant)
{
	if(curr == NULL)
		return false;
	if(curr->item == parentPlant){
		curr->left = new treenode(leftPlant);
		curr->right = new treenode(rightPlant);
		return true;
	}
	if(addChildrenInternal(curr->left, parentPlant, leftPlant, rightPlant))
		return true;
	if(addChildrenInternal(curr->right, parentPlant, leftPlant, rightPlant))
		return true;
	return false;
}

void planttree::display(void) const
{
	display(root, 0);
}

void planttree::display(treenode * curr, int level) const
{
	if(curr == NULL)
		return;
	for(int i=0; i < level; i++)
		cout << "  ";
	cout << curr->item << endl;
	display(curr->left, level+1);
	display(curr->right, level+1);
}

plant* planttree::findBestGrowth(void) const
{
	return findBestGrowthInternal(root, &(root->item));
}

plant* planttree::findBestNutrition(void) const
{
	return findBestNutritionInternal(root, &(root->item));
}

plant* planttree::findBestWater(void) const
{
	return findBestWaterInternal(root, &(root->item));
}

plant* planttree::findBestGrowthInternal(treenode* curr, plant* best) const
{
	if(curr == NULL)
		return best;

	if(curr->item.getGrowth() > best->growth)
		best = &(curr->item);

	plant * temp;
	temp = findBestGrowthInternal(curr->left, best);
	if(temp->growth > best->growth)
		best = temp;

	temp = findBestGrowthInternal(curr->right, best);
	if(temp->growth > best->growth)
		best = temp;
	temp = nullptr;
	return best;
}

plant* planttree::findBestNutritionInternal(treenode* curr, plant* best) const
{
	if(curr == NULL)
		return best;

	if(curr->item.getNutrition() > best->nutrition)
		best = &(curr->item);

	plant * temp;
	temp = findBestNutritionInternal(curr->left, best);
	if(temp->nutrition > best->nutrition)
		best = temp;

	temp = findBestNutritionInternal(curr->right, best);
	if(temp->nutrition > best->nutrition)
		best = temp;
	temp = nullptr;
	return best;
}

plant* planttree::findBestWaterInternal(treenode* curr, plant* best) const
{
	if(curr == NULL)
		return best;

	if(curr->item.getWater() > best->water)
		best = &(curr->item);

	plant * temp;
	temp = findBestWaterInternal(curr->left, best);
	if(temp->water > best->water)
		best = temp;

	temp = findBestWaterInternal(curr->right, best);
	if(temp->water > best->water)
		best = temp;
	temp = nullptr;
	return best;
}