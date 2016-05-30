#include<iostream>
#include<conio.h>
using namespace std;
//Objective: Implement a Dynamic Queue
-
template<class mytype>
class NODE		//template type NODE class
{
public:
	mytype data;			//data variable to store any type of variable
	NODE<mytype> *next;		//NODE type pointer to store address of next node

	NODE()	//Constructor 0 argument
	{
		next = 0;		//Initializing next pointer to 0
	}

	NODE(mytype element, NODE *n =  0) //Constructor 2-arguments, element variable to store data, create a new node 'n'
	{
		data = element;	//assign user given value to data
		next = n;		//store contents of n into next
	}
};
-
template <class mytype>
class dynamicQueue	//Class of Dynamic Queue
{
private:
	NODE<mytype> *tail;		//NODE type pointer tail to store last node of queue
	NODE<mytype> *find_node(mytype element);	//Address returning Function to find a specific data item in Queue
public:
	dynamicQueue()	//Constructor to initialize tail pointer
	{
		tail = 0;
	}
	~dynamicQueue();			//Destructor to be defined outside class
	
	bool is_Empty();				//Function to check if Queue is empty
	void enqueue(mytype element);	//Function to add note to tail with user given data, 'element'
	void dequeue();					//Function to delete a node from head of queue
	bool search_item(mytype element);//Function to search an item in Queue
	void delete_item(mytype element);//Delete a specific node with a certain data item
	void print_queue();				//Function to print complete queue
	int total_items();				//Function to tell total number of items in queue
};
-
template <class mytype> 
bool dynamicQueue<mytype>::is_Empty()
{
	if(tail==0)	//if tail = 0, then queue is empty
		return true;
	else
		return false;
}
template <class mytype> 
void dynamicQueue<mytype>::enqueue(mytype element)
{
	NODE<mytype> *temp = new NODE<mytype>(element, 0);	//Created a new node

	if(is_Empty())	//If Queue is empty, (for creation of 1st Node)
	{
		tail = temp;	//point tail to temp
		tail->next=tail;//store address of tail in tail's next so list is circular
	}
	else		//If Queue is not empty, then
	{
		temp->next=tail->next;	//put address of 1st node in temp's next (last node)
		tail->next=temp;		//put address of last node into 2nd last node's (tail) 'next'
		tail=temp;				//move tail 1 step further
	}
}
-
template <class mytype> 
void dynamicQueue<mytype>::dequeue()
{
	if(is_Empty())	//If Queue is empty then display error
	{
		cout<<"ERROR:: Queue is Empty!";
	}
	else	//If Queue is not empty, then 
	{
		if(tail->next==tail)	//if tail points to itself, hence Queue has only 1 node, then
		{
			tail=0;		//Initialize both to 0
			delete tail;//delete tail node
		}
		else	//if list has multiple nodes, then
		{
			NODE<mytype> *temp = tail->next; //created a new node pointer to make copy of head (i.e. tail->next)
			tail->next = temp->next;	//stored address of the 2nd node into last node (to keep Queue circular)
			delete temp;	// finally delete 1st node
		}
		cout<<"1st Item Deleted from Queue";
	}
}
template <class mytype> 
void dynamicQueue<mytype>::delete_item(mytype element)
{
	if(!is_Empty())	//If Queue not empty
	{
		if(element==tail->next->data)		//if specified data item is in 1st node
		{
			dequeue();	//calling function
			cout<<" with Value "<<element;
		}
		else		//else if data item is in any middle node
		{
			NODE<mytype> *temp = find_node(element); //created a new node pointer to store specific node temp

			if(tail->data==element)	//If data is present in tail
			{
				NODE<mytype> *temporary = tail->next; //created a new node pointer (to make copy of head)
				while(temporary->next!=tail)		 //until temporary reaches last node
				{
					temporary=temporary->next;	//move temporary node to next node
				}
				temporary->next=tail->next;	//stored address of 1st node into temporary (2nd last node)
				delete tail;				//Delete tail node
				tail=temporary;				//move back tail to 2nd last node
				cout<<"Last Item Deleted with Value "<<element;
			}
			else if(temp->data==element)	//if element found in the node
			{
				NODE<mytype> *prev = tail->next;	//created a new node to copy head (i.e. tail->next), & to reach node before temp node
				while(prev->next!=temp)	//until prev node reaches the node before that node whose data is specified data (i.e. temp node)
				{
					prev=prev->next;	//move prev to next node
				}
				prev->next=temp->next;	//store address of temp's next node in 'next' of prev node, so temp is skipped from Queue
				delete temp;			//Finally delet temp node

				cout<<"Item Deleted with Value "<<element;
			}
			else
			{
				cout<<"ERROR:: Item Not Found that has "<<element;
			}
		}
	}
	else
	{
		cout<<"ERROR:: Queue is Empty.. Data Item can't be searched.";
	}
}
-
template <class mytype> 
NODE<mytype>* dynamicQueue<mytype>::find_node(mytype element)
{
	NODE<mytype> *temp = tail->next;	//created a new node pointer to copy head (i.e. tail->next)

	while(temp!=tail && temp->data!=element)	//until Queue ends or data is found (& is used because search STOPS if data is found in a node)
	{
		temp=temp->next;	//move temp node to next node
	}
	return temp;
}

template <class mytype>
bool dynamicQueue<mytype>::search_item(mytype element)
{
	if(!is_Empty())
	{
		NODE<mytype> *temp = tail->next;	//created a new node pointer to copy head
		while(temp!=tail && temp->data!=element)	//until Queue ends or data is found (& is used because search STOPS if data is found in a node)
		{
			temp=temp->next;	//move temp node to next node
		}
		if(temp->data==element)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout<<"ERROR:: Queue is Empty.. Data item can't be searched";
	}
}

template <class mytype>
void dynamicQueue<mytype>::print_queue()
{
	if(is_Empty())		//Checking if Queue is empty
	{
		cout<<"\tERROR:: Queue Is Empty!";
	}
	else		//If Queue not empty, then
	{
		NODE<mytype> *temp = tail->next;	//Created a new node pointer to copy head (tail->next)

		while(temp!=tail)	//until temp's next pointer reaches tail
		{
			cout<<"| "<<temp->data<<" ";		//print node's contents
			temp=temp->next;	//move temp node to next node
		}
		cout<<"| "<<temp->data<<" |";			//print last node
	}
}

template <class mytype>
int dynamicQueue<mytype>::total_items()
{
	if(!is_Empty())	//If Queue is not empty
	{
		int counter=0;	//variable to store counts of nodes in Queue
		NODE<mytype> *temp = tail->next;	//created a node pointer to copy head (temp->next)
		if(tail->next==tail)	//If Queue has just 1 node, 
		{
			return 1;	//then return 1
		}
		else
		{
			while(temp!=tail)	//Until Queue ends
			{
				counter++;		//Increment counter by 1
				temp=temp->next;	//move temp to next node
			}
			counter++;	//Increment again for last node
			return counter;
		}

	}
	else	//If Queue is empty, then
	{
		return 0;	//return 0
	}
}

template <class mytype> 
dynamicQueue<mytype>::~dynamicQueue()	//Destructor Function
{
	if(!is_Empty())	//If Queue not empty
	{
		while(tail->next!=tail)	//until link list has only 1 node
		{
			dequeue();	//keep deleteing
		}
		dequeue();		//finally delete last node too
	}
}