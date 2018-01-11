#include "department.h"

Department::Department(int id, QString name) : m_id(id), m_name(name){

}

bool Department::validate(QJsonObject json){
    // TODO implement me
}

QMap<QString, QVariant> Department::valuesMap(){
    // TODO implement me
}

void Department::setValuesMap(QMap<QString, QVariant> values){
    // TODO implement me
}

int Department::id() const {
    return m_id;
}

void Department::setId(int id){
    m_id = id;
}

QString Department::name() const {
    return m_name;
}

void Department::setName(const QString &name){
    m_name = name;
}

