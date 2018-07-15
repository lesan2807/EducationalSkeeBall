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
};

#endif // GAMEMENUVIEW_H
