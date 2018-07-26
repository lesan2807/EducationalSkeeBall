#include "MediumHole.h"

MediumHole::MediumHole(double x = 0, double y = 0)
{
    this->x = x;
    this->y = y;
    this->setRadius(60);
    this->setColor(QColor(3,180,0));
}
