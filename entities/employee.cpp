#include "employee.h"

Employee::Employee(int id, QString name, QString surname, double hourlyRate, int hourCount, int departmentId)
    : m_id(id), m_name(name), m_surname(surname), m_hourlyRate(hourlyRate), m_hourCount(hourCount),
      m_departmentId(departmentId){

}

bool Employee::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("name")) return false;
    if(!json.contains("surname")) return false;
    if(!json.contains("hourly_rate")) return false;
    if(!json.contains("hour_count")) return false;
    if(!json.contains("department_id")) return false;
    return true;
}

QVariantMap Employee::valuesMap(){
    QVariantMap values;
    values.insert("id", m_id);
    values.insert("name", m_name);
    values.insert("surname", m_surname);
    values.insert("hourly_rate", m_hourlyRate);
    values.insert("hour_count", m_hourCount);
    values.insert("department_id", m_departmentId);
    return values;
}

void Employee::setValuesMap(QVariantMap values){
    m_id = values.value("id").toInt();
    m_name = values.value("name").toString();
    m_surname = values.value("surname").toString();
    m_hourlyRate = values.value("hourly_rate").toDouble();
    m_hourCount = values.value("hour_count").toInt();
    m_departmentId = values.value("department_id").toInt();
}

int Employee::id() const {
    return m_id;
}

void Employee::setId(int id){
    m_id = id;
}

QString Employee::name() const {
    return m_name;
}

void Employee::setName(const QString &name){
    m_name = name;
}

QString Employee::surname() const {
    return m_surname;
}

void Employee::setSurname(const QString &surname){
    m_surname = surname;
}

double Employee::hourlyRate() const {
    return m_hourlyRate;
}

void Employee::setHourlyRate(double hourlyRate){
    m_hourlyRate = hourlyRate;
}

int Employee::hourCount() const {
    return m_hourCount;
}

void Employee::setHourCount(int hourCount){
    m_hourCount = hourCount;
}

int Employee::departmentId() const {
    return m_departmentId;
}

void Employee::setDepartmentId(int departmentId){
    m_departmentId = departmentId;
}
