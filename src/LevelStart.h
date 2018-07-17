#ifndef LEVELSTART_H
#define LEVELSTART_H

#include <QApplication>
#include <QWidget>


class QGraphicsScene;
class QGraphicsView;
class QWidget;

class LevelStart : public QWidget
{
  private:
    // Manages graphic items. It is an invisible manager
    QGraphicsScene* scene;
    /// A visible widget that renders the scene
    QGraphicsView* view;

  public:
    explicit LevelStart(QWidget *parent = 0);
    ~LevelStart();
    void viewLevelStart();

};

#endif // LEVELSTART_H
