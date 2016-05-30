#include<iostream>
#include<conio.h>
using namespace std;
//Objective: Implement a Dynamic Queue
//--------------------
template<class mytype>
class QueueNODE              //template type QueueNODE class
{
public:
        mytype data;                    //data variable to store any type of variable
        QueueNODE<mytype> *next;             //QueueNODE type pointer to store address of next QueueNODE

        QueueNODE()  //Constructor 0 argument
        {
                next = 0;               //Initializing next pointer to 0
        }
        QueueNODE(mytype element, QueueNODE *n =  0) //Constructor 2-arguments, element variable to store data, create a new QueueNODE 'n'
        {
                data = element; //assign user given value to data
                next = n;               //store contents of n into next
        }
};
//--------------------
template <class mytype>
class dynamicQueue//Class of Dynamic Queue
{
public:
        QueueNODE<mytype> *tail;             //QueueNODE type pointer tail to store last QueueNODE of queue
        QueueNODE<mytype> *find_QueueNODE(mytype element);        //Address returning Function to find a specific data item in Queue

        dynamicQueue()  //Constructor to initialize tail pointer
        {
                tail = 0;
        }
        ~dynamicQueue();                        //Destructor to be defined outside class
        
        bool is_Empty();                                //Function to check if Queue is empty
        void enqueue(mytype element);   //Function to add note to tail with user given data, 'element'
		mytype dequeue();		//Function to return data of QueueNODE & then delete QueueNODE from tail
        bool search_item(mytype element);//Function to search an item in Queue
        void delete_item(mytype element);//Delete a specific QueueNODE with a certain data item
        void print_queue();                             //Function to print complete queue
        int total_items();                              //Function to tell total number of items in queue
};
//--------------------
template <class mytype> 
bool dynamicQueue<mytype>::is_Empty()
{
        if(tail==0)     //if tail = 0, then queue is empty
        {
                return true;
        }
        else
                return false;
}
template <class mytype> 
void dynamicQueue<mytype>::enqueue(mytype element)
{
        QueueNODE<mytype> *temp = new QueueNODE<mytype>(element, 0);      //Created a new QueueNODE

        if(is_Empty())  //If Queue is empty, (for creation of 1st QueueNODE)
        {
                tail = temp;    //point tail to temp
                tail->next=tail;//store address of tail in tail's next so list is circular
        }
        else            //If Queue is not empty, then
        {
                temp->next=tail->next;  //put address of 1st QueueNODE in temp's next (last QueueNODE)
                tail->next=temp;                //put address of last QueueNODE into 2nd last QueueNODE's (tail) 'next'
                tail=temp;                              //move tail 1 step further
        }
}
//--------------------
template <class mytype>
mytype dynamicQueue<mytype>::dequeue()
{
    if(!is_Empty())    //If Queue is not empty, then 
	{
		mytype data;
                if(tail->next==tail)    //if tail points to itself, hence Queue has only 1 QueueNODE, then
                {
					data = tail->next->data;
                    tail=0;         //Initialize both to 0
                    delete tail;//delete tail QueueNODE
					return data;
                }
                else    //if list has multiple QueueNODEs, then
                {
					QueueNODE<mytype> *temp = tail->next; //created a new QueueNODE pointer to make copy of head (i.e. tail->next)
                    tail->next = temp->next;        //stored address of the 2nd QueueNODE into last QueueNODE (to keep Queue circular)
					data = temp->data;
					delete temp;    // finally delete 1st QueueNODE
					return data;
                }
	}
	else
		return 0;
}
//--------------------
template <class mytype> 
void dynamicQueue<mytype>::delete_item(mytype element)
{
        if(!is_Empty()) //If Queue not empty
        {
                if(element==tail->next->data)           //if specified data item is in 1st QueueNODE
                {
                        dequeue();      //calling function
                        cout<<" with Value "<<element;
                }
                else            //else if data item is in any middle QueueNODE
                {
                        QueueNODE<mytype> *temp = find_QueueNODE(element); //created a new QueueNODE pointer to store specific QueueNODE temp

                        if(tail->data==element) //If data is present in tail
                        {
                                QueueNODE<mytype> *temporary = tail->next; //created a new QueueNODE pointer (to make copy of head)
                                while(temporary->next!=tail)             //until temporary reaches last QueueNODE
                                {
                                        temporary=temporary->next;      //move temporary QueueNODE to next QueueNODE
                                }
                                temporary->next=tail->next;     //stored address of 1st QueueNODE into temporary (2nd last QueueNODE)
                                delete tail;                            //Delete tail QueueNODE
                                tail=temporary;                         //move back tail to 2nd last QueueNODE
                                cout<<"Last Item Deleted with Value "<<element;
                        }
                        else if(temp->data==element)    //if element found in the QueueNODE
                        {
                                QueueNODE<mytype> *prev = tail->next;        //created a new QueueNODE to copy head (i.e. tail->next), & to reach QueueNODE before temp QueueNODE
                                while(prev->next!=temp) //until prev QueueNODE reaches the QueueNODE before that QueueNODE whose data is specified data (i.e. temp QueueNODE)
                                {
                                        prev=prev->next;        //move prev to next QueueNODE
                                }
                                prev->next=temp->next;  //store address of temp's next QueueNODE in 'next' of prev QueueNODE, so temp is skipped from Queue
                                delete temp;                    //Finally delet temp QueueNODE

                                cout<<"Item Deleted with Value "<<element;
                        }
                        else
                        {
                                cout<<"\t\tERROR:: Item Not Found that has "<<element;
                        }
                }
        }
        else
        {
                cout<<"ERROR:: Queue is Empty.. Data Item can't be searched.";
        }
}
//--------------------
template <class mytype> 
QueueNODE<mytype>* dynamicQueue<mytype>::find_QueueNODE(mytype element)
{
        QueueNODE<mytype> *temp = tail->next;        //created a new QueueNODE pointer to copy head (i.e. tail->next)

        while(temp!=tail && temp->data!=element)        //until Queue ends or data is found (& is used because search STOPS if data is found in a QueueNODE)
        {
                temp=temp->next;        //move temp QueueNODE to next QueueNODE
        }
        return temp;
}
//-------------------
template <class mytype>
bool dynamicQueue<mytype>::search_item(mytype element)
{
        if(!is_Empty())
        {
                QueueNODE<mytype> *temp = tail->next;        //created a new QueueNODE pointer to copy head
                while(temp!=tail && temp->data!=element)        //until Queue ends or data is found (& is used because search STOPS if data is found in a QueueNODE)
                {
                        temp=temp->next;        //move temp QueueNODE to next QueueNODE
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
//-------------------
template <class mytype>
void dynamicQueue<mytype>::print_queue()
{
        if(is_Empty())          //Checking if Queue is empty
        {
                cout<<"\tERROR:: Queue Is Empty!";
        }
        else            //If Queue not empty, then
        {
                QueueNODE<mytype> *temp = tail->next;        //Created a new QueueNODE pointer to copy head (tail->next)

                while(temp!=tail)       //until temp's next pointer reaches tail
                {
                        cout<<"\t- "<<temp->data<<" \n";                //print QueueNODE's contents
                        temp=temp->next;        //move temp QueueNODE to next QueueNODE
                }
                cout<<"\t- "<<temp->data<<" ";                  //print last QueueNODE
        }
}
//-------------------
template <class mytype>
int dynamicQueue<mytype>::total_items()
{
        if(!is_Empty()) //If Queue is not empty
        {
                int counter=0;  //variable to store counts of QueueNODEs in Queue
                QueueNODE<mytype> *temp = tail->next;        //created a QueueNODE pointer to copy head (temp->next)
                if(tail->next==tail)    //If Queue has just 1 QueueNODE, 
                {
                        return 1;       //then return 1
                }
                else
                {
                        while(temp!=tail)       //Until Queue ends
                        {
                                counter++;              //Increment counter by 1
                                temp=temp->next;        //move temp to next QueueNODE
                        }
                        counter++;      //Increment again for last QueueNODE
                        return counter;
                }

        }
        else    //If Queue is empty, then
        {
                return 0;       //return 0
        }
}
//-------------------
template <class mytype> 
dynamicQueue<mytype>::~dynamicQueue()   //Destructor Function
{
        if(!is_Empty()) //If Queue not empty
        {
                while(tail->next!=tail) //until link list has only 1 QueueNODE
                {
                        dequeue();      //keep deleteing
                }
                dequeue();              //finally delete last QueueNODE too
        }
}
//-------------------