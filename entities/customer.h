#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "jsonable.h"

class Customer : public JSONAble {
protected:
    int m_id;
    QString m_name;
    QString m_address;
    QString m_nip;
public:
    Customer(int id, QString name, QString address, QString nip);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QString address() const;
    void setAddress(const QString &address);

    QString nip() const;
    void setNip(const QString &nip);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QVariantMap valuesMap() override;
    void setValuesMap(QVariantMap values) override;
};

#endif // CUSTOMER_H
