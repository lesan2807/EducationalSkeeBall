#ifndef LEVELSTART_H
#define LEVELSTART_H

#include <QWidget>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QMap>
#include <QVector>
#include "Hole.h"

namespace Ui
{
    class LevelStart;
}

class Score;
class QDomElement;

/**
 * @brief The LevelStart class is a designer form class that represents the game board
 */

class LevelStart : public QWidget
{
    /// Tells the compilator thar this class has gui elements
    Q_OBJECT

  private:
    QMap<int,QVector<Hole*>> levels;
    QVector<Hole*> holes;
    /// User inteface
    Ui::LevelStart *ui;
    /// Scene
    QGraphicsScene *scene;
    /// The ball inside the cannon
    QGraphicsEllipseItem *ball;
    /// Central circle where the cannon is
    QGraphicsEllipseItem *ellipseShooter;
    /// Big circle where the holes will appear
    QGraphicsEllipseItem *ellipseBackground;
    /// Group of graphic items
    QGraphicsItemGroup *group;
    /// Cannon
    QGraphicsRectItem *shooter;
    /// Player's score
    Score* score;
    /// Keeps record of the number of balls the user has
    Score* balls;
    double angle;


  public:
    /// Constructor
    explicit LevelStart(QWidget *parent = 0);
    /// Destructor
    ~LevelStart();
    /// Adds a graphic item to the scene
    void addElementsToScene();
    /// Build the corresponding level
    void buildLevel( int level );
    void rotateCannon(double angle);
    /// Add the corresponding holes to each level
    void level1( const QString& mode);
    void moveBall();
    void delay();
    bool checkCollision();

  private:
    int loadLevels();
    int loadHoles(const QDomElement& rootElement);
    Hole* createHole(const QString& type);

  signals:
    /// The user asked to return to the main menu
    void gameMenuAsked();
    /// The user wants to start playing
    void startGame();
    /// The user asked to shoot a ball out of the cannon
    void shoot();
    /// The user asked to return to the levels menu
    void gameLevelsAsked();

  private slots:
    void on_enterAngle_valueChanged(double arg1);
    void on_shootButton_clicked();
};

#endif // LEVELSTART_H
