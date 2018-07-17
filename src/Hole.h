#ifndef HOLE_H
#define HOLE_H

#include<QGraphicsEllipseItem>

class Hole : public QGraphicsEllipseItem
{


protected:
    double x;
    double y;
    double radius;


public:
    explicit Hole(double x, double y, double radius);
    Hole(const Hole& other);
    virtual ~Hole();
    void setX(double x);
    void setY(double y);
    void setRadius(double radius);
    double getX();
    double getY();
    double getRadius();
};

#endif // HOLE_H
