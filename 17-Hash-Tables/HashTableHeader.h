#include <conio.h>
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
template <class WA>
class HashNODE
{
public:
	WA key;	//key is data value to be stored in hash table 
	bool flag;	//to check status of an index storage

	HashNODE()	//DEFAULT CONSTRUCTOR
	{	
		key = -1;	//nullify key
		flag = true;	//set flag to true
	}
	HashNODE(WA v)	//PARAMETERIZED CONSTRUCTOR
	{
		key = v;	//assign user given value to key
		flag = false;	//set flag to false
	}
};
//////////////////////////////////////////END OF NODE CLASS
template <class WA>
class HashTable
{
private:
	HashNODE<WA> *hashtable;	//declared a hash table
	int size;	//to store size of table
	
	unsigned int HashFunction(WA key);	//function that maps index from key
	unsigned int ModulusMethod(WA key);	//a method to calculate index from key

	int LinearProbing(int index);	//function to resolve collision
	int LinearProbing(int index, WA key);	//function to resolve collision
public:
	HashTable(int s)	//PARAMETERIZED CONSTRUCTOR
	{
		hashtable = new HashNODE<WA>[s];	//creating hash table (array based) of user-given size 's'
		size = s; //save s into size
	}
	void Insert(WA key);	//function to insert key
	int Search(WA key);	//to search a key in hash table
	WA GetKey(WA key);	//to withdraw a key from hash table
	void ShowTable();	//to print complete hash table
};
//////////////////////////////////////////END OF HASH TABLE CLASS

//===================================\\//===================================//
template <class WA>
unsigned int HashTable<WA>::HashFunction(WA key)
{
	return ModulusMethod(key);	//calling modulus method function
}
//===================================\\//===================================//
template <class WA>
unsigned int HashTable<WA>::ModulusMethod(WA key)
{
	return key%size;	//Return Modulu
}
//===================================\\//===================================//
template <class WA>
int HashTable<WA>::LinearProbing(int index)
{
	for(int i = index+1; i<size; i++)	//loop to start searching required index from index + 1
	{
		if(hashtable[i].flag==true)	//if ith space is empty in table then
		{	return i;	}	//return i as next index
	}
	
	for(int i = 0; i<size; i++)	//loop to start searching required index from 0 index
	{
		if(hashtable[i].flag==true)	//if ith space is empty in table then
		{	return i;	}	//return i as next index
	}

	return -1;	//else case: return -1 to show no space in table
}
//===================================\\//===================================//
template <class WA>
int HashTable<WA>::LinearProbing(int index, WA key)
{
	for(int i = index+1; i<size; i++)	//loop to start searching required index from index + 1
	{
		if(hashtable[i].key==key)	//if ith space has key
		{	return i;	}	//return i as next index
	}
	
	for(int i = 0; i<size; i++)	//loop to start searching required index from 0 index
	{
		if(hashtable[i].key==key)	//if ith space has key
		{	return i;	}	//return i as next index
	}

	return -1;	//else case: return -1 to show key is not present in table
}
//===================================\\//===================================//
template <class WA>
void HashTable<WA>::Insert(WA key)
{
	int find = Search(key);
	if(find==0)
	{
		int index = HashFunction(key);	//get index from hash function
		if(hashtable[index].flag==true)	//if space at index is empty
		{	
			hashtable[index].key = key;	//put user given key to that place
			hashtable[index].flag = false;	//set flag to false
			cout<<"\n\tValue added Successfully!";	//respective output message
		}	
		
		else	//if space at index is not empty
		{
			int nextindex = LinearProbing(index);	//get next index
			if(nextindex!=-1)	//if hash table is not full
			{
				hashtable[nextindex].key = key;	//assign key at nextindex location
				hashtable[nextindex].flag = false;	//set flag to false
				cout<<"\n\tValue added Successfully!";	//respective output message
			}
			else	//if table is full then
			{	cout<<"\n\tERROR:: Hash Table is Full!";	}	//respective output message
		}
	}
	else
	{	cout<<"\n\tERROR:: Duplication is forbidden!";	}
}
//===================================\\//===================================//
template <class WA>
int HashTable<WA>::Search(WA key)
{
	int index = HashFunction(key);	//get index from hash function
	if(hashtable[index].key==key)	//if key at index is present
	{	return index;	}
	
	else	//if space at index is not empty
	{
		int nextindex = LinearProbing(index, key);	//get next index
		if(nextindex!=-1)	//if hash table has key
		{	return nextindex;	}
		else	//if table has not key then
		{	return 0;	}	//to show error
	}
}
//===================================\\//===================================//
template <class WA>
WA HashTable<WA>::GetKey(WA key)
{
	WA value = NULL;	//value to be returned (Null if key not found in table)
	int index = HashFunction(key);	//get index from hash function
	if(hashtable[index].key==key)	//if key at index is present
	{	
		hashtable[index].flag = true;	//set flag to make index empty
		value = hashtable[index].key;	//assign value
		hashtable[index].key = -1;		//make index empty
	}
	
	else	//if space at index is not empty
	{
		int nextindex = LinearProbing(index, key);	//get next index
		if(nextindex!=-1)	//if hash table has key
		{	
			hashtable[index].flag = true;	//set flag to make index empty
			value = hashtable[index].key;	//assign value
			hashtable[index].key = -1;		//make index empty
		}
	}
	return value;	//return value finally
}
//===================================\\//===================================//
template <class WA>
void HashTable<WA>::ShowTable()
{
	cout<<"Index\tValue\n";
	for(int i = 0; i<size; i++)	//loop to change index i
	{	cout<<"  "<<i<<"\t";
		if(hashtable[i].key!=-1)	//if ith key slot is not empty then
		{	cout<<"  "<<hashtable[i].key<<endl;	}	//show its key
		else	//if ith key slot is empty then
		{	cout<<"  X\n";	}
	}
}
//===================================\\//===================================//