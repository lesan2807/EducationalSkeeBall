#ifndef GAMEMENUVIEW_H
#define GAMEMENUVIEW_H

#include <QWidget>

namespace Ui
{
    class GameMenuView;
}

/**

 * @brief A designer for class that represents the game main menu.

 */

class GameMenuView : public QWidget
{
    /// Tells the compiler that this class has gui elements
    Q_OBJECT

  private:
    /// User interface
    Ui::GameMenuView *ui;

  public:
    /// Constructor
    explicit GameMenuView(QWidget* parent = nullptr);
    /// Destructor
    ~GameMenuView();

  signals:
    /// The user asked to return to the main menu
    void gameLevelsAsked();
    /// The user asked to start playing
    void startGameAsked();
};

#endif // GAMEMENUVIEW_H
