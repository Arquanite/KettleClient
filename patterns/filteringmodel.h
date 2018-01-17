#ifndef FILTERINGMODEL_H
#define FILTERINGMODEL_H

#include "jsonmodel.h"
// Dekorator

class FilteringModel : public JSONModel {
    JSONModel *m_model;
    int m_number = 0;
    QString m_filter;
public:
    FilteringModel(JSONModel *sourceModel, QObject *parent);
    void filter(int columnNumber, QString text);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void reload();
};

#endif // FILTERINGMODEL_H
