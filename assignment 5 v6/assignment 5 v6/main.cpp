#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    cout << "input number of nodes for binary search tree. " << endl;

    int userInput;
    cin >> userInput;

    cout << "create tree with: " << userInput << " nodes\n";
    BST bst1(userInput);

    for (int i = 1; i <= userInput; i++)
    {
        bst1.insert(i);
    }
    cout << "this bst1\n";
    cout << bst1 << endl;

    cout << "coping bst1 to bst2\n";
    BST bst2 = bst1;

    cout << "this is bst2\n";
    cout << bst2 << endl;

    cout << "This is bst1 now\n";
    cout << bst1 << endl;
}
