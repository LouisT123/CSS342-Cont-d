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
    //    BNode(const BNode &input);
    BNode();
    BNode(int input);
    BNode& operator=(const BNode& input);
    ~BNode();
};

class BST
{
    //Purpose: Print out tree
    //Preconditions: takes BST object
    //Postconditions: outputs string created in display function
    friend ostream& operator<<(ostream& out, BST& bst);

public:

    BST();



    //Purpose: constructor for node
    //Preconditions: takes in integer input
    //Postconditions: outputs BNode object
    BST(int input);

    //Purpose: copy constructor for BST
    //Preconditions: takes in integer input
    //Postconditions: outputs BNode object
    BST(const BST& input);

    //Purpose: inserts node into BST
    //Preconditions: takes in integer input
    //Postconditions: inserts it into BST
    void insert(int input);

    //Purpose: format values of BST into a string
    //Preconditions: none
    //Postconditions: outputs BST as a string to be sent to ostream
    string display();

    //Purpose: removes nodes from BST
    //Preconditions: takes in an integer value
    //Postconditions: removes node from Bst
    void remove(int value);

    //Purpose: removes even numbers
    //Preconditions: none
    //Postconditions: outputs BST as an even number string
    void removeEven();

    ~BST();



private:
    BNode* root;
};


