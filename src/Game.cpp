#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "Game.h"
#include "MainWindow.h"

Game::Game(int& argc, char* argv[])
    : QApplication(argc, argv)
{
}

Game::~Game()
{
    /// Deletes the main window of the game
    delete this->mainWindow;
}

int Game::run()
{
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
