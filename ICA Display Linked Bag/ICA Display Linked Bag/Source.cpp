template<class ItemType>
void LinkedBag<ItemType>::displayBag() const
{
	cout << "The bag contains " << itemCount << " items: " << endl;
	Node<ItemType>* currentPtr = headPtr;
	int counter = 0;
	while ((currentPtr != nullptr) && (counter < itemCount))
	{
		cout << currentPtr->getItem()) << " ";
		currentPtr = currentPtr->getNext();
		counter++;
	}
	cout << endl;
}