#include "SmallHole.h"
#include <QBrush>
#include <QGraphicsScene>
#include <iostream>

SmallHole::SmallHole(double x, double y)
{
    this->x = x;
    this->y = y;
    this->setRadius(18.4);
    this->setColor(QColor(4,255,0));
    graphic = new QGraphicsEllipseItem(this->x,this->y,radius,radius);
    this->score = 500;
}

int SmallHole::getScore() const
{
    std::cerr << "why";
    return 500;
}




