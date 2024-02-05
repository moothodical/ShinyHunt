#include "huntwindow.h"
#include "ui_huntwindow.h"

HuntWindow::HuntWindow(const HuntData& huntData, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::HuntWindow),
    huntData(huntData)
{
    ui->setupUi(this);
    setWidgetValues();
    ui->encountersLabel->setFocus();
}

HuntWindow::~HuntWindow()
{
    delete ui;
}

void HuntWindow::setWidgetValues()
{
    ui->pokemonLabel->setText(huntData.GetPokemonName());
    ui->gameLabel->setText(huntData.GetGame());
    ui->methodLabel->setText(huntData.GetMethod());
    ui->oddsLabel->setText(QString::number(huntData.GetOdds()));
    ui->incrementSpinBox->setValue(1);
}

void HuntWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        huntData.Increment(ui->incrementSpinBox->value());
        ui->encountersLabel->setText(QString::number(huntData.GetCurrentEncounters()));
    }
}


void HuntWindow::on_incrementSpinBox_valueChanged(int arg1)
{

}



void HuntWindow::on_targetButton_clicked()
{

}


void HuntWindow::on_phaseButton_clicked()
{

}

