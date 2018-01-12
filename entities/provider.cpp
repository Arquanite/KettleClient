#include "provider.h"

Provider::Provider(int id, QString name, QString address) : m_id(id), m_name(name), m_address(address){

}

bool Provider::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("name")) return false;
    if(!json.contains("address")) return false;
    return true;
}

QVariantMap Provider::valuesMap(){
    QVariantMap values;
    values.insert("id", m_id);
    values.insert("name", m_name);
    values.insert("address", m_address);
    return values;
}

void Provider::setValuesMap(QVariantMap values){
    m_id = values.value("id").toInt();
    m_name = values.value("name").toString();
    m_address = values.value("address").toString();
}

int Provider::id() const {
    return m_id;
}

void Provider::setId(int id){
    m_id = id;
}

QString Provider::name() const {
    return m_name;
}

void Provider::setName(const QString &name){
    m_name = name;
}

QString Provider::address() const {
    return m_address;
}

void Provider::setAddress(const QString &address){
    m_address = address;
}
