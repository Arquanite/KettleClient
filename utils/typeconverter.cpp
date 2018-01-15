#include "typeconverter.h"

#include "pdebug.h"

QList<Customer> TypeConverter::toCustomer(QJsonArray array){
    Customer c(0, "", "", "");
    QList<Customer> list;
    for(int i=0; i<array.size(); i++){
        if(c.fromJSON(array.at(i).toObject())){
            list.append(c);
        }
    }
    return list;
}

QList<Department> TypeConverter::toDepartment(QJsonArray array){
    Department d(0, "");
    QList<Department> list;
    for(int i=0; i<array.size(); i++){
        if(d.fromJSON(array.at(i).toObject())){
            list.append(d);
        }
    }
    return list;
}

QList<Employee> TypeConverter::toEmployee(QJsonArray array){
    Employee e(0, "", "", 0, 0, 0, 0);
    QList<Employee> list;
    for(int i=0; i<array.size(); i++){
        if(e.fromJSON(array.at(i).toObject())){
            list.append(e);
        }
    }
    return list;
}

QList<Order> TypeConverter::toOrder(QJsonArray array){
    Order o = Order::builder(0, 0, "").build();
    QList<Order> list;
    for(int i=0; i<array.size(); i++){
        if(o.fromJSON(array.at(i).toObject())){
            list.append(o);
        }
    }
    return list;
}

QList<Part> TypeConverter::toPart(QJsonArray array){
    Part p(0, "", 0);
    QList<Part> list;
    for(int i=0; i<array.size(); i++){
        if(p.fromJSON(array.at(i).toObject())){
            list.append(p);
        }
    }
    return list;
}

QList<Product> TypeConverter::toProduct(QJsonArray array){
    Product p = Product::builder(0, "").build();
    QList<Product> list;
    for(int i=0; i<array.size(); i++){
        if(p.fromJSON(array.at(i).toObject())){
            list.append(p);
        }
    }
    return list;
}

QList<Provider> TypeConverter::toProvider(QJsonArray array){
    Provider p(0, "", "");
    QList<Provider> list;
    for(int i=0; i<array.size(); i++){
        if(p.fromJSON(array.at(i).toObject())){
            list.append(p);
        }
    }
    return list;
}

QList<State> TypeConverter::toState(QJsonArray array){
    State s(0, "", 0);
    QList<State> list;
    for(int i=0; i<array.size(); i++){
        if(s.fromJSON(array.at(i).toObject())){
            list.append(s);
        }
    }
    return list;
}
