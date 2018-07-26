#include "BigHole.h"

BigHole::BigHole(double x = 0, double y = 0)
{
    this->x = x;
    this->y = y;
    this->setRadius(90);
    this->setColor(QColor(2,130,0));
}
