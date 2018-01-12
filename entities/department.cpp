#include "department.h"

Department::Department(int id, QString name) : m_id(id), m_name(name){

}

bool Department::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("name")) return false;
    return true;
}

QVariantMap Department::valuesMap(){
    QVariantMap values;
    values.insert("id", m_id);
    values.insert("name", m_name);
    return values;
}

void Department::setValuesMap(QVariantMap values){
    m_id = values.value("id").toInt();
    m_name = values.value("name").toString();
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

