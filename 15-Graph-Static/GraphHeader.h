//Inamullah Taj - 1446
// OBJECTIVE: Implement a Class of Static Graph
#include "QueueHeader.h"
#include "StackHeader.h"
#include <conio.h>
#include <fstream>
#include <iostream>
using namespace std;
class SGraph
{
private:
	int vertices;	//to store total number of vertices of graph
	bool **gMatrix;	//Bool type Double pointer
public:
	SGraph()	//CONSTRUCTOR | nv is user-supplied number of vertices
	{
		ifstream file("GraphMatrix.txt");	//created file object to read from file
		file>>vertices;	//store first digit in vertices
		
		gMatrix = new bool *[vertices];	//dynamic creation of rows of 2D array

		for(int i = 0 ; i<vertices; i++)	//loop to iterate array #
		{
			gMatrix[i] = new bool[vertices];	//dynamic creation of columns of 2D array
		}
		
		while(file)	//until file's eof
		{
			for (int i = 0; i < vertices; i++)	//loop to iterate row number
			{
				for (int j = 0; j < vertices; j++)	//loop to iterate column number
				{	file>>gMatrix[i][j];	}	//read a digit from file & store it in array's target location
			}
		}
	}
	
	void ShowGraph();	//function to show graph edges
	
	void DisplayAdjacent(int n);	//to display neighbours of a ggiven vertex
	void DisplayPredecessor(int vertex);	//to display predecessors of a given vertex
	void DisplaySuccessor(int vertex);		//to display successors of a given vertex

	void BreadthFirst(int vertex);
	void BFS(int vertex, bool visited[]);	//function to traverse graph by Breadth first method
	
	void DepthFirst(int vertex);
	void DFS(int vertex, bool visited[]);	//function to traverse graphy by Depth
	
	int InDegree(int vertex);		//to return in degree of a given vertex
	int OutDegree(int vertex);		//to return out degree of a given vertex
	
	void InDegreeAll();		//to check in degree of all vertices in graph
	void OutDegreeAll();	//to check out degree of all vertices in graph
	
	void SourceVertex();	//to find all Source vertexes in graph
	void SinkVertex();		//to find all Sink vertexes in graph
	 
};
///////////////////////////////////////END OF GRAPH CLASS
//--------------------------------------//
void SGraph::ShowGraph()
{
	cout<<"Total Vertices = "<<vertices<<endl;
	cout<<"Edges:\n\t";
	for (int i = 0; i < vertices; i++)	//loop to iterate row #
	{
		for (int j = 0; j < vertices; j++)	//loop to iterate column #
		{
			cout<<gMatrix[i][j]<<" ";	//print content
		}
		cout<<endl<<"\t";	//go to next line after printing 1st array
	}

}
//--------------------------------------//
void SGraph::DisplayAdjacent(int n)	//n is the vertex for which neighbours are to be searched
{
	cout<<"\n\tNeighbours = ";
	for(int j = 0; j<vertices; j++)	//loop to iterate column #
	{
		if(gMatrix[n][j]!=false)	//if array index is not empty then
		{	cout<<j<<" ";	}	//display content
	}
}
//--------------------------------------//
void SGraph::DisplayPredecessor(int vertex)	//vertex is whose predecessors are to be found
{
	for (int i = 0; i < vertices; i++)	//loop to iterate row of Matrix
	{
		if (gMatrix[i][vertex] != false)	//if matrix's specified index is true then
		{
			cout<<i<<"  ";	//display index
		}
	}
}
//--------------------------------------//
void SGraph::DisplaySuccessor(int vertex)
{
	for (int i = 0; i < vertices; i++)	//loop to iterate column of Matrix
	{
		if (gMatrix[vertex][i] != false)	//if matrix's specified index is true then
		{
			cout<<i<<"  ";	//display index
		}
	}
}
//--------------------------------------//
void SGraph::BreadthFirst(int vertex)
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
//--------------------------------------//
void SGraph::BFS(int vertex, bool visited[])	//v is the starting vertex for traversal
{
	dynamicQueue<int> queue;

	queue.enqueue(vertex);	//enqueue 1st vertex 
	if(visited[vertex] != true)	{	visited[vertex] = true;	}	//& mark it as visited

	while ( ! (queue.is_Empty() ) )
	{
		int currentV = queue.dequeue();		//dequeue vertex & store it in currentV
		cout<<currentV<<"  ";	//print contents

		//now checking neighbours of currentVertex
		for (int j = 0; j < vertices; j++)	//loop to iterate column #,
		{
			if (gMatrix[currentV][j] == true)	//if current vertex has a neighbour
			{
				if(visited[j] != true)	//if neighbour's index in visited array is not marked then
				{	
					visited[j] = true;	// mark neighbour as visited
					queue.enqueue(j);	//& enqueue it	
				}
			}
		}
	}
}
//--------------------------------------//
void SGraph::DepthFirst(int vertex)
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
//--------------------------------------//
void SGraph::DFS(int vertex, bool visited[])
{
	dynamicStack<int> stack;

	stack.push(vertex);	//push 1st vertex into stack 
	if(visited[vertex] != true)	{	visited[vertex] = true;	}	//& mark it as visited

	while ( !( stack.is_Empty() ) )
	{
		int currentV = stack.pop();		//dequeue vertex & store it in currentV
		cout<<currentV<<"  ";	//print contents

		//now checking neighbours of currentVertex
		for (int j = 0; j < vertices; j++)	//loop to iterate column #,
		{
			if (gMatrix[currentV][j] == true)	//if current vertex has a neighbour
			{
				if(visited[j] != true)	//if neighbour's index in visited array is not marked then
				{	
					visited[j] = true;	// mark neighbour as visited
					stack.push(j);	//& push it	
				}
			}
		}
	}
}
//--------------------------------------//
int SGraph::InDegree(int vertex)
{
	int indegree = NULL;	//to store indegree of a given vertex

	for (int i = 0; i < vertices; i++)	//loop to iterate column
	{
		if (gMatrix[i][vertex] != false)	//if specified index is not false then
		{	++indegree;		}	//increment indegree
	}
	return indegree;
}
//--------------------------------------//
int SGraph::OutDegree(int vertex)
{
	int outdegree = NULL;	//to store indegree of a given vertex

	for (int i = 0; i < vertices; i++)	//loop to iterate row
	{
		if (gMatrix[vertex][i] != false)	//if specified index is not false then
		{	++outdegree;		}	//increment indegree
	}
	return outdegree;
}
//--------------------------------------//
void SGraph::InDegreeAll()
{
	for (int i = 0; i < vertices; i++)	//loop to check all vertices
	{
		cout<<"\t   "<<i<<"\t    "<<InDegree(i)<<"\n";	//display vertex # & its respective degree
	}
}
//--------------------------------------//
void SGraph::OutDegreeAll()
{
	for (int i = 0; i < vertices; i++)	//loop to check all vertices
	{
		cout<<"\t   "<<i<<"\t    "<<OutDegree(i)<<"\n";	//display vertex # & its respective degree
	}
}
//--------------------------------------//
void SGraph::SourceVertex()
{
	for (int i = 0; i < vertices; i++)	//loop to check all vertices
	{
		if (InDegree(i) == 0)	//if indegree for a vertex i is 0 then
		{	cout<<i<<"  ";	}	//display index because its required vertex
	}
}
//--------------------------------------//
void SGraph::SinkVertex()
{
	for (int i = 0; i < vertices; i++)	//loop to check all vertices
	{
		if (OutDegree(i) == 0)	//if outdegree for a vertex i is 0 then
		{	cout<<i<<" ";	}	//display index because its required vertex
	}
}