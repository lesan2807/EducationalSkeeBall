#include <QDesktopWidget>

#include "MainWindow.h"
#include "LevelStart.h"
#include "GameMenuView.h"
#include "LevelsMenu.h"
#include "ui_GameMenuView.h"
#include "ui_LevelsMenu.h"
#include "ui_LevelStart.h"
#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /// Sets the window`s size and title
    this->buildInterface();
    /// Starts the game by opening the main menu
    this->showGameMenu();
    /// Set window size
    this->resize(800,500);
}

MainWindow::~MainWindow()
{
}

void MainWindow::buildInterface()
{
    /// sets the window title to "Angular Skee-Ball"
    this->setWindowTitle("Angular Skee-Ball");

    /// For desktop, resize the main  window
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->resize(480, 320);
  #endif
}

void MainWindow::showGameMenu()
{
    /// Show the game menu to select between start, levels or exit
    GameMenuView* gameMenuView = new GameMenuView(this);
    this->setCentralWidget(gameMenuView);
    /// Show the levels menu if the Levels button is pressed
    this->connect( gameMenuView, &GameMenuView::gameLevelsAsked, this, &MainWindow::showLevelsMenu );
    /// Show the Initial Level if the Start button is pressed
    this->connect( gameMenuView, &GameMenuView::startGameAsked, this, &MainWindow::showLevelStart );

    /// Now the application is in game menu state
    this->state = GameState::gameMenu;
}

void MainWindow::showLevelsMenu()
{
    /// Show the level map to select which levels are avaliable to play
    LevelsMenu* levels = new LevelsMenu(this);
    this->setCentralWidget(levels);
    /// Returns to the menu if return is pressed
    this->connect( levels, &LevelsMenu::gameMenuAsked, this, &MainWindow::showGameMenu );
    /// Shows the level corresponding if a level button is pressed
    this->connect( levels, &LevelsMenu::startGame, this, &MainWindow::showLevelStart );

    /// Now the application  is in level menu state
    this->state = GameState::gameLevelsMenu;
}

void MainWindow::showLevelStart()
{
    /*/// Get the name of the object that sended the signal
    QString name = QObject::sender()->objectName();
    //QString mode;
    /// If the signal to start playig was sent by the LevelsMenu, the mode can be either Radians or Degrees
    if( name == "LevelsMenu" )
        mode = "Radians or Degrees";
    /// If the signal to start playing was sent by the GameMenuVie, the mode is Degrees
   if( name == "GameMenuView" )
        mode = "Degrees";*/
    /// Show the starting level
    LevelStart* start = new LevelStart(this);
    this->setCentralWidget(start);
    /// Tells the level which mode the user chose
    start->buildLevel(1);
    /// Return to the menu if the Menu button is pressed
    this->connect( start,  &LevelStart::gameMenuAsked, this, &MainWindow::showGameMenu );
    /// Return to the menu if the Return button is pressed
    this->connect( start, &LevelStart::gameLevelsAsked, this, &MainWindow::showLevelsMenu );

    /// Now the application is in start level state
    this->state = GameState::gameStart;
}
