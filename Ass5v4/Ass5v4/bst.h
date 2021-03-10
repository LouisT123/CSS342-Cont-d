#include <iostream>
#include <cstdlib>

using namespace std;
class Node
{
public:
	int value;
	Node* left;
	Node* right;
	bool leftthread;
	bool rightthread;
};

class Bst
{
public:
	Bst();
	void insert(int value);
	void display();
	void remove(int value);

private:
	Node* root;
};


