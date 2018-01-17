#include "product.h"
#include "pdebug.h"

Product::Product(int id, QString name, QList<Part> parts) : m_id(id), m_name(name), m_parts(parts){

}

Product::Builder Product::builder(int id, QString name){
    return Builder(id, name);
}

bool Product::validate(QJsonObject json){
    if(!json.contains("id")) return false;
    if(!json.contains("name")) return false;
    if(!json.contains("parts")) return false;
    return true;
}

QVariantMap Product::valuesMap(){
    QVariantMap values;
    values.insert("id", m_id);
    values.insert("name", m_name);
    QList<QVariant> parts;
    for(Part p : m_parts) parts.append(p.toJSON());
    values.insert("parts", parts);
    return values;
}

void Product::setValuesMap(QVariantMap values){
    m_id = values.value("id").toInt();
    m_name = values.value("name").toString();
    QList<QVariant> parts = values.value("parts").toList();
    for(QVariant p : parts){
        QVariantMap m = p.toMap();
        Part part(m.value("id").toInt(), m.value("name").toString(), m.value("provider_id").toInt());
        pDebug()<<m.value("provider_id").toInt();
        m_parts.append(part);
    }
}

int Product::id() const {
    return m_id;
}

void Product::setId(int id){
    m_id = id;
}

QString Product::name() const {
    return m_name;
}

void Product::setName(const QString &name){
    m_name = name;
}

QList<Part> Product::parts() const {
    return m_parts;
}

void Product::setParts(const QList<Part> &parts){
    m_parts = parts;
}

Product::Builder::Builder(int id, QString name) : m_id(id), m_name(name){

}

Product::Builder &Product::Builder::addPart(Part p){
    m_parts.append(p);
    return *this;
}

Product Product::Builder::build(){
    return Product(m_id, m_name, m_parts);
}
