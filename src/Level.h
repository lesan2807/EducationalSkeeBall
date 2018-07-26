#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <QDomElement>
#include <QWidget>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QList>

#include "Hole.h"
#include "Score.h"
#include "MainWindow.h"

class MainWindow;
class QWidget;
class QMainWindow;

namespace Ui
{
    class Level;
}

class Level : public QWidget
{
    /// Tells the compilator thar this class has gui elements
    Q_OBJECT

  private:
    ///Q_DISABLE_COPY(Level);
    /// User inteface
    Ui::Level *ui;
    QVector<Hole*> holes;
    int minScore;
    int number;

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
    Level(QWidget *parent, int number = 0, int minScore = 0);
    ~Level();
    static Hole* createHole(const QString& type, double x, double y);
    bool addHole(const QString& type, double x, double y);
    void addElementsToScene();
    /// Build the corresponding level
    void buildLevel( int level, QVector<Level*> levels);
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

#endif // LEVEL_H
