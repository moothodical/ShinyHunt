#ifndef HUNTWINDOW_H
#define HUNTWINDOW_H

#include <QDialog>
#include <QKeyEvent>

#include "../data/huntdata.h"

namespace Ui {
class HuntWindow;
}

class HuntWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::HuntWindow *ui;
    HuntData huntData;
private:
    void setWidgetValues();

public:
    explicit HuntWindow(const HuntData& huntData, QWidget *parent = nullptr);
    ~HuntWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void on_incrementSpinBox_valueChanged(int arg1);
    void on_targetButton_clicked();
    void on_phaseButton_clicked();
};

#endif // HUNTWINDOW_H
