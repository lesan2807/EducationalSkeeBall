
#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>
#include <QGraphicsEllipseItem>

#include "Ball.h"
#include "ui_Level.h"

Ball::Ball()
{

    //connect(timer, &QTimer::timeout, this, &Ball::move);
    // Continuously check for collisions
    QTimer* collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Ball::detectCollisions);
    collisionTimer->setInterval(25);
    collisionTimer->start();

}

Ball::~Ball()
{

}

void Ball::setInitialPos()
{
    // Place the ball
    setPos(QPointF(202.0, 197.0));
}



QGraphicsEllipseItem* Ball::addToScene(QGraphicsScene *scene)
{
    QGraphicsEllipseItem* ball = scene->addEllipse(202.0, 197.0, 16.0, 16.0, QPen(Qt::black), QColor(Qt::white));
    return ball;
}

void Ball::setTransform(QGraphicsScene *scene, const QTransform &matrix, bool combine)
{
    QGraphicsEllipseItem* ball = this->addToScene(scene);
    ball->setTransform(matrix,combine);
}


void Ball::move()
{
    this->moveAnimation = new QPropertyAnimation(this, "pos");
    this->moveAnimation->setStartValue(QPointF(202.0, 197.0));

    // To a random point within the scene/screen
    float targetX = 202.0;
    float targetY = scene()->height();
    QPointF endPos(targetX, targetY);
    this->moveAnimation->setEndValue(endPos);

    // The duration is proportional to the max distance possible
    double distance = std::hypot(targetX - 202.0, targetY - 197.0);
    double screenDiagonal = std::hypot(scene()->width(), scene()->height());
    int duration = distance / screenDiagonal * 1500.0;
    this->moveAnimation->setDuration(duration);

    // Start the animation
    this->moveAnimation->start();
}

#include "Hole.h"
void Ball::detectCollisions()
{
    // Traverse all graphic items that are colliding with this
    const QList<QGraphicsItem*>& items = QGraphicsItem::collidingItems();
    for ( QGraphicsItem* item : items )
    {
        // If a graphic item is an obstacle remove it from scene
        if ( /*Hole* hole =*/ dynamic_cast<Hole*>(item) )
        {
            this->moveAnimation->stop();
        }
    }
}
