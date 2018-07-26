#include "BigHole.h"
#include "SmallHole.h"
#include "MediumHole.h"
#include "LevelStart.h"
#include "Score.h"
#include "ui_LevelStart.h"
#include <QDomDocument>
#include <QList>
#include <QtMath>
#include <QTime>

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
    /// Add the common graphic items of all levels
    addElementsToScene();
    /// Returns to the menu when the menu button is clicked
    this->connect(ui->menuButton, &QPushButton::clicked, this, &LevelStart::gameMenuAsked);
    /// Returns to the levels menu if the return buton is pressed
    this->connect(ui->returnButton, &QPushButton::clicked, this, &LevelStart::gameLevelsAsked);
    /// Shoots ball
    this->connect(ui->shootButton, &QPushButton::clicked, this, &LevelStart::shoot);
    /// If the user presses the Exit button the game closes
    this->connect(ui->exitButton, &QPushButton::clicked, parent, &QWidget::close);

    this->loadLevels();
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
    /// Adds the score to the scene
    score = new Score(tr("Score"), 0, Qt::blue);
    score->setPos(-50, 0);
    scene->addItem(this->score);
    /// Adds the number of balls that the user has to the scene
    balls = new Score(tr("Balls"), 3, Qt::blue);
    balls->setPos(380, 0);
    scene->addItem(this->balls);
}

LevelStart::~LevelStart()
{
    for(long long index = 0; index < holes.size(); ++index)
        delete holes[index];
    /// Destroys the user interface
    delete ui;
    /// Destroys the scene
    delete scene;
    //levels.clear();
}

void LevelStart::on_enterAngle_valueChanged(double arg1)
{
    Q_UNUSED(arg1)
    if( balls->getScore() > 0 )
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
    angle += text.toDouble();
    this->rotateCannon(angle);
    balls->decrease();
    if( balls->getScore() == 0 )
        ui->shootButton->setEnabled(false);
    this->moveBall();
}

void LevelStart::moveBall()
{
    ui->shootButton->setEnabled(false);
    ui->returnButton->setEnabled(false);
    ui->exitButton->setEnabled(false);
    ui->menuButton->setEnabled(false);
    double move = angle - 90.0;
    qreal xTemp = ball->x();
    qreal yTemp = ball->y();
    for(int index = 0; index < 180 && !checkCollision(); ++index)
    {
        ball->setX((ball->x()+qCos(qDegreesToRadians(move))));
        ball->setY((ball->y()+qSin(qDegreesToRadians(move))));
        delay();
    }
    ball->setX(xTemp);
    ball->setY(yTemp);
    QTime* time = new QTime;
    angle = qrand()*time->currentTime().msec() % 360;
    this->rotateCannon(angle);
    if( balls->getScore() > 0 )
        ui->shootButton->setEnabled(true);
    ui->returnButton->setEnabled(true);
    ui->exitButton->setEnabled(true);
    ui->menuButton->setEnabled(true);
}

