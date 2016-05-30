#include<iostream>
#include<conio.h>
using namespace std;
//Objective: Implement a Singly Linked List
//--------------------
template<class mytype>
class ListNODE		//template type ListNODE class
{
public:
	mytype data;			//data variable to store any type of variable
	ListNODE<mytype> *next;		//ListNODE type pointer to store address of next ListNODE

	ListNODE()	//Constructor 0 argument
	{
		next = 0;		//Initializing next pointer to 0
	}

	ListNODE(mytype element, ListNODE *n =  0) //Constructor 2-arguments, element variable to store data, create a new ListNODE 'n'
	{
		data = element;	//assign user given value to data
		next = n;		//store contents of n into next
	}
};
//--------------------
template <class mytype>
class SingleLinkList	//Class of Singly Linked List
{
protected:
	ListNODE<mytype> *head;		//ListNODE type pointer head to store 1st ListNODE of list
	ListNODE<mytype> *tail;		//ListNODE type pointer tail to store last ListNODE of list
	ListNODE<mytype> *find_ListNODE(mytype element);	//Address returning Function to find a specific ListNODE that has a certain data item
public:
	SingleLinkList()	//Constructor to initialize head and tail pointer
	{
		head = tail = 0;
	}
	~SingleLinkList();				//Destructor to be defined outside class

