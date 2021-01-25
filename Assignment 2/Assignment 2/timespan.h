//timespan.h 
//declaration of class and variables for .h
//Louis Taing

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
	//Purpose: output timespan format
	//Preconditions: takes timespan object 
	//Postconditions: outputs string in correct time format
	friend ostream& operator<<(ostream& out, const TimeSpan& ts);

public:
	//Purpose: constructor
	//Preconditions: takes in double variables
	//Postconditions: outputs built timespan object
	// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
	explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);

	//Purpose: add
	//Preconditions: takes timespan object 
	//Postconditions: outputs sum of two timespans
	TimeSpan operator+(const TimeSpan& ts) const;

	//Purpose: subtract
	//Preconditions: takes timespan object 
	//Postconditions: outputs difference of two timespans
	TimeSpan operator-(const TimeSpan& ts) const;

	//Purpose: check equality
	//Preconditions: takes timespan object 
	//Postconditions: outputs true or false depending on timespan is equal or not, respectively
	bool operator==(const TimeSpan& ts) const;

	//Purpose: check inequality
	//Preconditions: takes timespan object 
	//Postconditions: outputs true or false depending on timespan is notequal or not, respectively
	bool operator!=(const TimeSpan& ts) const;

	//Purpose: multiply timespan by an unsigned number
	//Preconditions: takes unsigned int number
	//Postconditions: outputs product of timespan and unsigned int number
	TimeSpan operator*(unsigned int number) const;

	//Purpose: operator+= add to current time
	//Preconditions: takes timespan object
	//Postconditions: outputs the sum of current timespan with assigned timespan
	TimeSpan& operator+=(const TimeSpan& ts);

	//Purpose: operator-= subtract from current time
	//Preconditions: takes timespan object
	//Postconditions: outputs the difference of current timespan with assigned timespan
	TimeSpan& operator-= (const TimeSpan& ts);

	//Purpose: operator< compare less than new time
	//Preconditions: takes timespan object
	//Postconditions: outputs true or false depending on timespan is less than or not, respectively
	bool operator< (const TimeSpan& ts) const;

	//Purpose: operator> compare less than new time
	//Preconditions: takes timespan object
	//Postconditions: outputs true or false depending on timespan is greater than or not, respectively
	bool operator> (const TimeSpan& ts) const;

	//Purpose: operator>= compare greater than current time
	//Preconditions: takes timespan object
	//Postconditions: outputs true or false depending on timespan is (greater than or equal to) or not, respectively
	bool operator>= (const TimeSpan& ts) const;

	//Purpose: operator<= compare less than current time
	//Preconditions: takes timespan object
	//Postconditions: outputs true or false depending on timespan is (less than or equal to) or not, respectively
	bool operator<= (const TimeSpan& ts) const;


	// hour component of timespan (getter)
	int getHour() const;

	// minute component of timespan (getter)
	int getMinute() const;

	// second component of timespan (getter)
	int getSecond() const;

	// true if timespan is 0 or larger (getter)
	//Purpose: check if timespan is positive
	//Preconditions: none 
	//Postconditions: outputs true or false depending on timespan is greater than 0 or not, respectively
	bool isPositive() const;


private:
	//variable holds time in seconds
	double time = 0;

};

#endif // ASS2_TIMESPAN_H
