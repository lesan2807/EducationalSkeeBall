#include "LevelsMenu.h"
#include "ui_LevelsMenu.h"

LevelsMenu::LevelsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelsMenu)
{
    /// Set the levels menu as the user interface
    ui->setupUi(this);
    /// Closes when exit button is clicked
    this->connect( ui->exitButton, &QPushButton::clicked, parent, &QWidget::close );
    /// Returns to the menu when the return button is clicked
    this->connect( ui->returnButtton, &QPushButton::clicked, this, &LevelsMenu::gameMenuAsked );

    /// All the level buttons alows the user to start playing
    this->connect( ui->degreesLvl1, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl2, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl3, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl4, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl5, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl6, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl7, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl8, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl9, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->degreesLvl10, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl1, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl2, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl3, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl4, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl5, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl6, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl7, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl8, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl9, &QPushButton::clicked, this, &LevelsMenu::mode );
    this->connect( ui->radiansLvl10, &QPushButton::clicked, this, &LevelsMenu::mode );
}

LevelsMenu::~LevelsMenu()
{
    /// Delete the user interface
    delete ui;
}

void LevelsMenu::mode()
{
    QString nombre = sender()->objectName();
    emit startGame(nombre);
}


