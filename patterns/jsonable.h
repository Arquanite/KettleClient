#ifndef JSONABLE_H
#define JSONABLE_H

#include <QJsonObject>
#include <QVariantMap>
#include <QString>

// Metoda szablonowa

class JSONAble {
protected:
    virtual bool validate(QJsonObject json) = 0;
    virtual QVariantMap valuesMap() = 0;
    virtual void setValuesMap(QVariantMap values) = 0;
    JSONAble() { }
public:
    virtual ~JSONAble();
    bool fromJSON(QJsonObject json);
    QJsonObject toJSON();
};

#endif // JSONABLE_H
