//BST.cpp
//implementations of funtions declared in bast.h
//Louis Taing and Dai Nguyen
#include "BST.h"

//Purpose: Print out tree
//Preconditions: takes BST object
//Postconditions: outputs string created in display function
ostream& operator<<(ostream& out, BST& bst)
{
    out << bst.display();
    return out;
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

BNode& BNode::operator=(const BNode& input)
{
    value = input.value;
    leftthread = input.leftthread;
    rightthread = input.rightthread;

    BNode* temp = nullptr;
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

//BNode::BNode(const BNode &input) : value{input.value}, left{nullptr}, right{
//        nullptr}, leftthread{input.leftthread}, rightthread{rightthread}
//{
//    if (input.left)
//    {
//        left = new BNode(*input.left);  //overflow
//    }
//    if (input.right)
//    {
//        right = new BNode(*input.right);  //overflow
//    }
//}

BNode::BNode()
{
    value = MAX;
    left = nullptr;
    right = nullptr;
    leftthread = false;
    rightthread = false;
}

BNode::~BNode()
{
    delete left;
    delete right;
}


BST::BST()
{
    root = new BNode();
    root->right = root;
    root->left = root;
    root->leftthread = true;
    root->value = MAX;
}


//Purpose: constructor for BST
//Preconditions: takes in BNode object
//Postconditions: outputs BST object
BST::BST(int input) : root{ new BNode(MAX) }
{
    root->right = root;
    root->left = root;
    root->leftthread = true;

    for (int i = 1; i <= input; i++)
    {
        insert(i);
    }
}

//Purpose: copy constructor for BST
//Preconditions: takes in integer input
//Postconditions: outputs BNode object
BST::BST(const BST& input)
{
    //    BST *temp = new BST();
    //    BNode &tempNode = *input.root;
    //
    //    temp->root = &tempNode;
    //    this->root = temp->root;
    //    this->root->value = temp->root->value;
    //    this->root->value = input.root->value;

    auto temp = new BNode(*input.root);
    this->root = temp;

  

    //    this->root = new BNode(input.root->value);
    //    //Make new node
    //    auto *tempBNode = new BNode(*input.root);
    //    auto *tempLeft = new BNode(*input.root->left);
    //    auto *tempRight = new BNode(*input.root->right);
    //    node->value = input.root->value;
    //    node->rightthread = input.root->rightthread;
    //    node->leftthread = input.root->leftthread;
    //    node->right = input.root->right;
    //    node->left = input.root->left;

    //    if(input.root == nullptr)
    //    {
    //        return;
    //    }

        //copy object
    //    this->root = tempBNode;
    //    this->root->right = tempRight;
    //    this->root->left = tempLeft;

    //    BNode *temp = input.root;
    //    root = new BNode;
    //
    //    root->value = temp->value;
    //    root->left = temp->left;
    //    root->right = temp->right;
    //    root->leftthread = temp->leftthread;
    //    root->rightthread = temp->rightthread;

    //removeEven();
}

BST::~BST()
{

}

//Purpose: inserts node into BST
//Preconditions: takes in integer input
//Postconditions: inserts it into BST
void BST::insert(int input)
{
    BNode* curr = root;
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
    BNode* tempNode = new BNode(input);
    tempNode->rightthread = true;
    tempNode->leftthread = true;

    //if parent less than new value
    if (curr->value < input)
    {
        tempNode->right = curr->right;
        tempNode->left = curr;
        curr->right = tempNode;
        curr->rightthread = false;
    }
    //if parent is greater than
    //if (parent->value > value)
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
    BNode* ptr = root;
    BNode* parent = nullptr;
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
//Purpose: removes even numbers
//Preconditions: none
//Postconditions: outputs BST as an even number string
/*void BST::removeEven()
{
    BNode* ptr = root;
    BNode* parent = nullptr;
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
        // if that pointer is even
        if (((ptr->value) % 2) == 0)
        {
            remove(ptr->value);

        }
    }
}

*/


//Purpose: removes nodes from BST
//Preconditions: takes in an integer value
//Postconditions: removes node from Bst
void BST::remove(int value)
{

    BNode* tempNode1 = root->left;
    BNode* parent = root;
    while(tempNode1->value % 2 == 0)
    {
        while(true)
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

        BNode* tempNode2 = tempNode1;
        //if has two children
        if (!tempNode1->rightthread && !tempNode1->leftthread)
        {
            parent = tempNode1;
            tempNode2 = tempNode2->left;
            while (!tempNode2->rightthread)
            {
                parent = tempNode2;
                tempNode2 = tempNode2->right;
            }
            //node is replaced
            tempNode1->value = tempNode2->value;
        }

        if (parent->value >= tempNode1->value)
        {
            //if only left child
            if (tempNode1->rightthread && tempNode1->leftthread)
            {
                parent->left = tempNode1->left;
                parent->leftthread = true;
            }
            else if (tempNode1->rightthread)
            {
                BNode* max = tempNode1->left;
                while (!max->rightthread)
                {
                    max = max->right;
                }
                max->right = parent;
                parent->left = tempNode1->left;

            }
            else
            {
                BNode* min = tempNode1->right;
                while (!min->leftthread)
                {
                    min = min->left;
                }
                min->left = tempNode1->left;
                parent->left = tempNode1->right;
            }
        }

        else
        {
            //if only right child
            if (tempNode1->rightthread && tempNode1->leftthread)
            {
                parent->left = tempNode1->left;
                parent->leftthread = true;
            }
            else if (tempNode1->rightthread)
            {
                BNode* max = tempNode1->left;
                while (!max->rightthread)
                {
                    max = max->right;
                }
                max->right = parent;
                parent->left = tempNode1->left;

            }
            else
            {
                BNode* min = tempNode1->right;
                while (!min->leftthread)
                {
                    min = min->left;
                }
                min->left = tempNode1->left;
                parent->right = tempNode1->right;
            }

        }
    }
    
}











