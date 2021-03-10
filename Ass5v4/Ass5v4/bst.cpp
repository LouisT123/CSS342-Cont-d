#include "bst.h"
#include <iostream>

using namespace std;
const int MAX_VAL = INT_MAX;

Bst::Bst()
{
	root = new Node();
	root->right = root;
	root->left = root;										//modded 
	root->leftthread = true;
	//slight mod here 
	root->value = MAX_VAL;
}

void Bst::insert(int value)
{
	Node* parent = root;
	while (true)											//mod 1- works good
	{
		if (parent->value < value)
		{
			if (parent->rightthread)
			{
				break;
			}
			parent = parent->right;
		}
		else if (parent->value > value)
		{
			if (parent->leftthread)
			{
				break;
			}
			parent = parent->left;
		}
		else
		{
			return;
		}
	}
	Node* tempNode = new Node();
	tempNode->value = value;
	tempNode->rightthread = true;
	tempNode->leftthread = true;						//modded
	
	//if parent less than new value
	if (parent->value < value)
	{
		tempNode->right = parent->right;
		tempNode->left = parent;
		parent->right = tempNode;
		parent->rightthread = false;
	}
	//if parent is greater than                        //formmerly modified here
	if (parent->value > value)
	
	{
		tempNode->right = parent;
		tempNode->left = parent->left;
		parent->left = tempNode;
		parent->leftthread = false;
	}

}



void Bst::display()
{
	Node* ptr = root;
	Node* parent = NULL;									//personal mod
	while(true)												//mod 2 - works good
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
		cout << ptr->value << " ";
	}
	cout << endl;
}

void Bst::remove(int value)
{
	Node* tempNode1 = root->left;
	Node* parent = root;
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



	Node* tempNode2 = tempNode1;
	//if has two children
	if (!tempNode1->rightthread && !tempNode1->leftthread)
	{
		parent = tempNode1;
		tempNode2 = tempNode1->left;
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
		//if only left child --------------------------------------can be helper function 
		if (tempNode1->rightthread && tempNode1->leftthread)
		{
			parent->left = tempNode1->left;
			parent->leftthread = true;
		}
		else if (tempNode1->rightthread)
		{
			Node* max = tempNode1->left;
			while (!max->rightthread)
			{
				max = max->right;
			}
			max->right = parent;
			parent->left = tempNode1->left;

		}
		else
		{
			Node* min = tempNode1->right;
			while (!min->leftthread)
			{
				min = min->left;
			}
			min->left = tempNode1->left;
			parent->left = tempNode1->right;			// this line is different
		}
	}

	else
	{
		//if only right child ---------------------------------------can be helper function b/c same code as above
		if (tempNode1->rightthread && tempNode1->leftthread)
		{
			parent->left = tempNode1->left;
			parent->leftthread = true;
		}
		else if (tempNode1->rightthread)
		{
			Node* max = tempNode1->left;
			while (!max->rightthread)
			{
				max = max->right;
			}
			max->right = parent;
			parent->left = tempNode1->left;

		}
		else
		{
			Node* min = tempNode1->right;
			while (!min->leftthread)
			{
				min = min->left;
			}
			min->left = tempNode1->left;
			parent->right = tempNode1->right;					//this line is different
		}

	}
}







