#include "LevelStart.h"
#include "ui_LevelStart.h"
#include <QList>

LevelStart::LevelStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelStart)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    holePoint = new Hole();
    addElementsToScene();
    addHoles();
    createGroupElements();
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
    ellipseBackground = scene->addEllipse(10.0, 10.0, 400.0, 400.0, blackPen, darkCyanBrush );
    ellipseShooter = scene->addEllipse(160.0, 165.0, 100.0, 100.0, blackPen, darkRedBrush);
    shooter = scene->addRect(200.0, 165.0, 20.0, 60.0, blackPen, darkMagentaBrush);
    ballTop = scene->addEllipse(200.0, 165.0, 19.0, 19.0, whitePen, darkGrayBrush);
    ballMiddle = scene->addEllipse(200.0, 185.0, 19.0, 19.0, whitePen, darkGrayBrush);
    ballDown = scene->addEllipse(200.0, 205.0, 19.0, 19.0, whitePen, darkGrayBrush);


}

void LevelStart::createGroupElements()
{
    QList<QGraphicsItem *> items;
    items.append(shooter);
    items.append(ballTop);
    items.append(ballMiddle);
    items.append((ballDown));
    group = scene->createItemGroup(items);
}

void LevelStart::addHoles()
{
    QPen blackPen(Qt::black);
    QBrush darkMagentaBrush(Qt::darkMagenta);
    QBrush darkGreenBrush(Qt::darkGreen);
    QBrush darkGrayBrush(Qt::darkGray);
    scene->addEllipse(holePoint->setX(80), holePoint->setY(50) , holePoint->getRadius(), holePoint->getRadius(), blackPen, darkGrayBrush);
    scene->addEllipse(holePoint->setX(270), holePoint->setY(250), holePoint->setRadius(100), holePoint->setRadius(100), blackPen, darkMagentaBrush);
    scene->addEllipse(holePoint->setX(30), holePoint->setY(180), holePoint->setRadius(75), holePoint->setRadius(75), blackPen, darkGreenBrush);
    scene->addEllipse(holePoint->setX(270), holePoint->setY(70), holePoint->setRadius(75), holePoint->setRadius(75), blackPen, darkGreenBrush);
    scene->addEllipse(holePoint->setX(100), holePoint->setY(300), holePoint->setRadius(50), holePoint->setRadius(50), blackPen, darkGrayBrush);
}

LevelStart::~LevelStart()
{
    delete ui;
    delete scene;
}



