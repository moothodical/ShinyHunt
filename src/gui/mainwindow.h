#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QSharedPointer>

#include "../data/huntdata.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool UserHuntsFileExists();
    bool EnsureUserFilesDirExists();
    bool CopyFileToUserDir(const QString& filePath);
    QList<QSharedPointer<HuntData>> ParseUserFile(const QString& filePath);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void userFileParsed();
    void huntChosen();

private slots:
    void on_newHuntButton_clicked();
    void on_continueHuntButton_clicked();
    void OnUserFileParsed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
