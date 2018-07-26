#include "LevelStart.h"
#include "Score.h"
#include "ui_LevelStart.h"
#include <QList>
#include <QTime>
#include <QtMath>


LevelStart::LevelStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelStart)
{
    /// Set the board as the user interface
    ui->setupUi(this);
    /// Create a graphics scene
    scene = new QGraphicsScene(this);
    /// Set the graphic scene of the view
    ui->graphicsView->setScene(scene);
    ball = new QGraphicsEllipseItem();
    /// Add the common graphic items of all levels
    addElementsToScene();
    this->createGroupElements();
    /// Returns to the menu when the menu button is clicked
    this->connect(ui->menuButton, &QPushButton::clicked, this, &LevelStart::gameMenuAsked);
    /// Returns to the levels menu if the return buton is pressed
    this->connect(ui->returnButton, &QPushButton::clicked, this, &LevelStart::gameLevelsAsked);
    /// Shoots ball
    this->connect(ui->shootButton, &QPushButton::clicked, this, &LevelStart::shoot);
    /// If the user presses the Exit button the game closes
    this->connect(ui->exitButton, &QPushButton::clicked, parent, &QWidget::close);
}

void LevelStart::addElementsToScene()
{
    /// Initialize variables as colors
    QBrush lightGray(QColor(160,160,160));
    QBrush cannon(QColor(50,50,50));
    QBrush darkGray(QColor(80,80,80));
    QBrush white(Qt::white);
    QPen blackPen(Qt::black);
    /// Add the bigger circle to the scene
    ellipseBackground = scene->addEllipse(10.0, 10.0, 400.0, 400.0, blackPen, lightGray );
    /// Add the center circle to the scene
    ellipseShooter = scene->addEllipse(160.0, 165.0, 100.0, 100.0, blackPen, darkGray);
    /// Add the cannon to the scene
    shooter = scene->addRect(202.0, 165.0, 16.0, 50.0, blackPen, cannon);
    /// Add the ball to the cannon
    ball = scene->addEllipse(202.0, 197.0, 16.0, 16.0, QPen(Qt::black), QColor(Qt::white));
    /// Adds the score to the scene
    score = new Score(tr("Score"), 0, Qt::blue);
    score->setPos(-50, 0);
    scene->addItem(this->score);
    /// Adds the number of balls that the user has to the scene
    balls = new Score(tr("Balls"), 3, Qt::blue);
    balls->setPos(380, 0);
    scene->addItem(this->balls);
}

void LevelStart::createGroupElements()
{
}

LevelStart::~LevelStart()
{
    delete ball;
    /// Destroys the user interface
    delete ui;
    /// Destroys the scene
    delete scene;
}

void LevelStart::on_enterAngle_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->shootButton->setEnabled(true);
}

void LevelStart::rotateCannon( double angle )
{
    QPoint point(210,215);
    QTransform transform;
    transform.translate(point.x(), point.y());
    transform.rotate(angle);
    transform.translate(-point.x(), -point.y());
    shooter->setTransform(transform);
    ball->setTransform(transform);
}

void LevelStart::on_shootButton_clicked()
{
    QString text = ui->enterAngle->text();
    for( int index = 0; index < text.length() && text[index] != ','; ++index )
    {
        if( text[index+1] == ',' )
            text[index+1] = '.';
    }
    this->rotateCannon(text.toDouble());
    this->moveBall(text.toDouble());
    balls->decrease();
}

#include <iostream>

void LevelStart::moveBall(double move)
{
    qreal xTemp = ball->x();
    qreal yTemp = ball->y();
    {
        for(int index = 0; index < 180; ++index)
        {
            ball->setX((ball->x()+qCos(qDegreesToRadians(move))));
            ball->setY((ball->y()+qSin(qDegreesToRadians(move))));
            delay();
        }
    }
    ball->setX(xTemp);
    ball->setY(yTemp);
}

void LevelStart::buildLevel( int level )
{
    /// Depending on the value of level, build the correspondig holes
    switch ( level ) {
    case 1:
        //this->level1();
        break;
    }
}

void LevelStart::delay()
{
    QTime dieTime = QTime::currentTime().addMSecs(28);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void LevelStart::level1(const QString &mode)
{
    /// Changes the text that specifies the game mode between Radians and Degrees
    ui->DegreeOrRadian->setText(mode);
    /// Select the color for the holes
    QColor smallBalls(QColor(4,255,0));
    QColor mediumBalls(QColor(3,180,0));
    QColor bigBalls(QColor(2,130,0));
    QPen blackPen(Qt::black);
    /// Add 4 small holes
    QGraphicsEllipseItem* small1 = scene->addEllipse(200, 40, 30, 30, blackPen, smallBalls );
    QGraphicsEllipseItem* small2 = scene->addEllipse(40, 200, 30, 30, blackPen, smallBalls );
    QGraphicsEllipseItem* small3 = scene->addEllipse(230, 350, 30, 30, blackPen, smallBalls );
    QGraphicsEllipseItem* small4 = scene->addEllipse(300, 200, 30, 30, blackPen, smallBalls );
    /// Add 2 medium holes
    QGraphicsEllipseItem* medium1 = scene->addEllipse(100, 60, 60, 60, blackPen, mediumBalls );
    QGraphicsEllipseItem* medium2 = scene->addEllipse(260, 90, 60, 60, blackPen, mediumBalls );
    /// Add 1 big hole
    QGraphicsEllipseItem* big1 = scene->addEllipse(70, 250, 90, 90, blackPen, bigBalls );
    Q_UNUSED(small1);
    Q_UNUSED(small2);
    Q_UNUSED(small3);
    Q_UNUSED(small4);
    Q_UNUSED(medium1);
    Q_UNUSED(medium2);
    Q_UNUSED(big1);
}
