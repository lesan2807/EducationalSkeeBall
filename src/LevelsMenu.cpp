#include "LevelsMenu.h"
#include "ui_LevelsMenu.h"

LevelsMenu::LevelsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelsMenu)
{
    ui->setupUi(this);
    this->connect( ui->exitButton, &QPushButton::clicked, parent, &QWidget::close );
    this->connect( ui->returnButtton, &QPushButton::clicked, this, &LevelsMenu::gameMenuAsked );
}

LevelsMenu::~LevelsMenu()
{
    delete ui;
}
