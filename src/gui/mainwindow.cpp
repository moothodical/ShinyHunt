#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newhuntwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newHuntButton_clicked()
{
    NewHuntWindow *newHuntWindow = new NewHuntWindow(this);
    newHuntWindow->show();
    newHuntWindow->Populate();
}


void MainWindow::on_continueHuntButton_clicked()
{

}

