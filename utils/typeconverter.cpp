#include "typeconverter.h"

QList<Customer> TypeConverter::toCustomer(QJsonArray array){
    Customer c(0, "", "", "");
    QList<Customer> list;
    for(int i=0; i<array.size(); i++){
        if(c.fromJSON(array.at(i).toObject())) list.append(c);
    }
    return list;
}

QList<Department> TypeConverter::toDepartment(QJsonArray array){

}

QList<Employee> TypeConverter::toEmployee(QJsonArray array){

}

QList<Order> TypeConverter::toOrder(QJsonArray array){

}

QList<Part> TypeConverter::toPart(QJsonArray array){

}

QList<Product> TypeConverter::toProduct(QJsonArray array){

}

QList<Provider> TypeConverter::toProvider(QJsonArray array){

}

QList<State> TypeConverter::toState(QJsonArray array){

}
