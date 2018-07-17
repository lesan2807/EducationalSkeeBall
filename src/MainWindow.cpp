#include <QDesktopWidget>

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
    this->setWindowTitle("Angular Skee-Ball");
}

void MainWindow::showGameMenu()
{
    GameMenuView* gameMenuView = new GameMenuView(this);
    this->connect( gameMenuView, &GameMenuView::gameLevelsAsked, this, &MainWindow::showLevelsMenu );
    this->setCentralWidget(gameMenuView);
}

void MainWindow::showLevelsMenu()
{
    LevelsMenu* levels = new LevelsMenu(this);
    this->connect( levels, &LevelsMenu::gameMenuAsked, this, &MainWindow::showGameMenu );
    this->setCentralWidget(levels);
}
