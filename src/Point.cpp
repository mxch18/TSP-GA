#include "Point.h"

using namespace std;

Point::Point(int a, int b){

    x = a;
    y = b;

}

Point::Point(Point &p){

    x = p.x;
    y = p.y;

}

Point::~Point(){
    /* nothing because no dynamic memory allocation in this class */
}

bool Point::operator == (Point& pt){

    return (x == pt.x) && (y == pt.y);

}

int Point::getX(){

    return x;

}

int Point::getY(){

    return y;

}

int Point::distance(Point const&a) const{

    return ceil(sqrt(pow(x - a.x, 2) + pow(y - a.y, 2)) - 0.5);

}

void Point::setX(int a){

    x = a;

}

void Point::setY(int a){

    y = a;

}

void Point::setXY(int a, int b){

    setX(a);
    setY(b);

}

void Point::print(){

    cout << "x = " << x << " ; y = " << y << endl;

}

int indexOfMinVal(int* tab, int len){

    int m = tab[0];
    int ind = 0;

    for(int i = 0; i < len; i++)
    {
        if(tab[i] < m)
        {
            m = tab[i];
            ind = i;
        }
    }

    return ind;

}
