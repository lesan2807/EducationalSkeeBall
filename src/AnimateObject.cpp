#include <QGraphicsScene>
#include <QTimer>

#include "AnimateObject.h"

AnimateObject::AnimateObject(QGraphicsItem *parent)
    : QGraphicsSvgItem(parent)
    , timer( new QTimer(this) )
{
}

AnimateObject::~AnimateObject()
{
}

void AnimateObject::destroy(bool removeFromScene, bool deleteObject)
{
    timer->stop();
    if( removeFromScene ) scene()->removeItem(this);
    if( deleteObject ) this->deleteLater();
}
