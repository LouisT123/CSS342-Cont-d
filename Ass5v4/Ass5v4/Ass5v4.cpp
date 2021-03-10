// Ass5v4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bst.h"

int main()
{
    Bst tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);
    tree.insert(0);
    tree.insert(6);
    tree.display();

    std::cout << "removing 4" << endl;
    tree.remove(4);
    tree.display();
}


