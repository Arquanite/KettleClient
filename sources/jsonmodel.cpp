#include "jsonmodel.h"

JSONModel::JSONModel(QList<QJsonObject> data, QObject *parent) : QAbstractTableModel(parent), m_data(data){

}

int JSONModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.size();
}

int JSONModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.first().keys().size();
}

QVariant JSONModel::data(const QModelIndex &index, int role) const {
    QJsonObject obj = m_data.at(index.row());
    if(role == Qt::DisplayRole) return obj.value(obj.keys().at(index.column())).toVariant();
    return QVariant();
}


QVariant JSONModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole) return m_data.first().keys().at(section);
    return QAbstractTableModel::headerData(section, orientation, role);
}
