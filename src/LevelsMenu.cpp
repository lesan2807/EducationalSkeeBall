#include "LevelsMenu.h"
#include "ui_LevelsMenu.h"

LevelsMenu::LevelsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelsMenu)
{
    ui->setupUi(this);
}

LevelsMenu::~LevelsMenu()
{
    delete ui;
}
