#include "BinaryTreeHeader.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
void main()
{
	int op;
	char ext;
	BinaryTree<int> tree;	//created object of tree
	cout<<"\t\t\t\t->>RAW BINARY TREE<<-\n\n";
	do
	{
		cout<<"\n\tWhat to do?\n1 -> Insert new value\n2 -> Search a value\n3 -> Delete a value\n4 -> Traverse by PreOrder\n5 -> Traverse by InOrder\n6 -> Traverse by PostOrder\n7 -> Traverse by Breadth First\n8 -> Check Total Nodes\n9 -> Check Total Leaves\n10-> Check Numbe of Nodes with 2 Children\n\t\tYour Choice = ";	cin>>op;	cout<<endl;
		if (op==1)
		{
			int fathervalue=0, value, stat;
			if(!(tree.isEmpty()))
			{
				cout<<"Enter Father Value of New Entry = ";	cin>>fathervalue;
			}
			cout<<"Enter New Value to Insert = ";	cin>>value;
			stat = tree.insertvalue(fathervalue, value);
			if (stat==0)
			{	cout<<"\n\tERROR:: Both Children of Parent Node "<<fathervalue<<" are occupied!";	}
			else if(stat==-1)
			{	cout<<"\n\tERROR:: No Node has Father Value "<<fathervalue<<" in Tree!";	}
			else if(stat==1)
			{	cout<<"\n\tNew Value "<<value<<" Added Sucessfully!";	}
		}
		//--------------------------------------------------------------/////////
		else if (op==2)
		{
			if (tree.isEmpty())
			{
				cout<<"\n\tERROR: Tree is Empty. Can't search value yet..";
			}
			else
			{

				int value, confirm;
				cout<<"Enter Value to be Searched = ";	cin>>value;
				confirm = tree.search(value);
				if (confirm==1)
				{
					cout<<"\n\tValue "<<value<<" Found in Tree!";
				}
				else
				{
					cout<<"\n\tERROR:: Value "<<value<<" Not Found in Tree..";
				}
			}
		}
		//--------------------------------------------------------------/////////
		else if(op==3)
		{
			int value, status;
			cout<<"Enter Value to be Deleted = ";	cin>>value;
			status = tree.deletevalue(value);
			if(status==0)
			{	cout<<"\n\tERROR:: Value "<<value<<" Not Found in Tree! Can't Delete Value..";	}
			else if(status==1)
			{	cout<<"\n\t Deleted Value "<<value<<" from Tree!";	}
		}
		//--------------------------------------------------------------/////////
		else if (op==4)
		{
			if(!(tree.isEmpty()))
			{
				cout<<"Tree has:\n";	tree.preorder();
			}
			else
			{
				cout<<"\n\tERROR:: Tree is Empty! Can't complete traversal..";
			}
		}
		//--------------------------------------------------------------/////////
		else if (op==5)
		{
			if(!(tree.isEmpty()))
			{
				cout<<"Tree has:\n";	tree.inorder();
			}
			else
			{
				cout<<"\n\tERROR:: Tree is Empty! Can't complete traversal..";
			}
		}
		//--------------------------------------------------------------/////////
		else if (op==6)
		{
			if(!(tree.isEmpty()))
			{
				cout<<"Tree has:\n";	tree.postorder();
			}
			else
			{
				cout<<"\n\tERROR:: Tree is Empty! Can't complete traversal..";
			}
		}
		//--------------------------------------------------------------/////////
		else if(op==7)
		{
			if(!(tree.isEmpty()))
			{
				cout<<"Tree has:\n";	tree.breadthfirst();
			}
			else
			{
				cout<<"\n\tERROR:: Tree is Empty! Can't complete traversal..";
			}
		}
		//--------------------------------------------------------------/////////
		else if (op==8)
		{
			cout<<"\nTotal Nodes in Tree = "<<tree.totalNodes();
		}
		//--------------------------------------------------------------/////////
		else if(op==9)
		{
			cout<<"\nTotal Leaves in Tree = "<<tree.total_leaves();
		}
		//--------------------------------------------------------------/////////
		else if(op==10)
		{
			cout<<"\nTotal Nodes with 2 Children in Tree = "<<tree.total2ChildNodes();
		}
		//--------------------------------------------------------------/////////
		else
		{
			cout<<"\n\tERROR:: Wrong Choice! Try Again...";
		}
		cout<<"\n\n\t\t\tENTER to continue | ESc to exit....";		ext = _getch();
	}
	while(ext!=27);
}