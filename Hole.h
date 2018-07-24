#ifndef HOLE_H
#define HOLE_H

#include<QGraphicsEllipseItem>

/**

 * @brief The Hole class represents the holes that will appear in the board

 */

class Hole : public QGraphicsEllipseItem
{
  protected:
    /// X coordinate
    double x;
    /// Y coordinate
    double y;
    /// Hole's radius
    double radius;

  public:
    /// Constructor
    explicit Hole(double x, double y, double radius);
    /// Destructor
    virtual ~Hole();
    /// Change X coordinate
    void setX(double x);
    /// Change Y coordinate
    void setY(double y);
    /// Change radius
    void setRadius(double radius);
    /// Get x coordinate
    double getX();
    /// Get y coordinate
    double getY();
    /// Get radius
    double getRadius();
};

#endif // HOLE_H
