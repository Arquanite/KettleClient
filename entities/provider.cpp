#include "provider.h"

Provider::Provider(int id, QString name, QString address) : m_id(id), m_name(name), m_address(address){

}

bool Provider::validate(QJsonObject json){
    // TODO implement me
}

QMap<QString, QVariant> Provider::valuesMap(){
    // TODO implement me
}

void Provider::setValuesMap(QMap<QString, QVariant> values){
    // TODO implement me
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