void LevelStart::delay()
{
    QTime dieTime = QTime::currentTime().addMSecs(10);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

bool LevelStart::checkCollision()
{
    /// Traverse all graphic items that are colliding with the ball
    const QList<QGraphicsItem*>& items = ball->collidingItems();
    for(int index = 0; index < items.count(); ++index)
    {
        if( items[index] != ellipseBackground && items[index] != ellipseShooter && items[index] != shooter )
        {
            for( int hole = 0; hole < holes.count(); ++hole )
            {
                if( holes[hole]->graphic->x() == items[index]->x() )
                {
                    score->increase(holes[hole]->getScore());
                    return true;
                }
            }
        }
    }
    return false;
}

void LevelStart::buildLevel( int level )
{
    Q_UNUSED(level)
    //QMap<int,QVector<Hole*>>::iterator it = levels.begin();
    //for( int index = 0; index < it.value().count(); ++index )
        //scene->addEllipse(it.value().at(index)->graphic);
    /*if( it == levels.end() )
        ui->DegreeOrRadian->setText(tr("Nada guardado en el mapa"));
    else
        ui->DegreeOrRadian->setText(tr("Size=%1 (%2,%3)").arg(it.value().count()).arg(0).arg(0));*/
}

int LevelStart::loadLevels()
{
    /// Open the levels file as a Qt resource
    const char* const filename = ":/AngularSkeeBall.xml";
    QFile file(filename);
    if( !file.open(QIODevice::ReadOnly) )
        return 2;

    /// Parse the levels file as an XML document
    QDomDocument document("levels");
    if( !document.setContent( &file ) )
    {
        file.close();
        return 3;
    }
    file.close();

    /// Load each level´s hole from the document and fill the holes array
    return loadHoles(document.documentElement());
}

int LevelStart::loadHoles(const QDomElement& rootElement)
{
    int level;
    QMap<int,QVector<Hole*>>::iterator it;
    QVector<Hole*> vector;
    ui->DegreeOrRadian->setText(rootElement.tagName());
    /// Load each level from the document
    for( QDomElement element = rootElement.firstChildElement(); !element.isNull(); element = element.nextSiblingElement() )
    {
        //ui->DegreeOrRadian->setText(element.tagName());
        if( element.tagName() == "level" )
        {
            /// Use the type attribute required to create a question object
            const QString& number = element.attribute("number");
            level = number.toInt();
            //levels.insert(level,vector);
        }
        if( element.tagName() == "hole" )
        {
            //ui->DegreeOrRadian->setText(element.tagName());
            const QString& type = element.attribute("type");
            double x = element.attribute("x").toDouble();
            double y = element.attribute("y").toDouble();
            if( type == "big" )
            {
                Hole* hole = new BigHole(x,y);
                it.value().push_back(hole);
            }
            if( type == "medium" )
            {
                Hole* hole = new MediumHole(x,y);
                //while( (it = levels.find(level)) == levels.end() )
                //    levels.insert(level,vector);
                it.value().push_back(hole);
            }
            if( type == "small" )
            {
                Hole* hole = new SmallHole(x,y);
                //while( (it = levels.find(level)) == levels.end() )
                //    levels.insert(level,vector);
                it.value().push_back(hole);
            }
        }
    }
    return level;
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
    Hole* hole1 = new Hole(small1);
    hole1->setScore(500);
    holes.push_back(hole1);

    QGraphicsEllipseItem* small2 = scene->addEllipse(40, 200, 30, 30, blackPen, smallBalls );
    Hole* hole2 = new Hole(small2);
    hole2->setScore(500);

    holes.push_back(hole2);
    QGraphicsEllipseItem* small3 = scene->addEllipse(230, 350, 30, 30, blackPen, smallBalls );
    Hole* hole3 = new Hole(small3);
    hole3->setScore(500);

    holes.push_back(hole3);
    QGraphicsEllipseItem* small4 = scene->addEllipse(300, 200, 30, 30, blackPen, smallBalls );
    Hole* hole4 = new Hole(small4);
    hole4->setScore(500);
    holes.push_back(hole4);
    /// Add 2 medium holes
    QGraphicsEllipseItem* medium1 = scene->addEllipse(100, 60, 60, 60, blackPen, mediumBalls );
    Hole* hole5 = new Hole(medium1);
    hole5->setScore(200);
    holes.push_back(hole5);
    QGraphicsEllipseItem* medium2 = scene->addEllipse(260, 90, 60, 60, blackPen, mediumBalls );
    Hole* hole6 = new Hole(medium2);
    hole6->setScore(200);
    holes.push_back(hole6);
    /// Add 1 big hole
    QGraphicsEllipseItem* big1 = scene->addEllipse(70, 250, 90, 90, blackPen, bigBalls );
    Hole* hole7 = new Hole(big1);
    hole7->setScore(100);
    holes.push_back(hole7);
    /// Add the ball to the cannon
    ball = scene->addEllipse(202.0, 197.0, 16.0, 16.0, blackPen, Qt::white);
    Q_UNUSED(small1);
    Q_UNUSED(small2);
    Q_UNUSED(small3);
    Q_UNUSED(small4);
    Q_UNUSED(medium1);
    Q_UNUSED(medium2);
    Q_UNUSED(big1);
    QTime* time = new QTime();
    angle = qrand()*time->currentTime().msec() % 360;
    this->rotateCannon(angle);
}
