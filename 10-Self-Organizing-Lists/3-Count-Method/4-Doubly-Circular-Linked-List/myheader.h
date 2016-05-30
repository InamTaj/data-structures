#include<iostream>
#include<conio.h>
using namespace std;
//Objective: Implement a Self Adjusting Doubly Circular Linked List
//--------------------using counting Method
template<class mytype>
class NODE		//template type NODE class
{
public:
	mytype data;	//data variable to store any type of variable
	NODE<mytype> *next, *prev;		//NODE type pointers; 'next' to store address of next node & 'prev' to store address of previous node
	int counter;	//variable to store no. of times a node is accessed

	NODE()	//Constructor 0 argument
	{
		next = prev = 0;		//Initializing both pointers to 0
		counter = 0;
	}

	NODE(mytype element, NODE *n =  0, NODE *p = 0, int c = 0) //Constructor 2-arguments, element variable to store data, create a new node 'n'
	{
		data = element;	//assign user given value to data
		next = n;		//store contents of n into next
		prev = p;		//store contents of p into previous
		counter = c;	//store contents of c into counter
	}
};
//--------------------
template <class mytype>
class DoublyCircularLinkedList	//Class of Singly Linked List
{
private:
	NODE<mytype> *tail;		//NODE type pointer tail to store last node of list
	NODE<mytype> *find_node(mytype element);	//Address returning Function to find a specific node that has a certain data item
public:
	DoublyCircularLinkedList()		//Constructor to initialize head and tail pointer
	{
		tail = 0;
	}
	~DoublyCircularLinkedList();				//Destructor to be defined outside class
	
