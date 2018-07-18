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

class Score;

/**
 * @brief The LevelStart class is a designer form class that represents the game board
 */

class LevelStart : public QWidget
{
    /// Tells the compilator thar this class has gui elements
    Q_OBJECT

  private:
    /// User inteface
    Ui::LevelStart *ui;
    /// Scene
    QGraphicsScene *scene;
    /// Three balls inside the cannon
    QGraphicsEllipseItem *ballTop;
    QGraphicsEllipseItem *ballMiddle;
    QGraphicsEllipseItem *ballDown;
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

  public:
    /// Constructor
    explicit LevelStart(QWidget *parent = 0);
    /// Destructor
    ~LevelStart();
    /// Adds a graphic item to the scene
    void addElementsToScene();
    /// Creates a group of graphic items
    void createGroupElements();
    /// Build the corresponding level
    void buildLevel( int level );
    /// Add the corresponding holes to each level
    void level1(const QString& mode);
    void level2();
    void level3();
    void level4();
    void level5();
    void level6();
    void level7();
    void level8();
    void level9();
    void level10();

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
    /// When the user changes the angle
    void on_enterAngle_textChanged(const QString &text);
};

#endif // LEVELSTART_H
