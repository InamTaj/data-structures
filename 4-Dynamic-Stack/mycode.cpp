#include"myheader.h"
#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	cout<<"\t\t\t>>Dynamic Stack<<\n\n";
	int op;		//variable to store choice of operation
	int value;	//variable to store value into node
	char ext;	//variable to exit loop
	int emt;	//variable to store result of is_Empty function
	int top;	//variable to store top of stack
	
	dynamicStack<int> obj;	//created object of Dynamic Stack
	do
	{
		cout<<"\t\tWhat to do?\n1. Push Item\n2. Pop Item\n3. Check if Stack is Empty\n4. Check top of Stack\n\tYour Choice = ";		cin>>op;
		if(op==1)
		{
			cout<<"Enter Value to be stored = ";	
			cin>>value;
			obj.push(value);
		}
		else if(op==2)
		{
			cout<<obj.pop()<<" popped from Stack.";

		}
		else if(op==3)
		{
			emt=obj.is_Empty();
			if(emt==1)
			{
				cout<<"Stack is Empty!";
			}
			else if(emt==0)
			{
				cout<<"Stack is NOT Empty!";
			}
		}
		else if(op==4)
		{
			top = obj.tell_top();
			if(top!=-1)
			{
				cout<<"Stack Top Item = "<<top;
			}
			else
			{
				cout<<"Stack is Empty!";
			}
		}
		else
		{
			cout<<"\n\tWrong Choice! Try Again..";
		}
	cout<<"\n\t\t\tESC to exit | Enter to Contine....";	ext=getch();	cout<<endl;
	}
	while(ext!=27);
}