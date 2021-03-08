/**
 * SkipList https://en.wikipedia.org/wiki/Skip_list
 * also used by MemSQL
 * https://www.singlestore.com/blog/what-is-skiplist-why-skiplist-index-for-memsql/
 * SkipList with a depth of 1 is similar to a doubly-linked list
 * Each item has a p percent chance of being at the next level up
 * For our implementation p = 50%
 * All elements are inserted at the lowest Depth (1)
 * 50% of the elements inserted in Depth = 2
 * 50% of 50%, or 25% of the elements inserted in Depth = 3
 * and so on
 *
 * If a Skip List has only 1 level, such as p = 0%
 * Insert O(n), Search O(n)
 * For Depth > 1
 * Insert O(log n), Search O(log n)
 * Modifying p allows us to trade off search speed and storage cost
 *
 */

 //skiplist.h 
 //declaration of class and variables for .h
 //Louis Taing

#ifndef ASS4_SKIPLIST_H
#define ASS4_SKIPLIST_H

#include <iostream>
#include <vector>

using namespace std;

// only SkipList class can create SNode objects

class SkipList;

class SNode {
	friend class SkipList;
	//Purpose: output Skiplist
	//Preconditions: takes Skiplist object
	//Postconditions: outputs Skiplist with all levels to console window
	friend ostream& operator<<(ostream& out, const SkipList& skip);

private:
	//Purpose: constructor
	//Preconditions: none
	//Postconditions: outputs SNode object
	explicit SNode(int value);

	// data contained in the object
	int value{ 0 };

	// link to Next SNode 
	SNode* forward;

	// link to Prev SNode
	SNode* backward;

	//link to up node 
	SNode* up;

	// link to down SNode
	SNode* down;

};

class SkipList {
	//Purpose: output Skiplist
	//Preconditions: takes Skiplist object
	//Postconditions: outputs Skiplist with all levels to console window
	friend ostream& operator<<(ostream& out, const SkipList& skip);

private:
	// maximum number of levels
	int maxLevel;

	// probability of inserting at a higher level
	// as an integer between 0% and 100% (exclusive)
	int probability;


	//Purpose: given a SNode, place it before the given nextNode
	//Preconditions: takes in two SNodes* a new and next node
	//Postconditions: none
	void addBefore(SNode* newNode, SNode* nextNode);

	
	//Purpose: flip coin to see if should insert node at higher level
	//Preconditions: none
	//Postconditions: return true p% of time for p = 50, each node has a 50% 
	//chance of being at higher level
	bool shouldInsertAtHigher() const;

	// array of Depth SNode* objects as FrontGuards linking levels
	SNode** FrontGuards;

	// array of Depth SNode* objects as RearGuards linking levels
	SNode** RearGuards;

public:
	
	//Purpose: constructor: default SkipList has only 1 level, just one doubly-linked list
	//Preconditions: takes in integers for max level and probability
	//Postconditions: outputs built timespan object
	explicit SkipList(int maxLevel = 1, int probability = 0);

	
	//Purpose: destructor
	//Preconditions: takes in a skiplist object
	//Postconditions: deletes built skiplist object freeing memory
	virtual ~SkipList();

	// copy not allowed
	SkipList(const SkipList& other) = delete;

	// move not allowed
	SkipList(SkipList&& other) = delete;

	// assignment not allowed
	SkipList& operator=(const SkipList& other) = delete;

	// move assignment not allowed
	SkipList& operator=(SkipList&& other) = delete;

	//Purpose: add nodes to Skiplist
	//Preconditions: takes in a integer value, a Skiplist exists
	//Postconditions: return true if successfully added, no duplicates allowed
	bool add(int value);

	//Purpose: filling the Skiplist with added nodes
	//Preconditions: takes in vector integer value, a SKiplist exists
	//Postconditions: return true if successfully added, no duplicates allowed
	bool add(const vector<int>& values);

	//Purpose: sorts nodes in Skiplist
	//Preconditions: takes in a SNode, a SKiplist exists
	//Postconditions: return true if successfully added, no duplicates allowed
	void sort(SNode* node);

	//Purpose: removes nodes from Skiplist
	//Preconditions: takes in a SNode, a Skiplist exists
	//Postconditions: return true if successfully removed
	// return true if successfully removed
	bool remove(int value);

	//Purpose: see if nodes contained in Skiplist
	//Preconditions: takes in a integer data, a SKiplist exists
	//Postconditions: return true if found in SkipList
	bool contains(int value) const;

	//getter returns maxlevel
	int getMaxLevel() const;

};

#endif // ASS4_SKIPLIST_H
