#ifndef PROVIDER_H
#define PROVIDER_H

#include "jsonable.h"

class Provider : public JSONAble {
protected:
    int m_id;
    QString m_name;
    QString m_address;
public:
    Provider(int id, QString name, QString address);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QString address() const;
    void setAddress(const QString &address);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QVariantMap valuesMap() override;
    void setValuesMap(QVariantMap values) override;
};

#endif // PROVIDER_H
