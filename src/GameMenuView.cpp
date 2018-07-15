#include "GameMenuView.h"
#include "LevelsMenu.h"
#include "ui_GameMenuView.h"
#include "ui_LevelsMenu.h"

GameMenuView::GameMenuView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameMenuView)
{
    ui->setupUi(this);
    this->connect( ui->exitButton, &QPushButton::clicked, parent, &QWidget::close );
}

GameMenuView::~GameMenuView()
{
    delete ui;
}
