#include"myheader.h"
#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	cout<<"\t\t\t\t>>SELF ORGANIZING<<\n\t\t\t>>Doubly Circular Linked List<<\n\n";
	int op;		//variable to store choice of operation
	int value;	//variable to store value into node
	char ext;	//variable to exit loop
	int cnt;	//variable to store count of nodes
	int search;	//variable to store search results
	
	DoublyCircularLinkedList<int> obj;	//created object of Doubly Circular linked list
	do
	{
		cout<<"\t\tWhat to do?\n1. Add to Head\n2. Add to Tail\n3. Delete from Head\n4. Delete from Tail\n5. Search Data in List\n6. Delete Node with Specific Data\n7. Check Total Number of Nodes\n8. Print List\n\tYour Choice = ";		cin>>op;
		if(op==1)
		{
			cout<<"Enter Value to be stored = ";	
			cin>>value;
			obj.add2DCLLhead(value);
		}
		else if(op==2)
		{
			cout<<"Enter Value to be stored = ";	
			cin>>value;
			obj.add2DCLLtail(value);
		}
		else if(op==3)
		{
			obj.deletefromDCLLhead();
		}
		else if(op==4)
		{
			obj.deletefromDCLLtail();
		}
		else if(op==5)
		{
			cout<<"Enter Value to Search = ";		cin>>value;
			search=obj.search_item(value);
			if(search==1)
				cout<<value<<" is present in LinkList!";
			else if(search==0)
				cout<<"ERROR:: Value NOT Found.";
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