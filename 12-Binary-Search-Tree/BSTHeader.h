#include "QueueHeader.h"	//included my own header file
#include <iostream>
#include <conio.h>
using namespace std;
//Objective: Implement Binary Search Tree
template <class WA>	//Class of Node of Binary Tree
class BSTNode
{
public:		//Everything of this class will be accessed by other class
	BSTNode<WA> *left;	//BSTNode type pointer to left of node
	BSTNode<WA> *right;	//BSTNode type pointer to right of node
	WA key;		//data element of node

	BSTNode()	//default constructor
	{	left = right = 0; }

	BSTNode(WA kk, BSTNode<WA> *L=0, BSTNode<WA> *R=0)	//Parameterized constructor
	{	
		key = kk;	//assigninge user given value
		left = L;
		right = R;
	}
};
///////////////////////END OF Binary Tree Node Class
template <class WA>
class BST	//Class of Binary Tree Data Structre
{
private:
	BSTNode<WA> *root;	//Node type root node of tree

	void cleartree(BSTNode<WA> *temp);	//to free memory reserved by nodes in tree
	
	bool insertvalue(BSTNode<WA> *leaf, WA value);	//pvt recursive function to insert new value in tree
	BSTNode<WA> *search (BSTNode<WA> *temp, WA value);	//to search a value in tree
	BSTNode<WA> *findfather (BSTNode<WA> *temp, BSTNode<WA> *leaf);	//to search a node's father in tree

	void preorder(BSTNode<WA> *temp);	//Traversel function
	void inorder(BSTNode<WA> *temp);		//Traversel function
	void postorder(BSTNode<WA> *temp);	//Traversel function

	void deletewithNochild(BSTNode<WA> *temp);	//function to delete a node with No child
	void deletewithOneChild(BSTNode<WA> *temp);	//function to delete a node with One Child
	void deletewith2Child(BSTNode<WA> *temp);	//function to delete a node with  children
	void deletewithcopying(BSTNode<WA> *temp);	//function to delete 2 Child node with 'deletebycopy' method
	void deletewithmerge(BSTNode<WA> *temp);	//function to delete 2 child node with delete by merging method

	int totalNodes(BSTNode<WA> *temp);		//function to count all nodes of tree
	int total_leaves(BSTNode<WA> *temp);		//function to count all leaves in tree
	int total2ChildNodes(BSTNode<WA> *temp);	//function count all nodes with 2 children

public:
	BST()	//Constructor
	{	root = NULL;	}	//nullifying root
	~BST()	//Destructor
	{	cleartree();	}	//calling cleartree function to delete nodes (by recursively visiting tree)
	void cleartree()	//overloaded function definition
	{ cleartree(root); root=0; }	//calling pvt function with root's address, after that, nullify root
	
	bool isEmpty() const
	{
		if (root==0)	//if tree is empty
		{	return true;	}
		else	//if tree is not empty
		{	return false;	}
	}

	bool search(WA value);	//overloaded public function declaration
	bool insertvalue(WA value);	//overloaded public function declaration
	bool deletevalue(WA value);	//function to delete a value in tree

	void preorder()	{ preorder(root); }		//overloaded public function declaration
	void inorder()	{ inorder(root);  }		//overloaded public function declaration
	void postorder() { postorder(root); }	//overloaded public function declaration
	void breadthfirst();	//function to traverse node level by level

	int totalNodes()        {       return totalNodes(root);        };      //public func to return total number of nodes in tree
	int total_leaves();     //public func to return 1 if tree has only 1 node otherwise count & return all leaves
	int total2ChildNodes(); //public func to count nodes with 2 children

};
////////////////////////////////////END OF TREE CLASS

