#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    cout << "input number of nodes for binary search tree. " << endl;

    int userInput;
    cin >> userInput;

    cout << "create tree with: " << userInput << " nodes\n";
    BST bst1(userInput);

    cout << "this bst1\n";
    cout << bst1 << endl;

    cout << "copying bst1 to bst2\n";
    BST bst2;
    bst2 = bst1;

    cout << "this is bst2\n";
    cout << bst2 << endl;

    cout << "this bst1 after bst2\n";
    cout << bst1 << endl;

    
}
