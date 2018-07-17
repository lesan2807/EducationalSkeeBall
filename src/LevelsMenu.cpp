#include "LevelsMenu.h"
#include "ui_LevelsMenu.h"

LevelsMenu::LevelsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelsMenu)
{
    ui->setupUi(this);
    // Closes when exit button is clicked
    this->connect( ui->exitButton, &QPushButton::clicked, parent, &QWidget::close );
    // Returns to the menu when the return button is clicked
    this->connect( ui->returnButtton, &QPushButton::clicked, this, &LevelsMenu::gameMenuAsked );
}

LevelsMenu::~LevelsMenu()
{
    delete ui;
}


