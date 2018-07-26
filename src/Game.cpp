#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "Game.h"
#include "MainWindow.h"
#include "LevelStart.h"
#include "ui_LevelStart.h"
#include <QFile>
#include "Level.h"
#include <iostream>

Game::Game(int& argc, char* argv[])
    : QApplication(argc, argv)
{
}

Game::~Game()
{
    for(long long index = 0; index < levels.size(); ++ index)
        delete levels[index];
    /// Deletes the main window of the game
    delete this->mainWindow;
}

int Game::run()
{
    if ( int result = this->loadLevels() )
        return result;
    std::cerr << "levels loaded"  <<std::endl;
    /// shows Main Window
    this->mainWindow = new MainWindow();
    mainWindow->show();

    /// Play background music
    playBackgroundMusic("game.mp3");


    return this->exec();
}

void Game::playBackgroundMusic(const QString& audioFilename)
{
    /// We add the sound to a playlist
    QMediaPlaylist* playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/" + audioFilename));

    /// We add the playlist to a media player object
    QMediaPlayer* mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setPlaylist(playlist);

    /// Play the playlist in an infinite loop
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    /// Set half of the volume and start playing the background music
    mediaPlayer->setVolume(50);
    mediaPlayer->play();
}

int Game::loadLevels()
{
    /// Open the levels file as a Qt resource
    const char* const filename = ":/AngularSkeeBall.xml";
    QFile file(filename);
    if( !file.open(QIODevice::ReadOnly) )
        return 2;

    /// Parse the levels file as an XML document
    QDomDocument document("levels");
    if( !document.setContent( &file ) )
    {
        file.close();
        return 3;
    }
    file.close();

    /// Load each level´s hole from the document and fill the holes array
    return loadHoles(document.documentElement());
}

#include "BigHole.h"
#include "SmallHole.h"
#include "MediumHole.h"

int Game::loadHoles(const QDomElement &rootElement)
{
    int level;
    int score;
    QMap<int,QVector<Hole*>>::iterator it;
    //ui->DegreeOrRadian->setText(rootElement.tagName());
    /// Load each level from the document
    for( QDomElement element = rootElement.firstChildElement(); !element.isNull(); element = element.nextSiblingElement() )
    {
        //ui->DegreeOrRadian->setText(element.tagName());
        if( element.tagName() == "level" )
        {
            /// Use the type attribute required to create a question object
            const QString& number = element.attribute("number");
            const QString& points = element.attribute("score");
            level = number.toInt();
            score = points.toInt();
            Level* newLevel = new Level(mainWindow, level, score);
            levels.append(newLevel);
        }
        if( element.tagName() == "hole" )
        {
            //ui->DegreeOrRadian->setText(element.tagName());
            const QString& type = element.attribute("type");
            double x = element.attribute("x").toDouble();
            double y = element.attribute("y").toDouble();
            if( type == "big" )
            {
                Hole* hole = new BigHole(x,y);
                it.value().push_back(hole);
            }
            if( type == "medium" )
            {
                Hole* hole = new MediumHole(x,y);
                //while( (it = levels.find(level)) == levels.end() )
                //    levels.insert(level,vector);
                it.value().push_back(hole);
            }
            if( type == "small" )
            {
                Hole* hole = new SmallHole(x,y);
                //while( (it = levels.find(level)) == levels.end() )
                //    levels.insert(level,vector);
                it.value().push_back(hole);
            }
        }
    }
    return 0;
}

