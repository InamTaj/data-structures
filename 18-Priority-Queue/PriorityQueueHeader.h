#include "QueueHeader.h"	//included my own header file
#include <iostream>
#include <conio.h>
using namespace std;
template <class WA>
class DHeapNODE
{
public:
	WA key;	//data to be stored in NODE
	DHeapNODE *father, *left, *right;	//father to store father of a node, left to store left subtree, right to store right subtree

	DHeapNODE()	//DEFAULT CONSTRUCTOR
	{
		key = NULL;	//nullifying data
		father = left = right = NULL;	//nullifying all pointers
	}

	DHeapNODE(int k, DHeapNODE *f, DHeapNODE *l, DHeapNODE *r)	//PARAMETERIZED CONSTRUCTOR
	{
		key = k;		//assigning user given data to key
		father = f;
		left = l;
		right = r;
	}
};
///////////////////////////////////////////////////////////END OF DYNAMIC HEAP NODE CLASS
template <class WA>
class DynamicHeap
{
private:
	DHeapNODE<WA> *root;	//to store address of root
	DHeapNODE<WA> *lastadded;	//to store address of last visited node

	void PercolateUp(DHeapNODE<WA> *temp);	//restore heap property after insertion
	void PercolateDown();	//restore heap property after deletion
	void SetLastInserted();	//Adjust position of last inserted pointer
	void SwapValues(WA &first, WA &second);	//function to swap key of temp with its fathers'
public:
	DynamicHeap()	//DEFAULT CONSTRUCTOR
	{	root = NULL;	}	//nullifying root

	bool isEmpty()	//to check if queue is empty
	{
		if (root==NULL)	//if root is empty
		{	return true;	}
		else	//if root is not empty
			return false;
	}

	void Insert(WA key);	//insert new user-given value into heap
	WA Delete();	//to return a value from heap
	bool SearchValue(WA value);	//to search a value in queue
	void PrintQueue();	//to display complete priority queue

};
///////////////////////////////////////////////////////////END OF DYNAMIC HEAP CLASS

