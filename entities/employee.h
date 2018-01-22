#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "jsonable.h"

class Employee : public JSONAble {
protected:
    int m_id;
    QString m_name;
    QString m_surname;
    double m_hourlyRate;
    int m_hourCount;
    int m_departmentId;
public:
    Employee(int id, QString name, QString surname, double hourlyRate, int hourCount, int departmentId);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QString surname() const;
    void setSurname(const QString &surname);

    double hourlyRate() const;
    void setHourlyRate(double hourlyRate);

    int hourCount() const;
    void setHourCount(int hourCount);

    int departmentId() const;
    void setDepartmentId(int departmentId);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QVariantMap valuesMap() override;
    void setValuesMap(QVariantMap values) override;
};

#endif // EMPLOYEE_H
