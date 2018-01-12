#include "order.h"

Order::Order(int id, int customerId, QString date, QList<Product> products)
    : m_id(id), m_customerId(customerId), m_date(date), m_products(products){

}

Order::Builder Order::builder(int id, int customerId, QString date){
    return Builder(id, customerId, date);
}

bool Order::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("customer_id")) return false;
    if(!json.contains("date")) return false;
    if(!json.contains("products")) return false;
    return true;
}

QVariantMap Order::valuesMap(){
    QVariantMap values;
    values.insert("id", m_id);
    values.insert("customer_id", m_customerId);
    values.insert("date", m_date);
    QList<QVariant> products;
    for(Product p : m_products) products.append(p.toJSON());
    values.insert("products", products);
    return values;
}

void Order::setValuesMap(QVariantMap values){
    m_id = values.value("id").toInt();
    m_customerId = values.value("customer_id").toInt();
    m_date = values.value("date").toString();
    QList<QVariant> products = values.values("products");
    for(QVariant p : products){
        Product product = Product::builder(0, "").build();
        product.fromJSON(p.toJsonObject());
        m_products.append(product);
    }
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

Order::Builder::Builder(int id, int customerId, QString date) : m_id(id), m_customerId(customerId), m_date(date){

}

Order::Builder &Order::Builder::addProduct(Product p){
    m_products.append(p);
    return *this;
}

Order Order::Builder::build(){
    return Order(m_id, m_customerId, m_date, m_products);
}
