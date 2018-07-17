#include "Hole.h"
#include <QPen>
#include <QPainter>

double Hole::setX(double x)
{
    this->x = x;
    return this->x;
}

double Hole::setY(double y)
{
    this->y = y;
    return this->y;
}

double Hole::setRadius(double radius)
{
    this->radius = radius;
    return this->radius;
}

double Hole::getX()
{
    return this->x;
}

double Hole::getY()
{
    return this->y;
}

double Hole::getRadius()
{
    return this->radius;
}



