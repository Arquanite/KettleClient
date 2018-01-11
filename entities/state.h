#ifndef STATE_H
#define STATE_H

#include "jsonable.h"

class State : public JSONAble {
protected:
    int m_id;
    QString m_name;
    int m_departmentId;
public:
    State(int id, QString name, int departmentId);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    int departmentId() const;
    void setDepartmentId(int departmentId);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QMap<QString, QVariant> valuesMap() override;
    void setValuesMap(QMap<QString, QVariant> values) override;
};

#endif // STATE_H