	bool is_Empty();					//Function to check if Link List is empty
	void add2DCLLhead(mytype element);	//Function to add node to head with user given data, 'element'
	void add2DCLLtail(mytype element);	//Function to add note to tail with user given data, 'element'
	void deletefromDCLLhead();			//Function to delete a node from head of list
	void deletefromDCLLtail();			//Function to delete a node from tail of list
	void delete_item(mytype element);	//Delete a specific node with a certain data item
	bool search_item(mytype element);	//Function to search an item in link list
	void print_list();					//Function to print complete link list
	int total_nodes();					//Function to tell total number of nodes created
	void sortlist();				//Function to sort list nodes based on its 'counter'
};
//--------------------
template <class mytype> 
bool DoublyCircularLinkedList<mytype>::is_Empty()
{
	if(tail==0)	//if head = 0, then list is empty
		return true;
	else
		return false;
}
//--------------------
template <class mytype> 
void DoublyCircularLinkedList<mytype>::add2DCLLhead(mytype element)
{
	NODE<mytype> *temp = new NODE<mytype>(element, 0, 0);	//Created a new node 'temp'
	if(is_Empty())	//If link list is empty, (for creation of 1st Node)
	{
		tail = temp;		//Created a new node temp and pointed both head & tail to temp
		tail->next=tail;	//store address of tail in tail's next so list is circular
	}
	else			//If link list is not empty, then 
	{
		temp->next=tail->next;	//stored address of tail in temp's next
		tail->next->prev=temp;	//stored addres of new node temp in tail's previous, to keep list doubly linked
		tail->next=temp;		//stored address of head (1st) in tail's next, to keep list circular
	}
}
//--------------------
template <class mytype> 
void DoublyCircularLinkedList<mytype>::add2DCLLtail(mytype element)
{
	NODE<mytype>*temp = new NODE<mytype>(element, 0, 0);	//Created a new node and pointed both head & tail to temp

	if(is_Empty())	//If link list is empty, (for creation of 1st Node)
	{
		tail = temp;		//Created a new node temp and pointed both head & tail to temp
		tail->next=tail;	//store address of tail in tail's next so list is circular
	}
	else			//If link list is not empty, then
	{
		temp->next=tail->next;	//store address of head in 'next' of temp node
		tail->next=temp;		//store address of temp in tail's next
		temp->prev=tail;		//store address of tail in temp's previous
		tail=temp;				//move tail to next node
	}
}
//--------------------
template <class mytype> 
void DoublyCircularLinkedList<mytype>::deletefromDCLLhead()
{
	if(is_Empty())//If Link List is empty then display error
	{
		cout<<"ERROR:: Link List is Empty!";
	}
	else		//If Link List is not empty, then 
	{

		if(tail==tail->next)	//if both tail ponits to itself, hence list has only 1 node, then
		{
			tail=0;			//Initialize tail to 0
			delete tail;	//delete head
		}
		else			//if list has multiple nodes, then
		{
			NODE<mytype> *temp = tail->next; //created a new node pointer (to make copy of head)
			tail->next = temp->next;		//stored address of the node after 1st node into last node (to keep list circular)
			temp->prev=0;					//Nullify temp's previous
			delete temp;					// finally delete 1st node
		}
		cout<<"1st Node Deleted from LinkList";
	}
}
//--------------------
template <class mytype> 
void DoublyCircularLinkedList<mytype>::deletefromDCLLtail()
{
	if(is_Empty())	//If Link List is empty then display error
	{
		cout<<"ERROR:: Link List is Empty!";
	}
	else			//If Link List is not empty, then 
	{
		if(tail==tail->next)	//if tail points to itself, hence list has only 1 node, then
		{
			tail=0;			//Initialize both to 0
			delete tail;	//tail deleted
		}
		else			//if link list has multiple nodes
		{
			NODE<mytype> *temp = tail->prev; //created a new node pointer (to make copy of head)
			temp->next=tail->next;	//stored address of 1st node into temp (2nd last node)
			delete tail;			//Delete last node
			tail=temp;				//move back tail to 2nd last node (which is now last)
		}
		cout<<"Last Node Deleted from LinkList";
	}
}
//--------------------
template <class mytype> 
void DoublyCircularLinkedList<mytype>::delete_item(mytype element)
{
	if(!is_Empty())
	{
		if(element==tail->next->data)		//if specified data item is in 1st node
		{
			deletefromDCLLhead();
			cout<<" with Value "<<element;
		}
		else if(element==tail->data)//else if specified data item is in 1st node
		{
			deletefromDCLLtail();
			cout<<" with Value "<<element;
		}
		else		//else if data item is in any middle node
		{
			NODE<mytype> *temp = find_node(element); //created a new node pointer to store specific node temp
			if(temp->data==element)
			{
				temp->prev->next=temp->next;		//put address of temp's next into 'next' of temp's previous node
				temp->next->prev=temp->prev;		//put address of temp's previous node into 'previous' part of temp's next node 
				delete temp;	//Delete node
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
NODE<mytype>* DoublyCircularLinkedList<mytype>::find_node(mytype element)
{
	NODE<mytype> *temp = tail->next;	//created a new node pointer to copy head

	while(temp!=tail && temp->data!=element)	//until Link list ends or data is found (& is used because search stops if data is found in a node)
	{
		temp=temp->next;		//move temp node to next node
	}
	return temp;
}
//-------------------
template <class mytype> 
bool DoublyCircularLinkedList<mytype>::search_item(mytype element)
{
	if(is_Empty())	//Checking if list is empty
	{
		cout<<"ERROR:: Link List is Empty. Data can't be searched..";
	}
	else			// If list not empty
	{
		if(element==tail->next->data)	//If data is in first node
		{
			tail->next->counter++;
			sortlist();
			return true;
		}
		else if(element==tail->data)	//if data is in last node
		{
			tail->counter++;
			sortlist();
			return true;	
		}
		else					//if data is some where in list
		{
			NODE<mytype> *temp = tail->next;	//created a new node pointer
			while(temp!=tail && temp->data!=element)	//until list ends or data is found in list
			{
				temp = temp->next;	//move temp to next node
			}
			if(element==temp->data)	//if data is found in list
			{
				temp->counter++;
				sortlist();
				return true;	
			}
			else	//other wise return false
			{
				return false;
			}
		}
	}
}
//-------------------
template <class mytype>
void DoublyCircularLinkedList<mytype>::print_list()
{
	if(is_Empty())//Checking if Link List is empty
	{
		cout<<"\tERROR:: Link List Is Empty!";
	}
	else		//If link list not empty, then
	{
		NODE<mytype> *temp = tail->next;	//Created a new node pointer to copy head
		while(temp!=tail)		//until temp's next pointer has Null (until link list ends)
		{
			cout<<"| "<<temp->data<<"*"<<temp->counter<<" ";//print node's contents
			temp=temp->next;			//move temp node to next node
		}
		cout<<"| "<<temp->data<<"*"<<temp->counter<<" |";	//print last node
	}
}
//-------------------
template <class mytype>
int DoublyCircularLinkedList<mytype>::total_nodes()
{
	if(!is_Empty())		//If link list is not empty
	{
		int counter=0;	//variable to store counts of nodes in link list
		if(tail==tail->next)	//If link list has just 1 node, 
		{
			return 1;	//then return 1
		}
		else
		{
			NODE<mytype> *temp = tail->next;	//created a node pointer to copy head
			while(temp!=tail)	//Until Link List ends
			{
				counter++;			//Increment counter by 1
				temp=temp->next;	//move temp to next node
			}
			counter++;	//Increment counter for last node
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
void DoublyCircularLinkedList<mytype>::sortlist()
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
DoublyCircularLinkedList<mytype>::~DoublyCircularLinkedList()	//Destructor Function
{
	if(!is_Empty())
	{
		while(tail->next!=tail)
		{
			deletefromDCLLhead();
		}
		deletefromDCLLhead();
	}
}
//-------------------