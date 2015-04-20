#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Coordinate class declaration
class Coordinate
{
private:
    int X;
    int Y;

public:
    Coordinate() { X=0; Y=0; }
    Coordinate(int x, int y) { X=x; Y=y; }
    void setX(int x) {  X = x; }
    void setY(int y) {  Y = y; }
    int getX() { return X; }
    int getY() { return Y; }
    void incX() {  X++; }
    void incY() {  Y++; }
    void decX() {  X--; }
    void decY() {  Y--; }
    void incX(int d) {  X+=d; }
    void incY(int d) {  Y+=d; }
    void decX(int d) {  X-=d; }
    void decY(int d) {  Y-=d; }
};

class Rectangle
{
private:
    Coordinate ll; //Lower left corner
    Coordinate ur; //Upper right corner

public:
    Rectangle();
    Rectangle(int, int, int, int);
    Rectangle(Coordinate, Coordinate);
    void SetLowerLeft(Coordinate );
    void SetUpperRight(Coordinate );
    Coordinate GetLowerLeft()
    {
        return ll;
    }
    Coordinate GetUpperRight()
    {
        return ur;
    }
    int GetWidth();
    int GetLength();
    int GetArea()
    {
        return (ur.getX()-ll.getX())*(ur.getY()-ll.getY());
    }

    void Move(Coordinate);
};

Rectangle::Rectangle (){
    ll.setX(rand()%101+1);
    ll.setY(rand()%101+1);
    ur.setX(rand()%101+1);
    ur.setY(rand()%100+1);
    if(ll.getX()>ur.getX())
    {   int temp;
        temp = ur.getX();
        ur.setX(ll.getX());
        ll.setX(temp);
    }
    if(ll.getY()>ur.getY())
    {
        int temp;
        temp=ur.getY();
        ur.setY(ll.getY());
        ll.setY(temp);
    }
    //Create random location (lower left coordinate and upper right coordinate)
    //note 1: any x and y in lower left coordinate and upper right coordinate is between range 0 to 100
    //note 2: coordinates of lower left corner should be smaller than upper right corner.
    //note 3: do NOT call srand() in the constructor (which should be used only once in a program).
}

void AddArea(vector<Rectangle*>& V)
{
    for(int i=0;i<10;i++)  //Add area of all rectangles
    {
        cout<<V[i]->GetArea()<<endl;
    }
    cout<<"all area  "<<V[0]->GetArea()+V[1]->GetArea()+V[2]->GetArea()+V[3]->GetArea()+V[4]->GetArea()+V[5]->GetArea()+V[6]->GetArea()+V[7]->GetArea()+V[8]->GetArea()+V[9]->GetArea()<<endl;
}

int main()
{
    vector<Rectangle* > Container;
    srand(0);
    for(int i=0;i<10;i++)
    {
        Rectangle *rectangle= new Rectangle;
        //cout<<rectangle->GetArea()<<endl;
        Container.push_back(rectangle);
    }
    //Declare a vector named Container to store 10 "Rectangle pointer"
    //Please use a for-loop to push_back() Rectangle pointers into the vector
    //use "AddArea" function to add all areas of them
    AddArea(Container);

    return 0;
}
