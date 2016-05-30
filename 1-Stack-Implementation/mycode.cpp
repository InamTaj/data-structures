#include <conio.h>
#include <iostream>
#include "myhead.h"		//I included my self created header file
using namespace std;

void main()			//Main function to test stack class
{
	cout<<"\t\t\t>>Static Stack<<\n\n";
	int stacktype;		//variable to store choice, type of stack to be created
	int op;			//variable to store choices for in-stack operations, e.g. What do you want -- Push or pop?
	char exit_var=0;	//variable to confirm exit if user presses ESCAPE Key
	
	cout<<"Select type of Stack to be created:\n\n1.Integer Stack\n2.Float Stack\n3.Double Stack\n4.Character Stack\tYour Choice = ";	cin>>stacktype;
	
	if(stacktype==1)
	{
		mystack <int> ii;		//created object of stack of integer data type
		do
		{
			cout<<"\n\n\tWHAT TO DO?\n1. Push Item\n2. Pop Item\n3. Check Status of Stack\n4. Empty Stack\n5. Check top-most item    \tYour Choice = ";	cin>>op;
			if(op==1)
			{
				ii.push();
			}
			else if(op==2)
			{
				cout<<"\nInteger Stack has: "<<ii.pop();
			}
			else if(op==3)
			{
				cout<<"\nStack Status = ";	ii.stack_check();
			}
			else if(op==4)
			{
				ii.make_empty();	cout<<"\nStack is Emptied!";

			}
			else if(op==5)
			{
				ii.tell_top();

			}
			else
			{
				cout<<"Wrong Choice! Try Again!";
			}
			cout<<"\n\n\t[ESC to exit or Enter to Contine]";		exit_var = _getch();

		}
	   while(exit_var!=27);
	}

	else if(stacktype==2)
	{
		mystack <float> f;		//created object of stack of float data type
		do
		{
			cout<<"\n\n\tWHAT TO DO?\n1. Push Item\n2. Pop Item\n3. Check Status of Stack\n4. Empty Stack\n5. Check top-most item    \tYour Choice = ";	cin>>op;
			if(op==1)
			{
				f.push();
			}
			else if(op==2)
			{
				cout<<"\nFloat Stack has: "<<f.pop();
			}
			else if(op==3)
			{
				cout<<"\nStack Status = ";	f.stack_check();
				
			}
			else if(op==4)
			{
				f.make_empty();		cout<<"\nStack is Emptied!";

			}
			else if(op==5)
			{
				f.tell_top();

			}
			else
			{
				cout<<"Wrong Choice! Try Again!";
			}

			cout<<"\n\n\tESC to exit | Enter to Contine....";		exit_var = _getch();
		}
		while(exit_var!=27);
	}
	else if(stacktype==3)
	{
		mystack <double> d;		//created object of stack of character data type
		do
		{
			cout<<"\n\n\tWHAT TO DO?\n1. Push Item\n2. Pop Item\n3. Check Status of Stack\n4. Empty Stack\n5. Check top-most item    \tYour Choice = ";	cin>>op;
			if(op==1)
			{
				d.push(); 
			}
			else if(op==2)
			{
				cout<<"\nDouble Stack has: "<<d.pop();
			}
			else if(op==3)
			{
				cout<<"\nStack Status = ";	d.stack_check();			
			}
			else if(op==4)
			{
				d.make_empty();		cout<<"\nStack is Emptied!";
			}
			else if(op==5)
			{
				d.tell_top();
			}
			else
			{
				cout<<"Wrong Choice! Try Again!";				
			}
			cout<<"\n\n\t[ESC to exit or Enter to Contine]";		exit_var = _getch();		
		}
		while(exit_var!=27);
	}
	else if(stacktype==4)
	{
		mystack <char> c;		//created object of stack of character data type
		do
		{
			cout<<"\n\n\tWHAT TO DO?\n1. Push Item\n2. Pop Item\n3. Check Status of Stack\n4. Empty Stack\n5. Check top-most item    \tYour Choice = ";	cin>>op;
			if(op==1)
			{
				c.push(); 
			}
			else if(op==2)
			{
				cout<<"\nCharacter Stack has: "<<c.pop();
			}
			else if(op==3)
			{
				cout<<"\nStack Status = ";	c.stack_check();
			}
			else if(op==4)
			{
				c.make_empty();		cout<<"\nStack is Emptied!";
			}
			else if(op==5)
			{
				c.tell_top();
			}
			else
			{
				cout<<"Wrong Choice! Try Again!";
			}
			cout<<"\n\n\t[ESC to exit or Enter to Contine]";		exit_var = _getch();
		}
		while(exit_var!=27);		
	}
	else
	{
		cout<<"WRONG ENTRY! TRY AGAIN!";
	}	
}