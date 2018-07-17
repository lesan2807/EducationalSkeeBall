#include <QGraphicsView>
#include "Game.h"
#include "MainWindow.h"

Game::Game(int& argc, char* argv[])
    : QApplication(argc, argv)
{
}

Game::~Game()
{
    delete this->mainWindow;
}

int Game::run()
{
    // shows Main Window
    this->mainWindow = new MainWindow();
    mainWindow->show();

    return this->exec();
}
