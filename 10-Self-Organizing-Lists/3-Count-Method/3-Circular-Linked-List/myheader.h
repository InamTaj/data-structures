#include<iostream>
#include<conio.h>
using namespace std;
//Objective: Implement a Self Adjusting Circular Linked List
//--------------------Using Counting Method
template<class mytype>
class NODE		//template type NODE class
{
public:
	mytype data;			//data variable to store any type of variable
	NODE<mytype> *next;		//NODE type pointer to store address of next node
	int counter;			//variable to store no. of times a node is accessed

	NODE()	//Constructor 0 argument
	{
		next = 0;		//Initializing next pointer to 0
		counter = 0;		//Initializing counter to 0
	}

	NODE(mytype element, NODE *n =  0, int c = 0) //Constructor 2-arguments, element variable to store data, create a new node 'n'
	{
		data = element;	//assign user given value to data
		next = n;		//store contents of n into next
		counter = c;	//to store contents of c into counter
	}
};
//--------------------
template <class mytype>
class CircularLinkList	//Class of Circular Linked List
{
private:
	NODE<mytype> *tail;	//NODE type pointer tail to store last node of list
	NODE<mytype> *find_node(mytype element);	//Address returning Function to find a specific node that has a certain data item
public:
	CircularLinkList()	//Constructor to initialize tail pointer
	{
		tail = 0;
	}
	~CircularLinkList();			//Destructor to be defined outside class
	
