#ifndef PRODUCT_H
#define PRODUCT_H

#include "jsonable.h"
#include "part.h"

class Product : public JSONAble {
    class Builder;
protected:
    int m_id;
    QString m_name;
    QList<Part> m_parts;

    Product(int id, QString name, QList<Part> parts);

public:
    static Builder builder(int id, QString name);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QList<Part> parts() const;
    void setParts(const QList<Part> &parts);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QVariantMap valuesMap() override;
    void setValuesMap(QVariantMap values) override;
};

class Product::Builder {
    int m_id;
    QString m_name;
    QList<Part> m_parts;

public:
    Builder(int id, QString name);
    Builder& addPart(Part p);
    Product build();
};
#endif // PRODUCT_H
