//Main.cpp
//test the operator overloading functions and constructor using timespan.h and timespan.cpp
//Louis taing
#include <cassert>
#include <iostream>
#include <sstream>

#include "timespan.h"

using namespace std;

//Purpose: testing constructor
//Preconditions: takes timespan object
//Postconditions: outputs test1 complete if all assert tests are passed
void test1() {
  TimeSpan ts(1, 20, 30);
  stringstream ss;
  ss << ts;
  assert(ss.str() == "1:20:30");

  TimeSpan ts2(4, -20, -90);
  ss.str("");
  ss << ts2;
  assert(ss.str() == "3:38:30");

  TimeSpan ts3(1.5, 30.5, -90);
  ss.str("");
  ss << ts3;
  assert(ss.str() == "1:59:00");

  TimeSpan ts4(0, 0.07, 0);
  ss.str("");
  ss << ts4;
  assert(ss.str() == "0:00:04");
  cout << "test1 complete" << endl;
}

//Purpose: testing equality, addition, subtraction, multiplication operator overload functions
//Preconditions: takes timespan object
//Postconditions: outputs test2 complete if all assert tests are passed
void test2() {
  TimeSpan ts(1, 20, 30);
  TimeSpan ts2(1, 20, 30);
  TimeSpan ts3(0, 0, 0);
  assert(ts == ts2);
  assert(!(ts != ts2));
  assert(ts != ts3);
  assert((ts + ts + ts) == (ts2 * 3));
  assert((ts * 5) == (ts2 * 4) + ts2);
  assert((ts * 5) == (ts2 * 6) - ts2);
  assert((ts + ts - ts) == ((ts2 * 2) - ts));
  assert((ts - ts2) == ts3);
  assert((ts3 * 5) == ts3);
  cout << "test2 complete" << endl;
}


//Purpose: testing ispostive and negative hour
//Preconditions: takes timespan object
//Postconditions: outputs test3 complete if all assert tests are passed
void test3() {
  TimeSpan ts0(0, 0, 0);
  TimeSpan ts1(0, 0, 10);
  TimeSpan ts2 = ts0 - ts1;
  assert(ts1.isPositive() && !ts2.isPositive());
  
  
 stringstream ss;
 ss << ts2;
 assert(ss.str() == "-0:00:10");  
 cout << "test3 complete" << endl;
}

//Purpose: test overloaded operators 
//Preconditions: takes timespan object
//Postconditions: outputs test4 complete if all assert tests are passed
void test4() {
	TimeSpan ts(0, 5, 0);
	TimeSpan ts1(0, 4, 0);
	TimeSpan ts2(0, 4, 0);
	assert(ts > ts1);
	assert(ts1 < ts);
	assert(ts2 <= ts1);
	assert(ts2 >= ts1);

	
	TimeSpan ts3(0, 5, 0);
	TimeSpan ts4(0, 4, 0);
	TimeSpan ts5(0, 9, 0);
	TimeSpan ts6(0, 5, 0);
	ts3 += ts4; //5+4
	assert(ts3 == ts5); //9
	ts5 -= ts4; //9-4
	assert(ts5 == ts6); //5
	cout << "test4 complete" << endl;
}
//Purpose: main function
//Preconditions: takes tests
//Postconditions: outputs done if all tests pasts
int main() {
  test1();
  test2();
  test3();
  test4();
  cout << "Done." << std::endl;
  return 0;
}