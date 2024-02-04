#ifndef NEWHUNTWINDOW_H
#define NEWHUNTWINDOW_H

#include <QDialog>

#include "../data/pokemonparser.h"

namespace Ui {
class NewHuntWindow;
}

class NewHuntWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewHuntWindow(QWidget *parent = nullptr);
    ~NewHuntWindow();
    void Populate();

private slots:
    void on_gameComboBox_currentIndexChanged(int index);
    void on_newHuntButton_clicked();

private:
    Ui::NewHuntWindow *ui;
    void PopulatePokemonComboBox();
    void PopulateGameComboBox();
    void PopulateMethodComboBox();
};

#endif // NEWHUNTWINDOW_H
