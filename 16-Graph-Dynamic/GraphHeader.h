#include "QueueHeader.h"
#include "StackHeader.h"
#include "LinkListHeader.h"
#include <conio.h>
#include <fstream>
#include <iostream>
using namespace std;
class DGraph
{
private:
	int vertices;	//to store number of vertices
	SingleLinkList<int> *gList;	//Link List type pointer to array
public:
	DGraph()	//CONSTRUCTOR
	{
		int dummy;	//to store digit from file
		ifstream file("GraphList.txt");	//created file object to read from file
		file>>vertices;	//read first digit into vertices
		gList = new SingleLinkList<int>[vertices];	//create a dynamic array of size of vertices 
		
		while (file)	//until file's eof
		{
			for (int j = 0; j < vertices; j++)	//loop to iterate List #
			{
				file>>dummy;	//read a digit from file into dummy
				while (dummy!=-1)	//until dummy becomes -1
				{
					gList[j].add2tail(dummy);	//add dummy to j List
					file>>dummy;	//read next digit
				}
			}
		}
	}

	void ShowGraph();	//function to show graph
	
	void DisplayAdjacent(int vertex);	//to display neighbours of a given vertex
	void DisplayPredecessor(int vertex);	//to display predecessors of a given vertex
	void DisplaySuccessor(int vertex);		//to display successors of a given vertex

	void BreadthFirst(int vertex);	//function to traverse graph by Breadth first method
	void BFS(int vertex, bool visited[]);

	void DepthFirst(int vertex);	//function to traverse graphy by Depth
	void DFS(int vertex, bool visited[]);

	int InDegree(int vertex);		//to return in degree of a given vertex
	int OutDegree(int vertex);		//to return out degree of a given vertex
	
	void InDegreeAll();		//to check in degree of all vertices in graph
	void OutDegreeAll();	//to check out degree of all vertices in graph
	
	void SourceVertex();	//to find all Source vertexes in graph
	void SinkVertex();		//to find all Sink vertexes in graph
};
//////////////////////////////////////////END OF GRAPH CLASS

