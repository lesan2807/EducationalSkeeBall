#ifndef GAME_H
#define GAME_H

#include <QApplication>

class MainWindow;

/**
    Game controller. An object that represents the game.
*/

class Game : public QApplication
{
    Q_DISABLE_COPY(Game)

  private:
    /// Main Window:
    MainWindow* mainWindow = nullptr;


  public:
    /// Constructor
    Game(int& argc, char* argv[]);
    /// Destructor
    ~Game();
    /// Call this method instead of exec()
    int run();
    /// Play the given filename as background music
    // void playBackgroundMusic(const QString& audioFilename);


};

#endif // GAME_H
