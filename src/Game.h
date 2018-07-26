#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QDomElement>
#include "Hole.h"
#include "Level.h"

class MainWindow;

/**
    @brief Game controller. An object that represents the game.
*/

class Game : public QApplication
{
    /// Disables the option of copying an object od this class
    Q_DISABLE_COPY(Game)

  private:
    /// Main Window:
    MainWindow* mainWindow = nullptr;
    QVector<Level*> levels;

  public:
    /// Constructor
    Game(int& argc, char* argv[]);
    /// Destructor
    ~Game();
    /// Call this method instead of exec()
    int run();
    /// Play the given filename as background music
    void playBackgroundMusic(const QString& audioFilename);


  private:
    int loadLevels();
    int loadHoles(const QDomElement& rootElement);
    Hole* createHole(const QString& type);

 signals:


};

#endif // GAME_H
