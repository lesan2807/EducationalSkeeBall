#ifndef LEVELSMENU_H
#define LEVELSMENU_H

#include <QWidget>

namespace Ui {
class LevelsMenu;
}

class LevelsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit LevelsMenu(QWidget *parent = 0);
    ~LevelsMenu();

private:
    Ui::LevelsMenu *ui;
};

#endif // LEVELSMENU_H
