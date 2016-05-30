//Inamullah Taj - 1446
// OBJECTIVE: Implement a Class of Static Graph
#include "HashTableHeader.h"
#include <conio.h>
#include <iostream>
using namespace std;

void main()
{
	char ext;	
	int choice, size, value;
	cout<<"\t   \t  \t>>-> HASH TABLES <-<<\n\n";
	cout<<"\n\t\tEnter Size of Table = ";	cin>>size;
	HashTable<int> mytable(size);
	do
	{
		cout<<"\n\tWhat to do?\n1 -> Insert key\n2 -> Search Key\n3 -> Delete Key\n4 -> Show Table\n0 -> EXIT\n\t\tYour Choice = ";	cin>>choice;	cout<<endl;
		if(choice==1)
		{
			cout<<"Enter Value to insert = ";	cin>>value;
			mytable.Insert(value);
		}
		else if(choice==2)
		{
			cout<<"Enter Value to search = ";	cin>>value;
			int status =  mytable.Search(value);
			if(status != 0)
			{	cout<<"\n\tValue "<<value<<" is at Index "<<status;	}
			else if(status == 0)
			{	cout<<"\n\tERROR:: Value not Found in Table!";	}
		}
		else if(choice==3)
		{
			cout<<"Enter Value to Delete = ";	cin>>value;
			int stat = mytable.GetKey(value);
			if(stat!=0)
			{	cout<<"\n\tValue "<<value<<" Deleted from Table!";	}
			else
			{	cout<<"\n\tERROR:: Value not Found in Table!";		}
		}
		else if (choice==4)
		{
			mytable.ShowTable();
		}
		else if (choice==0)
		{	break;		}
		else
		{	cout<<"\n\tERROR:: Wrong Choice! Try Again..";	}
		
		cout<<"\n\n\t\t\tENTER to Continue | ESc to Exit..";	ext = _getch();
	}
	while(ext!=27);
}