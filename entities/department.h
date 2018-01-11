#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "jsonable.h"

class Department : public JSONAble {
protected:
    int m_id;
    QString m_name;
public:
    Department(int id, QString name);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QMap<QString, QVariant> valuesMap() override;
    void setValuesMap(QMap<QString, QVariant> values) override;
};

#endif // DEPARTMENT_H
