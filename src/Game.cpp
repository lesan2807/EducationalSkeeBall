#include <QGraphicsView>
#include <QDomDocument>
#include <iostream>
#include <QFile>

#include "Game.h"
#include "MainWindow.h"
#include "Level.h"


Game::Game(int& argc, char* argv[])
    : QApplication(argc, argv)
{
}

Game::~Game()
{
    /// Deletes the main window of the game
    delete this->mainWindow;
    /// Deletes the levels created
    for ( int index = 0; index < this->levels.size(); ++index )
        delete this->levels[index];
}

int Game::run()
{
    if ( int result = this->loadLevels() )
        return result;
    /// shows Main Window
    this->mainWindow = new MainWindow();
    mainWindow->show();

    return this->exec();
}

int Game::loadLevels()
{
    // Open the AngularSkeeBall file as a Qt resource
    const char* const filename = ":/AngularSkeeBall.xml";
    QFile file(filename);
    if ( ! file.open(QIODevice::ReadOnly) )
        return std::cerr << "AngularSkeeBall: could not open " << filename << std::endl, 2;

    // Parse the AngularSkeeBall file as an XML document
    QDomDocument document("skeeball");
    if ( ! document.setContent( &file ) )
    {
        file.close();
        return std::cerr << "AngularSkeeBall: invalid level files " << filename << std::endl, 3;
    }
    file.close();

    // Load each question from the document and fill the questions array
    return loadLevels(document.documentElement());

}

int Game::loadLevels(const QDomElement &rootElement)
{
    // Load each level from the document
    for ( QDomElement element = rootElement.firstChildElement(); ! element.isNull(); element = element.nextSiblingElement() )
    {
        // Only <level> elements are allowed to be children of the <skeeball> root element
        if ( element.tagName() == "level" )
        {
            const int& number = element.attribute("number").toInt();
            const int& score = element.attribute("score").toInt();
            // Use the type attribute required to create a level object
            Level* level = new Level(this->mainWindow, number, score);

            // If the Level is created, load the rest of the level from the element
            if ( level )
            {
                if ( level->loadFrom(element) )
                    this->levels.push_back( level );
                else
                    std::cerr << "AngularSkeeBall: invalid level at line " << element.lineNumber() << std::endl;
            }
            else
                return std::cerr << "AngularSkeeBall: invalid level " << number << std::endl, 3;
        }
        else
        {
            return std::cerr << "AngularSkeeBall: invalid element type " << qPrintable(element.tagName()) << std::endl, 4;
        }
    }
    return 0;
}

void Game::loadLevel(int level)
{
    //levels[level]->load();
}
