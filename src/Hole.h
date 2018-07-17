#ifndef HOLE_H
#define HOLE_H

#include<QGraphicsEllipseItem>


class Hole : public QGraphicsEllipseItem
{


protected:
    double x = 0;
    double y = 0;
    double radius = 50;
    int points = 100;



public:

    double setX(double x);
    double setY(double y);
    double setRadius(double radius);
    double getX();
    double getY();
    double getRadius();
};

#endif // HOLE_H
