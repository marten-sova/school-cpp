#ifndef STACK_H
#define STACK_H

#include "location.h"
class stack 
{
public:
	stack(); 
	stack(const stack& aStack);
	~stack();

	const stack& operator= (const stack& aStack);

	bool push(const location&);
	bool pop(location&);

	bool peek(location&)const;
	bool isEmpty(void)const;

private:	
	struct node
	{
		location pair; // x,y
		node * next;
	};
	node * top;
};
#endif