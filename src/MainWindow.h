#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum class GameState
{
    /// Starting state
    unknown,
    /// The game menu is opened
    gameMenu,
    /// The levels menu is opened
    gameLevelsMenu,
    /// The user is playing
    gameStart,
};

class MainWindow : public QMainWindow
{
    /// Tells the compiler that this class has gui elements
    Q_OBJECT
    /// Disables the option of copying objects of this class
    Q_DISABLE_COPY(MainWindow)

  private:
    /// Game starts with state 0: unknown
    GameState state = GameState::unknown;

  public:
    /// Constructor
    explicit MainWindow(QWidget* parent = nullptr);
    /// Destructor
    ~MainWindow();
    /// builds the interface
    void buildInterface();

  public slots:
    /// Shows game menu
    void showGameMenu();
    /// Shows levels menu
    void showLevelsMenu();
    /// show Start Level
    void showLevelStart();
};

#endif // MAINWINDOW_H
