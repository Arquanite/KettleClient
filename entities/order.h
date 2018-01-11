#ifndef ORDER_H
#define ORDER_H

#include "jsonable.h"
#include "product.h"

class Order : public JSONAble {
protected:
    int m_id;
    int m_customerId;
    QString m_date;
    QList<Product> m_products;

    Order(); // TODO something with this :u
public:

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
    QMap<QString, QVariant> valuesMap() override;
    void setValuesMap(QMap<QString, QVariant> values) override;
};

#endif // ORDER_H
