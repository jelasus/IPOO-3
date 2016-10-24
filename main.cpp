#include <iostream>
#include "typeown.h"
#include <math.h>

using namespace std;

class Point
{
public:
    reals _X;
    reals _Y;
    Point(const reals _x = 0, const reals _y = 0) : _X(_x), _Y(_y) {}

    reals getx()
    {
        return _X;
    }
    reals gety()
    {
        return _Y;
    }
};

class Line : public Point
{
public:
    Point pstar, pend;
    reals distancia;

    Line(Point _pstar, Point _pend) : pstar(_pstar),pend(_pend) {}

    reals getdistance()
    {
        reals dx,dy;
        dx = pow((pend.getx() - pstar.getx()),2);
        dy = pow((pend.gety() - pstar.gety()),2);
        distancia = sqrt(dx+dy);
        return distancia;
    }
};



int main()
{
    Point punto1(1.0,1.0);
    Point punto2(0.0,0.0);
    numbers a,b;
    a = punto1.getx();
    b = punto1.gety();
    Line line1 (punto2,punto1);
    reals d = line1.getdistance();
    cout << a << '\n' << b << '\n' ;
    cout << d << '\n';
    return 0;
}
