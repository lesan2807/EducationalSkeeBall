#ifndef LEVELSTART_H
#define LEVELSTART_H

#include <QWidget>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include "Hole.h"

namespace Ui
{
    class LevelStart;
}

class LevelStart : public QWidget
{
    Q_OBJECT

 private:
    Ui::LevelStart *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ballTop;
    QGraphicsEllipseItem *ballMiddle;
    QGraphicsEllipseItem *ballDown;
    QGraphicsEllipseItem *ellipseShooter;
    QGraphicsEllipseItem *ellipseBackground;
    QGraphicsItemGroup *group;
    QGraphicsRectItem *shooter;

 public:
    explicit LevelStart(QWidget *parent = 0);
    void addElementsToScene();
    void createGroupElements();
    ~LevelStart();

 signals:
    void gameMenuAsked();
    void startGame();
    void shoot();
};

#endif // LEVELSTART_H
