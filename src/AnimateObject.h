#ifndef ANIMATEOBJECT_H
#define ANIMATEOBJECT_H

#include <QGraphicsSvgItem>

class Qtimer;

/**
 * @brief An item that moves within the screen
 */

class AnimateObject : public QGraphicsSvgItem
{
    Q_OBJECT
    Q_DISABLE_COPY(AnimateObject)

  protected:
    /// To produce the move-up animation
    QTimer* timer;

  public:
    explicit AnimateObject(QGraphicsItem* parent = nullptr);
    ~AnimateObject();
    void destroy(bool removeFromScene = true, bool deleteObject = true);
};

#endif // ANIMATEOBJECT_H
