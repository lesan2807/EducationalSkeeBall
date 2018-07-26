#include "Level.h"
#include "Score.h"
#include "ui_Level.h"
#include <QList>

class MainWindow;
class Level;
class QMainWindow;
class QWidget;

Level::Level(QWidget *parent, int number, int minScore)
    : number{number}
    , QWidget(parent)
    , ui(new Ui::Level)
    , minScore{minScore}
{
    /// Set the board as the user interface
    this->ui->setupUi(this);
    /// Create a graphics scene
    scene = new QGraphicsScene(this);
    /// Set the graphic scene of the view
    ui->graphicsView->setScene(scene);
    /// Add the common graphic items of all levels
    addElementsToScene();
    /// Returns to the menu when the menu button is clicked
    this->connect(ui->menuButton, &QPushButton::clicked, this, &Level::gameMenuAsked);
    /// Returns to the levels menu if the return buton is pressed
    this->connect(ui->returnButton, &QPushButton::clicked, this, &Level::gameLevelsAsked);
    /// Shoots ball
    this->connect(ui->shootButton, &QPushButton::clicked, this, &Level::shoot);
    /// If the user presses the Exit button the game closes
    this->connect(ui->exitButton, &QPushButton::clicked, parent, &QWidget::close);
}

Level::~Level()
{

    for(int index = 0; index < this->holes.size(); ++index)
        delete this->holes[index];
    /// Destroys the scene
    delete scene;
    /// Destroys the user interface
    delete ui;

}

#include "BigHole.h"
#include "MediumHole.h"
#include "SmallHole.h"
//#include "BigLooseHole.h"
//#include "MediumLooseHole.h"
//#include "SmallLooseHole.h"
//#include "LooseBallHole.h"
//#include "WinBallHole.h"


Hole *Level::createHole(const QString &type, double x, double y)
{
    if(type == "big") return new BigHole(x,y);
    if(type == "medium") return new MediumHole(x,y);
    if(type == "small") return new SmallHole(x,y);
    return nullptr;
}

bool Level::addHole(const QString &type, double x, double y)
{
    Hole* hole = createHole(type, x, y);
    if( !hole )
        return false;
    this->holes.append(hole);
    return true;
}

bool Level::loadFrom(const QDomElement &element)
{
    return true;
}

void Level::rotateCannon(double angle)
{
    QPoint point(210,215);
    QTransform transform;
    transform.translate(point.x(), point.y());
    transform.rotate(angle);
    transform.translate(-point.x(), -point.y());
    shooter->setTransform(transform);
    ball->setTransform(transform);
}

void Level::addElementsToScene()
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
    ball = scene->addEllipse(202.0, 197.0, 16.0, 16.0, blackPen, white);
    /// Adds the score to the scene
    score = new Score(tr("Score"), 0, Qt::blue);
    score->setPos(-50, 0);
    scene->addItem(this->score);
    /// Adds the number of balls that the user has to the scene
    balls = new Score(tr("Balls"), 3, Qt::blue);
    balls->setPos(380, 0);
    scene->addItem(this->balls);
}

void Level::on_enterAngle_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    ui->shootButton->setEnabled(true);
}

void Level::on_shootButton_clicked()
{
    QString text = ui->enterAngle->text();
    for( int index = 0; index < text.length() && text[index] != ','; ++index )
    {
        if( text[index+1] == ',' )
            text[index+1] = '.';
    }
    this->rotateCannon(text.toDouble());
    balls->decrease();
}
