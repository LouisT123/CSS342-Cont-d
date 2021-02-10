// bigboi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    sumUpTo(6);
}
int sumUpTo(int n)
{
    cout << "n: " << n << endl;
    int sum = 0;
    if (n == 1) {
        cout << "base: " << n << endl;
        sum = 1;
    }
    else { // n > 1
        sum = n + sumUpTo(n - 1);
    }
    cout << "sum: " << sum << endl;
    return sum;
}
