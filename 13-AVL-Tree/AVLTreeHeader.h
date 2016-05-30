#include "QueueHeader.h"	//included my own header file
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
//Objective: Implement Binary Search Tree
template <class WA>	//Class of Node of Binary Tree
class AvLNode
{
public:		//Everything of this class will be accessed by other class
	AvLNode<WA> *left;	//AvLNode type pointer to left of node
	AvLNode<WA> *right;	//AvLNode type pointer to right of node
	WA key;		//data element of node
	int height;	//to store height of a node in tree

	AvLNode()	//default constructor
	{	
		left = right = height = NULL; 
	}

	AvLNode(WA kk, AvLNode<WA> *L=0, AvLNode<WA> *R=0)	//Parameterized constructor
	{	
		key = kk;	//assigninge user given value
		left = L;
		right = R;
		height = NULL;
	}
};
///////////////////////END OF Binary Tree Node Class
template <class WA>
class AvLTree	//Class of Binary Tree Data Structre
{
private:
	AvLNode<WA> *root;	//Node type root node of tree

	void cleartree(AvLNode<WA> *temp);	//to free memory reserved by nodes in tree
	int heightofnode(AvLNode<WA> *temp) const;	//to return height of node
	int balancefactor(AvLNode<WA> *temp) const;	//to return balance factor of a given node
	void setheight(AvLNode<WA> *temp);	//post order based function to update height of complete tree

	void insertvalue(AvLNode<WA> *&temp, const WA & value);	//pvt recursive function to insert new value in tree
	void deletevalue(AvLNode<WA> *&temp, const WA value);	//function to delete a value in tree

	AvLNode<WA> *search (AvLNode<WA> *temp, WA value);	//to search a value in tree
	AvLNode<WA> *findfather (AvLNode<WA> *temp, AvLNode<WA> *leaf);	//to search a node's father in tree


	void SingleRightRotation(AvLNode<WA> *&k2);	//function to perform single right rotation on a given node
	void SingleLeftRotation(AvLNode<WA> *&k2);	//function to perform single left rotation on a given node
	void DoubleLeftRightRotation(AvLNode<WA> *&k3);	//function to perform double rotation on a given node
	void DoubleRightLeftRotation(AvLNode<WA> *&k3);	//function to perform double rotation on a given node
	
	void BalanceNode(AvLNode<WA> *&temp);	//function to balance a given node

	void preorder(AvLNode<WA> *temp);	//Traversel function
	void inorder(AvLNode<WA> *temp);		//Traversel function
	void postorder(AvLNode<WA> *temp);	//Traversel function

	void deletewithNochild(AvLNode<WA> *temp);	//function to delete a node with No child
	void deletewithOneChild(AvLNode<WA> *temp);	//function to delete a node with One Child
	void deletewith2Child(AvLNode<WA> *temp);	//function to delete a node with  children
	void deletewithcopying(AvLNode<WA> *temp);	//function to delete 2 Child node with 'deletebycopy' method
	void deletewithmerge(AvLNode<WA> *temp);	//function to delete 2 child node with delete by merging method

