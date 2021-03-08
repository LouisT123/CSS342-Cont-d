//skiplist.cpp
//impelementations of functions declared in skiplist.h
//Louis Taing

#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "skiplist.h"

using namespace std;

//Purpose: output Skiplist
//Preconditions: takes Skiplist object
//Postconditions: outputs Skiplist with all levels to console window
ostream& operator<<(ostream& out, const SkipList& skip) {
    for (int d = skip.maxLevel - 1; d >= 0; d--) {
        out << d << ": ";
        SNode* curr = skip.FrontGuards[d];


        while (curr != nullptr) {
            out << "--> " << (curr->value);
            curr = curr->forward;
        }
        out << endl;
    }
    return out;
}


//Purpose: constructor
//Preconditions: none
//Postconditions: outputs SNode object
SNode::SNode(int value) : value{ value }, forward{ nullptr }, 
                          backward{ nullptr }, up{ nullptr }, down{ nullptr } {}

//Purpose: given a SNode, place it before the given nextNode
//Preconditions: takes in two SNodes* a new and next node
//Postconditions: none
void SkipList::addBefore(SNode* NewNode, SNode* NextNode) {
    // Link next to node in front
    NewNode->forward = NextNode;
    // Link prev to node behind
    NewNode->backward = NextNode->backward;
    // Link node in back to new node
    NextNode->backward->forward = NewNode;
    // Link node in front to new node
    NextNode->backward = NewNode;
}

//Purpose: flip coin to see if should insert node at higher level
//Preconditions: none
//Postconditions: return true p% of time for p = 50, each node has a 50% 
// chance of being at higher level
bool SkipList::shouldInsertAtHigher() const {
    //return rand() % 100 < probability;
    return rand() % 2 == 1;
}

// array of Depth SNode* objects as FrontGuards linking levels
SNode** FrontGuards;

// array of Depth SNode* objects as RearGuards linking levels
SNode** RearGuards;

//Purpose: constructor: default SkipList has only 1 level, just one doubly-linked list
//Preconditions: takes in integers for max level and probability
//Postconditions: outputs built timespan object
SkipList::SkipList(int maxLevel, int probability)
    : maxLevel{ maxLevel }, probability{ probability } {
    assert(maxLevel > 0 && probability >= 0 && probability < 100);

    this->maxLevel = maxLevel;

    //sets up nodes
    FrontGuards = new SNode *[maxLevel];
    RearGuards = new SNode *[maxLevel];
    auto Front = new SNode(INT_MIN);
    auto Back = new SNode(INT_MAX);

    //sets front and read to +/-inf?
    Front->forward = Back;
    Back->backward = Front;
    
    FrontGuards[0] = Front;
    RearGuards[0] = Back;

    for (int i = 1; i < maxLevel; i++)
    {
        Front = new SNode(INT_MIN);
        Back = new SNode(INT_MAX);

        Front->forward = Back;
        Back->backward = Front;
        FrontGuards[i] = Front;
        RearGuards[i] = Back;

        Front->down = FrontGuards[i - 1];
        FrontGuards[i - 1]->up = Front;

        Front->down = FrontGuards[i - 1];
        RearGuards[i - 1]->up = Back;

    }
}

//Purpose: destructor
//Preconditions: takes in a skiplist object
//Postconditions: deletes built skiplist object freeing memory
SkipList::~SkipList() {
    // need to delete individual nodes
    for (int i = 0; i < maxLevel; i++) {
        SNode* Current = FrontGuards[i];
        SNode* Temp;
        while (Current != nullptr) {
            Temp = Current->forward;
            delete Current;
            Current = Temp;
        }
        
    }
    
    delete[] FrontGuards;
    delete[] RearGuards;
}


//Purpose: add nodes to Skiplist
//Preconditions: takes in a integer value, a Skiplist exists
//Postconditions: return true if successfully added, no duplicates allowed 
bool SkipList::add(int value) {
    // Create a pointer to the beginning of the list
    SNode* Curr = FrontGuards[0]->forward;
    // Move forward until you find a duplicate or something greater
    while (Curr->value < value) {
        Curr = Curr->forward;
    }
    //no dupes
    if (Curr->value == value) {
        return false;
    }
    // Make a new node and insert it into the SkipList
    auto newNode = new SNode(value); 
    addBefore(newNode, Curr); //connect pointers
    //check 
    assert(newNode->forward == Curr && Curr->backward == newNode);
    assert(newNode->backward != nullptr && newNode->backward->value < newNode->value);
    // Check to see if you need to go up a level
    bool NextLevel = shouldInsertAtHigher();

    //higher level
    int CurrDepth = 1;
    
   
    while (NextLevel && (CurrDepth < maxLevel))
    {
        SNode* newNode = FrontGuards[CurrDepth]->forward;
        //Create another node to be inserted at the higher level, newUpper
        SNode* newUpper = new SNode(value);
        
        if (newUpper == nullptr) {
            return false;
        }
        
        newUpper->down = newNode;
        newNode->up = newUpper;
        
        addBefore(newUpper, newNode);
        sort(newUpper);
        newNode = newUpper;
        
        ++CurrDepth;
        NextLevel = shouldInsertAtHigher();
    }
    return true;
    
}

//Purpose: filling the Skiplist with added nodes
//Preconditions: takes in vector integer value, a SKiplist exists
//Postconditions: return true if successfully added, no duplicates allowed
bool SkipList::add(const vector<int>& values) {

    for (auto v = values.begin(); v != values.end(); v++)
    {
        //if vector contains value return false
        if (count(values.begin(), values.end(), values.size() - 1))
        {
            return false;
        }
        add(*v);
    }
    return true;
}

//Purpose: sorts nodes in Skiplist
//Preconditions: takes in a SNode, a SKiplist exists
//Postconditions: return true if successfully added, no duplicates allowed
void SkipList::sort(SNode* input)
{
    SNode* Curr;
    SNode* Next(NULL);
    Curr = input;
    while (Curr->forward != Next)
    {
        if (Curr->value > Curr->forward->value)
        {
            swap(Curr->value, Curr->forward->value);
        }
        Curr = Curr->forward;
    }
    Next = Curr;
}


//Purpose: removes nodes from Skiplist
//Preconditions: takes in a SNode, a Skiplist exists
//Postconditions: return true if successfully removed
// return true if successfully removed
bool SkipList::remove(int value) { 
    //if doesnt contain value, cannot remove
    if (contains(value) == false)
    {
        return false;
    }
    //for each level
    for (int i = 0; i < maxLevel; i++)
    {
        SNode* current = FrontGuards[i];
        //while next ptr is not null
        while (current != nullptr )
        {
            //value is same value as one called, readjust all nodes
            if (current->value == value)
            {
                current->backward->forward = current->forward;
                current->forward->backward = current->backward;
                delete current;
                break;
            }
            //continue forward
            current = current->forward;
        }
        
    }
    
    return true; 
}

//Purpose: see if nodes contained in Skiplist
//Preconditions: takes in a integer data, a SKiplist exists
//Postconditions: return true if found in SkipList
bool SkipList::contains(int value) const { 
    SNode* Temp{};
    for (int i = maxLevel; i-- > 0;) {
        Temp = FrontGuards[i];
        while (Temp != nullptr && Temp->value < value) {
            Temp = Temp->forward;
            if (Temp->value == value) {
                return true;
            }
        }
    }
    return false;
}

//getter returns maxlevel
int SkipList::getMaxLevel() const
{
    return maxLevel;
}




