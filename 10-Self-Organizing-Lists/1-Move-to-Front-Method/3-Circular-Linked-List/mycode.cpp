#include"myheader.h"
#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	int op;		//variable to store choice of operation
	int value;	//variable to store value into node
	char ext;	//variable to exit loop
	int cnt;	//variable to store count of nodes
	NODE<int> *search;	//variable to store result of search
	
	cout<<"\t\t\t   >>SELF ORGANIZING<<\n\t\t\t>>Circular Linked List<<\n\n";
	CircularLinkList<int> obj;	//created object of circular linked list
	do
	{
		cout<<"\t\tWhat to do?\n1. Add to Head\n2. Add to Tail\n3. Delete from Head\n4. Delete from Tail\n5. Search Item\n6. Delete Node with Specific Data\n7. Check Total Number of Nodes\n8. Print List\n\tYour Choice = ";		cin>>op;
		if(op==1)
		{
			cout<<"Enter Value to be stored = ";	
			cin>>value;
			obj.add2CLLhead(value);
		}
		else if(op==2)
		{
			cout<<"Enter Value to be stored = ";	
			cin>>value;
			obj.add2CLLtail(value);
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
			cout<<"Enter Data Item to search = ";		cin>>value;
			search=obj.find_node(value);
			if(search->data==value)
			{
				cout<<value<<" is present in Link List.";
			}
			else
			{
				cout<<"ERROR:: Value Not Found!";
			}
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
			cout<<"\n\tWrong Choice! Try Again..";
		}
	cout<<"\n\t\t\tEnter to Continue | ESC to Exit....";	ext=getch();	cout<<endl;
	}
	while(ext!=27);
}