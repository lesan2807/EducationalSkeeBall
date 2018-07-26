#ifndef SMALLHOLE_H
#define SMALLHOLE_H

#include "Hole.h"

class SmallHole : public Hole
{
  public:
    SmallHole(double x, double y);
    virtual int getScore() const;
};

#endif // SMALLHOLE_H
