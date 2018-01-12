#ifndef ORDER_H
#define ORDER_H

#include "jsonable.h"
#include "product.h"

class Order : public JSONAble {
    class Builder;
protected:
    int m_id;
    int m_customerId;
    QString m_date;
    QList<Product> m_products;

    Order(int id, int customerId, QString date, QList<Product> products);
public:
    static Builder builder(int id, int customerId, QString date);

    int id() const;
    void setId(int id);

    int customerId() const;
    void setCustomerId(int customerId);

    QString date() const;
    void setDate(const QString &date);

    QList<Product> products() const;
    void setProducts(const QList<Product> &products);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QVariantMap valuesMap() override;
    void setValuesMap(QVariantMap values) override;
};

class Order::Builder {
    int m_id;
    int m_customerId;
    QString m_date;
    QList<Product> m_products;

public:
    Builder(int id, int customerId, QString date);
    Builder& addProduct(Product p);
    Order build();
};

#endif // ORDER_H
