#ifndef JSONMODEL_H
#define JSONMODEL_H

#include <QAbstractTableModel>
#include "jsonable.h"
#include "sortingstrategy.h"

// Adapter

class JSONModel : public QAbstractTableModel {
protected:
    QList<JSONAble*> m_data;
    int m_selectedIndex;
    SortingStrategy *m_asc;
    SortingStrategy *m_dsc;

public:
    JSONModel(QList<JSONAble*> data, SortingStrategy *asc, SortingStrategy *dsc, QObject *parent = nullptr);
    void setSourceData(QList<JSONAble*> data);
    QList<JSONAble*> sourceData();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    int selectedIndex() const;
    void setSelectedIndex(int selectedIndex);
    JSONAble* json(int row);
    JSONAble* currentJSON();
    void sort(int column, Qt::SortOrder order) override;
};

#endif // JSONMODEL_H
