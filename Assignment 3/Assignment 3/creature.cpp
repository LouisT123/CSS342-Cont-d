//creature.cpp
//impelementations of functions declared in timespan.h
//Louis Taing

#include "creature.h"
//Purpose: output creature coordinates
//Preconditions: takes timespan object 
//Postconditions: outputs string in correct time format
std::ostream& operator<<(std::ostream& Out, const Creature& Creature) {        
	Out << "C(" << Creature.Row << ", " << Creature.Col << ")";
	return Out;
}
//Purpose: constructor
//Preconditions: takes in Row and Col
//Postconditions: outputs Creature object
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {
	initialPath = "";
}
//Purpose: check to see if creature is at exit
//Preconditions: takes in Maze
//Postconditions: outputs true or false depending on if at exit or not respectively
bool Creature::atExit(const Maze& Maze) const {
	return (Row == Maze.getExitRow() && (Col == Maze.getExitColumn()));
}

//Purpose: creature "movement" through maze at runtime as well as printing solution path
//Preconditions: takes in Maze
//Postconditions: outputs solution path 
string Creature::solve(Maze& Maze) {
    string Path;
    Maze.markAsPath(Row, Col);
    if (!atExit(Maze)) {
        Path = goNorth(Maze);
    }
    if (!atExit(Maze)) {
        Path = goWest(Maze);
    }
    if (!atExit(Maze)) {
        Path = goEast(Maze);
    }
    if (!atExit(Maze)) {
        Path = goSouth(Maze);
    }
return Path;
}

//Purpose: recursive function, creature goes north
//Preconditions: takes in Maze
//Postconditions: outputs path visited and path of solution
string Creature::goNorth(Maze& Maze) {

    string Output;
    if (Maze.isClear(Row - 1, Col)) {
        Row = Row - 1;
        Maze.markAsPath(Row, Col);
        if (atExit(Maze)) {
            Output = "N";
        }
        else {
            Output = "N" + goNorth(Maze) ; 
            if (!atExit(Maze)) {
                Output = "N" + goWest(Maze);
                if (!atExit(Maze)) {
                    Output = "N" + goEast(Maze);
                    if (!atExit(Maze)) {
                        Maze.markAsVisited(Row, Col);
                        Row=Row + 1;
                     
                    }
                }
            }
        }
    }
    return Output;
}
//Purpose: recursive function, creature goes south
//Preconditions: takes in Maze
//Postconditions: outputs path visited and path of solution
string Creature::goSouth(Maze& Maze) {

    string output;
    if (Maze.isClear(Row + 1, Col)) {
        Row=Row + 1;
        Maze.markAsPath(Row, Col);
        if (atExit(Maze)) {
            output = "S";
        }
        else {
            output = "S" + goWest(Maze);
            if (!atExit(Maze)) {
                output = "S" + goEast(Maze);
                if (!atExit(Maze)) {
                    output = "S" + goSouth(Maze);
                    if (!atExit(Maze)) {
                        Maze.markAsVisited(Row, Col);
                        Row=Row - 1;
                    }
                }
            }
        }
    }
    return output;
}
//Purpose: recursive function, creature goes east
//Preconditions: takes in Maze
//Postconditions: outputs path visited and path of solution
string Creature::goEast(Maze& Maze) {

    string output;
    if (Maze.isClear(Row, Col + 1)) {
        Col = Col + 1;
        Maze.markAsPath(Row, Col);
        if (atExit(Maze)) {
            output = "E";
        }
        else {
            output = "E" + goNorth(Maze);
            if (!atExit(Maze)) {
                output = "E" + goEast(Maze);
                if (!atExit(Maze)) {
                    output = "E" + goSouth(Maze);
                    if (!atExit(Maze)) {
                        Maze.markAsVisited(Row, Col);
                        Col=Col - 1;
                    }
                }
            }
        }
    }
    return output;

}
//Purpose: recursive function, creature goes west
//Preconditions: takes in Maze
//Postconditions: outputs path visited and path of solution
string Creature::goWest(Maze& Maze) {

    string output;
    if (Maze.isClear(Row, Col-1)) {
        Col = Col - 1;
        Maze.markAsPath(Row, Col);
        if (atExit(Maze)) {
            output = "W";
        }
        else {
            output = "W" + goNorth(Maze); 
            if (!atExit(Maze)) {
                output = "W" + goWest(Maze);
                if (!atExit(Maze)) {
                    output = "W" + goSouth(Maze);
                    if (!atExit(Maze)) {
                        Maze.markAsVisited(Row, Col);
                        Col=Col + 1;
                    }
                }
            }
        }
    }
    return output;
}

