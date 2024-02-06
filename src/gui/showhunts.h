#ifndef SHOWHUNTS_H
#define SHOWHUNTS_H

#include <QDialog>

namespace Ui {
class ShowHunts;
}

class ShowHunts : public QDialog
{
    Q_OBJECT

public:
    explicit ShowHunts(QWidget *parent = nullptr);
    ~ShowHunts();

private:
    Ui::ShowHunts *ui;
};

#endif // SHOWHUNTS_H
