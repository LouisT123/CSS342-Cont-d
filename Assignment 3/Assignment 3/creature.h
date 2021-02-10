//creature.h
//declaration of class and variables for creature.cpp
//Louis Taing

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
	//Purpose: output creature coordinates
	//Preconditions: takes timespan object 
	//Postconditions: outputs string in correct time format
	friend ostream& operator<<(ostream& Out, const Creature& Creature);
private:
	int Row = 0;
	int Col = 0;
	string initialPath = "";
public:
	//Purpose: constructor
	//Preconditions: takes in Row and Col
	//Postconditions: outputs Creature object
	Creature(int Row, int Col);
	//Purpose: check to see if creature is at exit
	//Preconditions: takes in Maze
	//Postconditions: outputs true or false depending on if at exit or not respectively
	bool atExit(const Maze& Maze) const;
	//Purpose: creature "movement" through maze at runtime as well as printing solution path
	//Preconditions: takes in Maze
	//Postconditions: outputs solution path 
	string solve(Maze& Maze);
	//Purpose: recursive function, creature goes north
	//Preconditions: takes in Maze
	//Postconditions: outputs path visited and path of solution
	string goNorth(Maze& Maze);
	//Purpose: recursive function, creature goes south
	//Preconditions: takes in Maze
	//Postconditions: outputs path visited and path of solution
	string goSouth(Maze& Maze);
	//Purpose: recursive function, creature goes east
	//Preconditions: takes in Maze
	//Postconditions: outputs path visited and path of solution
	string goEast(Maze& Maze);
	//Purpose: recursive function, creature goes west
	//Preconditions: takes in Maze
	//Postconditions: outputs path visited and path of solution
	string goWest(Maze& Maze);
};

#endif //ASS3_CREATURE_H
