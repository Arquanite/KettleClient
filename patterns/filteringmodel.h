#ifndef FILTERINGMODEL_H
#define FILTERINGMODEL_H

#include <QAbstractTableModel>
#include "jsonable.h"
// Dekorator

class FilteringModel : public QAbstractTableModel {
    QList<JSONAble*> m_data;
public:
    FilteringModel(QAbstractTableModel *sourceModel, QObject *parent);
    void filter(int columnNumber, QString text);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
};

#endif // FILTERINGMODEL_H
