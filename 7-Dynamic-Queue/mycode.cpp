#include"myheader.h"
#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	cout<<"\t\t\t>>DYNAMIC QUEUE<<\n\n";
	int op;		//variable to store choice of operation
	int value;	//variable to store value into node
	char ext;	//variable to exit loop
	int cnt;	//variable to store count of nodes
	int search=2;	//variable to store result of search
	
	dynamicQueue<int> obj;	//created object of dynamic Queue
	do
	{
		cout<<"\t\tWhat to do?\n1. Enqueue\n2. Dequeue\n3. Search Item\n4. Delete Specific Item in Queue\n5. Check Total Number of Items\n6. Print List\n\tYour Choice = ";		cin>>op;
		if(op==1)
		{
			cout<<"Enter Value to be stored = ";	
			cin>>value;
			obj.enqueue(value);
		}
		else if(op==2)
		{
			obj.dequeue();
		}
		else if(op==3)
		{
			cout<<"Enter Data Item to search = ";		cin>>value;
			search=obj.search_item(value);
			if(search==1)
			{
				cout<<value<<" is present in Queue.";
			}
			else if(search==0)
			{
				cout<<"ERROR:: Value Not Found!";
			}
		}
		else if(op==4)
		{
			cout<<"Enter Data Item to delete = ";		cin>>value;
			obj.delete_item(value);
			
		}
		else if(op==5)
		{
			cnt=obj.total_items();
			cout<<"Total Nodes In Queue = "<<cnt;
		}
		else if(op==6)
		{
			cout<<"Queue is:\n";
			obj.print_queue();
		}
		else
		{
			cout<<"\n\tERROR:: Wrong Choice! Try Again..";
		}
	cout<<"\n\t\t\tESC to exit | Enter to Contine....";	ext=getch();	cout<<endl;
	}
	while(ext!=27);
}