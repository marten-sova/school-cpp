#ifndef LIST_H
#define LIST_H

#include <cstring>
#include <ostream>
#include "family.h"

class list
{
public:
	list();
	list(const list& aList);
	~list();

	const list& operator=(const list& aList);

	bool insert(const family& aFamily);
	bool remove(const char* key);
	bool retrieve(const char* key, family& aFamily) const;
	int getSize(void) const;

	friend std::ostream& operator<<(std::ostream& out, const list& lst);

private:
	struct node
	{
		family entry;
		node * next;
	};

	node*	head;
	int		size;
};

#endif