//------------------------------------------------------------//
void DGraph::ShowGraph()
{
	cout<<"Total Vertices = "<<vertices<<endl;
	cout<<"Edges:\n\t";
	for (int i = 0; i < vertices; i++)	//loop to iterate List #
	{
		gList[i].print_list();	//print list i
		cout<<endl<<"\t";	//go to next line befor next list
	}
}
//------------------------------------------------------------//
void DGraph::DisplayAdjacent(int vertex)	
{ 
	gList[vertex].print_list();	//print list of vertex
}	
//------------------------------------------------------------//
void DGraph::DisplayPredecessor(int vertex)
{
	for (int i = 0; i < vertices; i++)	//loop to iterate array index
	{
		if (gList[i].search_item(vertex) != false)	//if searched item is found then
		{
			cout<<i<<"  ";	//display contents
		}
	}
}
//------------------------------------------------------------//
void DGraph::DisplaySuccessor(int vertex)
{
	gList[vertex].print_list();	//print list of a given vertex, as its list members are successors
}
//------------------------------------------------------------//
void DGraph::BreadthFirst(int vertex)
{
	bool *visited = new bool[vertices];	//created new array of bool type
	for (int i = 0; i < vertices; i++)	//loop to visit complete array &
	{	visited[i] = false;	}	//initialize each index to false (0)
	
	BFS(vertex, visited);	//start BFS with user given vertex

	for (int index = 0; index < vertices; index++)
	{
		if (visited[index]!=true)	//if index in visited is not yet visited then
		{	BFS(index, visited);	}	//start BFS with index as vertex
	}
}
//------------------------------------------------------------//
void DGraph::BFS(int vertex, bool visited[])
{
	dynamicQueue<int> queue;	//created queue

	queue.enqueue(vertex);	//enqueue 1st vertex 
	if(visited[vertex] != true)	{	visited[vertex] = true;	}	//& mark it as visited


	while ( ! (queue.is_Empty() ) )	//untill queue is empty
	{ 
		int currentV = queue.dequeue();
		cout<<currentV<<"  ";	//dequeue vertex & print contents
		//now checking neighbours of currentVertex
		for (int j = 0; j < gList[currentV].total_items(); j++)	//loop to iterate column #/members of i'th List 
		{
			int dummy = gList[currentV].ReturnElement(j);	//in List currentV, return value of node j, & store it in dummy
			if(visited[dummy]!= true)	//if it is already not visited then
			{	
				if(dummy!=-1) //if i list is not empty then
				{	queue.enqueue( dummy );	//enqueue node's j'th value
					visited[dummy] = true;	//& mark it as visited
				}	 		
			}
		}
	}
}
//------------------------------------------------------------//
void DGraph::DepthFirst(int vertex)
{
	bool *visited = new bool[vertices];	//created new array of bool type
	for (int i = 0; i < vertices; i++)	//loop to visit complete array &
	{	visited[i] = false;	}	//initialize each index to false (0)

	DFS(vertex, visited);	//start BFS with user given vertex

	for (int index = 0; index < vertices; index++)
	{
		if (visited[index]!=true)	//if index in visited is not yet visited then
		{	DFS(index, visited);	}	//start BFS with index as vertex
	}
}
//------------------------------------------------------------//
void DGraph::DFS(int vertex, bool visited[])
{
	dynamicStack<int> stack;

	stack.push(vertex);	//push 1st vertex into stack 
	
	while ( !( stack.is_Empty() ) )
	{
		int currentV = stack.pop();		//dequeue vertex & store it in currentV
		cout<<currentV<<"  ";	//print contents

		if(visited[currentV] != true)	{	visited[currentV] = true;	}	//& mark it as visited

		//now checking neighbours of currentVertex
		if ( !(gList[currentV].is_Empty()) )	//if current vertex has neighbours/ list is not empty
		{
			for (int j = 0; j < gList[currentV].total_items(); j++)	//loop to iterate column #/members of current List 
			{
				int dummy = gList[currentV].ReturnElement(j);	//in current List, return value of node j, & store it in dummy
				if(visited[dummy]!= true)	//if it is already not visited then
				{
					visited[dummy] = true;	//& mark it as visited
					if(dummy!=-1) //if i list is not empty then
					{	stack.push( dummy );	}	//enqueue node's j'th value 
				}
			}
		}
	}
}
//------------------------------------------------------------//
int DGraph::InDegree(int vertex)
{
	int indegree = NULL;	//to store degree of given vertex
	for (int i = 0; i < vertices; i++)	//loop to iterate array index
	{
		if (gList[i].search_item(vertex) != false)	//if searched item is found then
		{	++indegree;		}	//increment indegree
	}
	return indegree;
}
//------------------------------------------------------------//
int DGraph::OutDegree(int vertex)
{
	int outdegree = NULL;	//to store degree of given vertex
	outdegree = gList[vertex].total_items();	//count total items of list and store it in outdegree
	return outdegree;
}
//------------------------------------------------------------//
void DGraph::InDegreeAll()
{
	for (int i = 0; i < vertices; i++)	//loop to check all vertices
	{
		cout<<"\t   "<<i<<"\t    "<<InDegree(i)<<"\n";	//display vertex # & its respective degree
	}
}
//------------------------------------------------------------//
void DGraph::OutDegreeAll()
{
	for (int i = 0; i < vertices; i++)	//loop to check all vertices
	{
		cout<<"\t   "<<i<<"\t    "<<OutDegree(i)<<"\n";	//display vertex # & its respective degree
	}
}
//------------------------------------------------------------//
void DGraph::SourceVertex()
{
	for (int i = 0; i < vertices; i++)	//loop to check all vertices
	{
		if (InDegree(i) == 0)	//if indegree for a vertex i is 0 then
		{	cout<<i<<"  ";	}	//display index because its required vertex
	}
}
//------------------------------------------------------------//
void DGraph::SinkVertex()
{
	for (int i = 0; i < vertices; i++)	//loop to check all vertices
	{
		if (OutDegree(i) == 0)	//if outdegree for a vertex i is 0 then
		{	cout<<i<<" ";	}	//display index because its required vertex
	}
}
//------------------------------------------------------------//