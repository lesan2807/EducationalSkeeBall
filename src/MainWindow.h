#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum class GameState
{
    unknown,
    gameMenu,
    gameLevelsMenu,
    gameStart,
    gamePlay

};

class MainWindow : public QMainWindow
{
    Q_OBJECT
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
    void showGameMenu();
    void showLevelsMenu();
    void showLevelStart();
};

#endif // MAINWINDOW_H
