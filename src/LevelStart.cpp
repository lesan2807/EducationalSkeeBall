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
    addElementsToScene();
    createGroupElements();
    // Returns to the menu when the return button is clicked
    this->connect(ui->menuButton, &QPushButton::clicked, this, &LevelStart::gameMenuAsked);
    // Shoots ball
    this->connect(ui->shootButton, &QPushButton::clicked, this, &LevelStart::shoot);

}

void LevelStart::addElementsToScene()
{
    QBrush redBrush(Qt::darkRed);
    QBrush magentaBrush(Qt::darkMagenta);
    QBrush darkCyanBrush(Qt::darkCyan);
    QBrush greyBrush(Qt::darkGray);
    QPen blackPen(Qt::black);
    QPen whitePen(Qt::white);
    ellipseBackground = scene->addEllipse(10.0, 10.0, 400.0, 400.0, blackPen, darkCyanBrush );
    ellipseShooter = scene->addEllipse(160.0, 165.0, 100.0, 100.0, blackPen, redBrush);
    shooter = scene->addRect(200.0, 165.0, 20.0, 60.0, blackPen, magentaBrush);
    ballTop = scene->addEllipse(200.0, 165.0, 19.0, 19.0, whitePen, greyBrush);
    ballMiddle = scene->addEllipse(200.0, 185.0, 19.0, 19.0, whitePen, greyBrush);
    ballDown = scene->addEllipse(200.0, 205.0, 19.0, 19.0, whitePen, greyBrush);

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



LevelStart::~LevelStart()
{
    delete ui;
    delete scene;
}



