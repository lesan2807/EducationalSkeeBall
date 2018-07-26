#include "SmallHole.h"

SmallHole::SmallHole(double x, double y)
{
    this->x = x;
    this->y = y;
    this->setRadius(30);
    this->setColor(QColor(4,255,0));
}
