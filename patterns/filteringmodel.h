#ifndef FILTERINGMODEL_H
#define FILTERINGMODEL_H

#include <QAbstractTableModel>
#include "jsonmodel.h"
// Dekorator

class FilteringModel : public QAbstractTableModel {
    JSONModel *m_model;
    QList<JSONAble*> m_data;
public:
    FilteringModel(JSONModel *sourceModel, QObject *parent);
    void filter(int columnNumber, QString text);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
};

#endif // FILTERINGMODEL_H
