#include "customer.h"

Customer::Customer(int id, QString name, QString address, QString nip) : m_id(id), m_name(name), m_address(address), m_nip(nip) {

}

bool Customer::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("name")) return false;
    if(!json.contains("address")) return false;
    if(!json.contains("nip")) return false;
    return true;
}

QMap<QString, QVariant> Customer::valuesMap(){
    QMap<QString, QVariant> values;
    values.insert("id", m_id);
    values.insert("name", m_name);
    values.insert("address", m_address);
    values.insert("nip", m_nip);
    return values;
}

void Customer::setValuesMap(QMap<QString, QVariant> values){
    m_id = values.value("id").toInt();
    m_name = values.value("name").toString();
    m_address = values.value("address").toString();
    m_nip = values.value("nip").toString();
}

int Customer::id() const {
    return m_id;
}

void Customer::setId(int id){
    m_id = id;
}

QString Customer::name() const {
    return m_name;
}

void Customer::setName(const QString &name){
    m_name = name;
}

QString Customer::address() const {
    return m_address;
}

void Customer::setAddress(const QString &address){
    m_address = address;
}

QString Customer::nip() const {
    return m_nip;
}

void Customer::setNip(const QString &nip){
    m_nip = nip;
}
