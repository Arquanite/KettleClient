#ifndef PRODUCT_H
#define PRODUCT_H

#include "jsonable.h"
#include "part.h"

class Product : public JSONAble {
protected:
    int m_id;
    QString m_name;
    QList<class Part> m_parts;

    Product(); // TODO something with this :u
public:

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QList<class Part> parts() const;
    void setParts(const QList<class Part> &parts);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QMap<QString, QVariant> valuesMap() override;
    void setValuesMap(QMap<QString, QVariant> values) override;
};

#endif // PRODUCT_H
