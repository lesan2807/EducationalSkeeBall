#ifndef MEDIUMHOLE_H
#define MEDIUMHOLE_H

#include "Hole.h"

class MediumHole : public Hole
{
  public:
    MediumHole(double x, double y); 
    virtual int getScore() const override;
};

#endif // MEDIUMHOLE_H
