#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}