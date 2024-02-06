#include "showhunts.h"
#include "ui_showhunts.h"

ShowHunts::ShowHunts(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowHunts)
{
    ui->setupUi(this);
}

ShowHunts::~ShowHunts()
{
    delete ui;
}
