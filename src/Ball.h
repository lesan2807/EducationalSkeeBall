#ifndef BALL_H
#define BALL_H

#include "AnimateObject.h"
#include "ui_Level.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>

class QPropertyAnimation;
class QGraphicsItem;

class Ball : public AnimateObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Ball)

    /// Create a position property to animate the movement of this item
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

  private:
    QPropertyAnimation* moveAnimation = nullptr;

  public:
    /// Constructor
    Ball();
    /// Destructor
    virtual ~Ball();
    void setInitialPos(qreal x, qreal y);
    QGraphicsEllipseItem* addToScene(QGraphicsScene* scene);
    void setTransform(QGraphicsScene* scene, const QTransform &matrix, bool combine = false);
    /// Move the ball around the scene
    void move(double angle);


signals:

public slots:

    /// Detect and react to collisions with other elements
    void detectCollisions();
};

#endif // BALL_H
