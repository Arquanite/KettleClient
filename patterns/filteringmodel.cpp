#include "filteringmodel.h"

FilteringModel::FilteringModel(JSONModel *sourceModel, QObject *parent) : QAbstractTableModel(parent), m_model(sourceModel){

}

void FilteringModel::filter(int columnNumber, QString text){

}

int FilteringModel::rowCount(const QModelIndex &parent) const {

}

int FilteringModel::columnCount(const QModelIndex &parent) const {

}

QVariant FilteringModel::data(const QModelIndex &index, int role) const {

}
