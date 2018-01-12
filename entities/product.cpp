#include "product.h"

Product::Product(){
    // TODO implement me
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
    QList<QVariant> parts = values.values("products");
    for(QVariant p : parts){
        Part part(0, "", 0);
        part.fromJSON(p.toJsonObject());
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