	bool is_Empty();				//Function to check if Link List is empty
	void add2head(mytype element);	//Function to add ListNODE to head with user given data, 'element'
	void add2tail(mytype element);	//Function to add note to tail with user given data, 'element'
	void deletefromhead();			//Function to delete a ListNODE from head of list
	void deletefromtail();			//Function to delete a ListNODE from tail of list
	void delete_item(mytype element);//Delete a specific ListNODE with a certain data item
	bool search_item(mytype element);//Function to search user given data in list
	void print_list();				//Function to print complete link list
	int total_items();				//Function to tell total number of ListNODEs created
	mytype ReturnElement(int j);	//Function to return value of a specific node
};
//--------------------
template <class mytype> 
bool SingleLinkList<mytype>::is_Empty()
{
	if(head==0)	//if head = 0, then list is empty
		return true;
	else
		return false;
}
//--------------------
template <class mytype> 
void SingleLinkList<mytype>::add2head(mytype element)
{
	ListNODE<mytype> *temp = new ListNODE<mytype>(element, 0);	//Created a new ListNODE 'n'

	if(is_Empty())	//If link list is empty, (for creation of 1st ListNODE)
	{
		head = tail = temp;	//point both head & tail to n
	}
	else			//If link list is not empty, then 
	{
		temp->next=head;	//store address of head into next of temp ListNODE
		head=temp;			//and move back head to temp ListNODE
	}
}
//--------------------
template <class mytype> 
void SingleLinkList<mytype>::add2tail(mytype element)
{
	ListNODE<mytype> *temp = new ListNODE<mytype>(element, 0);	//Created a new ListNODE

	if(is_Empty())	//If link list is empty, (for creation of 1st ListNODE)
	{
		head = tail = temp;	//point both head & tail to n
	}
	else			//If link list is not empty, then
	{
		tail->next=temp;
		tail=temp;
	}
}
//--------------------
template <class mytype> 
void SingleLinkList<mytype>::deletefromhead()
{
	if(is_Empty())	//If Link List is empty then display error
	{
		cout<<"ERROR:: Link List is Empty!";
	}
	else			//If Link List is not empty, then 
	{
		ListNODE<mytype> *temp = head; //created a new ListNODE pointer (to make copy of head)

		if(head==tail)	//if both point to same ListNODE, hence list has only 1 ListNODE, then
		{
			head=tail=0;//Initialize both to 0, memory will be deleted later
		}
		else			//if list has multiple ListNODEs, then
		{
			head = head->next;	//move head to next ListNODE
		}
		delete temp;			//satisifying any of above conditions, finally delete ListNODE (1st ListNODE)
		cout<<"1st ListNODE Deleted from LinkList";
	}
}
//--------------------
template <class mytype> 
void SingleLinkList<mytype>::deletefromtail()
{
	if(is_Empty())	//If Link List is empty then display error
	{
		cout<<"ERROR:: Link List is Empty!";
	}
	else			//If Link List is not empty, then 
	{
		ListNODE<mytype> *temp = head;	//created a new ListNODE pointer (to copy head)
		
		if(head==tail)		//if both point to same ListNODE, hence list has only 1 ListNODE, then
		{
			head=tail=0;	//Initialize both to 0
			delete head;	//head deleted
		}
		else		//if link list has multiple ListNODEs
		{
			while(temp->next!=tail)	//until temp is second last ListNODE
			{
				temp=temp->next;	//move temp ListNODE to next ListNODE
			}
			delete tail;	//Delete tail ListNODE
			tail=temp;		//now assign tail to second last ListNODE
			tail->next=0;	//Nullify tail's next
		}
			cout<<"ERROR:: Last ListNODE Deleted from LinkList";
	}
}
//--------------------
template <class mytype> 
void SingleLinkList<mytype>::delete_item(mytype element)
{
	if(!is_Empty())
	{
		if(element==head->data)		//if specified data item is in 1st ListNODE
		{
			deletefromhead();
			cout<<" with Value "<<element;
		}
		else if(element==tail->data)//else if specified data item is in 1st ListNODE
		{
			deletefromtail();
			cout<<" with Value "<<element;
		}
		else		//else if data item is in any middle ListNODE
		{
			ListNODE<mytype> *temp = find_ListNODE(element); //created a new ListNODE pointer to store specific ListNODE temp

			if(temp->next!=0)
			{
				ListNODE<mytype> *prev = head;	//created a new ListNODE to copy head, & to reach ListNODE before temp ListNODE

				while(prev->next!=temp)		//until prev ListNODE reaches the ListNODE before that ListNODE whose data is specified data
				{
					prev=prev->next;		//move prev to next ListNODE
				}
				prev->next=temp->next;		//store contents of temp's next ListNODE into prev ListNODE's next
				delete temp;				//Finally delet temp ListNODE

				cout<<"ListNODE Deleted with Value "<<element;
			}
			else
			{
				cout<<"ERROR:: ListNODE Not Found that has "<<element;
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
ListNODE<mytype>* SingleLinkList<mytype>::find_ListNODE(mytype element)
{
	ListNODE<mytype> *temp = head;	//created a new ListNODE pointer to copy head

	while(temp->next!=0 && temp->data!=element)	//until Link list ends or data is found (& is used because search stops if data is found in a ListNODE)
	{
		temp=temp->next;		//move temp ListNODE to next ListNODE
	}
	return temp;
}
//-------------------
template <class mytype> 
bool SingleLinkList<mytype>::search_item(mytype element)
{
	if(is_Empty())	//Checking if list is empty
	{
		return false;
	}
	else			// If list not empty
	{
		if(element==head->data)		//If data is in first ListNODE
		{
			return true;
		}
		else if(element==tail->data)//if data is in last ListNODE
		{
			return true;
		}
		else	//if data is some where in list
		{
			ListNODE<mytype> *temp = head;	//created a new ListNODE pointer
			while(temp!=tail && temp->data!=element)	//until list ends or data is found in list
			{
				temp = temp->next;	//move temp to next ListNODE
			}
			if(element==temp->data)	//if data is found in list
			{
				return true;	
			}
			else					//other wise return false
			{
				return false;
			}
		}
	}
}
//-------------------
template <class mytype>
void SingleLinkList<mytype>::print_list()
{
	if(is_Empty())	//Checking if Link List is empty
	{
		cout<<"\tList Is Empty!";
	}
	else			//If link list not empty, then
	{
		ListNODE<mytype> *temp = head;	//Created a new ListNODE pointer to copy head

		while(temp->next!=0)		//until temp's next pointer has Null (until link list ends)
		{
			cout<<" "<<temp->data<<" ";//print ListNODE's contents
			temp=temp->next;			//move temp ListNODE to next ListNODE
		}
		cout<<" "<<temp->data<<" ";	//print last ListNODE
	}
}
//-------------------
template <class mytype>
int SingleLinkList<mytype>::total_items()
{
	int counter=0;	//variable to store counts of ListNODEs in link list
	if(!is_Empty())		//If link list is not empty
	{
		ListNODE<mytype> *temp = head;	//created a ListNODE pointer to copy head
		if(head==tail)	//If link list has just 1 ListNODE, 
		{ 	counter=1;		}
		else
		{
			while(temp->next!=0)	//Until Link List ends
			{
				counter++;			//Increment counter by 1
				temp=temp->next;	//move temp to next ListNODE
			}
			counter++;
		}
	}
	return counter;
}
//-------------------
template <class mytype>
mytype SingleLinkList<mytype>::ReturnElement(int j)	//j is index number of required node
{
	mytype value = -1;
	if( !is_Empty() )
	{
		ListNODE<mytype> *temp = head;	//created a new ListNODE pointer
		for(int i = 0; i<j; i++)
			{ temp=temp->next;	}
		value = temp->data;
	}
	return value;
}
//-------------------
template <class mytype> 
SingleLinkList<mytype>::~SingleLinkList()	//Destructor Function
{
	if(!is_Empty())
	{
		while(head!=0)
		{
			deletefromhead();
		}
	}
}
//-------------------