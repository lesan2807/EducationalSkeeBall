#include "Hole.h"
#include <QPen>
#include <QPainter>

Hole::Hole(double x, double y,  double radius)
    : x {x}
    , y {y}
    , radius {radius}
{
}


Hole::~Hole()
{
}


void Hole::setX(double x)
{
    /// Change the x coordinate of the hole
    this->x = x;
}

void Hole::setY(double y)
{
    /// Change the y coordinate of the hole
    this->y = y;
}

void Hole::setRadius(double radius)
{
    /// Change the radius of the circle
    this->radius = radius;
}

double Hole::getX()
{
    /// Return the x coordinate
    return this->x;
}

double Hole::getY()
{
    /// Return the y coordinate
    return this->y;
}

double Hole::getRadius()
{
    /// Return the radius
    return this->radius;
}
