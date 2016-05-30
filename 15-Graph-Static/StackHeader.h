//Implement a Dynamic Stack using Link List
//--------------------
template <class mytype>
class StackNODE	//StackNODE Class
{
public:
	mytype data;	//template type data variable
	StackNODE *prev;		//pointer to store address of previous StackNODE in stack;

	StackNODE()	//Constructor
	{
		prev = 0;
	}

	StackNODE(mytype element, StackNODE *n=0)	//Constructor 2-arguments
	{
		data = element;
		prev = n;
	}
};
//------------------
template <class mytype>
class dynamicStack	//Stack Class
{
private:
	StackNODE<mytype> *top;	//StackNODE pointer to point top of stack
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
//-----------------
template <class mytype>
bool dynamicStack<mytype>::is_Empty()
{
	if(top==0)		//If top pointer has 0, then stack is empty
		return true;
	else
		return false;
}
//-----------------
template <class mytype>
void dynamicStack<mytype>::push(mytype element)
{
	StackNODE<mytype> *temp = new StackNODE<mytype>(element, 0);		//Created a new StackNODE temp
	temp->prev = top;	//Store address of top into prev of temp
	top = temp;			//move back top 1 StackNODE 
}
//-----------------
template <class mytype>
mytype dynamicStack<mytype>::pop()
{
	if(!is_Empty())	//If stack is not empty
	{
		StackNODE<mytype> *temp = top;	//Created a new StackNODE pointer to copy top
		top = temp->prev;			//Move top to its next StackNODE
		return temp->data;			//return data of temp (previously top) StackNODE
	}
	else			//If stack is empty
	{
		return -1;
	}
}
//-----------------
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
//-----------------
template <class mytype>
dynamicStack<mytype>::~dynamicStack()
{
	if(!is_Empty())		//if stack is not empty
	{
		while(top!=0)	//until stack is empty
		{
			StackNODE<mytype> *temp = top;//make a copy of top
			top = top->prev;		// move top back
			delete temp;			//delelte memory of previous top
		}
	}
}