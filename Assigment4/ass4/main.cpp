#include <cassert>
#include <iostream>

#include "skiplist.h"

using namespace std;

void test1() {
	// setting seed for easy testing
	srand(10000);
	SkipList skp(5, 80); //lvl 5 80% prob
	cout << boolalpha;

	
	skp.add(3);
	skp.add(5);
	
	
	skp.add(vector<int>{1, 7, 9});
	// cannot add existing
	assert(!skp.add(vector<int>{1, 7}));
	cout << skp << endl;
	cout << "7 ? " << skp.contains(7) << endl;
	cout << "3 ? " << skp.contains(3) << endl;
	cout << "-100 ? " << skp.contains(-100) << endl;
	cout << "100 ? " << skp.contains(100) << endl;
	cout << "9 ? " << skp.contains(9) << endl;
	cout << "-9 ? " << skp.contains(-9) << endl << endl;
	bool result = skp.remove(5);
	assert(result);
	//cannot remove 5 again
	result = skp.remove(5);
	assert(!result);
	
	cout << skp << endl;
	
}


void test2()
{
	cout << endl << endl;
	srand(10000);
	SkipList skp(1, 50); //lvl 1 50% prob
	cout << boolalpha;

	//add
	skp.add(1);
	skp.add(2);
	skp.add(2);
	skp.add(vector<int>{4, 5, 3});
	//skips dupe 2
	skp.add(vector<int>{6, 17, 2, 42, 100});
	cout << skp << endl;


}

void test3()
{
	cout << "test 3" << endl;
	srand(10000);
	SkipList skp(12, 40); //lvl 12 40% prob
	cout << boolalpha;

	//add
	skp.add(1);
	skp.add(22);
	//cannot add again
	skp.add(1);

	skp.add(vector<int>{4, 5, 3});
	skp.add(vector<int>{12, 4, 16});

	bool result = skp.remove(4);
	assert(result);
	//cannot remove 4 again
	result = skp.remove(4);
	assert(!result);

	cout << "22 ? " << skp.contains(22) << endl;
	cout << "4 ? " << skp.contains(4) << endl;
	cout << "3 ? " << skp.contains(3) << endl;
	cout << skp << endl;

}



void test4()
{
	cout << "test 3" << endl;
	srand(10000);
	SkipList skp(21, 75); //lvl 21 75% prob
	cout << boolalpha;
	//add
	skp.add(11);
	skp.add(0);
	//cannot add again
	skp.add(0);

	skp.add(vector<int>{40, 52, 3});
	skp.add(vector<int>{1, 40, 52});

	bool result = skp.remove(1);
	assert(result);
	//cannot remove 1 again
	result = skp.remove(1);
	assert(!result);

	cout << "55 ? " << skp.contains(55) << endl;
	cout << "40 ? " << skp.contains(40) << endl;
	cout << "35 ? " << skp.contains(35) << endl;
	cout << skp << endl;
}

int main() {

	test1();
	test2();
	test3();
	test4();

	cout << "Done." << endl;
	return 0;
}