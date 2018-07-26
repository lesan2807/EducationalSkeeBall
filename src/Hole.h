#ifndef HOLE_H
#define HOLE_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

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
    QBrush color;
    QPen borde;
    int score;

  public:
    QGraphicsEllipseItem* graphic;

  public:
    Hole();
    Hole(QGraphicsEllipseItem* ellipse);
    /// Constructor
    Hole(double x, double y, double radius);
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
    void setColor(QBrush color);
    void setScore(int score);
    virtual int getScore();
};

#endif // HOLE_H
