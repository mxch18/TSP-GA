#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <math.h>

class Point{

private:
    int x; // the x position
    int y; // the y position

public:
    Point(int a = 0, int b = 0); // constructor with (optional) position parameters
    Point(Point&); // copy constructor

    ~Point(); /* destructor - EDIT: useless because no dynamic memory allocation with class Point. I leave it only to remember
                                    it is useless :^) */

    bool operator == (Point&);

    int getX(); // get the x position
    int getY(); // get the y position

    void setX(int); // set the X position
    void setY(int); // set the Y position
    void setXY(int, int); // set the X and Y positions

    int distance(Point const&) const; // the distance between two points

    void print();

};

int indexOfMinVal(int*, int);

#endif // POINT_H_INCLUDED
