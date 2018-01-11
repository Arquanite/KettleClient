#include "employee.h"

Employee::Employee(int id, QString name, QString surname, double hourlyRate, int hourCount, int supervisorId, int departmentId)
    : m_id(id), m_name(name), m_surname(surname), m_hourlyRate(hourlyRate), m_hourCount(hourCount),
      m_supervisorId(supervisorId), m_departmentId(departmentId){

}

bool Employee::validate(QJsonObject json){
    // TODO implement me
}

QMap<QString, QVariant> Employee::valuesMap(){
    // TODO implement me
}

void Employee::setValuesMap(QMap<QString, QVariant> values){
    // TODO implement me
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

int Employee::supervisorId() const {
    return m_supervisorId;
}

void Employee::setSupervisorId(int superVisorId){
    m_supervisorId = superVisorId;
}

int Employee::departmentId() const {
    return m_departmentId;
}

void Employee::setDepartmentId(int departmentId){
    m_departmentId = departmentId;
}
