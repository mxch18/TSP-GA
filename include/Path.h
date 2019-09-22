#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include "Point.h"
#include <iostream>
#include <stdlib.h>

#define GRID_WIDTH 640
#define GRID_LENGTH 480

class Path{

private:
    int n; // number of cities in the path
    Point *pointArray; // the array of the cities' locations

public:
    Path(int nn = 0); // Constructor with size parameter
    Path(Path const&); // Copy constructor

    ~Path(); // Destructor

    void setSize(int nn); // set the size of the Path
    Path& operator = (Path const&); // assignment operator
    Point& operator [] (int);

    void fillPath(); // fill the path with a random set of Points - used only once to create the first path
    void shuffle(); // randomly shuffle the path - will be used to create the path "universe"
    void ranSwap();
    void print(); // print the array of points associated to the path (just for test)
    int length(); // gives the length of the path - this is the fitness function
    int getN();
    Point getPointFromArray(int);
    bool pointInPath(Point);

};

Path* copyPathArray(Path*, int, int);

#endif // PATH_H_INCLUDED
