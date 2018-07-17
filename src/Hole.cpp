#include "Hole.h"
#include <QPen>
#include <QPainter>

Hole::Hole(double x, double y,  double radius)
    : x{x}
    , y{y}
    , radius{radius} 
{

}


Hole::~Hole()
{

}


void Hole::setX(double x)
{
    this->x = x;
}

void Hole::setY(double y)
{
    this->y = y;
}

void Hole::setRadius(double radius)
{
    this->radius = radius;
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

