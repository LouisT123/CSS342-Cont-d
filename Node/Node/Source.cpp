#include <iostream>
#include "Node.cpp"
#include <cstdlib>

using namespace std;


int main() {
	std::cout << rand() % 2;
	Node<int> N0;
	Node<int> N10(10);
	N0.setNext(&N10);
	Node<int>* NTemp = N0.getNext();
	std::cout << NTemp->getItem() << std::endl;

	Node<std::string> NS1("a");

	Node<int>* n = new Node<int>;
	//delete N0;
	 // //Does this mean I can mix and match?
	   // N10.setNext(&NS1);

	std::cout << "Hello World!\n";
}