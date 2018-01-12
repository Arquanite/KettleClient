#include "part.h"

Part::Part(int id, QString name, int providerId) : m_id(id), m_name(name), m_providerId(providerId){

}

bool Part::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("name")) return false;
    if(!json.contains("provider_id")) return false;
    return true;
}

QVariantMap Part::valuesMap(){
    QVariantMap values;
    values.insert("id", m_id);
    values.insert("name", m_name);
    values.insert("provider_id", m_providerId);
    return values;
}

void Part::setValuesMap(QVariantMap values){
    m_id = values.value("id").toInt();
    m_name = values.value("name").toString();
    m_providerId = values.value("provider_id").toInt();
}

int Part::id() const {
    return m_id;
}

void Part::setId(int id){
    m_id = id;
}

QString Part::name() const {
    return m_name;
}

void Part::setName(const QString &name){
    m_name = name;
}

int Part::providerId() const {
    return m_providerId;
}

void Part::setProviderId(int providerId){
    m_providerId = providerId;
}