//==============================//==============================//
template <class WA>
bool BST<WA>::search(WA value)	//////PUBLIC DEFINITION
{
	if (!isEmpty())	//if tree is not empty
	{
		BSTNode<WA> *searchedNode = search(root, value);		//created new node pointer & stored address returned from pvt search function
		if (searchedNode!=0)	//if node address is not empty then
		{
			return true;
		}
		else	//else if node address is empty
			return false;
	}
	else	//if tree is empty, then
		return false;
}
//==============================//==============================//
template <class WA>
BSTNode<WA>* BST<WA>::search(BSTNode<WA> *temp, WA value)	/////PVT DEFINITION
{
	BSTNode<WA> *to_searched = 0;	//created new node pointer in which address of required node will be saved
	if (temp!=0)	//if arg. given temp node is not empty, then
	{
		if (temp->key==value)	//if temp node has user-specified value then
		{	to_searched = temp;	}	//assign address of temp to to_searched node, which will be return @ the end
		if (to_searched==0)	//if node is still empt then
		{	to_searched = search(temp->left, value);	}	//recursive call to search in left sub-tree of temps
		if (to_searched==0)	//if node is still empt then
		{	to_searched = search(temp->right, value);	}	//recursive call to search in right sub-tree of temps
	}
	return to_searched;	//Finally return the searched node
}
//==============================//==============================//
template <class WA>
BSTNode<WA>* BST<WA>::findfather(BSTNode<WA>*temp, BSTNode<WA> *leaf)	//temp node is whose father is to be searched; leaf node is the current node where search will happen
{
	BSTNode<WA> *father = 0;	//created new node pointer in which father node's address will be stored 
	if(leaf!=0) //if leaf node is not empty, then
	{
		if(leaf->left==temp || leaf->right==temp)	//if temp node is leaf's left or right child then 
		{	father = leaf;	}	//assign address of leaf to father
		if(father==0)	//if still father is not found then
		{	father = findfather(temp, leaf->left);	}	//recursive call to search father in left sub-tree of leaf
		if(father==0)	//if still father is not found then
		{	father = findfather(temp, leaf->right);	}	//recursive call to search father in right sub-tree of leaf
	}
	return father;	//Finally return father node
}
//==============================//==============================//
template <class WA>
bool BST<WA>::insertvalue(WA value)
{
	if (isEmpty())	//if tree is empty
	{
		root = new BSTNode<WA>(value, 0, 0);	//create a node with user-given data & store its address in root
		return true;	//for confirmation of respective output message
	}
	else	//if tree is not empty then
	{
		return insertvalue(root, value);	//call & return result obtained from overloaded insert function, it may be true or false
	}
}
//==============================//==============================//
template <class WA>
bool BST<WA>::insertvalue(BSTNode<WA> *leaf, WA value)	//leaf 1st time is root, then it changes as it traverses the tree
{
	if(leaf->key==value)	//if value is equal to leaf's key
	{	return false;	}	//for confirmation of respective output message
	
	else if(value < leaf->key)	//if user-specified value is smaller than leaf's key then
	{
		if(leaf->left==0)	//if leaf's left node is empty then
		{
			leaf->left = new BSTNode<WA>(value, 0, 0);	//create a node with user-given data & store its address in leaf's left
			return true;	//for confirmation of respective output message
		}
		else	//if leaf's left is not empty 
		{
			return insertvalue(leaf->left, value);	//recursive call to insertvalue in leaf's left subtree
		}
	}
	else if(value > leaf->key)	//if user-specified value is larger than leaf's key then
	{
		if(leaf->right==0)	//if leaf's left node is empty then
		{
			leaf->right = new BSTNode<WA>(value, 0, 0);	//create a node with user-given data & store its address in leaf's left
			return true;	//for confirmation of respective output message
		}
		else	//if leaf's left is not empty
		{
			return insertvalue(leaf->right, value);	//recursive call to insertvalue in leaf's left subtree
		}
	}
	return false;	//for confirmation of respective output message
}
//==============================//==============================//
template <class WA>
bool BST<WA>::deletevalue(WA value)
{
	BSTNode<WA> *temp = search(root, value);	//calling search function to find node which has user-specified data & stored its address in temp pointer
	if(temp!=0)	//if temp node is not null then
	{
		if(temp->left==0 && temp->right==0)	//if temp node don't have any children
		{	deletewithNochild(temp);	}	//call to respective function
		else if( (temp->left!=0 && temp->right==0) || (temp->left==0 && temp->right!=0) )	//if temp node has any 1 child, left or right
		{	deletewithOneChild(temp);	}	//call to respective function
		else if(temp->left!=0 && temp->right!=0)	//if temp node has 2 children
		{	deletewith2Child(temp);		}	//call to respective function		
		return true;	//for prompting respective output message
	}
	else
		return false;	//for prompting respective output message
}
//==============================//==============================//
template <class WA>
void BST<WA>::deletewithNochild(BSTNode<WA> *temp)	//temp is node which is to be deleted
{
	if(temp==root)	//if temp is root node then
	{
		delete root;	//free memory of root node
		root = 0;	//nullify root
	}
	else	//if temp is some other node 
	{
		BSTNode<WA> *father = findfather(temp, root);	//calling findfather func to find father of temp node & store its address in father node pointer
		
		if(father->left==temp)	//if temp is left child of its father
		{
			delete temp;	//free memory of temp node
			father->left=0;	//nullify father's left
		}
		else if(father->right==temp)	//if temp is right child of its father
		{
			delete temp;	//free memory of temp node
			father->right=0;//nullify father's right
		}
	}
}
//==============================//==============================//
template <class WA>
void BST<WA>::deletewithOneChild(BSTNode<WA> *temp)	//temp is node which is to be deleted
{
	if(temp==root)	//if temp is root
	{
		if(temp->left!=0)	//if temp's left is not empty
		{	
			root = temp->left;	//then make root to temp's left node &
			delete temp;	//delete temp (previously root node)
		}
		else if(temp->right!=0)	//if temp's right is not empty
		{
			root = temp->right;	//then make root to temp's right node &
			delete temp;	//delete temp (previously root node)
		}
	}
	else	//if temp is some other node
	{
		BSTNode<WA> * father = findfather(temp, root);	//calling findfather func to find father of temp node & store its address in father node pointer
		if(father->left==temp)	//if temp is father's left node
		{
			if (temp->left!=0 && temp->right==0)    //if temp's left node is not empty then
			{
				father->left = temp->left;      //assign left of temp's child to father's left
				temp->left = 0;         //Nullify temp's left
			}
			else if (temp->left==0 && temp->right!=0)       //if father's right node is not empty then
			{
				father->left = temp->right;     //assign right of temp's child to father's left
				temp->right = 0;                //Nullify temp's right
			}
			delete temp;	//finally delete temp node
		}
		else if(father->right==temp)	//if temp node is father's right node
		{
			if (temp->left!=0 && temp->right==0)    //if temp's left node is not empty then
			{
				father->right = temp->left;             //assign left of temp's child to father's right
				temp->left = 0;         //Nullify temp's left
			}
			else if (temp->left==0 && temp->right!=0)       //if father's right node is not empty then
			{
				father->right = temp->right;    //assign right of temp's child to father's right
				temp->right = 0;		//Nullify temp's right
			}
		}
	}
}
//==============================//==============================//
template <class WA>
void BST<WA>::deletewith2Child(BSTNode<WA> *temp)	//temp is node which is to be deleted
{
	deletewithmerge(temp);
}
//==============================//==============================//
template <class WA>
void BST<WA>::deletewithmerge(BSTNode<WA> *temp)	//temp is node which is to be deleted
{
	BSTNode<WA> *leaf = temp->left;	//copied temp's left into leaf
	if(temp==root)	//if temp is root
	{
		root = temp->left;	//make root to temp's left node (sucessor)
	}
	else	//if temp is some other node
	{
		BSTNode<WA> * father = findfather(temp, root);	//calling findfather func to find father of temp node & store its address in father node pointer
		if(father->right==temp)	//if temp is right child of its father
		{
			father->right = temp->left;	//save temp's left in father's right
		}
		if(father->left==temp)	//if temp is left child of its father
		{
			father->left = temp->left;	//save temp's left in father's right
		}
	}
	while(leaf->right!=0)	//until leaf's right becomes 0
	{	leaf = leaf->right;	}	//advance leaf to leaf's righ node
	leaf->right = temp->right;	//put temp's right node into leaf's right node
	
	temp->left=temp->right=0;	//nullify temp's left & right (to prevent error)
	delete temp;	//finally delete temp
}
//==============================//==============================//
template <class WA>
void BST<WA>::deletewithcopying(BSTNode<WA> *temp)	//temp is node which is to be deleted
{
	BSTNode<WA> *leaf = temp;	//created copy of temp
	if(temp==root)	//if temp is root node then	[SUCESSOR CASE]
	{
		leaf = leaf->left;	//move leaf (root) to left
		while(leaf->right!=0)	//untill leaf's right is not empty
		{	leaf = leaf->right;	}	//move leaf to its right node
	}
	else	//if temp is some other node then
	{
		BSTNode<WA> *father = findfather(temp, root);	//calling findfather func to find father of temp node & store its address in father node pointer
	
		if(father->left==temp)	//if temp is father's left child	[SUCESSOR CASE]
		{
			leaf = leaf->left;	//move leaf (root) to left
			while(leaf->right!=0)	//untill leaf's right is not empty
			{	leaf = leaf->right;	}	//move leaf to its right node
		}
		else if(father->right==temp)	//if temp is father's right child [PREDECESSOR CASE]
		{
			leaf = leaf->right;	//move leaf (root) to right
			while(leaf->left!=0)	//untill leaf's left is not empty
			{	leaf = leaf->left;	}	//move leaf to its left node
		}
	}
	//swapping values
	WA val = temp->key;	//created a template type variable & store temp's key in it
	temp->key = leaf->key;	//assigned leaf's key to temp's key
	leaf->key = val;	//assigned val (temp's previous key) to leaf's key

	if( (leaf->left!=0 && leaf->right==0) || (leaf->left==0 && leaf->right!=0) )	// if leaf node has any 1 left or right child
	{	deletewithOneChild(leaf);	}	//call to respective function
	else if(leaf->left==0 && leaf->right==0)	//if leaf node has no children at all then
	{	deletewithNochild(leaf);	}	//call to respective function
}
//==============================//==============================//
template <class WA>
void BST<WA>::preorder(BSTNode<WA> *temp)	//temp is node which is to be visited
{
	if(temp!=0)	//if temp isn't empty then
	{
		cout<<"("<<temp->key<<") ";	//print temp's value
		preorder(temp->left);	//recursive call to visit temp's left sub-tree
		preorder(temp->right);	//recursive call to visit temp's left right-tree
	}
}
//==============================//==============================//
template <class WA>
void BST<WA>::inorder(BSTNode<WA> *temp)	//temp is node which is to be visited
{
	if(temp!=0)	//if temp isn't empty then
	{
		inorder(temp->left);	//recursive call to visit temp's left sub-tree
		cout<<"("<<temp->key<<") ";	//print temp's value
		inorder(temp->right);	//recursive call to visit temp's left right-tree
	}
}
//==============================//==============================//
template <class WA>
void BST<WA>::postorder(BSTNode<WA> *temp)	//temp is node which is to be visited
{
	if(temp!=0)	//if temp isn't empty then
	{
		postorder(temp->left);	//recursive call to visit temp's left sub-tree
		postorder(temp->right);	//recursive call to visit temp's left right-tree
		cout<<"("<<temp->key<<") ";	//print temp's value
	}
}
//==============================//==============================//
template <class WA>
void BST<WA>::breadthfirst()
{	
	dynamicQueue<BSTNode<WA>*> queue;	//created  a queue object of Dynamic Queue Class
	BSTNode<WA> *node = root;	//created copy of root
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
//==============================//==============================//
//-------------------------//-------------------------
template <class WA>
int BST<WA>::totalNodes(BSTNode<WA> *temp)
{
        if(temp!=0)
        {
                int total=1;    //variable to store number of nodes
                total += totalNodes(temp->left);        //go to left side of node to count total nodes
                total += totalNodes(temp->right);       //go to right side of node to count total nodes
                return total;   //return total count
        }
        else    //if temp is zero then
                return 0;
}
//==============================//==============================//
template <class WA>
int BST<WA>::total_leaves()  //public definition
{
        if(!isEmpty())  //if tree is not empty
        {
                if(root->left==0 && root->right==0) //if root has no children then
                        return 1;       
                else    //if tree has multiple nodes then
                        return total_leaves(root);      //call to recursive function for counting
        }
        else    //if tree is empty
                return 0;
}
//==============================//==============================//
template <class WA>
int BST<WA>::total_leaves(BSTNode<WA> *temp)      //private definition
{
        int total = 0;  //variable to store no. of leaves
        if(temp!=0)     //if node is not zero
        {
                if(temp->left==0 && temp->right==0)     //if node has no children then its leaf node, so increment total
                {       ++total;        }
                total += total_leaves(temp->left);      //go to left side of tree to search leaves
                total += total_leaves(temp->right);     //go to righat side of tree to search leaves
        }
        return total;   //return counter
}
//==============================//==============================//
template <class WA>
int BST<WA>::total2ChildNodes()
{
        if(isEmpty())   //if tree is empty then
        {
                return 0;
        }
        else    //if tree has nodes then
        {
                return total2ChildNodes(root);  //call to recursive function to count nodes
        }
}
//==============================//==============================//
template <class WA>
int BST<WA>::total2ChildNodes(BSTNode<WA> *temp)
{
        int total = 0;  //counter to count nodes
        if(temp!=0)     //if temp is not empty
        {
                if(temp->left!=0 && temp->right!=0)     //if node has two children, then
                {
                        ++total;        //increment total
                }
                total += total2ChildNodes(temp->left);  //go to left side of tree to search node & add count in total
                total += total2ChildNodes(temp->right); //go to right side of tree to search node & add count in total
        }
        return total;   //return counter
}
//==============================//==============================//
template <class WA>
void BST<WA>::cleartree(BSTNode<WA> *temp)	//temp is node which is to be visited
{
	if (temp!=0)	//if temp is not empty
	{
		cleartree(temp->left);	//recursive call to delete left sub-tree of temp node
		cleartree(temp->right);	//recursive call to delete left sub-tree of temp node
		delete temp;	//finally delete temp itself
	}
}
//==============================//==============================//