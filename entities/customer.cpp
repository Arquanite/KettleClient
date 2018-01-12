#include "customer.h"

Customer::Customer(int id, QString name, QString address, QString nip) : m_id(id), m_name(name), m_address(address), m_nip(nip) {

}

bool Customer::validate(QJsonObject json){
    // TODO implement me
}

QMap<QString, QVariant> Customer::valuesMap(){
    // TODO implement me
}

void Customer::setValuesMap(QMap<QString, QVariant> values){
    // TODO implement me
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
