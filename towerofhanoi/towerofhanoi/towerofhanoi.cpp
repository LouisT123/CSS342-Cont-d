#include <iostream>
#include <iomanip>

// Towers of Hanoi
// For the execution tree, label the three statements in the "else" as 1, 2, 3


using namespace std;

void moveDisks(int, char, char, char);

int main() {
    cout << "Move Disk #      From Peg     To Peg" << endl;
    moveDisks(3, 'A', 'C', 'B');
    return 0;
}

//-----------------------------------------------------------------------------
// moveDisks
// Moves n disks from fromPeg to toPeg using auxPeg as an auxiliary.

void moveDisks(int n, char fromPeg, char toPeg, char auxPeg) {

    if (n == 1) {                                           // stopping case
        cout << setw(6) << n
            << "            " << fromPeg
            << "            " << toPeg << endl;
    }
    else {                                                  // recursive step
        moveDisks(n - 1, fromPeg, auxPeg, toPeg);
        cout << setw(6) << n
            << "            " << fromPeg
            << "            " << toPeg << endl;
        moveDisks(n - 1, auxPeg, toPeg, fromPeg);
    }
}
