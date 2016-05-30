#include <conio.h>
#include <iostream>
#include "myhead.h"	//I included my header file
using namespace std;

void main()			//Main function to test queue class
{
	cout<<"\t\t\t>>Static Queue<<\n\n";
	int opt;		//opt variable to store option entered by user
	int choice;		//same purpose
	char exit_var;	//variable to confirm exit
	int ii;
	float ff;
	char cc;
	double dd;


	cout<<"Enter type of data work in Queue:\n1.Integer\n2.Float\n3.Character\n4.Double\t\tYour Choice = ";		cin>>opt;
	if(opt==1)
	{
		myQueue<int> obj;

		do
		{			
			cout<<"\nWhat to do?\n1. Enqueue\n2. Dequeue\t\tYour Choice = ";	cin>>choice;
			if(choice==1)
			{
				cout<<"\nEnter element to be Enqueued: ";	cin>>ii;
				obj.enqueue(ii);
				
				
			}
			else if(choice==2)
			{
				cout<<"\nDeleted item from Queue = "<<obj.dequeue();
			}
			else
			{
				cout<<"Wrong Choice! Try Again!";
			}


			cout<<"\n\n\tESC to exit | Enter to Contine....";		exit_var = getch();
		}
		while(exit_var!=27);
	}
	else if(opt==2)
	{
				myQueue<float> obj;

		do
		{			
			cout<<"\nWhat to do?\n1. Enqueue\n2. Dequeue\t\tYour Choice = ";	cin>>choice;
			if(choice==1)
			{
				cout<<"\nEnter element to be Enqueued: ";	cin>>ff;
				obj.enqueue(ff);
				
				
			}
			else if(choice==2)
			{
				cout<<"\nDeleted item from Queue = "<<obj.dequeue();
			}
			else
			{
				cout<<"Wrong Choice! Try Again!";
			}


			cout<<"\n\n\tESC to exit | Enter to Contine....";		exit_var = getch();
		}
		while(exit_var!=27);
	}
	else if(opt==3)
	{
				myQueue<char> obj;

		do
		{			
			cout<<"\nWhat to do?\n1. Enqueue\n2. Dequeue\t\tYour Choice = ";	cin>>choice;
			if(choice==1)
			{
				cout<<"\nEnter element to be Enqueued: ";	cin>>cc;
				obj.enqueue(cc);
				
				
			}
			else if(choice==2)
			{
				cout<<"\nDeleted item from Queue = "<<obj.dequeue();
			}
			else
			{
				cout<<"Wrong Choice! Try Again!";
			}


			cout<<"\n\n\tESC to exit | Enter to Contine....";		exit_var = getch();
		}
		while(exit_var!=27);
	}
	else if(opt==4)
	{
				myQueue<double> obj;

		do
		{			
			cout<<"\nWhat to do?\n1. Enqueue\n2. Dequeue\t\tYour Choice = ";	cin>>choice;
			if(choice==1)
			{
				cout<<"\nEnter element to be Enqueued: ";	cin>>dd;
				obj.enqueue(dd);
				
				
			}
			else if(choice==2)
			{
				cout<<"\nDeleted item from Queue = "<<obj.dequeue();
			}
			else
			{
				cout<<"Wrong Choice! Try Again!";
			}


			cout<<"\n\n\tESC to exit | Enter to Contine....";		exit_var = getch();
		}
		while(exit_var!=27);
	}
	else
	{
		cout<<"Wrong Choice! Try Again!";
	}
}