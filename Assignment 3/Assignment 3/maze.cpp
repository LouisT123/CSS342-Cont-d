//maze.cpp
//impelementations of functions declared in maze.h
//Louis Taing
#include <fstream>
#include <iostream>
#include <string>
#include "maze.h"

using namespace std;

//Purpose: prints maze
//Preconditions: takes in Maze
//Postconditions: outputs "Maze" in string form
ostream& operator<<(ostream& Out, const Maze& Maze) {
    for (int Row = 0; Row < Maze.Height; ++Row) {
        for (int Col = 0; Col < Maze.Width; ++Col) {
            Out << Maze.Field[Row][Col];
        }
        Out << endl;
    }
    Out << endl;
    return Out;
}

//Purpose: opens maze txt file
//Preconditions: takes in FileName
//Postconditions: creates maze
Maze::Maze(const string& FileName) {
    ifstream InFile;
    InFile.open(FileName);
    if (!InFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    InFile >> Width >> Height;
    InFile >> ExitRow >> ExitColumn;
    string Str;
    getline(InFile, Str);
    for (int Row = 0; Row < Height; ++Row) {
        for (int Col = 0; Col < Width; ++Col) {
            InFile.get(Field[Row][Col]);
            // cout << Row << ", " << Col << ": " << field[Row][Col] << endl;
        }
        getline(InFile, Str);
    }

}
//the exit's row (getter)
int Maze::getExitRow() const {
    return ExitRow;
}
//the exit's column (getter)
int Maze::getExitColumn() const {
    return ExitColumn;
}
//Purpose: if next spot is clear
//Preconditions: takes in row and column
//Postconditions: returns true or false depending if the next spot 
//is clear or not respectively
bool Maze::isClear(int Row, int Col) const {
    return Field[Row][Col] == ' ';
}
//Purpose: marks the solution path in maze
//Preconditions: takes in row and column
//Postconditions: outputs asterisk to mark maze
void Maze::markAsPath(int Row, int Col) {
    Field[Row][Col] = '*';
}
//Purpose: marks the path in maze that was visited but not solution path
//Preconditions: takes in row and column
//Postconditions: outputs a plus to mark maze
void Maze::markAsVisited(int Row, int Col) {
    Field[Row][Col] = '+';
}
