#include "jsonmodel.h"
#include <QDebug>

JSONModel::JSONModel(QList<QJsonObject> data, QObject *parent) : QAbstractTableModel(parent), m_data(data){

}

void JSONModel::setData(QList<QJsonObject> data){
    int rows = rowCount();
    int cols = columnCount();
    m_data = data;
    rows -= rowCount();
    cols -= columnCount();
    qDebug()<<"cols: "<<cols;
    if(cols < 0){
        beginInsertColumns(QModelIndex(), 0, -(cols+1));
        endInsertColumns();
    }
    else if(cols > 0){
        beginRemoveColumns(QModelIndex(), 0, cols-1);
        endRemoveColumns();
    }
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
    qDebug()<<"Działa?"<<rowCount()<<columnCount();
}

int JSONModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.size();
}

int JSONModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.isEmpty() ? 0 : m_data.first().keys().size();
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
