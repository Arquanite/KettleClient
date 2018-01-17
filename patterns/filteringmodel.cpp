#include "filteringmodel.h"
#include <QRegularExpression>

#include "ascendingstrategy.h"
#include "descendingstrategy.h"

#include <QString>

#include "pdebug.h"

FilteringModel::FilteringModel(JSONModel *sourceModel, QObject *parent) : JSONModel(QList<JSONAble*>(), new AscendingStrategy(), new DescendingStrategy(), parent), m_model(sourceModel){

}

void FilteringModel::filter(int columnNumber, QString text){
    m_number = columnNumber;
    m_filter = text;
    int rows = rowCount();
    int cols = columnCount();
    if(text.size() > 0){
        QRegularExpression regex(text);
        QList<JSONAble*> data = m_model->sourceData();
        m_data = QList<JSONAble*>();
        for(int i=0; i<data.size(); i++){
            QJsonObject json = data.at(i)->toJSON();
            if(regex.match(QString("%1").arg(json.value(json.keys().at(columnNumber)).toVariant().toString())).hasMatch()){
                m_data.append(data.at(i));
            }
        }
    }
    else m_data = m_model->sourceData();
    rows -= rowCount();
    cols -= columnCount();
    if(cols < 0){
        beginInsertColumns(QModelIndex(), 0, -(cols+1));
        endInsertColumns();
    }
    else if(cols > 0){
        beginRemoveColumns(QModelIndex(), 0, cols-1);
        endRemoveColumns();
    }
    if(rows < 0){
        beginInsertRows(QModelIndex(), 0, -(rows+1));
        endInsertRows();
    }
    else if(rows > 0){
        beginRemoveRows(QModelIndex(), 0, rows-1);
        endRemoveRows();
    }
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
}

int FilteringModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.size();
}

int FilteringModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.isEmpty() ? 0 : m_data.first()->toJSON().keys().size();
}

QVariant FilteringModel::data(const QModelIndex &index, int role) const {
    QJsonObject obj = m_data.at(index.row())->toJSON();
    if(role == Qt::DisplayRole) return obj.value(obj.keys().at(index.column())).toVariant();
    return QVariant();
}

QVariant FilteringModel::headerData(int section, Qt::Orientation orientation, int role) const{
    return m_model->headerData(section, orientation, role);
}

void FilteringModel::reload(){
    filter(m_number, m_filter);
}
