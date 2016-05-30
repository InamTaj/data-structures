//Inamullah Taj - 1446
// OBJECTIVE: Implement a Class of Static Graph
#include "GraphHeader.h"
#include <conio.h>
#include <iostream>
using namespace std;

void main()
{
	char ext;	
	int choice;
	cout<<"\t   \t  \t>>-> STATIC GRAPH <-<<\n\n";
	SGraph mygraph;
	do
	{ 
		cout<<"\n\tWhat to do?\n1 -> Show Graph Edges\n2 -> Check Neighbours\n3 -> Find Predecessors of a Vertex\n4 -> Find Successors of a Vertex\n5 -> Check In-Degree of a Vertex\n6 -> Check Out-Degree of a Vertex\n7 -> Breadth First Traversal\n8 -> Depth First Traversal\n9 -> Find Source Vertex\n10-> Find Sink Vertex\n11-> Check In-Degree of All Vertices\n12-> Check Out-Degree of All Vertices\n0 -> EXIT\n\t\tYour Choice = ";	cin>>choice;	cout<<endl;
		if(choice==1)
		{
			mygraph.ShowGraph();
		}
		else 
		if(choice==2)
		{
			int vertex;
			cout<<"Enter Vertex to check its Neighbours = ";	cin>>vertex;
			mygraph.DisplayAdjacent(vertex);
		}
		else if (choice==3)
		{
			int vertex;
			cout<<"Enter Vertex to check its Predecessors = ";	cin>>vertex;
			cout<<"\nPredecessors of "<<vertex<<" =  ";
			mygraph.DisplayPredecessor(vertex);
		}
		else if (choice==4)
		{
			int vertex;
			cout<<"Enter Vertex to check its Successors = ";	cin>>vertex;
			cout<<"\nSuccessors of "<<vertex<<" = ";
			mygraph.DisplaySuccessor(vertex);
		}
		else if (choice==5)
		{
			int vertex;
			cout<<"Enter Vertex = ";	cin>>vertex;
			cout<<"\n\tIn-Degree = "<<mygraph.InDegree(vertex);
		}
		else if (choice==6)
		{
			int vertex;
			cout<<"Enter Vertex = ";	cin>>vertex;
			cout<<"\n\tOut-Degree = "<<mygraph.OutDegree(vertex);
		}
		else if(choice==7)
		{
			int vertex;
			cout<<"Enter Starting Vertex = ";	cin>>vertex;
			cout<<"\nGraph ->>  ";
			mygraph.BreadthFirst(vertex);

		}
		else if (choice==8)
		{
			int vertex;
			cout<<"Enter Starting Vertex = ";	cin>>vertex;
			cout<<"\nGraph ->>  ";
			mygraph.DepthFirst(vertex);
		}
		else if (choice==9)
		{
			cout<<"Source Vertex in Graph = ";
			mygraph.SourceVertex();
		}
		else if (choice==10)
		{
			cout<<"Sink Vertex in Graph = ";
			mygraph.SinkVertex();
		}
		else if (choice==11)
		{
			cout<<"In-Degree of All Vertices in Graph:\n";
			cout<<"\n\tVertex\tIn-Degree\n";
			mygraph.InDegreeAll();
		}
		else if (choice==12)
		{
			cout<<"Out-Degree of All Vertices in Graph:\n";
			cout<<"\n\tVertex\tOut-Degree\n";
			mygraph.OutDegreeAll();
		}
		else if (choice==0)
		{	break;		}
		else
		{	cout<<"\n\tERROR:: Wrong Choice! Try Again..";	}
		
		cout<<"\n\n\t\t\tENTER to Continue | ESc to Exit..";	ext = _getch();
	}
	while(ext!=27);
}