#ifndef JSONMODEL_H
#define JSONMODEL_H

#include <QAbstractTableModel>
#include "jsonable.h"

// Adapter

class JSONModel : public QAbstractTableModel {
private:
    QList<JSONAble*> m_data;
    int m_selectedIndex;
public:
    JSONModel(QList<JSONAble*> data, QObject *parent = nullptr);
    void setSourceData(QList<JSONAble*> data);

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
};

#endif // JSONMODEL_H
