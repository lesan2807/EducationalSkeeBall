#include "MainWindow.h"
#include "GameMenuView.h"
#include "LevelsMenu.h"
#include "ui_GameMenuView.h"
#include "ui_LevelsMenu.h"

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
    this->setWindowTitle("Angular Seek-Ball");
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->resize(480, 320);
  #endif
}

void MainWindow::showGameMenu()
{
    GameMenuView* gameMenuView = new GameMenuView(this);
    this->setCentralWidget(gameMenuView);
}

void MainWindow::showLevelsMenu()
{
    LevelsMenu* levels = new LevelsMenu(this);
    this->setCentralWidget(levels);
}
