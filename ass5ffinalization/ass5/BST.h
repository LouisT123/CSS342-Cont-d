//BST.h
//declaration of class and variables for .h
//Louis Taing and Dai Nguyen
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
const int MAX = INT_MAX;

using namespace std;
class BNode
{
    
public:
    int value;
    BNode* left;
    BNode* right;
    bool leftthread;
    bool rightthread;

    //Purpose: constructor for node
    //Preconditions: nothing
    //Postconditions: outputs BNode object
    BNode();

    //Purpose: constructor for node
    //Preconditions: takes in integer input
    //Postconditions: outputs BNode object
    BNode(int input);

    //Purpose: equal operator for BNode
    //Preconditions: takes in integer input
    //Postconditions: outputs BNode object
    BNode &operator=(const BNode &input);

    //Purpose: destructor
    //Preconditions: takes in a BNode object
    //Postconditions: deletes built BNode object freeing memory
    ~BNode();

   
};

class BST
{
    //Purpose: Print out tree
    //Preconditions: takes BST object and ostream out
    //Postconditions: outputs string created in display function
    friend ostream &operator<<(ostream &out, BST &bst);

public:

    //Purpose: constructor for BST
    //Preconditions: take in a BST input
    //Postconditions: make a BST object
    BST();

    //Purpose: destructor
    //Preconditions: takes in a BST object
    //Postconditions: deletes built BST object freeing memory
    ~BST();


    //Purpose: equal operator for BST
    //Preconditions: take BST input
    //Postconditions: return a BST object
    BST &operator=(const BST &input);

    //Purpose: constructor for BST
    //Preconditions: takes in integer input
    //Postconditions: create a BST object
    BST(int input);

    //Purpose: inserts node into BST
    //Preconditions: takes in integer input
    //Postconditions: inserts it into BST
    void insert(int input);

    //Purpose: format values of BST into a string
    //Preconditions: none
    //Postconditions: outputs BST as a string to be sent to ostream
    string display();

    //Purpose: removes even numbers
    //Preconditions: none
    //Postconditions: none
    void removeEven();

    //Purpose: removes nodes from BST
    //Preconditions: takes in an integer value
    //Postconditions: removes node from Bst
    void remove(int value);


private:
    BNode* root;
    int highVal;
};


