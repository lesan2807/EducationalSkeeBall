#ifndef BIGHOLE_H
#define BIGHOLE_H

#include "Hole.h"

class BigHole : public Hole
{
  public:
    BigHole(double x, double y);
    virtual int getScore() const override;
};

#endif // BIGHOLE_H

