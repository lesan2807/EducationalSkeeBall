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
    this->buildInterface();
    this->showGameMenu();
}

MainWindow::~MainWindow()
{
}

void MainWindow::buildInterface()
{
    // sets the window title to "Angular Skee-Ball"
    this->setWindowTitle("Angular Skee-Ball");

    // For desktop, resize the main  window
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->resize(480, 320);
  #endif
}

void MainWindow::showGameMenu()
{
    this->resize(400,300);
    // Show the game menu to select between start, levels or exit
    GameMenuView* gameMenuView = new GameMenuView(this);
    // Show the levels menu if the Levels button is pressed
    this->connect( gameMenuView, &GameMenuView::gameLevelsAsked, this, &MainWindow::showLevelsMenu );
    // Show the Initial Level if the Start button is pressed
    this->connect( gameMenuView, &GameMenuView::startGameAsked, this, &MainWindow::showLevelStart );
    this->setCentralWidget(gameMenuView);

    // Now the application is in game menu state
    this->state = GameState::gameMenu;
}

void MainWindow::showLevelsMenu()
{
    // Show the level map to select which levels are avaliable to play
    LevelsMenu* levels = new LevelsMenu(this);
    // Returns to the menu if return is pressed
    this->connect( levels, &LevelsMenu::gameMenuAsked, this, &MainWindow::showGameMenu );
    this->setCentralWidget(levels);

    // Now the application  is in level menu state
    this->state = GameState::gameLevelsMenu;
}

void MainWindow::showLevelStart()
{
    // Show the starting level
    this->resize(635,500);
    LevelStart* start = new LevelStart(this);
    // Return to the menu if the Menu button is pressed
    this->connect( start ,  &LevelStart::gameMenuAsked, this, &MainWindow::showGameMenu );
    this->setCentralWidget(start);

    // Now the application is in start level state
    this->state = GameState::gameStart;
}
