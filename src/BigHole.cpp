#include "BigHole.h"
#include <QBrush>

BigHole::BigHole(double x, double y)
{
    this->x = x;
    this->y = y;
    this->setRadius(23.2);
    this->setColor(QBrush(QColor(2,130,0)));
    graphic = new QGraphicsEllipseItem(this->x,this->y,radius,radius);
}

