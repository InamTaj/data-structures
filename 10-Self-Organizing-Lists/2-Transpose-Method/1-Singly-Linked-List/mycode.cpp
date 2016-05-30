#include"myheader.h"
#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	cout<<"\t\t\t  >>SELF ORGANIZING<<\n\t\t\t>>Singly Linked List<<\n\n";
	int op;		//variable to store choice of operation
	int value;	//variable to store value into node
	char ext;	//variable to exit loop
	int cnt;	//variable to store count of nodes
	int search;//variable to store search results
	
	SingleLinkList<int> obj;	//created object of singly linked list
	do
	{
		cout<<"\t\tWhat to do?\n1. Add to Head\n2. Add to Tail\n3. Delete from Head\n4. Delete from Tail\n5. Search Data in List\n6. Delete Node with Specific Data\n7. Check Total Number of Nodes\n8. Print List\n\tYour Choice = ";		cin>>op;
		if(op==1)
		{
			cout<<"Enter Value to be stored = ";	
			cin>>value;
			obj.add2head(value);
		}
		else if(op==2)
		{
			cout<<"Enter Value to be stored = ";	
			cin>>value;
			obj.add2tail(value);
		}
		else if(op==3)
		{
			obj.deletefromhead();
		}
		else if(op==4)
		{
			obj.deletefromtail();
		}
		else if(op==5)
		{
			cout<<"Enter Data to Search = ";	cin>>value;
			search = obj.search_item(value);
			if(search==0)
				cout<<"Value Not Found!";
			else if(search==1)
				cout<<value<<" Found in Link List!"; 
		}
		else if(op==6)
		{
			cout<<"Enter Data Value to delete its Node: ";		cin>>value;
			obj.delete_item(value);
			
		}
		else if(op==7)
		{
			cnt=obj.total_nodes();
			cout<<"Total Nodes In LinkList = "<<cnt;
		}
		else if(op==8)
		{
			cout<<"Link List is:\n";
			obj.print_list();
		}
		else
		{
			cout<<"\n\tERROR:: Wrong Choice! Try Again..";
		}
	cout<<"\n\t\t\tESC to exit | Enter to Contine....";	ext=getch();	cout<<endl;
	}
	while(ext!=27);
}