	bool is_Empty();		//Function to check if Link List is empty
	void add2CLLhead(mytype element);	//Function to add node to head with user given data, 'element'
	void add2CLLtail(mytype element);	//Function to add note to tail with user given data, 'element'
	void deletefromhead();	//Function to delete a node from head of list
	void deletefromtail();	//Function to delete a node from tail of list
	bool search_item(mytype element);	//Function to search an item in Queue
	void delete_item(mytype element);	//Delete a specific node with a certain data item
	void print_list();		//Function to print complete link list
	int total_nodes();		//Function to tell total number of nodes created
	void sortlist();				//Function to sort list nodes based on its 'counter'
};
//--------------------
template <class mytype> 
bool CircularLinkList<mytype>::is_Empty()
{
	if(tail==0)	//if tail = 0, then list is empty
		return true;
	else
		return false;
}
//--------------------
template <class mytype> 
void CircularLinkList<mytype>::add2CLLhead(mytype element)
{
	NODE<mytype> *temp = new NODE<mytype>(element, 0);	//Created a new node 'temp'

	if(is_Empty())	//If link list is empty, (for creation of 1st Node)
	{
		tail = temp;		//point tail to temp node
		tail->next=tail;	//store address of tail in tail's next so list is circular
	}
	else		//If link list is not empty, then 
	{
		temp->next=tail->next;	//store address of head in 'next' of temp node
		tail->next=temp;		//and move back head to temp node
	}
}
//--------------------
template <class mytype> 
void CircularLinkList<mytype>::add2CLLtail(mytype element)
{
	NODE<mytype> *temp = new NODE<mytype>(element, 0);	//Created a new node

	if(is_Empty())	//If link list is empty, (for creation of 1st Node)
	{
		tail = temp;	//point tail to temp
		tail->next=tail;//store address of tail in tail's next so list is circular
	}
	else		//If link list is not empty, then
	{
		temp->next=tail->next;	//put address of 1st node in temp's next (last node)
		tail->next=temp;		//put address of last node into 2nd last node's (tail) 'next'
		tail=temp;				//move tail 1 step further
	}
}
//--------------------
template <class mytype> 
void CircularLinkList<mytype>::deletefromhead()
{
	if(is_Empty())	//If Link List is empty then display error
	{
		cout<<"ERROR:: Link List is Empty!";
	}
	else			//If Link List is not empty, then 
	{
		if(tail->next==tail)	//if tail points to itself, hence list has only 1 node, then
		{
			tail=0;	//Initialize both to 0, memory will be deleted later
			delete tail;
		}
		else		//if list has multiple nodes, then
		{
			NODE<mytype> *temp = tail->next; //created a new node pointer (to make copy of head)
			tail->next = temp->next;		//stored address of the node after 1st node into last node (to keep list circular)
			delete temp;					// finally delete 1st node
		}
		cout<<"1st Node Deleted from LinkList";
	}
}
//--------------------
template <class mytype> 
void CircularLinkList<mytype>::deletefromtail()
{
	if(is_Empty())	//If Link List is empty then display error
	{
		cout<<"ERROR:: Link List is Empty!";
	}
	else			//If Link List is not empty, then 
	{
		if(tail->next==tail)	//if tail points to itself, hence list has only 1 node, then
		{
			tail=0;				//Initialize both to 0, memory will be deleted later
			delete tail;
		}
		else		//if link list has multiple nodes
		{
			NODE<mytype> *temp = tail->next; //created a new node pointer (to make copy of head)
			while(temp->next!=tail)	//until temp reaches last node
			{
				temp=temp->next;	//move temp node to next node
			}
			temp->next=tail->next;	//stored address of 1st node into temp (2nd last node)
			delete tail;			//Delete tail node
			tail=temp;				//move back tail to 2nd last node
		}
			cout<<"Last Node Deleted from LinkList";
	}
}
//--------------------
template <class mytype>
bool CircularLinkList<mytype>::search_item(mytype element)
{
	if(!is_Empty())
	{
		NODE<mytype> *temp = tail->next;		//created a new node pointer to copy head
		while(temp!=tail && temp->data!=element)//until Queue ends or data is found (& is used because search STOPS if data is found in a node)
		{
			temp=temp->next;	//move temp node to next node
		}
		if(temp->data==element)
		{
			temp->counter++;
			sortlist();
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout<<"ERROR:: Link List is Empty.. Data item can't be searched";
	}
}
//--------------------
template <class mytype> 
void CircularLinkList<mytype>::delete_item(mytype element)
{
	if(!is_Empty())	//If Link List not empty
	{
		if(element==tail->next->data)		//if specified data item is in 1st node
		{
			deletefromhead();	//calling function
			cout<<" with Value "<<element;
		}
		else if(element==tail->data)//else if specified data item is in 1st node
		{
			deletefromtail();	//calling function
			cout<<" with Value "<<element;
		}
		else		//else if data item is in any middle node
		{
			NODE<mytype> *temp = find_node(element); //created a new node pointer to store specific node temp

			if(temp->data==element)	//if element found in the node
			{
				NODE<mytype> *prev = tail->next;	//created a new node to copy head (i.e. tail->next), & to reach node before temp node
				while(prev->next!=temp)		//until prev node reaches the node before that node whose data is specified data (i.e. temp node)
				{
					prev=prev->next;	//move prev to next node
				}
				prev->next=temp->next;	//store address of temp's next node in 'next' of prev node, so temp is skipped from list
				delete temp;			//Finally delet temp node

				cout<<"Node Deleted with Value "<<element;
			}
			else
			{
				cout<<"ERROR:: Node Not Found that has "<<element;
			}
		}
	}
	else
	{
		cout<<"ERROR:: Link List is Empty.. Data Item can't be searched.";
	}
}
//--------------------
template <class mytype> 
NODE<mytype>* CircularLinkList<mytype>::find_node(mytype element)
{
	NODE<mytype> *temp = tail->next;	//created a new node pointer to copy head (i.e. tail->next)

	while(temp!=tail && temp->data!=element)	//until Link list ends or data is found (& is used because search STOPS if data is found in a node)
	{
		temp=temp->next;	//move temp node to next node
	}
	return temp;
}
//-------------------
template <class mytype>
void CircularLinkList<mytype>::print_list()
{
	if(is_Empty())		//Checking if Link List is empty
	{
		cout<<"\tERROR:: Link List Is Empty!";
	}
	else		//If link list not empty, then
	{
		NODE<mytype> *temp = tail->next;	//Created a new node pointer to copy head (tail->next)

		while(temp!=tail)	//until temp's next pointer reaches tail
		{
			cout<<"| "<<temp->data<<"*"<<temp->counter<<" ";		//print node's contents
			temp=temp->next;	//move temp node to next node
		}
		cout<<"| "<<temp->data<<"*"<<temp->counter<<" |";			//print last node
	}
}
//-------------------
template <class mytype>
int CircularLinkList<mytype>::total_nodes()
{
	if(!is_Empty())	//If link list is not empty
	{
		int counter=0;	//variable to store counts of nodes in link list
		NODE<mytype> *temp = tail->next;	//created a node pointer to copy head (temp->next)
		if(tail->next==tail)	//If link list has just 1 node, 
		{
			return 1;	//then return 1
		}
		else
		{
			while(temp!=tail)	//Until Link List ends
			{
				counter++;		//Increment counter by 1
				temp=temp->next;	//move temp to next node
			}
			counter++;	//Increment again for last node
			return counter;
		}

	}
	else	//If link list is empty, then
	{
		return 0;	//return 0
	}
}
//-------------------
template <class mytype>
void CircularLinkList<mytype>::sortlist()
{
	if(!is_Empty())		//perform sorting if list is not empty
	{
		if(tail->next==tail)	//if list has only 1 node, then
		{
			//Do Nothing
		}
		else	//else if list has multiple nodes
		{
			NODE<mytype> *temp;	//temporary pointer to store head
			mytype var;			//temporary variable to store data values for swap
			int cntr;			//temporary variable to store counter values to swap
			for(int i = 1 ; i<total_nodes(); i++)	//repeat the sorting process until totalnodoes-1 times
			{
				temp = tail->next;	//initialized temp to head so everytime sort check is started from begining of list
				while (temp!=tail)//until list ends
				{
					if((temp->next->counter) > (temp->counter))
					{
						var = temp->data;
						temp->data = temp->next->data;
						temp->next->data = var;
						//------------------------------
						cntr = temp->counter;
						temp->counter = temp->next->counter;
						temp->next->counter = cntr;
					}
					temp = temp->next;
				}
			}
		}
	}
}
//-------------------
template <class mytype> 
CircularLinkList<mytype>::~CircularLinkList()	//Destructor Function
{
	if(!is_Empty())	//If link list not empty
	{
		while(tail->next!=tail)	//until link list has only 1 node
		{
			deletefromhead();	//keep deleteing
		}
		deletefromhead();		//finally delete last node too
	}
}
//-------------------