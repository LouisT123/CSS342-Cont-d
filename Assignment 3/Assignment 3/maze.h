//maze.h
//declaration of class and variables for maze.cpp
//Louis Taing

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
	//Purpose: prints maze
	//Preconditions: takes in Maze
	//Postconditions: outputs "Maze" in string form
	friend ostream& operator<<(ostream& Out, const Maze& Maze);
private:
	const static int MAX_SIZE = 100;
	char Field[MAX_SIZE][MAX_SIZE];
	int Width, Height;
	int ExitRow, ExitColumn;
public:
	//Purpose: opens maze txt file
	//Preconditions: takes in FileName
	//Postconditions: creates maze
	explicit Maze(const string& FileName);
	//the exit's row (getter)
	int getExitRow() const;
	//the exit's column (getter)
	int getExitColumn() const;
	//Purpose: if next spot is clear
	//Preconditions: takes in row and column
	//Postconditions: returns true or false depending if the next spot 
	//is clear or not respectively
	bool isClear(int Row, int Col) const;
	//Purpose: marks the solution path in maze
	//Preconditions: takes in row and column
	//Postconditions: outputs asterisk to mark maze
	void markAsPath(int Row, int Col);
	//Purpose: marks the path in maze that was visited but not solution path
	//Preconditions: takes in row and column
	//Postconditions: outputs a plus to mark maze
	void markAsVisited(int Row, int Col);
	
};

#endif //ASS3_MAZE_H
