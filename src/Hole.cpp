#include "Hole.h"
#include <QPen>
#include <QPainter>
#include <QGraphicsScene>

Hole::Hole(double x, double y)
    : x {x}
    , y {y}
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

void Hole::setColor(QColor newColor)
{
    /// Change the color of hole
    this->color = newColor;
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
    /// Return radius
    return this->radius;
}

void Hole::drawHole(double x, double y, QGraphicsScene scene)
{
    ///Draws hole in the scene
    QGraphicsEllipseItem* hole = scene.addEllipse(x,y,this->radius, this->radius, QPen(Qt::black), this->color);
    Q_UNUSED(hole);
}
