//BST.cpp
//implementations of funtions declared in bast.h
//Louis Taing and Dai Nguyen
#include "BST.h"

//Purpose: Print out tree
//Preconditions: takes BST object and ostream out
//Postconditions: outputs string created in display function
ostream &operator<<(ostream &out, BST &bst)
{
    out << bst.display();
    return out;
}

//Purpose: constructor for node
//Preconditions: nothing
//Postconditions: outputs BNode object
BNode::BNode()
{
    value = MAX;
    left = nullptr;
    right = nullptr;
    leftthread = false;
    rightthread = false;
}

//Purpose: constructor for node
//Preconditions: takes in integer input
//Postconditions: outputs BNode object
BNode::BNode(int input)
{
    value = input;
    left = nullptr;
    right = nullptr;
    leftthread = false;
    rightthread = false;
}

//Purpose: equal operator for BNode
//Preconditions: takes in integer input
//Postconditions: outputs BNode object
BNode &BNode::operator=(const BNode &input)
{
    value = input.value;
    leftthread = input.leftthread;
    rightthread = input.rightthread;

    BNode *temp = nullptr;
    if (input.left)
    {
        temp = new BNode(*input.left);
        delete left;
        left = temp;
    }
    if (input.right)
    {
        temp = new BNode(*input.right);
        delete right;
        right = temp;
    }
    return *this;
}

//Purpose: destructor
//Preconditions: takes in a BNode object
//Postconditions: deletes built BNode object freeing memory
BNode::~BNode() {}


//Purpose: constructor for BST
//Preconditions: take in a BST input
//Postconditions: make a BST object
BST::BST()
{

    root = new BNode();
    highVal = NULL;
    root->right = root;
    root->left = root;
    root->leftthread = true;
    root->value = MAX;
}
//Purpose: destructor
//Preconditions: takes in a BST object
//Postconditions: deletes built BST object freeing memory
BST::~BST() {}


//Purpose: equal operator for BST
//Preconditions: take BST input
//Postconditions: return a BST object
BST &BST::operator=(const BST &input)
{
    BST bst1(input.highVal);
    bst1.removeEven();

    this->root = bst1.root;
    this->highVal = bst1.highVal;

    return *this;
}

//Purpose: constructor for BST
//Preconditions: takes in integer input
//Postconditions: create a BST object
BST::BST(int input)

{
    root = new BNode(MAX);
    root->right = root;
    root->left = root;
    root->leftthread = true;
    highVal = input;

    for (int i = 1; i <= input; i++)
    {
        insert(i);
        
    }

    
}

//Purpose: inserts node into BST
//Preconditions: takes in integer input
//Postconditions: inserts it into BST
void BST::insert(int input)
{
    BNode *curr = root;
    while (true)
    {
        if (curr->value < input)
        {
            if (curr->rightthread)
            {
                break;
            }
            curr = curr->right;
        }
        else if (curr->value > input)
        {
            if (curr->leftthread)
            {
                break;
            }
            curr = curr->left;
        }
        else
        {
            return;
        }
    }
    auto tempNode = new BNode(input);
    //tempNode->value = input;
    tempNode->rightthread = true;
    tempNode->leftthread = true;
    
    if (curr->value < input)
    {
        tempNode->right = curr->right;
        tempNode->left = curr;
        curr->right = tempNode;
        curr->rightthread = false;
   
    }
    else
    {
        tempNode->left = curr->left;
        tempNode->right = curr;
        curr->left = tempNode;
        curr->leftthread = false;
       
    }



}

//Purpose: format values of BST into a string
//Preconditions: none
//Postconditions: outputs BST as a string to be sent to ostream
string BST::display()
{
    string ret;
    BNode *ptr = root;
    BNode *parent = nullptr;
    while (true)
    {
        parent = ptr;
        ptr = ptr->right;
        if (!parent->rightthread)
        {
            while (!ptr->leftthread)
            {
                ptr = ptr->left;
            }
        }
        if (ptr == root)
        {
            break;
        }
        ret += to_string(ptr->value);
        ret += " ";
    }
    return ret;
}

//Purpose: removes even nodes from BST
//Preconditions: n/a
//Postconditions: removes even node from Bst
void BST::removeEven()
{
    BNode *ptr = root;
    BNode *parent = nullptr;
    while (true)
    {
        parent = ptr;
        ptr = ptr->right;
        if (!parent->rightthread)
        {
            while (!ptr->leftthread)
            {
                ptr = ptr->left;
            }
        }
        if (ptr == root)
        {
            break;
        }
        if (((ptr->value) % 2) == 0)
        {
            remove(ptr->value);
        }
    }
}


//Purpose: removes nodes from BST
//Preconditions: takes in an integer value
//Postconditions: removes node from Bst
void BST::remove(int value)
{
    BNode *tempNode1 = root->left;
    BNode *parent = root;
    while (true)
    {
        if (tempNode1->value < value)
        {
            if (tempNode1->rightthread)
            {
                return;
            }
            parent = tempNode1;
            tempNode1 = tempNode1->right;
        }
        else if (tempNode1->value > value)
        {
            if (tempNode1->leftthread)
            {
                return;
            }
            parent = tempNode1;
            tempNode1 = tempNode1->left;
        }
        else
        {
            break;
        }

    }

    BNode *tempNode2 = tempNode1;

    if (!tempNode1->rightthread && !tempNode1->leftthread)
    {
        parent = tempNode1;
        tempNode2 = tempNode1->left;
        while (!tempNode2->rightthread)
        {
            parent = tempNode2;
            tempNode2 = tempNode2->right;
        }
        tempNode1->value = tempNode2->value;
    }

    if (parent->value >= tempNode2->value)
    {
        if (tempNode2->rightthread && tempNode2->leftthread)
        {
            parent->left = tempNode2->left;
            parent->leftthread = true;
        }
        else if (tempNode2->rightthread)
        {
            BNode *max = tempNode2->left;
            while (!max->rightthread)
            {
                max = max->right;
            }
            max->right = parent;
            parent->left = tempNode2->left;

        }
        else
        {
            BNode *min = tempNode2->right;
            while (!min->leftthread)
            {
                min = min->left;
            }
            min->left = tempNode2->left;
            parent->left = tempNode2->right;
        }
    }

    else
    {
        if (tempNode2->rightthread && tempNode2->leftthread)
        {
            parent->right = tempNode2->right;
            parent->rightthread = true;
        }
        else if (tempNode2->rightthread)
        {
            BNode *max = tempNode1->left;
            while (!max->rightthread)
            {
                max = max->right;
            }
            max->right = tempNode2->right;
            parent->right = tempNode1->left;

        }
        else
        {
            BNode *min = tempNode2->right;
            while (!min->leftthread)
            {
                min = min->left;
            }
            min->left = parent;
            parent->right = tempNode2->right;
        }
    }
}


















