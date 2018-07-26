
#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>
#include <QGraphicsItem>

#include "Ball.h"
#include "ui_Level.h"

Ball::Ball()
{

    //connect(timer, &QTimer::timeout, this, &Ball::move);
    //timer->setInterval(1000);
    timer->setSingleShot(true);
    timer->start(750);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
    // Continuously check for collisions
    QTimer* collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Ball::detectCollisions);
    collisionTimer->setInterval(25);
    collisionTimer->start();

}

Ball::~Ball()
{

}

void Ball::setInitialPos(qreal x, qreal y)
{
    // Place the ball
    setPos(QPointF(x, y));
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
    scene->removeItem(ball);
}


void Ball::move(double angle)
{
    if(int(angle) % 360 == 0)
        this->setY(90);
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
