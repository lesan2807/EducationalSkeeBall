#ifndef LEVELSMENU_H
#define LEVELSMENU_H

#include <QWidget>

namespace Ui
{
    class LevelsMenu;
}

class LevelsMenu : public QWidget
{
    Q_OBJECT

  private:
    Ui::LevelsMenu *ui;

  public:
    explicit LevelsMenu(QWidget *parent = 0);
    ~LevelsMenu();

  signals:
    void gameMenuAsked();
};

#endif // LEVELSMENU_H
