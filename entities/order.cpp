#include "order.h"

Order::Order(){
    // TODO implement me
}

bool Order::validate(QJsonObject json){
    // TODO implement me
}

QMap<QString, QVariant> Order::valuesMap(){
    // TODO implement me
}

void Order::setValuesMap(QMap<QString, QVariant> values){
    // TODO implement me
}

int Order::id() const {
    return m_id;
}

void Order::setId(int id){
    m_id = id;
}

int Order::customerId() const {
    return m_customerId;
}

void Order::setCustomerId(int customerId){
    m_customerId = customerId;
}

QString Order::date() const {
    return m_date;
}

void Order::setDate(const QString &date){
    m_date = date;
}

QList<Product> Order::products() const {
    return m_products;
}

void Order::setProducts(const QList<Product> &products){
    m_products = products;
}
