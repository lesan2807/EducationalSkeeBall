#include "GameMenuView.h"
#include "LevelsMenu.h"
#include "MainWindow.h"
#include "ui_GameMenuView.h"
#include "ui_LevelsMenu.h"

GameMenuView::GameMenuView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameMenuView)
{
    ui->setupUi(this);
    // When Exit button is clicked, close the menu
    this->connect( ui->exitButton, &QPushButton::clicked, parent, &QWidget::close );
<<<<<<< HEAD
    // When Levels button is clicked, show the Game Level Menu
    this->connect( ui->levelsButton, &QPushButton::clicked, this, &GameMenuView::gameLevelsAsked );
    // When Start button is clicked, start the game with the initial level
    this->connect( ui->startButton, &QPushButton::clicked, this, &GameMenuView::startGame );
=======
    this->connect( ui->levelsButton, &QPushButton::clicked, this, &GameMenuView::gameLevelsAsked );
>>>>>>> 23aacbd4bfaffdd378713347bcb78807016c91ba
}

GameMenuView::~GameMenuView()
{
    delete ui;
}
