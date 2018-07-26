#ifndef GAME_H
#define GAME_H

#include <QApplication> 
#include <QVector>

// Forward declarations
class MainWindow;
class Level;
class QDomElement;

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
    /// Levels
    QVector<Level*> levels;

  public:
    /// Constructor
    Game(int& argc, char* argv[]);
    /// Destructor
    ~Game();
    /// Call this method instead of exec()
    int run();
    /// Play the given filename as background music
    // void playBackgroundMusic(const QString& audioFilename);
  private:
    /// Load levels
    int loadLevels();
    int loadLevels(const QDomElement& rootElement);
    /// Load specific level
    void loadLevel(int level);


};

#endif // GAME_H
