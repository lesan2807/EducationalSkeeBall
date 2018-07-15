#ifndef GAME_H
#define GAME_H

#include <QApplication>

class MainWindow;

class Game : QApplication
{
    Q_DISABLE_COPY(Game)

  private:
    //int score = 0;
    MainWindow* mainWindow = nullptr;

  public:
    Game(int& argc, char* argv[]);
    ~Game();
    int run();
};

#endif // GAME_H
