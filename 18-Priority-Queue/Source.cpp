#include"PriorityQueueHeader.h"
#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	cout<<"\t\t\t\t>>PRIORITY QUEUE<<\n\n";
	int op;		//variable to store choice of operation
	int value;	//variable to store value into node
	char ext;	//variable to exit loop

	DynamicHeap<int> heap;	//created object of dynamic Queue
	do
	{
		cout<<"\t\tWhat to do?\n1 -> Enqueue\n2 -> Dequeue\n3 -> Search Item\n4 -> Print Queue\n0 -> EXiT\n\tYour Choice = ";		cin>>op;	cout<<endl;
		if(op==1)
		{
			cout<<"\nEnter Value to be stored = ";	cin>>value;
			heap.Insert(value);
			cout<<"\n\tValue "<<value<<" added successfully!";
		}
		else if(op==2)
		{
			if(heap.isEmpty())
			{	cout<<"\n\tERROR:: Queue is Empty.. Can't Delete!";			}
			else
			{	cout<<"\n\tValue "<<heap.Delete()<<" Deleted from Queue!";		}
		}
		else if(op==3)
		{
			if(heap.isEmpty())
			{	cout<<"\n\tERROR:: Queue is Empty.. Can't Search!";			}
			else
			{
				cout<<"Enter Data Item to search = ";		cin>>value;
				bool search = heap.SearchValue(value);
				if(search==true)
				{	cout<<"\n\tValue is Present!";	}
				else
				{	cout<<"\n\tERROR:: Value is not present..";		}
			}
		}
		else if(op==4)
		{
			if(heap.isEmpty())
			{	cout<<"\n\tERROR:: Queue is Empty..";			}
			else
			{
				cout<<"Queue has:\n";
				heap.PrintQueue();
			}
		}
		else if(op==0)
		{	break;	}
		else
		{
			cout<<"\n\tERROR:: Wrong Choice! Try Again..";
		}
	cout<<"\n\n\t\t\tESC to exit | Enter to Contine....";	ext=_getch();	cout<<endl;
	}
	while(ext!=27);
}