#include "SplayTreeHeader.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
void main()
{
	int op;
	char ext;
	SplayTree<int> tree;	//created object of tree
	cout<<"\t\t\t\t->>SPLAY TREE<<-\n\n";
	do
	{
		cout<<"\n\tWhat to do?\n1 -> Insert new value\n2 -> Search a value\n3 -> Delete a value\n4 -> Traverse by PreOrder\n5 -> Traverse by InOrder\n6 -> Traverse by PostOrder\n7 -> Traverse by Breadth First\n8 -> Check Total Nodes\n9 -> Check Total Leaves\n10-> Check Numbe of Nodes with 2 Children\n0 -> EXiT\n\t\tYour Choice = ";	cin>>op;	cout<<endl;
		if (op==1)
		{
			int value, stat;
			cout<<"Enter New Value to Insert = ";	cin>>value;
			stat = tree.insertvalue(value);
			if(stat==1)
			{	
				cout<<"\n\tValue "<<value<<" added successfully!";		
			}
			else if(stat==0)
			{	cout<<"\n\tERROR:: Duplication is prohibited.. Value "<<value<<" is present in Tree!";}
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
		else if (op==0)
		{
			break;
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