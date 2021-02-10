//Main.cpp
//test the maze from maze.h/.cpp using recursion functions implemented in creature.h/.cpp and 
//Louis Taing

#include <iostream>
#include "creature.h"
#include "maze.h"
//Purpose: testing maze
//Preconditions: takes Maze object
//Postconditions: outputs if maze is printed
void test() {
    Maze M("maze.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}
//Purpose: testing maze2
//Preconditions: takes Maze object
//Postconditions: outputs if maze is printed
void test2() {
    Maze M("mazetest2.txt");
    // cout << m << endl;
    Creature C2(1, 1);
    cout << "Path: " << C2.solve(M) << endl;
    cout << M << endl;
}
//Purpose: testing maze3 should not print any path (no exit)
//Preconditions: takes Maze object
//Postconditions: outputs if maze is printed
void test3() {
    
    Maze M("mazetestblock.txt");
    // cout << m << endl;
    Creature C3(1, 1);
    cout << "Path: " << C3.solve(M) << endl;
    cout << M << endl;
}
//Purpose: testing maze3 should not print any path (no exit)
//Preconditions: takes Maze object
//Postconditions: outputs if maze is printed
void test4() {
    //should not print any path (no exit)
    Maze M("mazetest3.txt");
    // cout << m << endl;
    Creature C4(1, 18);
    cout << "Path: " << C4.solve(M) << endl;
    cout << M << endl;
}
int main() {
    test();
    test2();
    test3();
    test4();
    cout << "Done!" << std::endl;
    return 0;
}