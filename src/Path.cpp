#include "Path.h"

using namespace std;

Path::Path(int nn)
{

    if(nn > 0){

        n = nn;
        pointArray = new Point[n];

    } else {

        n = 0;
        pointArray = NULL;

    }

}

void Path::setSize(int nn){

    if(n != nn){

        delete pointArray; /* in this line, we delete the array of points associated to the current path.
                        it calls for the class destructor ~Path() */

        n = nn;

        if(n){

            pointArray = new Point[n];
        }

    } else { return; }

}

Path& Path::operator = (Path const& p){

    if(this != &p){

        setSize(p.n);

        for(int i = 0; i < p.n; i++){

            pointArray[i] = p.pointArray[i];

        }

    }

    return *this;

}

Point& Path::operator [] (int i){

    return pointArray[i];

}

Path::Path(Path const& p){

    n = 0;
    pointArray = NULL;

    *this = p;

}

Path::~Path(){

    if(n)
        delete[] pointArray;

    n = 0;
    pointArray = NULL;

}

void Path::fillPath(){

    if(!n){ return; } // exit if path has no length

    for(int i = 0; i < this->n; i++){

        int xPos = rand()%(GRID_WIDTH + 1); // get an integer between 0 and GRID_WIDTH
        int yPos = rand()%(GRID_LENGTH + 1); // get an integer between 0 and GRID_LENGTH

        this->pointArray[i].setXY(xPos,yPos);

    }

}

void Path::shuffle(){

    if(!n){ return; } // exit if path has no length

    int index1 = 0, index2 = 0;

    for(int i = 0; i < 3*n; i++){

        // we will swap positions 3*n times, n being the size of the array

        index1 = 1 + rand()%(n-1); // random integer number between 1 and n-1; this way all path will start in the same city
        index2 = 1 + rand()%(n-1);

        swap(this->pointArray[index1],this->pointArray[index2]);

    }

}

void Path::ranSwap(){

    int i = 1 + rand()%(n-1);
    int j = 1 + rand()%(n-1);

    swap(this->pointArray[i],this->pointArray[j]);

}
void Path::print(){

    if(!n)
    {
        cout << "no" << endl;
        return;
    }

    cout << "Length of the path : " << this->n << endl;

    for(int i = 0; i < this->n; i++)
    {

        cout << "Point " << i << " : ";
        cout << "x : " << this->pointArray[i].getX() << " ; ";
        cout << "y : " << this->pointArray[i].getY() << endl;
        cout << endl;

    }

}

int Path::length(){

    if(!n){return 0;}

    int len = 0;

    for(int i = 0; i < this->n - 2; i++)
    {

        len += this->pointArray[i].distance(this->pointArray[i+1]);

    }

    return len;

}

int Path::getN(){

    return n;

}

Point Path::getPointFromArray(int index){

    if(index >= 0 && index < n)
    {
        return pointArray[index];
    } else
    {
        Point p;
        return p;
    }

}

bool Path::pointInPath(Point pt){

    bool inPath = false;

    for(int i = 0; i < n && !inPath; i++)
    {
        inPath = (pt == pointArray[i]) ? true : false;
    }

    return inPath;

}

//-----------------------------------------------------------------------------------------------------------------//

Path* copyPathArray(Path* pA, int beg, int en){

    if(beg < en)
    {
        int a = en - beg + 1;
        Path* out = new Path[a];

        for(int i = 0; i < a; i++)
        {

            out[i] = pA[beg + i];

        }

        return out;
    } else
    {
        return new Path[0];
    }

}
