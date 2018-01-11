#include "state.h"

State::State(int id, QString name, int departmentId) : m_id(id), m_name(name), m_departmentId(departmentId){

}

bool State::validate(QJsonObject json){
    // TODO implement me
}

QMap<QString, QVariant> State::valuesMap(){
    // TODO implement me
}

void State::setValuesMap(QMap<QString, QVariant> values){
    // TODO implement me
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
