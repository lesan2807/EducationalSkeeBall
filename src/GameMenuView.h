#ifndef GAMEMENUVIEW_H
#define GAMEMENUVIEW_H

#include <QWidget>

namespace Ui
{
    class GameMenuView;
}

class GameMenuView : public QWidget
{
    Q_OBJECT

  private:
    Ui::GameMenuView *ui;

  public:
    explicit GameMenuView(QWidget* parent = nullptr);
    ~GameMenuView();

  signals:
    void gameLevelsAsked();
<<<<<<< HEAD
    void startGame();
=======
>>>>>>> 23aacbd4bfaffdd378713347bcb78807016c91ba
};

#endif // GAMEMENUVIEW_H
