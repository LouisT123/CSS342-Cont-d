//timespan.cpp
//impelementations of functions declared in timespan.h
//Louis Taing
#include "timespan.h"

#include <cassert>
#include <cmath>
#include <sstream>

//Purpose: output timespan format
//Preconditions: takes timespan object 
//Postconditions: outputs string in correct time format
ostream& operator<<(ostream& out, const TimeSpan& ts)
{
	//if not positive add - to hour
	if (!ts.isPositive())
	{
		out << "-";
	}
	out << abs(ts.getHour()) << ":";
	//if minute not double digit add digit
	if (abs(ts.getMinute()) < 10)
	{
		out << "0";
	}
	out << abs(ts.getMinute()) << ":";
	//if second not double digit add digit
	if (abs(ts.getSecond()) < 10)
	{
		out << "0";
	}
	out << abs(ts.getSecond());
	return out;
}


//Purpose: constructor
//Preconditions: takes in double variables
//Postconditions: outputs built timespan object
// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
TimeSpan::TimeSpan(double hour, double minute, double second) {
	//time in seconds
	time = (double)((hour * 3600) + (minute * 60) + second);
	
}

// hour component (getter)
int TimeSpan::getHour() const {
	double tempHour = 0;
	tempHour = (time/3600);
	return (int)tempHour;
}

// minute component (getter)
int TimeSpan::getMinute() const { 
	double tempMinute = 0;
	tempMinute = (fmod(time, 3600) / 60);
	return (int)tempMinute;
}

// second component (getter)
int TimeSpan::getSecond() const {
	double tempSecond = 0;
	tempSecond = (int)(fmod(time, 60));
	return tempSecond;
}

//Purpose: check if timespan is 0 or larger (getter)
//Preconditions: none 
//Postconditions: outputs true or false depending on timespan is greater than 0 or not, respectively
bool TimeSpan::isPositive() const { 
	if (time >= 0)
	{
		return true;
	}
	return false;
;}


//Purpose: add
//Preconditions: takes timespan object 
//Postconditions: outputs sum of two timespans
TimeSpan TimeSpan::operator+(const TimeSpan& ts) const {
	TimeSpan tsSum;
	tsSum.time = this->time + ts.time;
	return tsSum;
}

//Purpose: subtract
//Preconditions: takes timespan object 
//Postconditions: outputs difference of two timespans
TimeSpan TimeSpan::operator-(const TimeSpan& ts) const {
	TimeSpan tsSub;
	tsSub.time = this->time - ts.time;
	return tsSub;
}

//Purpose: multiply timespan by an unsigned number
//Preconditions: takes unsigned int number
//Postconditions: outputs product of timespan and unsigned int number
TimeSpan TimeSpan::operator*(unsigned int number) const {
	TimeSpan tsLarge;
	tsLarge.time = this->time * number;
	return tsLarge;
}

//Purpose: operator+= add to current time
//Preconditions: takes timespan object
//Postconditions: outputs the sum of current timespan with assigned timespan
TimeSpan& TimeSpan::operator+=(const TimeSpan& ts) 
{
	this->time = time + ts.time;
	return *this;
}

//Purpose: operator-= subtract from current time
//Preconditions: takes timespan object
//Postconditions: outputs the difference of current timespan with assigned timespan
TimeSpan& TimeSpan::operator-=(const TimeSpan& ts)
{
	this->time = time - ts.time;
	return *this;
}

//Purpose: operator< compare less than new time
//Preconditions: takes timespan object
//Postconditions: outputs true or false depending on timespan is less than or not, respectively
bool TimeSpan::operator<(const TimeSpan& ts) const
{
	if (this->time < ts.time)
	{
		return true;
	}
	return false;
}

//Purpose: operator> compare less than new time
//Preconditions: takes timespan object
//Postconditions: outputs true or false depending on timespan is greater than or not, respectively
bool TimeSpan::operator>(const TimeSpan& ts) const
{
	if (this->time > ts.time)
	{
		return true;
	}
	return false;
}

//Purpose: operator>= compare greater than current time
//Preconditions: takes timespan object
//Postconditions: outputs true or false depending on timespan is (greater than or equal to) or not, respectively
bool TimeSpan::operator>=(const TimeSpan& ts) const
{
	if (this->time >= ts.time)
	{
		return true;
	}
	return false;
}

//Purpose: operator<= compare less than current time
//Preconditions: takes timespan object
//Postconditions: outputs true or false depending on timespan is (less than or equal to) or not, respectively
bool TimeSpan::operator<=(const TimeSpan& ts) const
{
	if (this->time <= ts.time)
	{
		return true;
	}
	return false;
}


//Purpose: check equality
//Preconditions: takes timespan object 
//Postconditions: outputs true or false depending on timespan is equal or not, respectively
bool TimeSpan::operator==(const TimeSpan& ts) const { 
	
	if (ts.time == this->time)
	{
		return true;
	}
	return false;
}

//Purpose: check inequality
//Preconditions: takes timespan object 
//Postconditions: outputs true or false depending on timespan is notequal or not, respectively
bool TimeSpan::operator!=(const TimeSpan& ts) const { 
	
	if (ts.time != this->time)
	{
		return true;
	}
	return false;
}
