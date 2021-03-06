#include<iostream>
#include<conio.h>
using namespace std;
//Objective: Implement a Self Adjusting Doubly Linked List
//--------------------using counting method
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
		counter = 0;		//Initializing counter to 0
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
class DoublyLinkedList	//Class of Singly Linked List
{
private:
	NODE<mytype> *head;		//NODE type pointer head to store 1st node of list
	NODE<mytype> *tail;		//NODE type pointer tail to store last node of list
	NODE<mytype> *find_node(mytype element);	//Address returning Function to find a specific node that has a certain data item
public:
	DoublyLinkedList()		//Constructor to initialize head and tail pointer
	{
		head = tail = 0;
	}
	~DoublyLinkedList();				//Destructor to be defined outside class
	
	bool is_Empty();					//Function to check if Link List is empty
	void add2DLLhead(mytype element);	//Function to add node to head with user given data, 'element'
	void add2DLLtail(mytype element);	//Function to add note to tail with user given data, 'element'
	void deletefromDLLhead();			//Function to delete a node from head of list
	void deletefromDLLtail();			//Function to delete a node from tail of list
	void delete_item(mytype element);	//Delete a specific node with a certain data item
	bool search_item(mytype element);	//Function to search an item in link list
	void print_list();					//Function to print complete link list
	int total_nodes();					//Function to tell total number of nodes created
	void sortlist();					//Function to sort list nodes based on its 'counter'
};
//--------------------
template <class mytype> 
bool DoublyLinkedList<mytype>::is_Empty()
{
	if(head==0)	//if head = 0, then list is empty
		return true;
	else
		return false;
}
//--------------------
template <class mytype> 
void DoublyLinkedList<mytype>::add2DLLhead(mytype element)
{
	

	if(is_Empty())	//If link list is empty, (for creation of 1st Node)
	{
		head = tail = new NODE<mytype>(element, 0, 0);		//Created a new node temp and pointed both head & tail to temp
	}
	else			//If link list is not empty, then 
	{
		NODE<mytype> *temp = new NODE<mytype>(element, 0);	//Created a new node 'n'
		temp->next=head;	//address of head stored in next of temp
		head->prev=temp;	//address of temp stored in previous of temp
		head=temp;			//moved head to 1 step back
	}
}
//--------------------
template <class mytype> 
void DoublyLinkedList<mytype>::add2DLLtail(mytype element)
{
	

	if(is_Empty())	//If link list is empty, (for creation of 1st Node)
	{
		head = tail = new NODE<mytype>(element, 0, 0);	//Created a new node and pointed both head & tail to temp
	}
	else			//If link list is not empty, then
	{
		NODE<mytype> *temp = new NODE<mytype>(element, 0, 0);	//Created a new node
		tail->next=temp;		//stored address of temp in tail's next
		temp->prev=tail;		//stored address of tail in temp's previous
		tail = temp;			//moved tail 1 step forward
	}
}
//--------------------
template <class mytype> 
void DoublyLinkedList<mytype>::deletefromDLLhead()
{
	if(is_Empty())//If Link List is empty then display error
	{
		cout<<"ERROR:: Link List is Empty!";
	}
	else		//If Link List is not empty, then 
	{

		if(head==tail)	//if both point to same node, hence list has only 1 node, then
		{
			head=tail=0;	//Initialize both to 0
			delete head;	//delete head
		}
		else			//if list has multiple nodes, then
		{
			head = head->next;	//move head to next node
			delete head->prev;	//delete address of previous node
			head->prev=0;		//Nullify head's previous
		}
		cout<<"1st Node Deleted from LinkList";
	}
}
//--------------------
template <class mytype> 
void DoublyLinkedList<mytype>::deletefromDLLtail()
{
	if(is_Empty())	//If Link List is empty then display error
	{
		cout<<"ERROR:: Link List is Empty!";
	}
	else			//If Link List is not empty, then 
	{
		NODE<mytype> *temp = head;	//created a new node pointer (to copy head)
		
		if(head==tail)	//if both point to same node, hence list has only 1 node, then
		{
			head=tail=0;	//Initialize both to 0
			delete head;	//head deleted
		}
		else			//if link list has multiple nodes
		{
			tail=tail->prev;	//Move back tail 1 node
			delete tail->next;	//Delete address of last node stored in tail's next
			tail->next=0;		//Nullify tail's next
		}
		cout<<"Last Node Deleted from LinkList";
	}
}
//--------------------
template <class mytype> 
void DoublyLinkedList<mytype>::delete_item(mytype element)
{
	if(!is_Empty())
	{
		if(element==head->data)		//if specified data item is in 1st node
		{
			deletefromDLLhead();
			cout<<" with Value "<<element;
		}
		else if(element==tail->data)//else if specified data item is in 1st node
		{
			deletefromDLLtail();
			cout<<" with Value "<<element;
		}
		else		//else if data item is in any middle node
		{
			NODE<mytype> *temp = find_node(element); //created a new node pointer to store specific node temp

			if(temp->next!=0)
			{
				temp->prev->next=temp->next;		//put address of temp's next into 'next' of temp's previous node
				temp->next->prev=temp->prev;		//put address of temp's previous node into 'previous' part of temp's next node 
				delete temp;		//Delete node
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
NODE<mytype>* DoublyLinkedList<mytype>::find_node(mytype element)
{
	NODE<mytype> *temp = head;	//created a new node pointer to copy head

	while(temp->next!=0 && temp->data!=element)	//until Link list ends or data is found (& is used because search stops if data is found in a node)
	{
		temp=temp->next;		//move temp node to next node
	}
	return temp;
}
//-------------------
template <class mytype> 
bool DoublyLinkedList<mytype>::search_item(mytype element)
{
	if(is_Empty())	//Checking if list is empty
	{
		cout<<"ERROR:: Link List is Empty. Data can't be searched..";
	}
	else			// If list not empty
	{
		if(element==head->data)	//If data is in first node
		{
			head->counter++;
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
			NODE<mytype> *temp = head;	//created a new node pointer
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
void DoublyLinkedList<mytype>::print_list()
{
	if(is_Empty())//Checking if Link List is empty
	{
		cout<<"\tERROR:: Link List Is Empty!";
	}
	else		//If link list not empty, then
	{
		NODE<mytype> *temp = head;	//Created a new node pointer to copy head
		while(temp->next!=0)		//until temp's next pointer has Null (until link list ends)
		{
			cout<<"| "<<temp->data<<"*"<<temp->counter<<" ";//print node's contents
			temp=temp->next;			//move temp node to next node
		}
		cout<<"| "<<temp->data<<"*"<<temp->counter<<" |";	//print last node
	}
}
//-------------------
template <class mytype>
int DoublyLinkedList<mytype>::total_nodes()
{
	if(!is_Empty())		//If link list is not empty
	{
		int counter=0;	//variable to store counts of nodes in link list
		NODE<mytype> *temp = head;	//created a node pointer to copy head
		if(head==tail)	//If link list has just 1 node, 
		{
			return 1;	//then return 1
		}
		else
		{
			while(temp->next!=0)	//Until Link List ends
			{
				counter++;			//Increment counter by 1
				temp=temp->next;	//move temp to next node
			}
			counter++;
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
void DoublyLinkedList<mytype>::sortlist()
{
	if(!is_Empty())		//perform sorting if list is not empty
	{
		if(head==tail)	//if list has only 1 node, then
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
				temp = head;	//initialized temp to head so everytime sort check is started from begining of list
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
DoublyLinkedList<mytype>::~DoublyLinkedList()	//Destructor Function
{
	if(!is_Empty())
	{
		while(head!=0)
		{
			deletefromDLLhead();
		}
	}
}
//-------------------