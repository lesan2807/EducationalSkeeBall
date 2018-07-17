#include "MainWindow.h"
#include "LevelStart.h"
#include "GameMenuView.h"
#include "LevelsMenu.h"
#include "ui_GameMenuView.h"
#include "ui_LevelsMenu.h"
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
    // sets the window title to "Angular Seek-Ball"
    this->setWindowTitle("Angular Skee-Ball");

    // For desktop, resize the main  window
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->resize(480, 320);
  #endif
}

void MainWindow::showGameMenu()
{
    // Show the game menu to select between start, levels or exit
    GameMenuView* gameMenuView = new GameMenuView(this);
    this->connect( gameMenuView, &GameMenuView::gameLevelsAsked, this, &MainWindow::showLevelsMenu );
    this->setCentralWidget(gameMenuView);

    // Now the application is in game menu state
    this->state = GameState::gameMenu;
}

void MainWindow::showLevelsMenu()
{
    // Show the level map to select which levels are avaliable to play
    LevelsMenu* levels = new LevelsMenu(this);
    this->connect( levels, &LevelsMenu::gameMenuAsked, this, &MainWindow::showGameMenu );
    this->setCentralWidget(levels);

    // Now the application  is in level menu state
    this->state = GameState::gameLevelsMenu;
}

void MainWindow::showLevelStart()
{
    // Show the starting level
    LevelStart* start = new LevelStart(this);

    start->viewLevelStart();
    this->setCentralWidget(start);

    // Now the application is in start level state
    this->state = GameState::gameStart;
}
