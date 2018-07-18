#include "LevelStart.h"
#include "Score.h"
#include "ui_LevelStart.h"
#include <QList>

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
    /// Group the cannon and all the ball inside of it
    createGroupElements();
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
    QBrush redBrush(Qt::darkRed);
    QBrush magentaBrush(Qt::darkMagenta);
    QBrush darkCyanBrush(Qt::darkCyan);
    QBrush greyBrush(Qt::darkGray);
    QPen blackPen(Qt::black);
    QPen whitePen(Qt::white);
    /// Add the bigger circle to the scene
    ellipseBackground = scene->addEllipse(10.0, 10.0, 400.0, 400.0, blackPen, darkCyanBrush );
    /// Add the center circle to the scene
    ellipseShooter = scene->addEllipse(160.0, 165.0, 100.0, 100.0, blackPen, redBrush);
    /// Add the cannon to the scene
    shooter = scene->addRect(203.0, 165.0, 16.0, 50.0, blackPen, magentaBrush);
    /// Add three balls to the cannon
    ballTop = scene->addEllipse(203.0, 165.0, 16.0, 16.0, whitePen, greyBrush);
    ballMiddle = scene->addEllipse(203.0, 181.0, 16.0, 16.0, whitePen, greyBrush);
    ballDown = scene->addEllipse(203.0, 197.0, 16.0, 16.0, whitePen, greyBrush);
    /// Adds the score to the scene
    score = new Score(tr("Score"), 0, Qt::blue);
    score->setPos(-50, 0);
    scene->addItem(this->score);
    /// Adds the number of balls that the user has to the scene
    score = new Score(tr("Balls"), 3, Qt::blue);
    score->setPos(380, 0);
    scene->addItem(this->score);

}

void LevelStart::createGroupElements()
{
    /// Create a list that contains graphic items
    QList<QGraphicsItem*> items;
    /// Add the cannon and the three balls to the list
    items.append(shooter);
    items.append(ballTop);
    items.append(ballMiddle);
    items.append((ballDown));
    /// Creates a gruop with the items contained in the list
    group = scene->createItemGroup(items);
}

LevelStart::~LevelStart()
{
    /// Destroys the user interface
    delete ui;
    /// Destroys the scene
    delete scene;
}

void LevelStart::on_enterAngle_textChanged(const QString& text)
{
    /// Avoids receiving an 'unused parameter' warning
    Q_UNUSED(text);
    /// If text is an empty QString the shoot button is disabled
    if( ui->enterAngle->text().trimmed().length() <= 0 )
        ui->shootButton->setEnabled(false);
    /// If text is a number the shoot button is enabled
    else
        ui->shootButton->setEnabled(true);
}

void LevelStart::buildLevel( int level )
{
    /// Depending on the value of level, build the correspondig holes
    switch ( level ) {
    case 1:
        //this->level1();
        break;
    case 2:
        this->level2();
        break;
    case 3:
        this->level3();
        break;
    case 4:
        this->level4();
        break;
    case 5:
        this->level5();
        break;
    case 6:
        this->level6();
        break;
    case 7:
        this->level7();
        break;
    case 8:
        this->level8();
        break;
    case 9:
        this->level9();
        break;
    case 10:
        this->level10();
        break;
    }
}

void LevelStart::level1(const QString &mode)
{
    /// Changes the text that specifies the game mode between Radians and Degrees
    ui->DegreeOrRadian->setText(mode);
    /// Select the color for the holes
    QBrush blue(Qt::blue);
    QBrush purple(Qt::darkMagenta);
    QBrush yellow(Qt::yellow);
    QPen blackPen(Qt::black);
    /// Add 4 small holes
    QGraphicsEllipseItem* small1 = scene->addEllipse(200, 40, 30, 30, blackPen, yellow );
    QGraphicsEllipseItem* small2 = scene->addEllipse(40, 200, 30, 30, blackPen, yellow );
    QGraphicsEllipseItem* small3 = scene->addEllipse(230, 350, 30, 30, blackPen, yellow );
    QGraphicsEllipseItem* small4 = scene->addEllipse(300, 200, 30, 30, blackPen, yellow );
    /// Add 2 medium holes
    QGraphicsEllipseItem* medium1 = scene->addEllipse(100, 60, 60, 60, blackPen, purple );
    QGraphicsEllipseItem* medium2 = scene->addEllipse(260, 90, 60, 60, blackPen, purple );
    /// Add 1 big hole
    QGraphicsEllipseItem* big1 = scene->addEllipse(70, 250, 90, 90, blackPen, blue );
    Q_UNUSED(small1);
    Q_UNUSED(small2);
    Q_UNUSED(small3);
    Q_UNUSED(small4);
    Q_UNUSED(medium1);
    Q_UNUSED(medium2);
    Q_UNUSED(big1);
}

void LevelStart::level2()
{

}

void LevelStart::level3()
{

}

void LevelStart::level4()
{

}

void LevelStart::level5()
{

}

void LevelStart::level6()
{

}

void LevelStart::level7()
{

}

void LevelStart::level8()
{

}

void LevelStart::level9()
{

}

void LevelStart::level10()
{

}
