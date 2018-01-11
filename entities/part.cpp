#include "part.h"

Part::Part(int id, QString name, int providerId) : m_id(id), m_name(name), m_providerId(providerId){

}

bool Part::validate(QJsonObject json){
    // TODO implement me
}

QMap<QString, QVariant> Part::valuesMap(){
    // TODO implement me
}

void Part::setValuesMap(QMap<QString, QVariant> values){
    // TODO implement me
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
