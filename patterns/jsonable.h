#ifndef JSONABLE_H
#define JSONABLE_H

#include <QJsonObject>
#include <QMap>
#include <QVariant>
#include <QString>

// Metoda szablonowa

class JSONAble {
protected:
    virtual bool validate(QJsonObject json) = 0;
    virtual QMap<QString, QVariant> valuesMap() = 0;
    virtual void setValuesMap(QMap<QString, QVariant> values) = 0;
public:
    virtual ~JSONAble();
    bool fromJSON(QJsonObject json);
    QJsonObject toJSON();
};

#endif // JSONABLE_H
