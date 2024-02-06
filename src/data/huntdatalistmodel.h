#ifndef HUNTDATALISTMODEL_H
#define HUNTDATALISTMODEL_H

#include <QAbstractListModel>
#include <QVariant>

class HuntDataListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    HuntDataListModel();
    void SetHuntDataList();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


};

#endif // HUNTDATALISTMODEL_H
