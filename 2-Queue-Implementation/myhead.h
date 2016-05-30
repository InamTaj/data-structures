//Purpose = Implement a highly flexible template circular queue using array

#include <iostream>
#include <conio.h>
using namespace std;

template <class mytype, int size = 100>	//template class
class myQueue	//class name 'myqueue'
{
protected:
	int front, back;				//'front' variable to show front of queue, while 'back' variable to show end of queue
	mytype queue_storage[size];		//storage array

public:
	myQueue()		//Constructor for initialization
	{
		front = back = -1;			//initialized front & end of queue to -1
	}

	bool full_check()
	{
		if(front==0 && back==size-1)	//if front points at 1st index, and back points to last index then 
			return true;				//queue is full
		else if(front==back+1)			//OR if front index is ahead (after) the back index, then 
			return true;				//queue is full
		else							//otherwise
			return false;				//queue is not full
	}

	bool empty_check()
	{
		if (front==-1)					//if front index = -1, then
			return true;				//queue is empty
		else
			return false;				//otherwise not
	}

	void enqueue(mytype);				//enqueue function to be defined outside the class
	mytype dequeue();					//dequeue function to be defined outside the class
};


template<class mytype, int size> 
void myQueue<mytype, size>::enqueue(mytype new_entry)
{	//OBJECTIVE = TO ADD A GIVEN ELEMENT INTO QUEUE

	if(!full_check())		//Checking if queue is full
	{
		if(back==-1)	//Checking if queue is empty; back index=-1
		{
			back=0;							//assign back=0;
			queue_storage[0] = new_entry;	//add new_entry to 1st index of queue
			front=0;						//also make front index = 0; beacuse for only one content in queue, front==back
			cout<<endl<<new_entry<<" added into Queue.";	//message statement
		}
		else if(back==size-1)	//Checking if back is at last index of queue
		{
			back=0;				//assign back = 0
			queue_storage[0] = new_entry;			//add new_entry to 1st index of queue
			cout<<endl<<new_entry<<" added into Queue.";	//message statement
		}
		else	//if queue has already some items & back is anywhere in array, then
		{
			queue_storage[++back] = new_entry; //increment back to next location, then insert new_entry 
			cout<<endl<<new_entry<<" added into Queue.";	//message statement
		}
	}
	else
	{
		cout<<"\n\tQueue is already Full!";
	}

}


template<class mytype, int size> 
mytype myQueue<mytype, size>::dequeue()
{ 	//OBJECTIVE = TO DELETE (SERVING FIRST) AN ELEMENT FROM QUEUE

	mytype temp;		//decleard a 'temp' variable of mytype

	if(!empty_check())	//Checking if queue is empty
	{
		temp = queue_storage[front];	//Storing front index of queue into temp
		if(back==front)				//if both are pointing to 1st element of queue then
		{
			back=front= -1;			//intialize both to -1
		}
		else if(front==size-1)		//if front index is at last index then
		{
			front = 0;				//initialize front index to 0
		}
		else						//otherwise if front is anywhere in queue, then
		{
			front++;				//increment front by 1
		}
		return temp;				//return temp (content pointed by front)
	}
	else
	{
		cout<<"\n\tQueue already Empty!";
	}
}
