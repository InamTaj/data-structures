//Implement a Dynamic Stack using Link List

#include<iostream>
#include<conio.h>
using namespace std;

template <class mytype>
class NODE	//NODE Class
{
public:
	mytype data;	//template type data variable
	NODE *prev;		//pointer to store address of previous node in stack;

	NODE()
	{
		prev = 0;
	}

	NODE(mytype element, NODE *n=0)	//Constructor 2-arguments
	{
		data = element;
		prev = n;
	}
};

template <class mytype>
class dynamicStack	//Stack Class
{
private:
	NODE<mytype> *top;	//Node pointer to point top of stack
public:

	dynamicStack()		//Constructor
	{
		top = 0;
	}

	~dynamicStack();	//Destructor
	bool is_Empty();	//Function to check if stack is empty
	void push(mytype element);	//Function to push value into stack
	mytype pop();		//Function to pop value from stack
	mytype tell_top();	//Function to tell top of stack
};

template <class mytype>
bool dynamicStack<mytype>::is_Empty()
{
	if(top==0)		//If top pointer has 0, then stack is empty
		return true;
	else
		return false;
}

template <class mytype>
void dynamicStack<mytype>::push(mytype element)
{
	NODE<mytype> *temp = new NODE<mytype>(element, 0);		//Created a new node temp
	temp->prev = top;	//Store address of top into prev of temp
	top = temp;			//move back top 1 node 
}

template <class mytype>
mytype dynamicStack<mytype>::pop()
{
	if(!is_Empty())	//If stack is not empty
	{
		NODE<mytype> *temp = top;	//Created a new node pointer to copy top
		top = temp->prev;			//Move top to its next node
		return temp->data;			//return data of temp (previously top) node
	}
	else			//If stack is empty
	{
		return -1;
	}
}

template <class mytype>
mytype dynamicStack<mytype>::tell_top()
{
	if(!is_Empty())	//If stack is not empty
	{
		return top->data;		//return data of top
	}
	else			//If stack is empty
	{
		return -1;
	}
}

template <class mytype>
dynamicStack<mytype>::~dynamicStack()
{
	if(!is_Empty())		//if stack is not empty
	{
		while(top!=0)	//until stack is empty
		{
			NODE<mytype> *temp = top;//make a copy of top
			top = top->prev;		// move top back
			delete temp;			//delelte memory of previous top
		}
	}
}