#ifndef TYPECONVERTER_H
#define TYPECONVERTER_H

#include <QList>
#include <QJsonArray>

#include "entities.h"

class TypeConverter {
public:
    TypeConverter() = delete;
    template<class T>
    static QList<JSONAble*> toJSONAble(QList<T> list);

    static QList<Customer> toCustomer(QJsonArray array);
    static QList<Department> toDepartment(QJsonArray array);
    static QList<Employee> toEmployee(QJsonArray array);
    static QList<Order> toOrder(QJsonArray array);
    static QList<Part> toPart(QJsonArray array);
    static QList<Product> toProduct(QJsonArray array);
    static QList<Provider> toProvider(QJsonArray array);
    static QList<State> toState(QJsonArray array);
};

template<class T>
QList<JSONAble*> TypeConverter::toJSONAble(QList<T> list){
    static_assert(!std::is_pointer<T>::value, "Argument cannot be pointer. You should use QList<T> instead of QList<T*>");
    static_assert(std::is_base_of<JSONAble, T>::value, "Base class of argument must be JSONAble");
    QList<JSONAble*> jsons;
    for(T element : list) jsons.append(new T(element));
    return jsons;
}

#endif // TYPECONVERTER_H
