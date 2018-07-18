#include "LevelStart.h"
#include "ui_LevelStart.h"
#include <QList>

LevelStart::LevelStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelStart)
{
    this->ui->setupUi(this);
    this->scene = new QGraphicsScene(this);
    this->ui->graphicsView->setScene(scene);
    this->holePoint = new Hole();
    this->addElementsToScene();
    this->addHoles();
    this->createGroupElements();
    // Returns to the menu when the return button is clicked
    this->connect(ui->menuButton, &QPushButton::clicked, this, &LevelStart::gameMenuAsked);
    // Shoots ball
    this->connect(ui->shootButton, &QPushButton::clicked, this, &LevelStart::shoot);

}

void LevelStart::addElementsToScene()
{
    QBrush darkRedBrush(Qt::darkRed);
    QBrush darkMagentaBrush(Qt::darkMagenta);
    QBrush darkCyanBrush(Qt::darkCyan);
    QBrush darkGrayBrush(Qt::darkGray);
    QPen blackPen(Qt::black);
    QPen whitePen(Qt::white);
    this->ellipseBackground = this->scene->addEllipse(10.0, 10.0, 400.0, 400.0, blackPen, darkCyanBrush );
    this->ellipseShooter = this->scene->addEllipse(160.0, 165.0, 100.0, 100.0, blackPen, darkRedBrush);
    this->shooter = this->scene->addRect(200.0, 165.0, 20.0, 60.0, blackPen, darkMagentaBrush);
    this->ballTop = this->scene->addEllipse(200.0, 165.0, 19.0, 19.0, whitePen, darkGrayBrush);
    this->ballMiddle = this->scene->addEllipse(200.0, 185.0, 19.0, 19.0, whitePen, darkGrayBrush);
    this->ballDown = this->scene->addEllipse(200.0, 205.0, 19.0, 19.0, whitePen, darkGrayBrush);

    // A label to show the player score
    this->score = new Score(tr("Points"), 1000, Qt::black);
    this->score->setPos(380, 380);
    this->scene->addItem(this->score);


}

void LevelStart::createGroupElements()
{
    QList<QGraphicsItem *> items;
    items.append(this->shooter);
    items.append(this->ballTop);
    items.append(this->ballMiddle);
    items.append((this->ballDown));
    this->group = this->scene->createItemGroup(items);
}

void LevelStart::addHoles()
{
    QPen blackPen(Qt::black);
    QBrush darkMagentaBrush(Qt::darkMagenta);
    QBrush darkGreenBrush(Qt::darkGreen);
    QBrush darkGrayBrush(Qt::darkGray);
    this->scene->addEllipse(holePoint->setX(80), holePoint->setY(50) , holePoint->getRadius(), holePoint->getRadius(), blackPen, darkGrayBrush);
    this->scene->addEllipse(holePoint->setX(270), holePoint->setY(250), holePoint->setRadius(100), holePoint->setRadius(100), blackPen, darkMagentaBrush);
    this->scene->addEllipse(holePoint->setX(30), holePoint->setY(180), holePoint->setRadius(75), holePoint->setRadius(75), blackPen, darkGreenBrush);
    this->scene->addEllipse(holePoint->setX(270), holePoint->setY(70), holePoint->setRadius(75), holePoint->setRadius(75), blackPen, darkGreenBrush);
    this->scene->addEllipse(holePoint->setX(100), holePoint->setY(300), holePoint->setRadius(50), holePoint->setRadius(50), blackPen, darkGrayBrush);
}

LevelStart::~LevelStart()
{
    delete this->ui;
    delete this->scene;
}



