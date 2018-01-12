#include "order.h"
// TODO destructor *->*
Order::Order(){
    // TODO implement me
}

bool Order::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("customer_id")) return false;
    if(!json.contains("date")) return false;
    if(!json.contains("products")) return false;
    return true;
}

QMap<QString, QVariant> Order::valuesMap(){
    QMap<QString, QVariant> values;
    values.insert("id", m_id);
    values.insert("customer_id", m_customerId);
    values.insert("date", m_date);
    QList<QVariant> products;
    for(Product p : m_products) products.append(p.toJSON());
    values.insert("products", products);
    return values;
}

void Order::setValuesMap(QMap<QString, QVariant> values){
    m_id = values.value("id").toInt();
    m_customerId = values.value("customer_id").toInt();
    m_date = values.value("date").toString();
    QList<QVariant> products = values.values("products");
    for(QVariant p : products){
        //m_products.append(new Product());
    }
    // TODO this
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
