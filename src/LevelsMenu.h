
#ifndef LEVELSMENU_H
#define LEVELSMENU_H

#include <QWidget>

namespace Ui
{
    class LevelsMenu;
}

/**
 * @brief The LevelsMenu class is a designer form class that represents the levels menu.
 */

class LevelsMenu : public QWidget
{
    /// Tells the compiler that this class has gui elements
    Q_OBJECT

  private:
    /// User interface
    Ui::LevelsMenu *ui;

  public:
    /// Constructor
    explicit LevelsMenu(QWidget *parent = 0);
    /// Destructor
    ~LevelsMenu();

  signals:
    /// The user asked to return to the main menu
    void gameMenuAsked();
    /// The user asked to start playing
    void startGame(QString& mode);

  public slots:
    void mode();
};

#endif // LEVELSMENU_H
