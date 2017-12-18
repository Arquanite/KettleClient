#include "viewcontroller.h"
#include <QJsonObject>
#include <functional>
#include "randomjsonfactory.h"

#include <QDebug>

ViewController::ViewController(JSONModel *model, QObject *parent) : QObject(parent), m_model(model){

}

void ViewController::viewChanged(int id){
    QList<QJsonObject> data;
    std::function<QJsonObject(void)> generate;
    RandomJSONFactory JSONFactory;
    switch (id) {
    case Provider:
        generate = std::bind(&RandomJSONFactory::randomProvider, JSONFactory);
        break;
    case Customer:
        generate = std::bind(&RandomJSONFactory::randomCustomer, JSONFactory);
        break;
    case Employee:
        generate = std::bind(&RandomJSONFactory::randomEmployee, JSONFactory);
        break;
    case Department:
        generate = std::bind(&RandomJSONFactory::randomDepartment, JSONFactory);
        break;
    case Part:
        generate = std::bind(&RandomJSONFactory::randomPart, JSONFactory);
        break;
    case Product:
        generate = std::bind(&RandomJSONFactory::randomProduct, JSONFactory);
        break;
    case State:
        generate = std::bind(&RandomJSONFactory::randomState, JSONFactory);
        break;
    case Order:
        generate = std::bind(&RandomJSONFactory::randomOrder, JSONFactory);
        break;
    }
    qDebug()<<"id"<<id;
    for(int i=0; i<25; i++){
        data.append(generate());
    }
    m_model->setData(data);
}
