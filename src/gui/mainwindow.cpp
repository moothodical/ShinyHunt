#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newhuntwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QTextStream>

static QString userFilesPath = QCoreApplication::applicationDirPath() + "/userfiles/";
static QString userFileName = "hunts.csv";
static QString userHuntsFile = userFilesPath + userFileName;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::userFileParsed, this, &MainWindow::OnUserFileParsed);
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
    // Check if there is already a user supplied hunts.csv
    if (UserHuntsFileExists())
    {
        ParseUserFile(userHuntsFile);
        return;
    }

    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*)"));

    if (!filePath.isEmpty())
    {
        if (EnsureUserFilesDirExists() && CopyFileToUserDir(filePath))
        {
            ParseUserFile(filePath);
        }
        else
        {
            qDebug() << "There was an error!";
        }
    }
}

bool MainWindow::UserHuntsFileExists()
{
    QFile huntsFile(userHuntsFile);
    bool exists = QFile::exists(userHuntsFile);
    return exists;
}

bool MainWindow:: EnsureUserFilesDirExists()
{
    QDir userFilesDir(userFilesPath);

    if (!userFilesDir.exists())
    {
        return userFilesDir.mkpath(".");
    }
    return true;
}

bool MainWindow::CopyFileToUserDir(const QString& filePath)
{
    QString destinationPath = userFilesPath + QFileInfo(filePath).fileName();
    QFile sourceFile(filePath);
    QFile destinationFile(destinationPath);
    return sourceFile.copy(destinationPath);
}

QList<QSharedPointer<HuntData>> MainWindow::ParseUserFile(const QString& filePath)
{
    QList<QSharedPointer<HuntData>> hunts;
    QFile huntsFile(filePath);

    if (huntsFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&huntsFile);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList fields = line.split(",");

            // parsing values
            QString pokemonName(fields.at(0));
            QString gameName(fields.at(1));
            QString method(fields.at(2));
            int odds = fields.at(3).toInt();
            int encounters = fields.at(4).toInt();

            HuntData* huntData = new HuntData(pokemonName, gameName, method, odds, encounters);
            QSharedPointer<HuntData> sharedHuntData(huntData);
            hunts.append(sharedHuntData);
        }
        huntsFile.close();
      }
    emit userFileParsed();
    return hunts;
}

void MainWindow::OnUserFileParsed()
{
    qDebug () << "You have reached the part where the user file signal has parsed";
}



