#include "viewcontroller.h"
#include <QJsonObject>
#include <functional>
#include "randomjsonfactory.h"

#include "customerdialog.h"
#include "departmentdialog.h"
#include "employeedialog.h"
#include "orderdialog.h"
#include "partdialog.h"
#include "productdialog.h"
#include "providerdialog.h"
#include "statedialog.h"
#include "waitingdialog.h"
#include "typeconverter.h"
#include "states.h"

#include <QDebug>
#include <QMessageBox>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>

ViewController::ViewController(JSONModel *model, QObject *parent) : QObject(parent), m_model(model){
    state = new CustomerState(&m_service, m_model);
}

void ViewController::viewChanged(int id){
    QList<QJsonObject> data;
    std::function<QJsonObject(void)> generate;
    RandomJSONFactory JSONFactory;
    m_current = id;
    switch (id) {
    case TypeProvider:
    {QNetworkReply *reply = m_service.getProviders();
        connect(reply, &QNetworkReply::finished, [=](){ qDebug()<<reply->readAll(); });}
//        generate = std::bind(&RandomJSONFactory::randomProvider, JSONFactory);
        break;
    case TypeCustomer: /*{
        QNetworkReply *reply = m_service.getCustomers();
        connect(reply, &QNetworkReply::finished, [=](){
            m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toCustomer(QJsonDocument::fromJson(reply->readAll()).array())));
        });}*/
        state->getList();
//        connect(reply, &QNetworkReply::finished, [=](){ qDebug()<<TypeConverter::toCustomer( reply->readAll()); });
        break;
    case TypeEmployee:
        generate = std::bind(&RandomJSONFactory::randomEmployee, JSONFactory);
        break;
    case TypeDepartment:
        generate = std::bind(&RandomJSONFactory::randomDepartment, JSONFactory);
        break;
    case TypePart:
        generate = std::bind(&RandomJSONFactory::randomPart, JSONFactory);
        break;
    case TypeProduct:
        generate = std::bind(&RandomJSONFactory::randomProduct, JSONFactory);
        break;
    case TypeState:
        generate = std::bind(&RandomJSONFactory::randomState, JSONFactory);
        break;
    case TypeOrder:
        generate = std::bind(&RandomJSONFactory::randomOrder, JSONFactory);
        break;
    }
    qDebug()<<"id"<<id;
//    for(int i=0; i<25; i++){
//        data.append(generate());
//    }
//    WaitingDialog *dialog = new WaitingDialog((QWidget*)parent());
//    dialog->exec();
//    m_model->setSourceData(data);
}

void ViewController::add(){
    QDialog *dialog = nullptr;
    switch(m_current){
    case 0:
        dialog = new ProviderDialog((QWidget*)parent());
        break;
    case 1:
        dialog = new CustomerDialog((QWidget*)parent());
        break;
    case 2:
        dialog = new EmployeeDialog((QWidget*)parent());
        break;
    case 3:
        dialog = new DepartmentDialog((QWidget*)parent());
        break;
    case 4:
        dialog = new PartDialog((QWidget*)parent());
        break;
    case 5:
        dialog = new ProductDialog((QWidget*)parent());
        break;
    case 6:
        dialog = new StateDialog((QWidget*)parent());
        break;
    case 7:
        dialog = new OrderDialog((QWidget*)parent());
        break;
    default:
        return;
    }
    dialog->exec();
}

void ViewController::edit(){
    QDialog *dialog = nullptr;
    switch(m_current){
    case 0:
        dialog = new ProviderDialog((QWidget*)parent());
        break;
    case 1:
        dialog = new CustomerDialog((QWidget*)parent());
        break;
    case 2:
        dialog = new EmployeeDialog((QWidget*)parent());
        break;
    case 3:
        dialog = new DepartmentDialog((QWidget*)parent());
        break;
    case 4:
        dialog = new PartDialog((QWidget*)parent());
        break;
    case 5:
        dialog = new ProductDialog((QWidget*)parent());
        break;
    case 6:
        dialog = new StateDialog((QWidget*)parent());
        break;
    case 7:
        dialog = new OrderDialog((QWidget*)parent());
        break;
    default:
        return;
    }
    dialog->exec();
}

void ViewController::remove(){
    QMessageBox::question((QWidget*)parent(), "Are you sure?", "Do you really want to remove selected row?");
}