	int totalNodes(AvLNode<WA> *temp);		//function to count all nodes of tree
	int total_leaves(AvLNode<WA> *temp);		//function to count all leaves in tree
	int total2ChildNodes(AvLNode<WA> *temp);	//function count all nodes with 2 children

public:
	AvLTree()	//Constructor
	{	root = NULL;	}	//nullifying root
	~AvLTree()	//Destructor
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
	void insertvalue(WA value);	//overloaded public function declaration
	void deletevalue(WA value)	{ deletevalue(root, value);	}	//function to delete a value in tree

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
int AvLTree<WA>::heightofnode(AvLNode<WA> *temp) const
{
	return temp==NULL ? -1 : temp->height;
}
//==============================//==============================//
template <class WA>
int AvLTree<WA>::balancefactor(AvLNode<WA> *temp) const
{
	return ( heightofnode(temp->left) - heightofnode(temp->right) );
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::setheight(AvLNode<WA> *temp)	//temp 1st time is root
{
	if(temp!=0)	//if temp isn't empty then
	{
		setheight(temp->left);	//recursive call to visit temp's left sub-tree
		setheight(temp->right);	//recursive call to visit temp's left right-tree
		//Balancing height
		temp->height = max(heightofnode(temp->left), heightofnode(temp->right)) + 1;	//update temp node's height
	}
}
//==============================//==============================//
template <class WA>
bool AvLTree<WA>::search(WA value)	//////PUBLIC DEFINITION
{
	if (!isEmpty())	//if tree is not empty
	{
		AvLNode<WA> *searchedNode = search(root, value);		//created new node pointer & stored address returned from pvt search function
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
AvLNode<WA>* AvLTree<WA>::search(AvLNode<WA> *temp, WA value)	/////PVT DEFINITION
{
	AvLNode<WA> *to_searched = 0;	//created new node pointer in which address of required node will be saved
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
AvLNode<WA>* AvLTree<WA>::findfather(AvLNode<WA>*temp, AvLNode<WA> *leaf)	//temp node is whose father is to be searched; leaf node is the current node where search will happen
{
	AvLNode<WA> *father = 0;	//created new node pointer in which father node's address will be stored 
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
void AvLTree<WA>::insertvalue(WA value)
{
	insertvalue(root, value);	//calling over loaded insert value function
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::insertvalue(AvLNode<WA> *&temp, const WA & value)		//leaf 1st time is root, then it changes as it traverses the tree
{
	if(temp==NULL)	//if provided node is empty then
	{
		temp = new AvLNode<WA> (value, NULL, NULL);	//create a node & 
	}
	else	//if node is not empty then
	{
		if(value < (temp->key) )	//if user provided value is smaller than temp's key then
		{
			insertvalue(temp->left, value);	//go to left sub-tree of temp to insert value
			if ( balancefactor(temp) == 2)	//if temp is left higher, ie. temp's Balance Factor = 2, then
			{
				if ( balancefactor(temp->left) == 1 ) //if temp's left node has Balance Factor 1 then
				{
					SingleRightRotation(temp);	//send temp node for rotation because temp is unbalance
				}
				else if ( balancefactor(temp->left) == -1 )	//if temp's left node has Balance Factor -1, then
				{
					DoubleLeftRightRotation(temp);	//send temp for double rotation because temp is unbalance
				}
			}
		}
		else if (value > (temp->key))	//if user provided value is greater than temp's key then
		{
			insertvalue(temp->right, value);	//go to right sub-tree of temp to insert value
			if ( balancefactor(temp) == -2 )	//if temp is right higher, ie. temp's Balance Factor = -2, then
			{
				if ( balancefactor(temp->right) == -1 )	//if temp's left node has Balance Factor -1 then
				{
					SingleLeftRotation(temp);	//send temp node for rotation because temp is unbalance
				}
				else if ( balancefactor(temp->right) == 1 )	//if temp's right node has Balance Factor 1, then
				{
					DoubleRightLeftRotation(temp);	//send temp for double rotation because temp is unbalance
				}
			}
		}
		else;	//for duplication, do nothing
		
		temp->height = max ( heightofnode(temp->left), heightofnode(temp->right) ) + 1;	//update node's height
	}
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::SingleRightRotation(AvLNode<WA> * & k2)	//k2 is temp node where imbalance is present & we have to rotate it
{
	AvLNode<WA> *k1 = k2->left;	//create copy of temp's left & store it in k1
	k2->left = k1->right;	//make k1's right child as temp's left child
	k1->right = k2;	//make k1 as parent of temp node	
	k2->height = max( heightofnode(k2->left), heightofnode(k1->right) ) + 1;	//update k2's height
	k1->height = max( heightofnode(k1->left), heightofnode(k2)) +1;	//update k1's height, as k1's right node is now k2(temp) so second arg. of max is k2's height
	k2 = k1;	//assign k1 as new temp node (this is done because temp was passed by reference)
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::SingleLeftRotation(AvLNode<WA> * & k2)
{
	AvLNode<WA> *k1 = k2->right;	//create copy of temp's right child & store it in k1
	k2->right = k1->left;	//store k1's left child as temp's right child
	k1->left = k2;	//make k2 as left child of k1
	k2->height = max ( heightofnode(k2->left), heightofnode(k2->right) ) + 1;	//update height of k2
	k1->height = max (heightofnode(k2), heightofnode(k1->right) ) +1;	//update height of k1, note k2's hieght as arg.
	k2 = k1;	//assign k1 as temp node (due to reference of k2)
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::DoubleLeftRightRotation(AvLNode<WA> *  &k3)	//k3 is node @ which imbalance is present
{
	SingleLeftRotation(k3->left);	//rotate k3's (temp) left child to left side
	SingleRightRotation(k3);	//rotate k3 (temp) to right side
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::DoubleRightLeftRotation(AvLNode<WA> *  &k3)	//k3 is node @ which imbalance is present
{
	SingleRightRotation(k3->right);	//rotate k3's (temp) right child to right side
	SingleLeftRotation(k3);	//rotate k3(temp) node toleft side
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::deletevalue(AvLNode<WA> *&temp, const WA value)
{
	if(value==temp->key)
	{
		if(temp->left==0 && temp->right==0)	//if temp node don't have any children
		{	deletewithNochild(temp);	}	//call to respective function
		else if( (temp->left!=0 && temp->right==0) || (temp->left==0 && temp->right!=0) )	//if temp node has any 1 child, left or right
		{	deletewithOneChild(temp);	}	//call to respective function
		else if(temp->left!=0 && temp->right!=0)	//if temp node has 2 children
		{	deletewith2Child(temp);		}	//call to respective function
		return;
	}
	else if(value < temp->key)	//if value is smaller than temp's key then
	{
		deletevalue(temp->left, value);	//recursive call to search in temp's left & delete node
	}
	else if(value > temp->key)	//if value is greater than temp's key then
	{
		deletevalue(temp->right, value);	//recursive call to search in temp's right & delete node
	}
	
	setheight(root);	//call func with root to update height of whole tree

	//NOW BALANCING
	if ( balancefactor(temp) == 2)	//if temp is left higher, ie. temp's Balance Factor = 2, then
	{
		if ( balancefactor(temp->left) >= 0 ) //if temp's left node has Balance Factor 1 or 0 then
		{
			SingleRightRotation(temp);	//send temp node for rotation because temp is unbalance
		}
		else if ( balancefactor(temp->left) == -1 )	//if temp's left node has Balance Factor -1, then
		{
			DoubleLeftRightRotation(temp);	//send temp for double rotation because temp is unbalance
		}
	}
	else 
	if ( balancefactor(temp) == -2 )	//if temp is right higher, ie. temp's Balance Factor = -2, then
	{
		if ( balancefactor(temp->right) <= 0 )	//if temp's left node has Balance Factor -1 or 0 then
		{
			SingleLeftRotation(temp);	//send temp node for rotation because temp is unbalance
		}
		else if ( balancefactor(temp->right) == 1 )	//if temp's right node has Balance Factor 1, then
		{
			DoubleRightLeftRotation(temp);	//send temp for double rotation because temp is unbalance
		}
	}
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::deletewithNochild(AvLNode<WA> *temp)	//temp is node which is to be deleted
{
	if(temp==root)	//if temp is root node then
	{
		delete root;	//free memory of root node
		root = 0;	//nullify root
	}
	else	//if temp is some other node 
	{
		AvLNode<WA> *father = findfather(temp, root);	//calling findfather func to find father of temp node & store its address in father node pointer
		
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
void AvLTree<WA>::deletewithOneChild(AvLNode<WA> *temp)	//temp is node which is to be deleted
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
		AvLNode<WA> * father = findfather(temp, root);	//calling findfather func to find father of temp node & store its address in father node pointer
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
void AvLTree<WA>::deletewith2Child(AvLNode<WA> *temp)	//temp is node which is to be deleted
{
	deletewithcopying(temp);
}
//==============================//==============================//
template <class WA>
void AvLTree<WA>::deletewithmerge(AvLNode<WA> *temp)	//temp is node which is to be deleted
{
	AvLNode<WA> *leaf = temp->left;	//copied temp's left into leaf
	if(temp==root)	//if temp is root
	{
		root = temp->left;	//make root to temp's left node (sucessor)
	}
	else	//if temp is some other node
	{
		AvLNode<WA> * father = findfather(temp, root);	//calling findfather func to find father of temp node & store its address in father node pointer
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
void AvLTree<WA>::deletewithcopying(AvLNode<WA> *temp)	//temp is node which is to be deleted
{
	AvLNode<WA> *leaf = temp;	//created copy of temp
	if(temp==root)	//if temp is root node then	[SUCESSOR CASE]
	{
		leaf = leaf->left;	//move leaf (root) to left
		while(leaf->right!=0)	//untill leaf's right is not empty
		{	leaf = leaf->right;	}	//move leaf to its right node
	}
	else	//if temp is some other node then
	{
		AvLNode<WA> *father = findfather(temp, root);	//calling findfather func to find father of temp node & store its address in father node pointer
	
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
void AvLTree<WA>::preorder(AvLNode<WA> *temp)	//temp is node which is to be visited
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
void AvLTree<WA>::inorder(AvLNode<WA> *temp)	//temp is node which is to be visited
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
void AvLTree<WA>::postorder(AvLNode<WA> *temp)	//temp is node which is to be visited
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
void AvLTree<WA>::breadthfirst()
{	
	dynamicQueue<AvLNode<WA>*> queue;	//created  a queue object of Dynamic Queue Class
	AvLNode<WA> *node = root;	//created copy of root
	if(node!=0)	//if node (root) is not empt then
	{
		queue.enqueue(node);	//enqueue node in queue
		while(!(queue.is_Empty()))	//until queue is empt
		{
			node = queue.dequeue();	//dequeue & store returned address into node
			cout<<"("<<node->key<<")\tHeight["<<heightofnode(node)<<"]\tbFactor["<<balancefactor(node)<<"]\n";	//print node's value
			if(node->left!=0)	//if node's left child is not empty
			{	queue.enqueue(node->left);	}	//enqueue node's left child
			if(node->right!=0)	//if node's left child is not empty
			{	queue.enqueue(node->right);	}	//enqueue node's right child
		}
	}
}
//==============================//==============================//
template <class WA>
int AvLTree<WA>::totalNodes(AvLNode<WA> *temp)
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
int AvLTree<WA>::total_leaves()  //public definition
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
int AvLTree<WA>::total_leaves(AvLNode<WA> *temp)      //private definition
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
int AvLTree<WA>::total2ChildNodes()
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
int AvLTree<WA>::total2ChildNodes(AvLNode<WA> *temp)
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
void AvLTree<WA>::cleartree(AvLNode<WA> *temp)	//temp is node which is to be visited
{
	if (temp!=0)	//if temp is not empty
	{
		cleartree(temp->left);	//recursive call to delete left sub-tree of temp node
		cleartree(temp->right);	//recursive call to delete left sub-tree of temp node
		delete temp;	//finally delete temp itself
	}
}
//==============================//==============================//