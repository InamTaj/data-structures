//Purpose: Impelment a highly flexible template Stack
#include <iostream>
#include <conio.h>
using namespace std;

template <class mytype>		//starting of 
class mystack				//template class, 'mystack'
{
private:
	mytype *dynamic_array;	//pointer to array to be used to store values into STACK
	int topindicator;		//variable to indicate top of stack
	int stacksize;			//variable to indicate if stack is full
	unsigned int arr_size;	//variable to set size of stack
public:
	mystack ()		//Constructor
	{
		cout<<"\nSet Stack Size = ";	
		cin>>arr_size; 	// setting size of stack
		stacksize = arr_size;			//setting stacksize as a reference variable to confirm bound-checking
		topindicator=-1;				//initializing topindicator
		dynamic_array = new mytype[arr_size];		//creating (dynamic array) stack
	}
	~mystack()		//Destructor
	{
		delete dynamic_array;	//Freeing dynamic memory
	}

	void push()		//Function having 'value' variable of datatype 'mytype' to be added to stack
	{
		mytype value;
		if(topindicator>=stacksize-1)	//Checking if stack is full, then display Error.
		{
			cout<<"Stack is FULL!";	
		}
		else		//if stack not full then
		{
			cout<<"\nEnter Item to be pushed = ";	cin>>value;
			dynamic_array[++topindicator] = value;		//add value to current top of stack
		}
	}

	mytype pop()		//generic type function to retrive value from stack
	{
		if(topindicator<0)
		{
			cout<<"\nStack is EMPTY!";	_getch();	exit(1);
		}
		else
		{
			return dynamic_array[topindicator--];
		}
	}

	void stack_check()	//function to check if Stack is full
	{
		if(topindicator==stacksize-1)
		{
			cout<<"Stack is Full!";
		}
		else if(topindicator<0)
		{
			cout<<"Stack is Empty!";
		}
		else
		{
			cout<<"Stack contains some items!";
		}
	}

bool is_Empty()	//function to check if stack is empty
{
	if(topindicator<0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool is_full()	//function to check if stack is full
{
	if(topindicator==stacksize-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

	void make_empty() //function to make Stack empty
	{
		topindicator=-1;
	}

	void tell_top() //function to return top-most item of Stack
	{
		if(topindicator<0)
		{
			cout<<"\nStack Empy!";
		}
		else
		{
			cout<<"Top-Most item = "<<dynamic_array[topindicator];
		}
	}

};
