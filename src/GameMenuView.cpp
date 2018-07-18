#include "GameMenuView.h"
#include "LevelStart.h"
#include "LevelsMenu.h"
#include "MainWindow.h"
#include "ui_GameMenuView.h"
#include "ui_LevelsMenu.h"
#include "ui_LevelStart.h"

GameMenuView::GameMenuView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameMenuView)
{
    /// Set the user interface as the game menu
    ui->setupUi(this);
    /// When Exit button is clicked, close the menu
    this->connect( ui->exitButton, &QPushButton::clicked, parent, &QWidget::close );
    /// When Levels button is clicked, show the Game Level Menu
    this->connect( ui->levelsButton, &QPushButton::clicked, this, &GameMenuView::gameLevelsAsked );
    /// When Start button is clicked, start the game with the initial level
    this->connect( ui->startButton, &QPushButton::clicked, this, &GameMenuView::startGameAsked );
}

GameMenuView::~GameMenuView()
{
    /// Delete the user interface
    delete ui;
}
