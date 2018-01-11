#include "product.h"

Product::Product(){
    // TODO implement me
}

bool Product::validate(QJsonObject json){
    // TODO implement me
}

QMap<QString, QVariant> Product::valuesMap(){
    // TODO implement me
}

void Product::setValuesMap(QMap<QString, QVariant> values){
    // TODO implement me
}

int Product::id() const {
    return m_id;
}

void Product::setId(int id){
    m_id = id;
}

QString Product::name() const {
    return m_name;
}

void Product::setName(const QString &name){
    m_name = name;
}

QList<Part> Product::parts() const {
    return m_parts;
}

void Product::setParts(const QList<Part> &parts){
    m_parts = parts;
}
