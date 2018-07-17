#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPainter>

#include "LevelStart.h"
#include "Hole.h"
#include "MainWindow.h"

class QBrush;
class QPen;

LevelStart::LevelStart(QWidget *parent) :
    QWidget(parent)

{

}

LevelStart::~LevelStart()
{
    delete this->scene;
    delete this->view;
}


void LevelStart::viewLevelStart()
{

    // An invisible object that manages all the items
    this->scene = new QGraphicsScene();

    // A visible rectangle of the scene
    this->view = new QGraphicsView(this->scene);

    // The scene has infinite size, but we want it has the same size than the view
    // This stops the weird behavior of the autoscroll feature of the view being smaller than the
    // scene, because the scene auto-increases when objects are moved
    this->scene->setSceneRect( this->view->rect() );

    // Disable scrollbars because they are not longer needed
    this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Adds an ellipse in the center:
    QPen pen;
    this->scene->addEllipse(280.0, 180.0, 80.0, 80.0 , pen, QBrush(Qt::blue));


    // Show the view and enter in application's event loop
    this->view->show();
}
