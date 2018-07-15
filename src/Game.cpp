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
    this->mainWindow = new MainWindow();
    mainWindow->show();

    return this->exec();
}
