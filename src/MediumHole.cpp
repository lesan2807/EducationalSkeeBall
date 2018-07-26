#include "MediumHole.h"
#include <QBrush>

MediumHole::MediumHole(double x, double y)
{
    this->x = x;
    this->y = y;
    this->setRadius(20.8);
    this->setColor(QColor(3,180,0));
    graphic = new QGraphicsEllipseItem(this->x,this->y,radius,radius);
}

