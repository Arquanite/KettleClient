#include "state.h"

State::State(int id, QString name, int departmentId) : m_id(id), m_name(name), m_departmentId(departmentId){

}

bool State::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("name")) return false;
    if(!json.contains("department_id")) return false;
    return true;
}

QVariantMap State::valuesMap(){
    QVariantMap values;
    values.insert("id", m_id);
    values.insert("name", m_name);
    values.insert("department_id", m_departmentId);
    return values;
}

void State::setValuesMap(QVariantMap values){
    m_id = values.value("id").toInt();
    m_name = values.value("name").toString();
    m_departmentId = values.value("departmend_id").toInt();
}

int State::id() const {
    return m_id;
}

void State::setId(int id){
    m_id = id;
}

QString State::name() const {
    return m_name;
}

void State::setName(const QString &name){
    m_name = name;
}

int State::departmentId() const {
    return m_departmentId;
}

void State::setDepartmentId(int departmentId){
    m_departmentId = departmentId;
}
