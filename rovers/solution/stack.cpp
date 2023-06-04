#include "stack.h"
#include <fstream>
#include <cassert>

stack::stack():top(NULL)
{
}

stack::stack(const stack& aStack)
{
	if(aStack.top == NULL) 
		top = NULL;
	else
	{
		//copy first node
		top = new node;
		assert(top != NULL); //check allocation
		top->pair = aStack.top->pair;

		//copy the rest of the list
		node * destNode = top;				//points to the last node in new stack
		node * srcNode = aStack.top->next;  //points to node in aStack
		while(srcNode != NULL) //or while (srcNode)
		{
			destNode->next = new node;
			assert(destNode->next != NULL); //check allocation
			destNode = destNode->next;
			destNode->pair = srcNode->pair;

			srcNode = srcNode->next;
		}
		destNode->next = NULL;
	}		
	
}

const stack& stack::operator=(const stack& aStack)
{
	if(this == &aStack)
		return *this;
	else
	{
		//release dynamically allocated memory held by current object
		node * curr = top;
		while(top)
		{
			curr = top->next;
			delete top;
			top = curr;
		}

		//make *this a deep copy of "aStack"
		if(!aStack.top)
			top = NULL;
		else
		{
			//copy the first node
			top = new node;
			assert(top != NULL);
			top->pair = aStack.top->pair;

			//copy the rest of the stack
			node * destNode = top;
			node * srcNode = aStack.top->next;

			while(srcNode)
			{
				destNode->next = new node;
				assert(destNode->next);
				destNode = destNode->next;
				destNode->pair = srcNode->pair;

				srcNode = srcNode->next;
			}
			destNode->next = NULL;
		}

		return *this;
	}
}

stack::~stack()
{
	node * curr = top;
	while(top)
	{
		curr = top->next;
		delete top;
		top = curr;
	}
	top = NULL;
}

bool stack::push(const location& pair)
{
	//create new node
	node * newNode = new node;
	newNode->pair = pair;
	newNode->next = NULL;

	//add on top
	newNode->next = top;
	top = newNode;

	return true;
}

bool stack::pop (location& pair)
{
	//empty stack, has nothing to pop
	node * temp;
	if(isEmpty())
		return false;
	else
	{
		pair = top->pair;
		temp = top;
		top = top->next;
		delete temp;
		return true;
	}
}

bool stack::isEmpty () const
{
	return top==NULL;
}

bool stack::peek (location& pair)const
{
	if(isEmpty())
		return false;
	else
	{
		pair = top->pair;
		return true;
	}
}
