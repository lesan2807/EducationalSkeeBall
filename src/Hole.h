#ifndef HOLE_H
#define HOLE_H

#include<QGraphicsEllipseItem>
#include<QColor>

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
    /// points
    int points = 0;
    /// color of hole
    QColor color;
    /// radius
    double radius;


  public:
    /// Constructor
    explicit Hole(double x = 0, double y = 0);
    /// Destructor
    virtual ~Hole();
    /// Change X coordinate
    virtual void setX(double x);
    /// Change Y coordinate
    virtual void setY(double y);
    /// Change radius
    virtual void setRadius(double radius);
    /// Change color
    virtual void setColor(QColor newColor);
    /// Get x coordinate
    virtual double getX();
    /// Get y coordinate
    virtual double getY();
    /// Get radius
    virtual double getRadius();
    /// Draw hole
    virtual void drawHole(double x, double y, QGraphicsScene scene);
};

#endif // HOLE_H