//=========================================\\//=========================================//
template <class WA>
void DynamicHeap<WA>::Insert(WA key)
{
	DHeapNODE<WA> *node = new DHeapNODE<WA>(key, 0, 0, 0);	//created a new node
	if(root==NULL)	{	root = node;	}	//if root is empty then make node as root
	else
	{
		dynamicQueue<DHeapNODE<WA> *> queue;	//created a	queue of type DHeapNODE *
		bool inserted = false;	//to confirm status of insertion
		
		queue.enqueue(root);	//pushing root

		while(!inserted)	//untill queue is empty
		{
			DHeapNODE<WA> *temp = queue.dequeue();	//dequeue and store into temp

			if(temp->left==0)	//if temp's left is empty
			{
				temp->left = node;		//store node's address in temp's left
				node->father = temp;	//assign new node's father to temp (which is at 1 level up)
				inserted = true;	//set flag to true
			}

			else if(temp->right==0)	//if temp's right is empty
			{
				temp->right = node;		//store node's address in temp's left
				node->father = temp;	//assign new node's father to temp (which is at 1 level up)
				inserted = true;	//set flag to true
			}
			else	//if both temp's children are not empty then
			{
				queue.enqueue(temp->left);	//enqueue temp's left child
				queue.enqueue(temp->right);	//enqueue temp's right child
			}
		}
		lastadded = node;	//assign lastadded to node because node is recently added
		PercolateUp(node);	//calling function to restore heap property after insertion
	}
}
//=========================================\\//=========================================//
template <class WA>
void DynamicHeap<WA>::PercolateUp(DHeapNODE<WA> *temp)
{
	bool heapcheck = false;	//to confirm if heap property is restored
	while( !(heapcheck) && !(temp->father!=0) )
	{
		if(temp->key > temp->father->key)	//if temp's key is greater than its father
		{
			SwapValues(temp->key, temp->father->key);	//swap key of temp with its father
			temp = temp->father;	//move temp to its father
		}
		else	//if temp's key is smalller than its father then
		{	heapcheck = true;	}	//set flag to true because heap property is restored
	}
}
//=========================================\\//=========================================//
template <class WA>
void DynamicHeap<WA>::SwapValues(WA &first, WA &second)
{
	WA dummy = first;
	first = second;
	second = dummy;
}
//=========================================\\//=========================================//
template <class WA>
WA DynamicHeap<WA>::Delete()
{
	WA value = root->key;	//value to be returned
	root->key = lastadded->key;	//assign lastadded key as root's key

	DHeapNODE<WA> *temp = lastadded;	//created temp to store node of last added key
	if (lastadded->father->right == lastadded)	//if lastadded is right child of its father then
	{
		lastadded->father->right = NULL;	//nullify itself
		lastadded = lastadded->father->left;	//now lastadded is left child of its father
	}
	else	//else if lastadded is left child of its father
	{
		lastadded->father->left = NULL;	//nullify itself
		SetLastInserted();	//adjust last added (by breadth first method)
	}

	delete temp;	//delete last added node
	PercolateDown();	//restore heap property

	return value;	//finally return key
}
//=========================================\\//=========================================//
template <class WA>
void DynamicHeap<WA>::PercolateDown()
{
	DHeapNODE<WA> *temp = root;	//making copy of root
	bool heapcheck = false;	//to confirm if heap property is restored
	while( (temp->left!=NULL) || (temp->right!=NULL) && !(heapcheck) )	//untill temp's left or right becomes 0 & heap flag becomes true
	{
		if( temp->right!=NULL && (temp->right->key) > (temp->left->key) )	//if temp's right is not empty & temp's right's key is greater than temp's left's key
		{
			if((temp->right->key) > (temp->key))	//if right of temp's key is greater than temp's key
			{
				SwapValues(temp->key, temp->right->key);	//swap key of temp with its right child
				temp = temp->right;	//move temp to its left
			}
			else	
			{	heapcheck = true;	}	//set flag to true because heap property is restored
		}
		else //if temp's right is empty or temp's left key is greater
		{
			if ( (temp->left->key) > (temp->key) )	//if temp's left's key is greater than temp's key
			{
				SwapValues(temp->key, temp->left->key);	//swap temp's key with its left child
				temp = temp->left;	//move temp to its left
			}
			else	
			{	heapcheck = true;	}	//set flag to true because heap property is restored
		}
	}
}
//=========================================\\//=========================================//
template <class WA>
void DynamicHeap<WA>::SetLastInserted()
{
	dynamicQueue<DHeapNODE<WA> *> queue;	//created a queue of type dynamic heap
	DHeapNODE<WA> *temp;	//create a new pointer

	queue.enqueue(root);	//enqueue root

	while(!(queue.is_Empty()))
	{
		temp = queue.dequeue();	//dequeue and store into temp
		
		if(temp->left!=NULL)	//if temp's left is not empty then
		{	queue.enqueue(temp->left);	}	//enqueue temp's left
		else if(temp->right!=NULL)	//if temp's right is not empty then
		{	queue.enqueue(temp->right);	}	//enqueue temp's right
	}

	lastadded = temp;	//assign temp to lastadded
}
//=========================================\\//=========================================//
template <class WA>
void DynamicHeap<WA>::PrintQueue()
{
	dynamicQueue<DHeapNODE<WA>*> queue;	//created  a queue object of Dynamic Queue Class
	DHeapNODE<WA> *node = root;	//created copy of root
	if(node!=0)	//if node (root) is not empt then
	{
		queue.enqueue(node);	//enqueue node in queue
		while(!(queue.is_Empty()))	//until queue is empt
		{
			node = queue.dequeue();	//dequeue & store returned address into node
			cout<<"("<<node->key<<") ";	//print node's value
			if(node->left!=0)	//if node's left child is not empty
			{	queue.enqueue(node->left);	}	//enqueue node's left child
			if(node->right!=0)	//if node's left child is not empty
			{	queue.enqueue(node->right);	}	//enqueue node's right child
		}
	}
}
//=========================================\\//=========================================//
template <class WA>
bool DynamicHeap<WA>::SearchValue(WA value)
{
	dynamicQueue<DHeapNODE<WA>*> queue;	//created  a queue object of Dynamic Queue Class
	DHeapNODE<WA> *node = root;	//created copy of root

	if(node!=0)	//if node (root) is not empt then
	{
		queue.enqueue(node);	//enqueue node in queue
		while( !(queue.is_Empty()) )	//until queue is empt
		{
			node = queue.dequeue();	//dequeue & store returned address into node
			if(value == node->key)
			{	return true;	}
			if(node->left!=0)	//if node's left child is not empty
			{	queue.enqueue(node->left);	}	//enqueue node's left child
			if(node->right!=0)	//if node's left child is not empty
			{	queue.enqueue(node->right);	}	//enqueue node's right child
		}
	}
	return false;
}
//=========================================\\//=========================================//